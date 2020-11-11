// pbrt is Copyright(c) 1998-2020 Matt Pharr, Wenzel Jakob, and Greg Humphreys.
// The pbrt source code is licensed under the Apache License, Version 2.0.
// SPDX: Apache-2.0

#ifndef PBRT_CPU_RENDER_H
#define PBRT_CPU_RENDER_H

#include <pbrt/pbrt.h>
#include <vector>
#include <string>

namespace pbrt {

class ParsedScene;

void CPURender(ParsedScene &scene);
void CPURenderMultipleViews(ParsedScene &scene, const std::vector<CameraTransform>& camera_lists, const std::vector<std::string>& outfiles);

}  // namespace pbrt

#endif  // PBRT_CPU_RENDER_H
