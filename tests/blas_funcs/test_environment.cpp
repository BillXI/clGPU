// Copyright (c) 2017-2018 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "test_helpers.hpp"
#include <primitive_db.hpp>

namespace iclgpu { namespace tests {

decltype(iclgpu::context::create()) test_env::_ctx = nullptr;

void test_env::SetUp()
{
    _ctx = iclgpu::context::create();
    _ctx->get_engine(engine_type::open_cl)->get_primitive_db()->insert({
    #include BLAS_OCL_KERNELS_DB
    });
}

void test_env::TearDown()
{
    _ctx.reset();
}

::testing::Environment* const foo_env = ::testing::AddGlobalTestEnvironment(new test_env);

}}
