#pragma once

#include <iostream>
#include <vector>

#include "TrajectorySegment.h"
#include "HolonomicTrajectorySample.h"

namespace helixtrajectory {

    class HolonomicTrajectorySegment : public TrajectorySegment {
    public:
        std::vector<HolonomicTrajectorySample> holonomicSamples;

        HolonomicTrajectorySegment(double intervalDuration, const std::vector<HolonomicTrajectorySample>& holonomicSamples);

        friend std::ostream& operator<<(std::ostream& stream, const HolonomicTrajectorySegment& segment);
    };
}