// ======================================================================== //
// Copyright 2009-2016 Intel Corporation                                    //
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

#include "MultiSceneParser.h"

#include "ParticleSceneParser.h"
#include "TriangleMeshSceneParser.h"

using namespace ospray;
using namespace ospcommon;

MultiSceneParser::MultiSceneParser(cpp::Renderer renderer) :
  m_renderer(renderer)
{
}

bool MultiSceneParser::parse(int ac, const char **&av)
{
  TriangleMeshSceneParser triangleMeshParser(m_renderer);
  ParticleSceneParser     particleParser(m_renderer);

  bool gotTriangleMeshScene = triangleMeshParser.parse(ac, av);
  bool gotPartileScene      = particleParser.parse(ac, av);

  SceneParser *parser = nullptr;

  if (gotTriangleMeshScene)
    parser = &triangleMeshParser;
  else if (gotPartileScene)
    parser = &particleParser;

  if (parser) {
    m_model = parser->model();
    m_bbox  = parser->bbox();
  }

  return parser != nullptr;
}

cpp::Model MultiSceneParser::model() const
{
  return m_model;
}

box3f MultiSceneParser::bbox() const
{
  return m_bbox;
}
