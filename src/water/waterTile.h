//
// Created by 54367 on 2019/2/23.
//

#ifndef OPENGL_WATER_TILE_H
#define OPENGL_WATER_TILE_H


class WaterTile {
public:
    WaterTile(float x, float z, float height);

    float getX() const;

    float getZ() const;

    float getHeight() const;

    static constexpr float TILE_SIZE = 200.0f;

private:
    float x, z, height;
};


#endif //OPENGL_WATER_TILE_H
