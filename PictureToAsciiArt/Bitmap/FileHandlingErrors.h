#ifndef FILEHANDLINGERRORS_H
#define FILEHANDLINGERRORS_H

namespace Bitmap
{
    enum class FileHandlingErrors
    {
        OK = 0
        , FileCorrupt
        , UnexpectedEndOfFile
        , FileTypeUnknown
        , Not24BitColourBitmap
        , CompressionNotSupported
        , PalettisedBitmapNotSupported
        , UnknownReadError
        , UnknownWriteError
    };
}

#endif