#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <vector>
#include <string>
#include "Layer.h"
#include "Player.h"

class TileLayer;

struct Tileset {
    int firstGridID;
    int titleWidth;
    int tileHeight;
    int spacing;
    int margin;
    int width;
    int height;
    int numColumns;
    std::string name;
};

class Level {
public:
    ~Level();

    void update();
    void render();

    std::vector<Tileset> *getTitlesets();
    std::vector<Layer*> *getLayers();
    std::vector<TileLayer*>* getCollisionLayers() { return &m_collisionLayers; }
    const std::vector<TileLayer*>& getCollidableLayers() { return m_collisionLayers; }

    Player* getPlayer() { return m_pPlayer; }
    void setPlayer(Player* pPlayer) { m_pPlayer = pPlayer; }
private:
    friend class LevelParser;

    Player *m_pPlayer;

    std::vector<Tileset> m_tilesets;
    std::vector<Layer*> m_layers;
    std::vector<TileLayer*> m_collisionLayers; 

    friend class LevelParser;
    Level();
};
#endif  /* defined(__LEVEL_H__) */
