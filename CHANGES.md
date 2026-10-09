# Pantheios.Extras.DiagUtil - Changes <!-- omit in toc -->


## 0.1.3-beta1 - 9th October 2026

* Applied **misc-dev-scripts** **0.6.0** editor/Git/`.sis` drop-in templates on **boilerplate**;
* Restored historical **.gitignore** patterns as a sorted union with **misc-dev-scripts** gold section layout;
* Brought the CMake helper scripts to the **misc-dev-scripts** `cmake-helpers` gold (SisClr colour, `cmake --build`, native `.cmd` runners); **run_all_unit_tests.sh** is now unit-only and **run_all_automated_tests.sh** is the aggregate; removed **execute_performance_tests.sh**;
* Renamed the scratch version reporter target to `test.scratch.versions`, which now also reports the **Pantheios** and **STLSoft** versions as efferent dependencies;
* Changed CI to run component tests via **run_all_component_tests.sh**;
* Applied **misc-dev-scripts** **0.6.0** editor/Git/`.sis` drop-in templates on **boilerplate**;
* Restored historical **.gitignore** patterns as a sorted union with **misc-dev-scripts** gold section layout;


## 0.1.3-alpha2 - 4th September 2026

* Renamed the MSVCRT CRT leak-trace API to **main_memory_msvcrt_leak_trace** (`pantheios_extras_diagutil_main_memory_msvcrt_leak_trace_invoke`, `pantheios::extras::diagutil::main_memory_msvcrt_leak_trace::invoke`);
* Kept **main_leak_trace** as a deprecated compatibility alias;


## 0.1.3-alpha1 - 2nd September 2026

* Aligned the **CMake** contract with peer Extras/freelibs (`MSVC_USE_MT`
  absorb, explicit `BUILD_TESTING`, stable `PANTHEIOS_EXTRAS_DIAGUTIL`
  version tag, lowercase export name with `NAMESPACE`);
* Added **xTests** unit coverage for version macros and portable
  `main_leak_trace` return-code propagation; wired `test/`;
* Added **.sis/project_name.txt** and aligned helper scripts; documented
  the library in **README.md** / **INSTALL.md** / **NEWS.md** /
  **CHANGES.md** / **AUTHORS.md** / **FAQ.md**;
* Added GitHub Actions CI (**ci.yml** / **ci-cell.yml**) with install
  smoke, including Pantheios stack dependencies;
* Install-smoke omits optional **b64** (as **Pantheios** install-smoke does)
  and finds **STLSoft** before **Pantheios**;


## 0.1.2 - historical

* Prior line recorded in repository history (CMake introduction and
  dependency self-sufficiency fixes);


## 0.1.1 - historical

* Initial public alpha of main leak-trace helpers for C and C++;


<!-- ########################### end of file ########################### -->
