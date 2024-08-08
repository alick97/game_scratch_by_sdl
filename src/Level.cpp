#include "Level.h"

Level::Level() {}
Level::~Level() {}

void Level::update() {
    for (auto p_layer : m_layers) {
        p_layer->update(this);
    }

}

void Level::render() {
    for(auto p_layer : m_layers) {
        p_layer->render();
    }
}

std::vector<Tileset> *Level::getTitlesets() {
    return &m_tilesets;
}

std::vector<Layer*> *Level::getLayers() {
    return &m_layers;
}
