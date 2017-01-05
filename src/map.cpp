#include <iostream>
#include <fstream>
#include <string>
#include "common.h"
#include "map.h"

namespace Soil {
    Map::Map() {
        this->cells = new uint8_t[0];
        this->cellcount = 0;
    }
    Map::Map(int cellcount) {
        this->cells = new uint8_t[cellcount];
        this->cellcount = cellcount;
    }

    bool Map::getCellInfo(uint8_t cell, int index) {
        return (bool) ((cell >> index) & 1);
    }

    uint8_t Map::setCellInfo(uint8_t cell, int index, bool value) {
        return (cell ^ (1 << index));
    }

    Map* Map::createFromFile(std::string filePath) {
        Map* map = new Map;

        std::ifstream fileStream;
        fileStream.open(filePath, std::ios::binary);
        fileStream.read((char*) &map->header, sizeof(FileHeader));

        map->cells = new uint8_t[map->header.cellcount];
        map->cellcount = map->header.cellcount;
        fileStream.read((char*) map->cells, map->header.cellcount);
        fileStream.close();

        return map;
    }

    void Map::generateHeader() {
        this->header.versionMajor = 0;
        this->header.versionMinor = 1;
        this->header.cellcount    = this->cellcount;
    }

    void Map::writeToFile(std::string filePath) {
        std::ofstream fileStream;
        fileStream.open(filePath, std::ios::binary | std::ios::trunc);
        fileStream.write((char*) &this->header, sizeof(FileHeader));
        fileStream.write((char*)  this->cells,  this->cellcount);
        fileStream.close();
    }
}
