# Pantheios.Extras.DiagUtil - Changes <!-- omit in toc -->


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
