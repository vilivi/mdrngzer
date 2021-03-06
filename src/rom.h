#ifndef ROM_H
#define ROM_H
#include <memory>
#include <cstdint>
#include <vector>
#include <random>
#include "itemspawn.h"

class ROM {
public:
    ROM(unsigned seed);
    void open(const std::string &filePath);
    int loadFile(const std::string &filePath, std::vector<uint8_t> &memory);
    void loadAllFiles();
    void save(const std::string &filePath);
    int saveFile(const std::string &filePath, std::vector<uint8_t> &memory);
    void saveAllFiles();
    
    void randPokemon();
    void randAbilities(unsigned percent);
    void randTypes(unsigned percent);
    void randIQs();
    void randMusic();
    void randTerrain();
    void randMoveset();
    void randItems();
    void randText();
    void randStarters();
    
    std::vector<uint8_t> dungeonMemory;
    std::vector<uint8_t> pokemonMemory;
    std::vector<uint8_t> moveMemory;
    std::vector<uint8_t> overlay13Memory;
    std::vector<uint8_t> textMemory;
public:

    std::mt19937 rand;
    
    template<typename Type>
    Type& vecRand(std::vector<Type> &vec) {
        return vec[rand() % vec.size()];
    }
    
    template<typename Type>
    Type vecRandAndRemove(std::vector<Type> &vec) {
        auto loc = vec.begin() + (rand() % vec.size());
        Type val = *loc;
        vec.erase(loc);
        return val;
    }
};

#endif // ROM_H

