# libgltf

[![glTF status](https://img.shields.io/badge/glTF-2%2E0-green.svg?style=flat)](https://github.com/KhronosGroup/glTF)
[![libgltf document](https://readthedocs.org/projects/libgltf/badge/?version=latest)](http://libgltf.rtfd.io/)
[![visit milestones](https://img.shields.io/badge/visit-milestones-blue.svg?style=flat)](https://github.com/code4game/libgltf/milestones)
[![CII best practices](https://bestpractices.coreinfrastructure.org/projects/1434/badge)](https://bestpractices.coreinfrastructure.org/projects/1434)

[![build](https://github.com/code4game/libgltf/workflows/build/badge.svg)](https://github.com/code4game/libgltf/actions?query=workflow%3Abuild)
[![Coverage status from coveralls](https://coveralls.io/repos/github/code4game/libgltf/badge.svg?branch=master)](https://coveralls.io/github/code4game/libgltf?branch=master)
[![Codacy](https://api.codacy.com/project/badge/Grade/fa7ee9a5bc9b4befb703298ca721bc9a)](https://www.codacy.com/app/code4game/libgltf?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=code4game/libgltf&amp;utm_campaign=Badge_Grade)

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
* Supports the `KHR_draco_mesh_compression` - [Google's Draco]
* Supports the `KHR_lights_punctual`
* Platforms
  * Windows (Win32 and x64)
  * Linux
  * macOS
  * Android (armeabi-v7a, armeabi-v7a-with-neon, arm64-v8a, x86 and x86_64)
  * iOS (simulator, iOS, tvOS and watchOS)

## Getting Started

1. Update the submodule
    > Run `git submodule update --init`
2. Generate the project by [CMake]
    > Run `cmake -G "[GENERATOR BY YOUR SYSTEM]" [LIBGLTF FOLDER]`
3. Build the project and generate the the static library `libgltf.lib` or `libgltf.a`
4. Include `libgltf/libgltf.h` in your project.
5. Link the static library `libgltf.lib` or `libgltf.a` in your project.
    > You have to link the static library `draco.lib` or `draco.a` with your project, if you want support the [Google's Draco].
    > And you can find the draco in the external folder.

Code example:

```cpp
std::shared_ptr<libgltf::IGlTFLoader> gltf_loader = libgltf::IGlTFLoader::Create(/*your gltf file*/);
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
