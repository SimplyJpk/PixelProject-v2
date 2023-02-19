#pragma once

#include <typeindex>
#include <unordered_map>

#include "PixelTypes.h"

class WorldDataHandler
{
public:
   static WorldDataHandler& GetInstance();

   // TODO : (James) Utility functions
   // std::string GetPixelName(const Pixels::PixelType& pixel_type) const;
   // const BasePixel& GetPixelFromColour(const Uint32& colour) const;

   // const BasePixel& GetPixelFromIndex(const uint8_t index) const;

   const uint8_t& GetRandomPixelUpdateOrder(Pixels::PixelType pixel_type) const;
   Uint32 GetPixelColour(const Pixels::PixelType& pixel_type) const;
   
   WorldDataHandler(const WorldDataHandler&) = delete;
   WorldDataHandler(WorldDataHandler&&) = delete;
   void operator=(const WorldDataHandler&) = delete;
   void operator=(WorldDataHandler&&) = delete;
   
protected:
   constexpr WorldDataHandler();

private:
   ~WorldDataHandler() = default;

   // Main array holding pixel types in contiguous memory
   std::array<BasePixel, Pixels::PIXEL_TYPE_COUNT> _pixel_types;

   // utility structures for fast lookup and iteration
   std::unordered_map<Uint32, BasePixel&> _pixel_colour_map;
   std::unordered_map<Pixels::PixelType, BasePixel&> _pixel_type_map;
};
