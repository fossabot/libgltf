# libgltf

[![glTF status](https://img.shields.io/badge/glTF-2%2E0-green.svg?style=flat)](https://github.com/KhronosGroup/glTF)
[![libgltf document](https://readthedocs.org/projects/libgltf/badge/?version=latest)](http://libgltf.rtfd.io/)
[![visit milestones](https://img.shields.io/badge/visit-milestones-blue.svg?style=flat)](https://github.com/code4game/libgltf/milestones)
[![CII best practices](https://bestpractices.coreinfrastructure.org/projects/1434/badge)](https://bestpractices.coreinfrastructure.org/projects/1434)
[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2Fcode4game%2Flibgltf.svg?type=shield)](https://app.fossa.com/projects/git%2Bgithub.com%2Fcode4game%2Flibgltf?ref=badge_shield)

[![build](https://github.com/code4game/libgltf/workflows/build/badge.svg)](https://github.com/code4game/libgltf/actions?query=workflow%3Abuild)
[![Coverage Status](https://coveralls.io/repos/github/code4game/libgltf/badge.svg)](https://coveralls.io/github/code4game/libgltf)

[![Codacy](https://api.codacy.com/project/badge/Grade/fa7ee9a5bc9b4befb703298ca721bc9a)](https://www.codacy.com/app/code4game/libgltf?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=code4game/libgltf&amp;utm_campaign=Badge_Grade)
[![Total alerts](https://img.shields.io/lgtm/alerts/g/code4game/libgltf.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/code4game/libgltf/alerts/)
[![Language grade: Python](https://img.shields.io/lgtm/grade/python/g/code4game/libgltf.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/code4game/libgltf/context:python)

[![Gitter](https://badges.gitter.im/code4game/libgltf.svg)](https://gitter.im/code4game/libgltf?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)
[![Support](https://img.shields.io/badge/support-buy%20a%20cup%20of%20coffee-orange.svg?style=flat)](https://c4gio.itch.io/libgltf-ue4)
[![Become a patreon](https://img.shields.io/badge/donation-become%20a%20patreon-orange.svg?style=flat)](https://www.patreon.com/bePatron?u=7553208)

This project was generated by glTF 2.0 JSON schema and support to load the glTF 2.0 file to a struct `SGlTF`.

It was used in [glTFForUE4](https://github.com/code4game/glTFForUE4).

## Features

* [glTF 2.0]
* Load the gltf/embedded/glb file
* This is a static library
* Cross platform
* C++11
* Supports the Unicode and UTF8
* Supports some extensions
  * `KHR_draco_mesh_compression` - [Google's Draco]
  * `KHR_lights_punctual`
  * `KHR_materials_pbrSpecularGlossiness`
  * `KHR_materials_clearcoat`
  * and more
* Platforms
  * Windows
    * Win32 (win32)
    * x64 (win64)
  * Linux (linux)
  * macOS (macos)
  * Android
    * armeabi-v7a
    * armeabi-v7a-with-neon
    * arm64-v8a
    * x86
    * x86_64
  * iOS
    * iOS (iphoneos)
    * watchOS (watchos)
    * simulator

## Getting Started

1. Update the submodule
    > Run `git submodule update --init`
2. Generate the project by [CMake]
    > Run `cmake -G "[GENERATOR BY YOUR SYSTEM]" [LIBGLTF FOLDER]`
3. Build the project and generate the static library `libgltf.lib` or `libgltf.a`
4. Include `libgltf/libgltf.h` in your project.
5. Link the static library `libgltf.lib` or `libgltf.a` in your project.
    > You have to link the static library `draco.lib` or `draco.a` with your project, if you want to support the [Google's Draco].
    > And you can find the draco in the external folder.

Code example:

```cpp
std::shared_ptr<libgltf::IglTFLoader> gltf_loader = libgltf::IglTFLoader::Create(/*your gltf file*/);
std::shared_ptr<libgltf::SGlTF> loaded_gltf = gltf_loader->glTF().lock();
if (!loaded_gltf)
{
    printf("failed to load your gltf file");
}
```

## License

This software is released under the MIT license.

[glTF 2.0]: https://www.khronos.org/gltf/
[Google's Draco]: https://github.com/google/draco
[CMake]: https://cmake.org/


[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2Fcode4game%2Flibgltf.svg?type=large)](https://app.fossa.com/projects/git%2Bgithub.com%2Fcode4game%2Flibgltf?ref=badge_large)