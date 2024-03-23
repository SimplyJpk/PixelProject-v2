#pragma once

#include <SDL_stdinc.h>
#include "World/WorldConstants.h"

/**
 Container Type\n
 [0] = E_LogicResults\n
 [1] = NeighbourType\n
 [2] = NewPixel = E_PixelType (Local)\n
 [3] = NewPixel = E_PixelType (Neighbour)\n
 [4] = E_ChunkDirection (Pixel Update Direction)
 
 Mess of a container class that is updates during pixel updates. This was made to pass only 1 reference around instead of 3 value types and 1 reference.
 This proves to be faster, if only because most updates only require setting the first value of the container (Fail/Pass) before continuing.
 Readability however, gets thrown out the window.
 */
class PixelUpdateResult
{
   // Typedef Pixel::LogicResult to LogicResult
   typedef Pixel::LogicResult LogicResult;
   typedef Pixel::PixelType PixelType;
   typedef Chunk::WorldDir WorldDir;

   enum ContainerIndex
   {
      Results = 0,
      NeighbourPixelType = 1,
      NewSelfType = 2,
      NewNeighbourType = 3,
      DirectionIndex = 4
   };
   
private:
   int8_t _results[5] = { 0 };
public:

   // Result
   inline LogicResult Result() { return static_cast<LogicResult>(_results[0]); }
   inline constexpr void SetResult(const LogicResult result) { _results[ContainerIndex::Results] = result; }

   // Neighbour
   inline PixelType NeighbourType() { return static_cast<PixelType>(_results[ContainerIndex::NeighbourPixelType]); }
   inline constexpr void SetNeighbour(const PixelType type) { _results[ContainerIndex::NeighbourPixelType] = static_cast<int8_t>(type); }

   // Local NewPixel
   inline PixelType NewLocal() { return static_cast<PixelType>(_results[ContainerIndex::NewSelfType]); }
   inline void SetLocal(const PixelType type)
   {
      _results[ContainerIndex::NewSelfType] = static_cast<int8_t>(type);
      _results[ContainerIndex::Results] = static_cast<int8_t>(LogicResult::FirstReturnPixel);
   }

   // Neighbour NewPixel
   inline PixelType NewNeighbour() { return static_cast<PixelType>(_results[3]); }
   inline void SetNewNeighbour(const PixelType type)
   {
      _results[ContainerIndex::NewNeighbourType] = static_cast<int8_t>(type);
      _results[ContainerIndex::Results] = static_cast<int8_t>(LogicResult::SecondReturnPixel);
   }

   // Direction
   inline WorldDir Dir() { return static_cast<WorldDir>(_results[ContainerIndex::DirectionIndex]); }
   inline void SetDirection(const WorldDir dir) { _results[ContainerIndex::DirectionIndex] = static_cast<int8_t>(dir); }


   // Set Local & Neighbour Type
   inline void SetLocalAndNeighbour(const PixelType local, const PixelType neighbour)
   {
      _results[ContainerIndex::NewSelfType] = static_cast<int8_t>(local);
      _results[ContainerIndex::NewNeighbourType] = static_cast<int8_t>(neighbour);
      _results[ContainerIndex::DirectionIndex] = static_cast<int8_t>(LogicResult::DualReturnPixel);
   }

   // Simple one liner
   inline constexpr void Fail() { _results[ContainerIndex::Results] = static_cast<int8_t>(LogicResult::FailedUpdate); }
   inline constexpr void Pass() { _results[ContainerIndex::Results] = static_cast<int8_t>(LogicResult::SuccessUpdate); }
};