// Copyright (c) 2019, NVIDIA CORPORATION. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef DALI_OPERATORS_DISPLACEMENT_ROTATE_H_
#define DALI_OPERATORS_DISPLACEMENT_ROTATE_H_

#include <memory>
#include <vector>
#include <sstream>
#include "dali/kernels/imgproc/warp/affine.h"
#include "dali/kernels/imgproc/warp/mapping_traits.h"
#include "dali/operators/displacement/warp.h"
#include "dali/operators/displacement/rotate_params.h"

namespace dali {

template <typename Backend>
class Rotate : public Warp<Backend, Rotate<Backend>> {
 public:
  using Base = Warp<Backend, Rotate<Backend>>;
  using Base::Base;

  template <int ndim>
  using Mapping = kernels::AffineMapping<ndim>;

  template <int spatial_ndim, typename BorderType>
  using ParamProvider = RotateParamProvider<Backend, spatial_ndim, BorderType>;

  template <int spatial_ndim, typename BorderType>
  auto CreateParamProvider() {
    return std::make_unique<ParamProvider<spatial_ndim, BorderType>>();
  }
};

}  // namespace dali

#endif  // DALI_OPERATORS_DISPLACEMENT_ROTATE_H_
