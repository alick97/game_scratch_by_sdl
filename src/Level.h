#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <vector>
#include <string>
#include "Layer.h"


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
private:
    std::vector<Tileset> m_tilesets;
    std::vector<Layer*> m_layers;

    friend class LevelParser;
    Level();
};
#endif  /* defined(__LEVEL_H__) */
