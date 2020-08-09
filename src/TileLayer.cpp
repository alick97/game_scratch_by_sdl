#include "TileLayer.h"

TileLayer::TileLayer(int tileSize, const std::vector<Tileset> &tilesets):
    m_numColumns(0),
    m_numRows(0),
    m_tileSize(tileSize),
    m_tilesets(tilesets) {

}

void TileLayer::update() {

}

void TileLayer::render() {

}

void TileLayer::setTileIDs(const std::vector<std::vector<int>>& data) {
    m_tileIDs = data;
}

void TileLayer::setTileSize(int tileSize) {
    m_tileSize = tileSize;
}

Tileset TileLayer::getTilesetByID(int tileID) {
    for(int i = 0; i + 1 < m_tilesets.size() - 1; ++i) {
        if (tileID >= m_tilesets[i].firstGridID && tileID < m_tilesets[i+1].firstGridID) {
            return m_tilesets[i];
        }
    }

    std::cout << "did not find tileset, returning empty tileset\n";
    Tileset t;
    return t;
}
