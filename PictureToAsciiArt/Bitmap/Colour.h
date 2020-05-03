#ifndef COLOUR_H
#define COLOUR_H

namespace Bitmap
{
    using ColourChannel = unsigned char;

    struct Colour
    {
        Colour()
            : blue(0)
            , green(0)
            , red(0)
        {
        }

        Colour(ColourChannel r, ColourChannel g, ColourChannel b)
            : blue(b)
            , green(g)
            , red(r)
        {
        }

        ColourChannel blue;
        ColourChannel green;
        ColourChannel red;
    };
}

#endif