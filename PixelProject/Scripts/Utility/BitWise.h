#pragma once

namespace PixelProject::Utility {
inline void SetBit(unsigned int& value, const unsigned short bit)
{
   value |= (1 << bit);
}

inline void ClearBit(unsigned int& value, const unsigned short bit)
{
   value &= ~(1 << bit);
}

inline bool IsBitSet(const unsigned int value, const unsigned short bit)
{
   return (value & (1 << bit)) != 0;
}

inline void ToggleBit(unsigned int& value, const unsigned short bit)
{
   value ^= (1 << bit);
}
}
