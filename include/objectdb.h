#include "common.h"
#include "rapidjson-1.1.0/document.h"
#include <string>
#include <vector>

namespace Soil {
    class ObjectDB {
        public:
            ObjectDB(std::string worldName);

            std::string           getObjectClassification(std::string modelInfo);
            void                  dumpToFile(std::string fileName = "dump.json");
            //std::vector<position> getObjectPositions(std::string modelInfo);
            //std::vector<position> getObjectPositions(std::string modelInfo, std::string[] allowedTags);
            //std::vector<position> getObjectPositionsOrdered(std::string modelInfo, std::string[] allowedTags);

        private:
            rapidjson::Document json;

            static rapidjson::Document readFromFile(std::string fileName);
    };
}
