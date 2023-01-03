#pragma once

#include "Macros/InlineReturn.h"

struct Vec2
{
    float x;
    float y;
    
    Vec2();
    Vec2(const float x, const float y);

#pragma region STATIC_CONSTANTS
    
    static Vec2 Zero()  INLINE_RETURN(Vec2(0.0f, 0.0f))
    static Vec2 One()   INLINE_RETURN(Vec2(1.0f, 1.0f))
    static Vec2 Left()  INLINE_RETURN(Vec2(-1.0f, 0.0f))
    static Vec2 Right() INLINE_RETURN(Vec2(1.0f, 0.0f))
    static Vec2 Up()    INLINE_RETURN(Vec2(0.0f, 1.0f))
    static Vec2 Down()  INLINE_RETURN(Vec2(0.0f, -1.0f))

#pragma endregion STATIC_CONSTANTS

#pragma region OPPERATOR_OVERLOADS
    
    Vec2 operator+(const Vec2& rhs) const;

    Vec2& operator =(const Vec2 other);

#pragma endregion OPPERATOR_OVERLOADS
    
};
