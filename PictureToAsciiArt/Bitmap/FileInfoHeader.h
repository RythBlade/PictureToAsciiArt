#ifndef FILEINFOHEADER_H
#define FILEINFOHEADER_H

namespace Bitmap
{
    struct FileInfoHeader
    {
        FileInfoHeader()
            : imageWidth(0)
            , imageHeight(0)
        {
        }

        unsigned int imageWidth;
        unsigned int imageHeight;
    };
}

#endif