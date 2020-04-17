/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * License); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * AS IS BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*
 * Copyright (c) 2017, Open AI Lab
 * Author: haitao@openailab.com
 */
#include <iostream>
#include <functional>

#include "logger.hpp"
#include "onnx_serializer.hpp"

namespace TEngine {
    extern bool OnnxSerializerRegisterOpLoader();
}    // namespace TEngine

using namespace TEngine;

extern "C" int onnx_plugin_init(void)
{
    std::cout << "hhhh" << std::endl;
    auto factory = SerializerFactory::GetFactory();

    factory->RegisterInterface<OnnxSerializer>("onnx");
    auto onnx_serializer = factory->Create("onnx");

    SerializerManager::SafeAdd("onnx", SerializerPtr(onnx_serializer));
    OnnxSerializerRegisterOpLoader();

    return 0;
}
