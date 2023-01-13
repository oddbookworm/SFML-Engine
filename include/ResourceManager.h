#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <memory>
#include <string>
#include <unordered_map>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "utility.hpp"

typedef std::shared_ptr<sf::Texture> texPtr;
typedef std::shared_ptr<sf::Font> fontPtr;
typedef std::shared_ptr<sf::SoundBuffer> soundPtr;

/**
 * @brief Class that manages references to sf::Texture, sf::Font, and
 * sf::SoundBuffer objects
 *
 */
class ResourceManager {
public:
    /**
     * @brief add an sf::Texture into the manager
     *
     * @param name std::string with the name of the texture
     * @param texture std::shared_ptr<sf::Texture> to be managed
     */
    void addTexture(const std::string& name, texPtr texture);
    /**
     * @brief add an sf::Font into the manager
     *
     * @param name std::string with the name of the font
     * @param font std::shared_ptr<sf::Font> to be managed
     */
    void addFont(const std::string& name, fontPtr font);
    /**
     * @brief add an sf::SoundBuffer into the manager
     *
     * @param name std::string with the name of the sound
     * @param buff std::shared_ptr<sf::SoundBuffer> to be managed
     */
    void addSound(const std::string& name, soundPtr buff);

    /**
     * @brief Get the texture corresponding to name
     *
     * @param name std::string name of the texture
     * @return texPtr std::shared_ptr<sf::Texture> containing the texture
     */
    texPtr getTexture(const std::string& name);
    /**
     * @brief Get the font corresponding to name
     *
     * @param name std::string name of the font
     * @return fontPtr std::shared_ptr<sf::Font> containing the font
     */
    fontPtr getFont(const std::string& name);
    /**
     * @brief Get the soundbuffer corresponding to name
     *
     * @param name std::string name of the sound
     * @return fontPtr std::shared_ptr<sf::SoundBuffer> containing the sound
     */
    soundPtr getSound(const std::string& name);

    /**
     * @brief removes the texture corresponding to name from the manager
     *
     * @param name std::string giving the name of the texture to remove
     */
    void removeTexture(const std::string& name);
    /**
     * @brief removes the font corresponding to name from the manager
     *
     * @param name std::string giving the name of the font to remove
     */
    void removeFont(const std::string& name);
    /**
     * @brief removes the soundbuffer corresponding to name from the manager
     *
     * @param name std::string giving the name of the soundbuffer to remove
     */
    void removeSound(const std::string& name);

    /**
     * @brief removes all textures from the manager
     *
     */
    void clearTextures();
    /**
     * @brief removes all fonts from the manager
     *
     */
    void clearFonts();
    /**
     * @brief removes all sounds from the manager
     *
     */
    void clearSounds();
    /**
     * @brief removes all resources from the manager
     *
     */
    void clearAllResources();

    /**
     * @brief load texture from file and add it to the manager
     *
     * @param filename name of the file to load
     * @param name name for the texture
     * @return true if successful, false if failed
     */
    bool tex_FromFile(const std::string& filename, const std::string& name);
    /**
     * @brief load font from file and add it to the manager
     *
     * @param filename name of the file to load
     * @param name name for the font
     * @return true if successful, false if failed
     */
    bool font_FromFile(const std::string& filename, const std::string& name);
    /**
     * @brief load sound from file and add it to the manager
     *
     * @param filename name of the file to load
     * @param name name for the sound
     * @return true if successful, false if failed
     */
    bool sound_FromFile(const std::string& filename, const std::string& name);

private:
    std::unordered_map<std::string, texPtr> textures;
    std::unordered_map<std::string, fontPtr> fonts;
    std::unordered_map<std::string, soundPtr> sounds;
};

#endif