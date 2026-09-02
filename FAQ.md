# Pantheios.Extras.DiagUtil - FAQ <!-- omit in toc -->

The FAQ list is under (constant) development. If you post a question on the
Issues forum (https://github.com/synesissoftware/Pantheios.Extras.DiagUtil/issues)
it will be used to create one.


## Table of Contents <!-- omit in toc -->

- [Q1: "How do I build Pantheios.Extras.DiagUtil?"](#q1-how-do-i-build-pantheiosextrasdiagutil)
- [Q2: "How do I install Pantheios.Extras.DiagUtil?"](#q2-how-do-i-install-pantheiosextrasdiagutil)
- [Q3: "How do I use Pantheios.Extras.DiagUtil?"](#q3-how-do-i-use-pantheiosextrasdiagutil)
- [Q4: "Why do I see no leak report on macOS or Linux?"](#q4-why-do-i-see-no-leak-report-on-macos-or-linux)


# FAQs: <!-- omit in toc -->

## Q1: "How do I build Pantheios.Extras.DiagUtil?"

See [INSTALL.md](./INSTALL.md) for the recommended **CMake** flow
(**prepare_cmake.sh**, then **build_cmake.sh**). Install **Pantheios** and
**STLSoft** first. For tests, also install **xTests**, then:

```bash
$ ./prepare_cmake.sh -m
$ ./run_all_unit_tests.sh -M
```

Execute `$ ./prepare_cmake.sh --help` for the full set of options.


## Q2: "How do I install Pantheios.Extras.DiagUtil?"

See [INSTALL.md](./INSTALL.md). The library is header-only; install copies
headers and **CMake** package files.


## Q3: "How do I use Pantheios.Extras.DiagUtil?"

Include **pantheios/extras/diagutil.h** (C) or
**pantheios/extras/diagutil.hpp** (C++) and wrap your program entry with
`pantheios_extras_diagutil_main_leak_trace_invoke` or
`pantheios::extras::diagutil::main_leak_trace::invoke`.

With **CMake**, link the INTERFACE target
`Pantheios.Extras.DiagUtil::Pantheios.Extras.DiagUtil` after
`find_package(pantheios.extras.diagutil REQUIRED)`.


## Q4: "Why do I see no leak report on macOS or Linux?"

CRT leak dumping is implemented only when compiling with **MSVC** and
**`_DEBUG`**. Elsewhere the invoke API simply calls your `main`-like
function and returns its status. Unit tests cover that portable
passthrough behaviour.


<!-- ########################### end of file ########################### -->
