#ifndef __TILELAYER_H__
#define __TILELAYER_H__
#include <iostream>
#include <vector>
#include "Vector2D.h"
#include "Layer.h"
#include "Level.h"
#include "Game.h"

class TileLayer : public Layer {
public:
    TileLayer(int tileSize, const std::vector<Tileset> &tilesets);

    void update() override;
    void render() override;

    void setTileIDs(const std::vector<std::vector<int>>& data);
    void setTileSize(int tileSize);
    Tileset getTilesetByID(int tileID);
private:
    int m_numColumns;
    int m_numRows;
    int m_tileSize;

    Vector2D m_position;
    Vector2D m_velocity;

    const std::vector<Tileset> &m_tilesets;
    std::vector<std::vector<int>> m_tileIDs;
};

#endif  /* defined(__TILELAYER_H__) */
