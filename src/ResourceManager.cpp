#include "../include/ResourceManager.h"
#include "../include/utility.hpp"

void ResourceManager::addTexture(const std::string& name, texPtr texture) {
    textures.emplace(name, texture);
}
void ResourceManager::addFont(const std::string& name, fontPtr font) {
    fonts.emplace(name, font);
}
void ResourceManager::addSound(const std::string& name, soundPtr buff) {
    sounds.emplace(name, buff);
}

texPtr ResourceManager::getTexture(const std::string& name) {
    return textures[name];
}
fontPtr ResourceManager::getFont(const std::string& name) {
    return fonts[name];
}
soundPtr ResourceManager::getSound(const std::string& name) {
    return sounds[name];
}

void ResourceManager::removeTexture(const std::string& name) {
    if (!keyExists<std::string, texPtr>(textures, name)) {
        std::cout << "Cannot delete texture with name " << name
                  << " because it does not exist";
        return;
    }
    textures.erase(name);
}
void ResourceManager::removeFont(const std::string& name) {
    if (!keyExists<std::string, fontPtr>(fonts, name)) {
        std::cout << "Cannot delete font with name " << name
                  << " because it does not exist";
        return;
    }
    fonts.erase(name);
}
void ResourceManager::removeSound(const std::string& name) {
    if (!keyExists<std::string, soundPtr>(sounds, name)) {
        std::cout << "Cannot delete soundbuffer with name " << name
                  << " because it does not exist";
        return;
    }
    sounds.erase(name);
}

void ResourceManager::clearTextures() {
    textures.clear();
}
void ResourceManager::clearFonts() {
    fonts.clear();
}
void ResourceManager::clearSounds() {
    sounds.clear();
}
void ResourceManager::clearAllResources() {
    clearTextures();
    clearFonts();
    clearSounds();
}

bool ResourceManager::tex_FromFile(const std::string& filename,
                                   const std::string& name) {
    auto tex = std::make_shared<sf::Texture>();
    if (!tex->loadFromFile(filename)) {
        return false;
    }

    addTexture(name, tex);
    return true;
}
bool ResourceManager::font_FromFile(const std::string& filename,
                                    const std::string& name) {
    auto font = std::make_shared<sf::Font>();
    if (!font->loadFromFile(filename)) {
        return false;
    }

    addFont(name, font);
    return true;
}
bool ResourceManager::sound_FromFile(const std::string& filename,
                                     const std::string& name) {
    auto sound = std::make_shared<sf::SoundBuffer>();
    if (!sound->loadFromFile(filename)) {
        return false;
    }

    addSound(name, sound);
    return true;
}