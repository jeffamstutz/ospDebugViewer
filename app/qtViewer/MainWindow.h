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

#pragma once

#include <QMainWindow>

#include "ui_MainWindow.h"

#include <ospray_cpp/Model.h>
#include <ospray_cpp/Renderer.h>
#include <ospcommon/box.h>
#include <ospcommon/common.h>

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:

  MainWindow(QWidget *parent = nullptr);

private slots:

  void on_actionFileOpen_triggered();
  void on_actionTile_triggered();
  void on_actionCascade_triggered();
  void on_actionTabbed_triggered();
  void on_actionAbout_triggered();

private:

  // Helper functions /////////////////////////////////////////////////////////

  std::pair<ospray::cpp::Renderer, ospcommon::box3f>
  openFile(QString fileName);

  void addRenderSubWindow(ospray::cpp::Renderer renderer,
                          const ospcommon::box3f &bounds);

  // Private data /////////////////////////////////////////////////////////////

  std::unique_ptr<Ui::MainWindow> ui;

  using NamedModel = std::pair<std::string, ospray::cpp::Model>;
  std::vector<NamedModel> m_loadedModels;
};

