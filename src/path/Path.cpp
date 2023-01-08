// Copyright (c) TrajoptLib contributors

#include "path/Path.h"

#include <vector>

#include "constraint/Constraint.h"
#include "obstacle/Obstacle.h"
#include "path/Waypoint.h"

namespace trajopt {

Path::Path(Obstacle bumpers, std::vector<Constraint> globalConstraints)
    : bumpers(std::move(bumpers)),
      globalConstraints(std::move(globalConstraints)) {}

size_t Path::ControlIntervalTotal() const {
  size_t controlIntervalTotal = 0;
  for (size_t waypointIndex = 1; waypointIndex < Length(); waypointIndex++) {
    controlIntervalTotal += GetWaypoint(waypointIndex).controlIntervalCount;
  }
  return controlIntervalTotal;
}

bool Path::IsValid() const noexcept {
  if (Length() == 0 || ControlIntervalTotal() == 0) {
    return false;
  }
  for (size_t index = 0; index < Length(); index++) {
    if (!GetWaypoint(index).IsValid()) {
      return false;
    }
  }
  return true;
}
}  // namespace trajopt