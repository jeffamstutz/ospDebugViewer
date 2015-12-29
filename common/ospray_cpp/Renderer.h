// ======================================================================== //
// Copyright 2009-2015 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

#include <ospray_cpp/Light.h>
#include <ospray_cpp/ManagedObject.h>
#include <ospray_cpp/Material.h>

namespace ospray {
namespace cpp    {

class Renderer : public ManagedObject
{
public:

  Renderer(const std::string &type);
  Renderer(const Renderer &copy);
  Renderer(OSPRenderer existing);

  Material newMaterial(const std::string &type);
  Light    newLight(const std::string &type);
};

// Inlined function definitions ///////////////////////////////////////////////

inline Renderer::Renderer(const std::string &type)
{
  OSPRenderer c = ospNewRenderer(type.c_str());
  if (c) {
    m_object = c;
  } else {
    throw std::runtime_error("Failed to create OSPRenderer!");
  }
}

inline Renderer::Renderer(const Renderer &copy) :
  ManagedObject(copy.handle())
{
}

inline Renderer::Renderer(OSPRenderer existing) :
  ManagedObject(existing)
{
}

inline Material Renderer::newMaterial(const std::string &type)
{
  return Material(ospNewMaterial((OSPRenderer)handle(), type.c_str()));
}

inline Light Renderer::newLight(const std::string &type)
{
  return Light(ospNewLight((OSPRenderer)handle(), type.c_str()));
}


}// namespace cpp
}// namespace ospray
