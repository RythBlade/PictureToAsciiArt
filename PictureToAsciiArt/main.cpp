#include <stdio.h>

#include "Bitmap/ImageFile.h"
#include "Bitmap/ImageCanvas.h"
#include "Bitmap/Colour.h"
#include <string.h>

void pixelToAscii(char const* const sourceFileName, char const* const outputFileName)
{
    Bitmap::ImageCanvas myCanvas(2, 2);
    Bitmap::ImageFile myFile;

    Bitmap::FileHandlingErrors error = myFile.load(sourceFileName, myCanvas);

    bool shouldContinue = error == Bitmap::FileHandlingErrors::OK;

    if (shouldContinue)
    {
        printf("Successfully read \"%s\". Image size: %d x %d\n", sourceFileName, myCanvas.getWidth(), myCanvas.getHeight());

        unsigned int const width = myCanvas.getWidth();
        unsigned int const height = myCanvas.getHeight();

        char const* const mappingString = "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
        unsigned int const lengthOfString = strlen(mappingString);

        FILE* outputFile = nullptr;
        errno_t fileError = fopen_s(&outputFile, outputFileName, "w");

        if (outputFile && fileError == 0)
        {


            for (unsigned y = 0; y < height; ++y)
                //for (unsigned x = width - 1; x >= 0 && x < width; --x)
            {
                for (unsigned x = 0; x < width; ++x)
                    //for (unsigned y = height - 1; y >= 0 && y < height; --y)
                {
                    Bitmap::Colour const& pixel = myCanvas.getPixel(x, y);

                    float const greyscaleAverage = (static_cast<float>(pixel.blue) + static_cast<float>(pixel.green) + static_cast<float>(pixel.red)) / 3.0f;

                    float const mappedIndex = (greyscaleAverage / 255.0f) * static_cast<float>(lengthOfString - 1); // -1 off the length of the string as the mapping is inclusive of the limit

                    unsigned char mappedIndexInteger = static_cast<unsigned char>(mappedIndex);

                    fwrite(&mappingString[mappedIndexInteger], sizeof(char), 1, outputFile);
                    fwrite(&mappingString[mappedIndexInteger], sizeof(char), 1, outputFile);
                }

                fwrite("\n", sizeof(char), 1, outputFile);
            }

            fclose(outputFile);
        }
    }
}

int main()
{
    {
        char const* const sourceFileName = "TestImages\\imageToLoad.bmp";
        char const* const outputFileName = "TestImages\\imageToLoad.txt";

        pixelToAscii(sourceFileName, outputFileName);
    }

    {
        char const* const sourceFileName = "TestImages\\imageToLoad2.bmp";
        char const* const outputFileName = "TestImages\\imageToLoad2.txt";

        pixelToAscii(sourceFileName, outputFileName);
    }

    return 0;
}