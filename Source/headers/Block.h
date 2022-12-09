#include <vector>
namespace LightMC
{
    /// @brief The minium unit of terrain.
    class Block
    {
    public:
        float x, y, z;
        float width, height, depth;
        //3 float  for 1 vertex
        //Each block obtain 8 vertices

    public:
        std::vector<float> positions;
        Block(float _x, float _y, float _z, float _width, float _height, float _depth);
    };
}