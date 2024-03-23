#include "IVec2.h"

IVec2::IVec2()
{
   x = 0;
   y = 0;
}

constexpr IVec2::IVec2(const int x, const int y): x(x), y(y)
{
}

IVec2 IVec2::operator+(const IVec2& rhs) const
{
   return {x + rhs.x, y + rhs.y};
}

IVec2 IVec2::operator-(const IVec2& rhs) const
{
   return {x - rhs.x, y - rhs.y};
}

IVec2& IVec2::operator=(const IVec2 other)
{
   x = other.x;
   y = other.y;
   return *this;
}

IVec2& IVec2::operator+=(const IVec2& vec2)
{
   x += vec2.x;
   y += vec2.y;
   return *this;
}

IVec2& IVec2::operator-=(const IVec2& vec2)
{
   x -= vec2.x;
   y -= vec2.y;
   return *this;
}

bool IVec2::operator==(const IVec2& vec2) const
{
   return x == vec2.x && y == vec2.y;
}

IVec2 IVec2::GetNormalized() const
{
   const float length = GetMagnitude();
   return {static_cast<int>(x / length), static_cast<int>(y / length)};
}

void IVec2::Normalize()
{
   const float length = GetMagnitude();
   x /= length;
   y /= length;
}

float IVec2::GetMagnitude() const
{
   return static_cast<float>(sqrt(x * x + y * y));
}
