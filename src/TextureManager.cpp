#include "TextureManager.h"

bool TextureManager::load(const std::string& fileName, std::string id,
SDL_Renderer* pRender) {
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

    if (NULL == pTempSurface) {
        std::cerr<<"err: src: " << __FILE__ << " function: " << __FUNCTION__ << " file: "
        << fileName << " not exist\n";
        return false;
    }

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(
        pRender, pTempSurface);

    SDL_FreeSurface(pTempSurface);

    // everything went ok, add the texture to our list
    if (NULL != pTexture) {
        m_textureMap[id] = pTexture;
        return true;
    }

    // reaching here means something went wrong
    std::cerr << "Error creating texture: " << SDL_GetError() << std::endl;

    return false;
}

void TextureManager::draw(const std::string& id, int x, int y,
int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
    SDL_Rect srcRect, destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id],
    &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(const std::string& id, int x, int y,
    int width, int height, int currentRow, int currentFrame,
    SDL_Renderer *pRenderer, 
    double angle, int alpha,
    SDL_RendererFlip flip) {
    SDL_Rect srcRect, destRect;
    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1); // for naturally first row is 1 not 0
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    // set the alpha of the texture and pass in the angle.
    SDL_SetTextureAlphaMod(m_textureMap[id], alpha);
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
    &destRect, angle, 0, flip);
}

TextureManager* TextureManager::Instance() {
    if (NULL == s_pInstance) {
        s_pInstance = new TextureManager();
        return s_pInstance;
    }

    return s_pInstance;
}

void  TextureManager::clearFromTextureMap(std::string id) {
    m_textureMap.erase(id);
}

void TextureManager::drawTile(
    std::string id, int margin, int spacing,
    int x, int y, int width, int height,
    int currentRow, int currentFrame, SDL_Renderer *pRenderer) {
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = margin + (spacing + width) * currentFrame;
    srcRect.y = margin + (spacing + height) * currentRow;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
    &destRect, 0, 0, SDL_FLIP_NONE);
}


TextureManager* TextureManager::s_pInstance = NULL;