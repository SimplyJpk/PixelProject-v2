#include "IVec2.h"

IVec2::IVec2()
{
   x = 0;
   y = 0;
}

IVec2::IVec2(const int x, const int y): x(x), y(y)
{
}

IVec2 IVec2::operator+(const IVec2& rhs) const
{
   return {x + rhs.x, y + rhs.y};
}

IVec2& IVec2::operator=(const IVec2 other)
{
   x = other.x;
   y = other.y;
   return *this;
}
