#include "Vec2.h"

Vec2::Vec2()
{
   x = 0;
   y = 0;
}

Vec2::Vec2(const float x, const float y): x(x), y(y)
{
}

Vec2 Vec2::operator+(const Vec2& rhs) const
{
   return {x + rhs.x, y + rhs.y};
}

Vec2& Vec2::operator=(const Vec2 other)
{
   x = other.x;
   y = other.y;
   return *this;
}
