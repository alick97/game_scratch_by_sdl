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
    virtual ~TileLayer() {}

    void update() override;
    void render() override;

    void setTileIDs(const std::vector<std::vector<int>>& data);
    void setTileSize(int tileSize);
    void setMapWidth(int mapWidth) { m_mapWidth = mapWidth; }
    Tileset getTilesetByID(int tileID);
    const std::vector<std::vector<int>>& getTileIDs() { return m_tileIDs; }
    int getTileSize() { return m_tileSize; }
    const Vector2D getPosition() { return m_position; }
private:
    int m_numColumns;
    int m_numRows;
    int m_tileSize;
    
    int m_mapWidth;

    Vector2D m_position;
    Vector2D m_velocity;

    const std::vector<Tileset> &m_tilesets;
    std::vector<std::vector<int>> m_tileIDs;
};

#endif  /* defined(__TILELAYER_H__) */
