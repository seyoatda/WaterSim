//
// Created by 54367 on 2019/2/23.
//

#include "waterTile.h"

WaterTile::WaterTile(float x, float z, float height) :x(x),z(z),height(height){}

float WaterTile::getHeight() const {return height;}

float WaterTile::getX() const {return x;}

float WaterTile::getZ() const {return z;}

