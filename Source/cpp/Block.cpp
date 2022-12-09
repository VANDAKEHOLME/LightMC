#include "Block.h"
LightMC::Block::Block(float _x, float _y, float _z, float _width, float _height, float _depth) : x(_x), y(_y), z(_z), width(_width), height(_height), depth(_depth)
{
    positions = {
            x, y, z, x + width, y, z, x + width, y, z + depth, x, y, z + depth,
            x, y + height, z, x + width, y + height, z, x + width, y + height, z + depth, x, y + height, z + depth};

}