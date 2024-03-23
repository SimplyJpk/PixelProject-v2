#pragma once

#include "Input/InputContainer.h"
#include "Macros/InlineReturn.h"

struct IVec2
{
   int x;
   int y;

   IVec2();
   constexpr IVec2(int x, int y);
   constexpr IVec2(const short x, const short y) : x(static_cast<int>(x)), y(static_cast<int>(y)) {}
   
   template <class Archive>
   void serialize(Archive& archive)
   {
      archive(x, y);
   }

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
   IVec2 operator-(const IVec2& rhs) const;

   IVec2& operator =(const IVec2 other);
   IVec2& operator+=(const IVec2& vec2);
   IVec2& operator-=(const IVec2& vec2);
   bool operator==(const IVec2& vec2) const;

#pragma endregion OPPERATOR_OVERLOADS

#pragma region FUNCTIONS
   
   IVec2 GetNormalized() const;
   void Normalize();
   
   float GetMagnitude() const;

#pragma endregion FUNCTIONS
};

namespace std
{
   template <>
   struct hash<IVec2>
   {
      size_t operator()(const IVec2& vec2) const
      {
         return hash<int>()(vec2.x) ^ hash<int>()(vec2.y);
      }
   };
}
