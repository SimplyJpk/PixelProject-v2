#pragma once

#include "Macros/InlineReturn.h"

struct IVec2
{
   int x;
   int y;

   IVec2();
   IVec2(const int x, const int y);

#pragma region STATIC_CONSTANTS

   static IVec2 Zero() INLINE_RETURN(IVec2(0, 0))
   static IVec2 One() INLINE_RETURN(IVec2(1, 1))
   static IVec2 Left() INLINE_RETURN(IVec2(-1, 0))
   static IVec2 Right() INLINE_RETURN(IVec2(1, 0))
   static IVec2 Up() INLINE_RETURN(IVec2(0, 1))
   static IVec2 Down() INLINE_RETURN(IVec2(0, -1))

#pragma endregion STATIC_CONSTANTS

#pragma region OPPERATOR_OVERLOADS

   IVec2 operator+(const IVec2& rhs) const;

   IVec2& operator =(const IVec2 other);

#pragma endregion OPPERATOR_OVERLOADS
};
