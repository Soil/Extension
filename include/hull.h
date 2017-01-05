#include <vector>

namespace Soil {
    class Hull {
        public:
            static std::vector<position> findFromPositions(const std::vector<position> positions);
        private:
            static std::vector<position> applyGrahamScan(const std::vector<position> positions);
            static bool                  isCounterClockwise(position p1, position p2, position p3);
    };
}
