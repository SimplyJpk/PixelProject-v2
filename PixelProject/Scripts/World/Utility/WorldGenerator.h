#pragma once

#include "FastNoiseSIMD/FastNoiseSIMD.h"
#include "World/Chunk/WorldChunk.h"

class WorldGenerator
{
public:
   WorldGenerator();
   
   static inline FastNoiseSIMD* noise = nullptr;

   static bool GenerateChunk(WorldChunk* world_chunk);

   static void GenerateNoise();

};
