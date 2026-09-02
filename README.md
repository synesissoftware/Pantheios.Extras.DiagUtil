# Pantheios.Extras.DiagUtil <!-- omit in toc -->

Header-only **C** and **C++** library in the **Pantheios.Extras** namespace that aids diagnostics — notably memory-leak tracing around `main()`.

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)
[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
[![GitHub release](https://img.shields.io/github/v/release/synesissoftware/Pantheios.Extras.DiagUtil.svg)](https://github.com/synesissoftware/Pantheios.Extras.DiagUtil/releases/latest)
[![Last Commit](https://img.shields.io/github/last-commit/synesissoftware/Pantheios.Extras.DiagUtil)](https://github.com/synesissoftware/Pantheios.Extras.DiagUtil/commits/master)


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
  - [Why main leak-trace](#why-main-leak-trace)
  - [Dependencies](#dependencies)
- [Installation](#installation)
- [Components](#components)
  - [C API](#c-api)
  - [C++ API](#c-api-1)
- [Examples](#examples)
- [Project Information](#project-information)
  - [Where to get help](#where-to-get-help)
  - [Contribution guidelines](#contribution-guidelines)
  - [Dependencies](#dependencies-1)
    - [Development dependencies](#development-dependencies)
  - [Related projects](#related-projects)
  - [License](#license)


## Introduction

**Pantheios.Extras.DiagUtil** is a small **header-only** library under the [Pantheios](http://pantheios.org/) extras namespace. It wraps a `main()`-like entry point so that, when compiling with **Microsoft Visual C++** in **`_DEBUG`**, CRT memory allocations leaked by that call are reported via `_CrtMemDumpAllObjectsSince`. On other toolchains (and non-debug MSVC) the invoke path is a transparent passthrough.

That keeps application `main()` free of `#if`/`crtdbg.h` boilerplate while remaining compatible with the usual Extras nesting — for example wrapping **Pantheios.Extras.Main** and/or command-line helpers so leak tracing runs while the diagnostic logging layer is still initialised.


### Why main leak-trace

Hand-rolled CRT leak checkpoints in `main()` are noisy and easy to get wrong:

* You must remember conditional includes and checkpoints around every return path;
* Exception paths need an explicit dump before rethrow;
* Future backends (other compilers or leak detectors) would force every client to change;

**Pantheios.Extras.DiagUtil** centralises that protocol behind one C function and one C++ `invoke` overload set.


### Dependencies

| Component     | Implemented in | Use in                                              | Dependencies |
| ------------- | -------------- | --------------------------------------------------- | ------------ |
| Core library  | C / C++ headers | C — **pantheios/extras/diagutil.h**; C++ — **…/diagutil.hpp** | [Pantheios](https://github.com/synesissoftware/Pantheios), [STLSoft](https://github.com/synesissoftware/STLSoft/) |
| Examples      | C / C++        | —                                                   | Pantheios, STLSoft |
| Tests         | C              | —                                                   | Pantheios, STLSoft, [xTests](https://github.com/synesissoftware/xTests/) |


## Installation

Detailed instructions — via **CMake**, via bundling — are provided in the accompanying [INSTALL.md](./INSTALL.md) file.


## Components

### C API

```C
#include <pantheios/extras/diagutil.h>

int
pantheios_extras_diagutil_main_leak_trace_invoke(
    int                 argc
,   char**              argv
,   int (STLSOFT_CDECL* pfnMain)(int, char*[])
);
```

### C++ API

```C++
#include <pantheios/extras/diagutil.hpp>

namespace pantheios {
namespace extras {
namespace diagutil {
namespace main_leak_trace {

int invoke(int argc, char** argv, int (STLSOFT_CDECL* pfnMain)(int, char*[]));

} // namespace main_leak_trace
} // namespace diagutil
} // namespace extras
} // namespace pantheios
```


## Examples

Examples are provided in the `examples` directory (`example.c.main_leak_trace.1`, `example.cpp.main_leak_trace.1`).


## Project Information


### Where to get help

[GitHub Page](https://github.com/synesissoftware/Pantheios.Extras.DiagUtil)


### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/Pantheios.Extras.DiagUtil.


### Dependencies

* [Pantheios](https://github.com/synesissoftware/Pantheios);
* [STLSoft](https://github.com/synesissoftware/STLSoft/);


#### Development dependencies

* [xTests](https://github.com/synesissoftware/xTests/);


### Related projects

* [Pantheios](https://github.com/synesissoftware/Pantheios);
* [Pantheios.Extras.AtExit](https://github.com/synesissoftware/Pantheios.Extras.AtExit);
* [Pantheios.Extras.Main](https://github.com/synesissoftware/Pantheios.Extras.Main);


### License

**Pantheios.Extras.DiagUtil** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.


<!-- ########################### end of file ########################### -->
