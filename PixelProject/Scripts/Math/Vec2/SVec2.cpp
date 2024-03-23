#include "SVec2.h"

SVec2::SVec2()
{
   x = 0;
   y = 0;
}

SVec2::SVec2(const short x, const short y): x(x), y(y)
{
}

SVec2 SVec2::operator+(const SVec2& rhs) const
{
   return {static_cast<short>(x + rhs.x), static_cast<short>(y + rhs.y)};
}

SVec2& SVec2::operator=(const SVec2 other)
{
   x = other.x;
   y = other.y;
   return *this;
}
