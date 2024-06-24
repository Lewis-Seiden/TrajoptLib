// Copyright (c) TrajoptLib contributors

#pragma once

#include "trajopt/util/SymbolExports.hpp"
#include "trajopt/set/Set2d.hpp"

namespace trajopt {

/**
 * Constrains a point on the robot to a Set2d of the field.
 */
struct TRAJOPT_DLLEXPORT TranslationConstraint {
  /// Translation bound.
  Set2d translationBound;
  /// robot point x
  double robotPointX { 0.0 };
  /// robot point y
  double robotPointY { 0.0 };

};
}  // namespace trajopt
