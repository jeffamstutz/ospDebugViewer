﻿// ======================================================================== //
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

#include <ospray/ospray.h>

namespace osp {
namespace cpp {

//! \todo auto-commit mode

class ManagedObject
{
public:

  ManagedObject();
  ManagedObject(OSPObject object);
  virtual ~ManagedObject();

  // Parameter 'set' functions //

  // string
  void set(const std::string &name, const std::string &v);

  // int
  void set(const std::string &name, int v);
  void set(const std::string &name, int v1, int v2);
  void set(const std::string &name, int v1, int v2, int v3);

  // float
  void set(const std::string &name, float v);
  void set(const std::string &name, float v1, float v2);
  void set(const std::string &name, float v1, float v2, float v3);

  // double
  void set(const std::string &name, double v);
  void set(const std::string &name, double v1, double v2);
  void set(const std::string &name, double v1, double v2, double v3);

  // void*
  void set(const std::string &name, void *v);

  // OSPObject*
  void set(const std::string &name, OSPObject v);

  // osp::cpp::ManagedObject
  void set(const std::string &name, const ManagedObject &v);

  //! \todo add get functions

  //! Commit to ospray
  void commit() const;

  //! Get the underlying OSPObject handle
  OSPObject handle() const;

protected:

  OSPObject m_object;
};

// Inlined function definitions ///////////////////////////////////////////////

inline ManagedObject::ManagedObject() :
  m_object(NULL)
{
}

inline ManagedObject::ManagedObject(OSPObject object) :
  m_object(object)
{
}

inline ManagedObject::~ManagedObject()
{
}

inline void ManagedObject::set(const std::string &name, const std::string &v)
{
  ospSetString(m_object, name.c_str(), v.c_str());
}

inline void ManagedObject::set(const std::string &name, int v)
{
  ospSet1i(m_object, name.c_str(), v);
}

inline void ManagedObject::set(const std::string &name, int v1, int v2)
{
  ospSet2i(m_object, name.c_str(), v1, v2);
}

inline void ManagedObject::set(const std::string &name, int v1, int v2, int v3)
{
  ospSet3i(m_object, name.c_str(), v1, v2, v3);
}

inline void ManagedObject::set(const std::string &name, float v)
{
  ospSet1f(m_object, name.c_str(), v);
}

inline void ManagedObject::set(const std::string &name, float v1, float v2)
{
  ospSet2f(m_object, name.c_str(), v1, v2);
}

inline void ManagedObject::set(const std::string &name,
                               float v1, float v2, float v3)
{
  ospSet3f(m_object, name.c_str(), v1, v2, v3);
}

inline void ManagedObject::set(const std::string &name, double v)
{
  ospSet1f(m_object, name.c_str(), v);
}

inline void ManagedObject::set(const std::string &name, double v1, double v2)
{
  ospSet2f(m_object, name.c_str(), v1, v2);
}

inline void ManagedObject::set(const std::string &name,
                               double v1, double v2, double v3)
{
  ospSet3f(m_object, name.c_str(), v1, v2, v3);
}

inline void ManagedObject::set(const std::string &name, void *v)
{
  ospSetVoidPtr(m_object, name.c_str(), v);
}

inline void ManagedObject::set(const std::string &name, OSPObject v)
{
  ospSetObject(m_object, name.c_str(), v);
}

inline void ManagedObject::set(const std::string &name, const ManagedObject &v)
{
  ospSetObject(m_object, name.c_str(), v.handle());
}

inline void ManagedObject::commit() const
{
  ospCommit(m_object);
}

inline OSPObject ManagedObject::handle() const
{
  return m_object;
}

// Forward declarations ///////////////////////////////////////////////////////

class Camera;
class Data;
class FrameBuffer;
class Geometry;
class Light;
class Material;
class Model;
class PixelOp;
class Renderer;
class TransferFunction;
class Texture2D;
class Volume;

// Class definitions //////////////////////////////////////////////////////////

// Camera class //

class Camera : public ManagedObject
{
public:

