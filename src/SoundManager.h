#ifndef __SOUND_MANAGER_H__
#define __SOUND_MANAGER_H__
#include <string>
#include <map>
#include <SDL_mixer.h>

enum sound_type {
  SOUND_MUSIC = 0,
  SOUND_SFX = 1  // sound effects.
};


class SoundManager {
public:
    static SoundManager* Instance();
    bool load(std::string fileName, std::string id, sound_type type);
    void playSound(std::string id, int loop);
    void playMusic(std::string id, int loop);
private:
    static SoundManager* s_pInstance;

    std::map<std::string, Mix_Chunk*> m_sfxs;
    std::map<std::string, Mix_Music*> m_music;
    
    SoundManager();
    ~SoundManager();
    
    SoundManager(const SoundManager&);  // not support;
    SoundManager &operator=(const SoundManager&);  // not support;
    
};

typedef SoundManager TheSoundManager;

#endif