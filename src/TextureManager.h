#ifndef __TEXTUREMANGER__
#define __TEXTUREMANGER__
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>

class TextureManager {
public:
    bool load(const std::string& fileName, std::string id, SDL_Renderer* pRenderer);

    // draw
    void draw(const std::string& id, int x, int y, int width, int
    height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    // drawframe
    void drawFrame(const std::string& id, int x, int y, int width, int height,
    int currentRow, int currentFrame, SDL_Renderer* pRenderer,
    double angle, int alpha,
    SDL_RendererFlip flip = SDL_FLIP_NONE);

    // clear texture
    void clearFromTextureMap(std::string id);
    
    // draw tile
    void drawTile(
        std::string id, int margin, int spacing,
        int x, int y, int width, int height,
        int currentRow, int currentFrame, SDL_Renderer *pRenderer);

    static TextureManager* Instance();
private:
    std::map<std::string, SDL_Texture*> m_textureMap;
    static TextureManager* s_pInstance;
    TextureManager() {}
};

typedef TextureManager TheTextureManager;

#endif /* defined(__TEXTUREMANGER__) */
