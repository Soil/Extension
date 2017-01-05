#include <iostream>
#include <fstream>
#include <string>

namespace Soil {
    struct BaseFileHeader {
        char type[8];
        uint8_t  versionMajor;
        uint8_t  versionMinor;
    };

    class Map {
        private:
            Map();

        public:
            struct FileHeader {
                const char type[8] = "SOILMAP";
                uint8_t  versionMajor;
                uint8_t  versionMinor;
                uint16_t cellcount;
                const uint32_t reserved = 0;
            };

            enum CellInfoIndex {
                LAND = 0,
                FOREST = 1,
                ROCKS = 2,
                BUILDINGS = 3,
                MILITARY = 4,
                PEAK = 5,
                VALLEY = 6
            };

            FileHeader header;
            uint8_t*   cells;
            uint16_t   cellcount;

            Map(int cellcount);

            static bool    getCellInfo(uint8_t cell, int index);
            static uint8_t setCellInfo(uint8_t cell, int index, bool value);
            static Map*    createFromFile(std::string filePath);

            void generateHeader();
            void writeToFile(std::string filePath);
    };
};
