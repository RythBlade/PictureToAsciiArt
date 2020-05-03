#ifndef IMAGECANVAS_H
#define IMAGECANVAS_H

// forward declarations
namespace Bitmap
{
    struct Colour;
}

namespace Bitmap
{
    class ImageCanvas
    {
    public:
        ImageCanvas(unsigned int width, unsigned int height);
        ~ImageCanvas();

        void resize(unsigned int width, unsigned int height);

        inline unsigned int getWidth() const { return m_canvasWidth; }
        inline unsigned int getHeight() const { return m_canvasHeight; }

        inline Colour const* getRawColourData() const { return m_colourData; }

        Colour const& getPixel(unsigned int x, unsigned int y) const;
        void setPixel(unsigned int x, unsigned int y, Colour const& colour) const;

        void setCanvasToTestImage();

    private:
        void deleteColourData();

    private:
        unsigned int m_canvasWidth;
        unsigned int m_canvasHeight;

        Colour* m_colourData;
    };
}

#endif // IMAGECANVAS_H