  Camera(const std::string &type);
  Camera(const Camera &copy);
  Camera(OSPCamera existing);
};

// Data class //

class Data : public ManagedObject
{
public:

  Data(const Data &copy);
  Data(OSPData existing);
};

// FrameBuffer class //

class FrameBuffer : public ManagedObject
{
public:

  FrameBuffer(const FrameBuffer &copy);
  FrameBuffer(OSPFrameBuffer existing);

  void setPixelOp(PixelOp &p);
  void setPixelOp(OSPPixelOp p);
};

// Geometry class //

class Geometry : public ManagedObject
{
public:

  Geometry(const std::string &type);
  Geometry(const Geometry &copy);
  Geometry(OSPGeometry existing);

  void setMaterial(Material &m);
  void setMaterial(OSPMaterial m);
};

// Light class //

class Light : public ManagedObject
{
public:

  Light(const Light &copy);
  Light(OSPLight existing);
};

// Material class //

class Material : public ManagedObject
{
public:

  Material(const Material &copy);
  Material(OSPMaterial existing);
};

// Model class //

class Model : public ManagedObject
{
public:

  Model();
  Model(const Model &copy);
  Model(OSPModel existing);

  void addGeometry(Geometry &v);
  void addGeometry(OSPGeometry v);

  void removeGeometry(Geometry &v);
  void removeGeometry(OSPGeometry v);

  void addVolume(Volume &v);
  void addVolume(OSPVolume v);
};

// PixelOp class //

class PixelOp : public ManagedObject
{
public:

  PixelOp(const std::string &type);
  PixelOp(const PixelOp &copy);
  PixelOp(OSPPixelOp existing);
};

// Renderer class //

class Renderer : public ManagedObject
{
public:

  Renderer(const std::string &type);
  Renderer(const Renderer &copy);
  Renderer(OSPRenderer existing);

  Material newMaterial(const std::string &type);
  Light    newLight(const std::string &type);
};

// TransferFunction class //

class TransferFunction : public ManagedObject
{
public:

  TransferFunction(const std::string &type);
  TransferFunction(const TransferFunction &copy);
  TransferFunction(OSPTransferFunction existing);
};

// Texture2D class //

class Texture2D : public ManagedObject
{
public:

  Texture2D(const Texture2D &copy);
  Texture2D(OSPTexture2D existing);
};

// Volume class //

class Volume : public ManagedObject
{
public:

