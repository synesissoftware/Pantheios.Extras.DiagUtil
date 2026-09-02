# Pantheios.Extras.DiagUtil - Installation and Use <!-- omit in toc -->

**Pantheios.Extras.DiagUtil** is a header-only C and C++ library: public
headers live under **include/pantheios/extras**. There is no compiled
`src` library target. Once the headers are on the include path (and
**Pantheios** / **STLSoft** are available), include
**pantheios/extras/diagutil.h** (C) or **pantheios/extras/diagutil.hpp**
(C++) and call the leak-trace invoke API.

Building the project's tests additionally requires **xTests**.


## Table of Contents <!-- omit in toc -->

- [CMake](#cmake)
- [Bundled](#bundled)


## CMake

The primary choice for installation is by use of **CMake**.

1. Obtain the latest distribution of **Pantheios.Extras.DiagUtil**, from
   https://github.com/synesissoftware/Pantheios.Extras.DiagUtil/, e.g.

   ```bash
   $ mkdir -p ~/open-source
   $ cd ~/open-source
   $ git clone https://github.com/synesissoftware/Pantheios.Extras.DiagUtil/
   ```

2. Install **Pantheios** and **STLSoft** 1.11 (and **xTests** if you will
   build tests) via their own **CMake** scripts first.

3. Prepare the CMake configuration, via the **prepare_cmake.sh** script.

   Headers-and-examples only (no **xTests** required):

   ```bash
   $ cd ~/open-source/Pantheios.Extras.DiagUtil
   $ ./prepare_cmake.sh --disable-testing -v
   ```

   Full build including examples and tests:

   ```bash
   $ cd ~/open-source/Pantheios.Extras.DiagUtil
   $ ./prepare_cmake.sh -v
   ```

   If **STLSoft** is available as a source tree rather than an installed
   **CMake** package, pass its root with `--stlsoft-root-dir` / `-s`.

   (**Hint**: execute `$ ./prepare_cmake.sh --help` for more information.)

4. Run a build of the generated **CMake**-derived build files via the
   **build_cmake.sh** script, as in:

   ```bash
   $ ./build_cmake.sh
   ```

   (**NOTE**: if you provide the flag `--run-make` (=== `-m`) in step 3 then
   you do not need this step.)

5. As a check (when testing was not disabled), execute the built unit-test
   programs via **run_all_unit_tests.sh**, as in:

   ```bash
   $ ./run_all_unit_tests.sh
   ```

6. Install the headers (and **CMake** package files) on the host, via
   `cmake`, as in:

   ```bash
   $ sudo cmake --install ${SIS_CMAKE_BUILD_DIR:-./_build} --config Release
   ```

7. Then to use the library:

   1. A minimal C consumer:

      ```c
      /* main.c */
      #include <pantheios/extras/diagutil.h>

      #include <stdlib.h>

      static int
      program(int argc, char** argv)
      {
          ((void)argc);
          ((void)argv);

          return EXIT_SUCCESS;
      }

      int main(int argc, char** argv)
      {
          return pantheios_extras_diagutil_main_leak_trace_invoke(
              argc, argv, program);
      }
      ```

   2. Compile against the installed include tree (and **Pantheios** /
      **STLSoft** as required by those packages):

      ```bash
      $ cc -c main.c
      ```

   Consumers that use **CMake** may instead depend on the installed package:

   ```cmake
   find_package(pantheios.extras.diagutil REQUIRED)
   target_link_libraries(your_target PRIVATE
       Pantheios.Extras.DiagUtil::Pantheios.Extras.DiagUtil)
   ```


## Bundled

**Pantheios.Extras.DiagUtil** is small enough that it may be bundled into
other projects. In that case:

* add **Pantheios.Extras.DiagUtil**'s **include** directory to your
  project's include path;
* ensure **Pantheios** and **STLSoft** headers are available; and
* `#include <pantheios/extras/diagutil.h>` or
  `#include <pantheios/extras/diagutil.hpp>`.


<!-- ########################### end of file ########################### -->
