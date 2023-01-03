#pragma once

#include "Macros/InlineReturn.h"

struct SVec2
{
    short x;
    short y;
    
    SVec2();
    SVec2(const short x, const short y);

#pragma region STATIC_CONSTANTS
    
    static SVec2 Zero()  INLINE_RETURN(SVec2(0, 0))
    static SVec2 One()   INLINE_RETURN(SVec2(1, 1))
    static SVec2 Left()  INLINE_RETURN(SVec2(-1, 0))
    static SVec2 Right() INLINE_RETURN(SVec2(1, 0))
    static SVec2 Up()    INLINE_RETURN(SVec2(0, 1))
    static SVec2 Down()  INLINE_RETURN(SVec2(0, -1))

#pragma endregion STATIC_CONSTANTS

#pragma region OPPERATOR_OVERLOADS
    
    SVec2 operator+(const SVec2& rhs) const;

    SVec2& operator =(const SVec2 other);

#pragma endregion OPPERATOR_OVERLOADS
    
};