  Volume(const std::string &type);
  Volume(const Volume &copy);
  Volume(OSPVolume existing);
};

// Inlined function definitions ///////////////////////////////////////////////

// Camera inlined members //

inline Camera::Camera(const std::string &type)
{
  OSPCamera c = ospNewCamera(type.c_str());
  if (c) {
    m_object = c;
  } else {
    throw std::runtime_error("Failed to create OSPCamera!");
  }
}

inline Camera::Camera(const Camera &copy) :
  ManagedObject(copy.handle())
{
}

inline Camera::Camera(OSPCamera existing) :
  ManagedObject(existing)
{
}

// Data inlined members //

inline Data::Data(const Data &copy) :
  ManagedObject(copy.handle())
{
}

inline Data::Data(OSPData existing) :
  ManagedObject(existing)
{
}

// FrameBuffer inlined members //

inline FrameBuffer::FrameBuffer(const FrameBuffer &copy) :
  ManagedObject(copy.handle())
{
}

inline FrameBuffer::FrameBuffer(OSPFrameBuffer existing) :
  ManagedObject(existing)
{
}

inline void FrameBuffer::setPixelOp(PixelOp &p)
{
  setPixelOp((OSPPixelOp)p.handle());
}

inline void FrameBuffer::setPixelOp(OSPPixelOp p)
{
  ospSetPixelOp((OSPFrameBuffer)handle(), p);
}

// Geometry inlined members //

inline Geometry::Geometry(const std::string &type)
{
  OSPGeometry c = ospNewGeometry(type.c_str());
  if (c) {
    m_object = c;
  } else {
    throw std::runtime_error("Failed to create OSPGeometry!");
  }
}

inline Geometry::Geometry(const Geometry &copy) :
  ManagedObject(copy.handle())
{
}

inline Geometry::Geometry(OSPGeometry existing) :
  ManagedObject(existing)
{
}

inline void Geometry::setMaterial(Material &m)
{
  setMaterial((OSPMaterial)m.handle());
}

inline void Geometry::setMaterial(OSPMaterial m)
{
  ospSetMaterial((OSPGeometry)handle(), m);
}

// Light inlined members //

inline Light::Light(const Light &copy) :
  ManagedObject(copy.handle())
{
}

inline Light::Light(OSPLight existing) :
  ManagedObject(existing)
{
}

// Material inlined members //

inline Material::Material(const Material &copy) :
  ManagedObject(copy.handle())
{
}

inline Material::Material(OSPMaterial existing) :
  ManagedObject(existing)
{
}

// Model inlined members //

inline Model::Model()
{
  OSPModel c = ospNewModel();
  if (c) {
    m_object = c;
  } else {
    throw std::runtime_error("Failed to create OSPModel!");
  }
}

inline Model::Model(const Model &copy) :
  ManagedObject(copy.handle())
{
}

inline Model::Model(OSPModel existing) :
  ManagedObject(existing)
{
}

inline void Model::addGeometry(Geometry &v)
{
  addGeometry((OSPGeometry)v.handle());
}

inline void Model::addGeometry(OSPGeometry v)
{
  ospAddGeometry((OSPModel)handle(), v);
}

inline void Model::removeGeometry(Geometry &v)
{
  removeGeometry((OSPGeometry)v.handle());
}

inline void Model::removeGeometry(OSPGeometry v)
{
  ospRemoveGeometry((OSPModel)handle(), v);
}

inline void Model::addVolume(Volume &v)
{
  addVolume((OSPVolume)v.handle());
}

inline void Model::addVolume(OSPVolume v)
{
  ospAddVolume((OSPModel)handle(), v);
}

// PixelOp inlined members //

inline PixelOp::PixelOp(const std::string &type)
{
  OSPPixelOp c = ospNewPixelOp(type.c_str());
  if (c) {
    m_object = c;
  } else {
    throw std::runtime_error("Failed to create OSPPixelOp!");
  }
}

inline PixelOp::PixelOp(const PixelOp &copy) :
  ManagedObject(copy.handle())
{
}

inline PixelOp::PixelOp(OSPPixelOp existing) :
  ManagedObject(existing)
{
}

// Renderer inlined members //

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

// TransferFunction inlined members //

inline TransferFunction::TransferFunction(const std::string &type)
{
  OSPTransferFunction c = ospNewTransferFunction(type.c_str());
  if (c) {
    m_object = c;
  } else {
    throw std::runtime_error("Failed to create OSPTransferFunction!");
  }
}

inline TransferFunction::TransferFunction(const TransferFunction &copy) :
  ManagedObject(copy.handle())
{
}

inline TransferFunction::TransferFunction(OSPTransferFunction existing) :
  ManagedObject(existing)
{
}

// Texture2D inlined members //

inline Texture2D::Texture2D(const Texture2D &copy) :
  ManagedObject(copy.handle())
{
}

inline Texture2D::Texture2D(OSPTexture2D existing) :
  ManagedObject(existing)
{
}

// Volume inlined members //

inline Volume::Volume(const std::string &type)
{
  OSPVolume c = ospNewVolume(type.c_str());
  if (c) {
    m_object = c;
  } else {
    throw std::runtime_error("Failed to create OSPVolume!");
  }
}

inline Volume::Volume(const Volume &copy) :
  ManagedObject(copy.handle())
{
}

inline Volume::Volume(OSPVolume existing) :
  ManagedObject(existing)
{
}

}// namespace cpp
}// namespace osp
