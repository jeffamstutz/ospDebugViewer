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

// viewer widget
#include "common/widgets/glut3D.h"

#include "miniSG/miniSG.h"

#include "ospray/ospray.h"

#include "ViewerConfig.h"

namespace ospray {

class CommandLineSceneBuilder
{
public:

  CommandLineSceneBuilder(int ac, const char **&av);

  miniSG::Model* sgmodel();
  OSPModel       model();
  OSPRenderer    renderer();
  OSPCamera      camera();
  ViewerConfig   viewerConfig();

private:

  // Helper functions //

  void parseCommandLine(int ac, const char **&av);
  void reportParsedData();
  void createRenderer();
  void createScene();
  void createSpheres();
  void createCylinders();
  void createSunLight();

  OSPMaterial createDefaultMaterial(OSPRenderer renderer);
  OSPMaterial createMaterial(OSPRenderer renderer, miniSG::Material *mat);

  // Data //

  OSPModel    m_model;
  OSPRenderer m_renderer;
  OSPCamera   m_camera;

  ViewerConfig m_config;

  // Previously global data //

  Ref<miniSG::Model> m_msgModel;
  std::vector<miniSG::Model *> m_msgAnimation;

  /*! when using the OBJ renderer, we create a automatic dirlight with this
   * direction; use ''--sun-dir x y z' to change */
  vec3f m_defaultDirLight_direction;

  bool m_fullScreen;

  bool m_alpha;
  bool m_createDefaultMaterial;

  int m_spp; /*! number of samples per pixel */

  unsigned int m_maxObjectsToConsider;
  // if turned on, we'll put each triangle mesh into its own instance,
  // no matter what
  bool m_forceInstancing;
  /*! if turned on we're showing the depth buffer rather than the (accum'ed)
   *  color buffer */
  glut3D::Glut3DWidget::FrameBufferMode m_frameBufferMode;

  std::string m_rendererType;
  std::string m_cameraType;
};

// Inlined function definitions ///////////////////////////////////////////////

inline miniSG::Model *CommandLineSceneBuilder::sgmodel()
{
  return m_msgModel.ptr;
}

inline OSPModel CommandLineSceneBuilder::model()
{
  return m_model;
}

inline OSPRenderer CommandLineSceneBuilder::renderer()
{
  return m_renderer;
}

inline OSPCamera CommandLineSceneBuilder::camera()
{
  return m_camera;
}

inline ViewerConfig CommandLineSceneBuilder::viewerConfig()
{
  return m_config;
}

}// namespace ospray
