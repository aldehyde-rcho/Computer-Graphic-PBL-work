

#ifndef RASTERIZER_TEXTURE_H
#define RASTERIZER_TEXTURE_H
#include <eigen3/Eigen/Eigen>
class Texture
{
private:
public:
    Texture(const std::string &name)
    {
    }

    int width, height;

    Eigen::Vector3f getColor(float u, float v)
    {
    }
};
#endif // RASTERIZER_TEXTURE_H
