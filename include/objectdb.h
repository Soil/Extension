#include "common.h"
#include <string>

namespace Soil {
    class ObjectDB {
        public:
            position[] getObjectPositions(std::string modelInfo);
            position[] getObjectPositions(std::string modelInfo, std::string[] allowedTags);
            position[] getObjectPositionsOrdered(std::string modelInfo, std::string[] allowedTags);
    };
}
