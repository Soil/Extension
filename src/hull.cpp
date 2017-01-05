#include "common.h"
#include "hull.h"
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdio>

namespace Soil {
    std::vector<position> Hull::findFromPositions(const std::vector<position> positions) {
        return Hull::applyGrahamScan(positions);
    }

    std::vector<position> Hull::applyGrahamScan(std::vector<position> positions) {
        // TODO: Error handling if only <3 positions are passed etc
        int n = positions.size();

        // Find position with lowest y coordinate
        position lowestY      = positions[0];
        int      lowestYIndex = 0;

        for (int i = 0; i < positions.size(); i++) {
            auto pos = positions[i];
            if (pos[1] < lowestY[1]) {
                lowestY      = pos;
                lowestYIndex = i;
            }
        }

        // Make it the first element
        positions[lowestYIndex] = positions[0];
        positions[0]            = lowestY;

        // Order positions by angle to positions[0]
        std::sort(positions.begin() + 1, positions.end(),
            [positions] (position a, position b) {
                auto angleA = atan((a[1] - positions[0][1]) / (a[0] - positions[0][0]));
                auto angleB = atan((b[1] - positions[0][1]) / (b[0] - positions[0][0]));
                return angleA < angleB;
            }
        );

        std::vector<position> hull;
        hull.push_back(positions[0]);
        hull.push_back(positions[1]);

        for (int i = 2; i < positions.size(); i += 0) {
            position p1 = hull[hull.size() - 1];
            position p2 = hull[hull.size() - 2];

            if (Hull::isCounterClockwise(p1, p2, positions[i])) {
                hull.push_back(positions[i]);
                i++;
            } else {
                hull.pop_back();
            }
        }
        return hull;
    }

    bool Hull::isCounterClockwise(position p1, position p2, position p3) {
        return ((p2[0] - p1[0]) * (p3[1] - p1[1]) - (p2[1] - p1[1]) * (p3[0] - p1[0])) <= 0;
    }
}
