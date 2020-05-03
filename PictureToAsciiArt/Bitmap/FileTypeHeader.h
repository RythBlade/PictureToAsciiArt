#ifndef FILETYPEHEADER_H
#define FILETYPEHEADER_H

namespace Bitmap
{
    struct FileTypeHeader
    {
        FileTypeHeader()
            : fileSize(0)
            , offsetToBitmapData(0)
        {
        }

        unsigned int fileSize;
        unsigned int offsetToBitmapData;
    };
}

#endif