## ======================================================================== ##
## Copyright 2009-2016 Intel Corporation                                    ##
##                                                                          ##
## Licensed under the Apache License, Version 2.0 (the "License");          ##
## you may not use this file except in compliance with the License.         ##
## You may obtain a copy of the License at                                  ##
##                                                                          ##
##     http://www.apache.org/licenses/LICENSE-2.0                           ##
##                                                                          ##
## Unless required by applicable law or agreed to in writing, software      ##
## distributed under the License is distributed on an "AS IS" BASIS,        ##
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. ##
## See the License for the specific language governing permissions and      ##
## limitations under the License.                                           ##
## ======================================================================== ##

set(LIBRARY_NAME ospray_glut3d)

add_library(${LIBRARY_NAME} SHARED glut3D.cpp)
target_link_libraries(${LIBRARY_NAME}
  ${OPENGL_LIBRARIES}
  ${GLUT_LIBRARIES}
  ${OSPRAY_LIBRARIES}
)
# ------------------------------------------------------------
install(TARGETS ${LIBRARY_NAME} DESTINATION lib)

