#include "ImageCanvas.h"

#include "Colour.h"

namespace Bitmap
{
    ImageCanvas::ImageCanvas(unsigned int width, unsigned int height)
        :m_canvasWidth(width)
        , m_canvasHeight(height)
        , m_colourData(nullptr)
    {
        resize(width, height);
    }

    ImageCanvas::~ImageCanvas()
    {
        deleteColourData();
    }

    void ImageCanvas::resize(unsigned int width, unsigned int height)
    {
        m_canvasWidth = width;
        m_canvasHeight = height;

        deleteColourData();

        m_colourData = new Colour[m_canvasWidth * m_canvasHeight];
    }

    Bitmap::Colour const& ImageCanvas::getPixel(unsigned int x, unsigned int y) const
    {
        // origin of the image is the top left corner
        // right == m_canvasWidth
        // left == 0
        // top == m_canvasHeight == y=0
        // bottom == 0

        unsigned int pixelIndex = 0;

        if (x < m_canvasWidth && y < m_canvasHeight)
        {
            pixelIndex = (m_canvasHeight - y) * m_canvasWidth + x;
        }

        return m_colourData[pixelIndex];
    }

    void ImageCanvas::setPixel(unsigned int x, unsigned int y, Colour const& colour) const
    {
        unsigned int pixelIndex = 0;

        if (x < m_canvasWidth && y < m_canvasHeight)
        {
            pixelIndex = y * m_canvasWidth + x;
        }

        m_colourData[pixelIndex] = colour;
    }

    void ImageCanvas::setCanvasToTestImage()
    {
        int nextPixelIndex = 0;

        // top to bottom
        for (unsigned int j = 0; j < m_canvasHeight; ++j)
        {
            // left to right
            for (unsigned int i = 0; i < m_canvasWidth; ++i)
            {
                float const horizontalRatio = static_cast<float>(i) / m_canvasWidth;
                float const verticalRatio = static_cast<float>(j) / m_canvasHeight;

                ColourChannel finalHorizontalValue = static_cast<ColourChannel>(horizontalRatio * 127.0f);
                ColourChannel finalVerticalValue = static_cast<ColourChannel>(verticalRatio * 127.0f);
                ColourChannel combinedValue = finalHorizontalValue + finalVerticalValue;

                float const borderWidth = 5;

                Colour combinedColour(combinedValue, combinedValue, combinedValue);

                // bottom left == white
                Colour bottomLeft(255u, 255u, 255u);

                // left == red
                Colour left(255u, 0u, 0u);

                // top left == blue
                Colour topLeft(0u, 0u, 255u);

                // bottom right == black
                Colour bottomRight(0u, 0u, 0u);

                // right == green
                Colour right(0u, 255u, 0u);

                // top right == red + blue
                Colour topRight(255u, 0u, 255u);

                // bottom == red + green
                Colour bottom(255u, 255u, 0u);

                // top == green + blue
                Colour top(0u, 255u, 255u);

                if (i < borderWidth)
                {
                    if (j < borderWidth)
                    {
                        m_colourData[nextPixelIndex] = bottomLeft;
                    }
                    else if (j > (m_canvasHeight - borderWidth))
                    {
                        m_colourData[nextPixelIndex] = topLeft;
                    }
                    else
                    {
                        m_colourData[nextPixelIndex] = left;
                    }
                }
                else if (i > (m_canvasWidth - borderWidth))
                {
                    if (j < 5)
                    {
                        m_colourData[nextPixelIndex] = bottomRight;
                    }
                    else if (j > (m_canvasHeight - borderWidth))
                    {
                        m_colourData[nextPixelIndex] = topRight;
                    }
                    else
                    {
                        m_colourData[nextPixelIndex] = right;
                    }
                }
                else if (j < borderWidth)
                {
                    m_colourData[nextPixelIndex] = bottom;
                }
                else if (j > (m_canvasHeight - borderWidth))
                {
                    m_colourData[nextPixelIndex] = top;
                }
                else
                {
                    m_colourData[nextPixelIndex] = combinedColour;
                }

                ++nextPixelIndex;
            }
        }
    }

    void ImageCanvas::deleteColourData()
    {
        if (m_colourData)
        {
            delete[] m_colourData;
            m_colourData = nullptr;
        }
    }

}