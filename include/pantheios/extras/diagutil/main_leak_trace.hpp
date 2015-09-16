/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/extras/diagutil/main_leak_trace.hpp
 *
 * Purpose:     Definition of the pantheios::extras::diagutil::main_leak_trace::invoke() function.
 *
 * Created:     28th December 2010
 * Updated:     10th September 2015
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2011-2015, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file pantheios/extras/diagutil/main_leak_trace.h
 * [C only] Definition of the pantheios::extras::diagutil::main_leak_trace::invoke() function,
 *   as part of the
 *   \ref group__library__pantheios_extras_diagutil "Pantheios.Extras.DiagUtil" library.
 */

#ifndef PANTHEIOS_EXTRAS_DIAGUTIL_INCL_PANTHEIOS_EXTRAS_DIAGUTIL_HPP_MAIN_LEAK_TRACE
#define PANTHEIOS_EXTRAS_DIAGUTIL_INCL_PANTHEIOS_EXTRAS_DIAGUTIL_HPP_MAIN_LEAK_TRACE

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_PANTHEIOS_EXTRAS_DIAGUTIL_HPP_MAIN_LEAK_TRACE_MAJOR      1
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_PANTHEIOS_EXTRAS_DIAGUTIL_HPP_MAIN_LEAK_TRACE_MINOR      1
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_PANTHEIOS_EXTRAS_DIAGUTIL_HPP_MAIN_LEAK_TRACE_REVISION   2
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_PANTHEIOS_EXTRAS_DIAGUTIL_HPP_MAIN_LEAK_TRACE_EDIT       5
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <pantheios/extras/diagutil/main_leak_trace.h>
#include <pantheios/extras/diagutil/internal/common.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

/** The <strong>Pantheios</strong> root namespace - <code>pantheios</code>.
 *
 * This namespace is used by the Pantheios main library.
 * <strong>Pantheios.Extras.DiagUtil</strong> elements are defined within the
 * <code>pantheios::extras::diagutil</code> namespace
 */
namespace pantheios
{
/** The <strong>Pantheios::Extras</strong> root namespace - <code>pantheios::extras</code>.
 *
 * This namespace is used to contain all Pantheios::Extras projects.
 * <strong>Pantheios.Extras.DiagUtil</strong> elements are defined within the
 * <code>pantheios::extras::diagutil</code> namespace
 */
namespace extras
{
/** The namespace used by the <strong>Pantheios.Extras.DiagUtil</strong>
 * library - <code>pantheios::extras::diagutil</code>
 */
namespace diagutil
{

/** The namespace within with the \ref group__library__pantheios_extras_diagutil_memleaktrace library
 * C++ components are defined, which offer leak-tracing for <code>main()</code> functions.
 */
namespace main_leak_trace
{

/* /////////////////////////////////////////////////////////////////////////
 * API Functions
 */

/** Invokes the given <code>main()</code>-like function and, when compiling
 * in the presence of _MSC_VER and _DEBUG, traces any memory resources
 * leaked by the call.
 *
 * \ingroup group__library__pantheios_extras_diagutil_memleaktrace
 *
 * Consider the following example:
 *
\htmlonly
<pre>
  int main0(int argc, char** argv)
  {
    new char[1];

    return EXIT_SUCCESS;
  }

  int main(int argc, char** argv)
  {
      return pantheios::extras::diagutil::main_leak_trace::invoke(argc, argv, main0);
  }
</pre>
\endhtmlonly
 *
 * The memory leaked by the call to <code>malloc()</code> will be reported by
 * pantheios::extras::diagutil::main_leak_trace::invoke().
 *
 * \param argc The <code>argc</code> parameter of <code>main()</code>.
 * \param argv The <code>argv</code> parameter of <code>main()</code>.
 * \param pfnMain The <code>main()</code>-like function to be invoked.
 *
 * \return The return value of <code>pfnMain</code>.
 *
 * \pre (NULL != argv)
 * \pre (NULL != pfnMain)
 */

inline
int
invoke(
    int                 argc
,   char**              argv
,   int (STLSOFT_CDECL* pfnMain)(int, char**)
)
{
    return pantheios_extras_diagutil_main_leak_trace_invoke(argc, argv, pfnMain);
}

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
inline
int
invoke(
    int                 argc
,   char const* const*  argv
,   int (STLSOFT_CDECL* pfnMain)(int, char const* const*)
)
{
    return pantheios_extras_diagutil_main_leak_trace_invoke(argc, const_cast<char**>(argv), reinterpret_cast<int (STLSOFT_CDECL*)(int, char**)>(pfnMain));
}
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace main_leak_trace

} // namespace diagutil
} // namespace extras
} // namespace pantheios

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_EXTRAS_DIAGUTIL_INCL_PANTHEIOS_EXTRAS_DIAGUTIL_HPP_MAIN_LEAK_TRACE */

/* ///////////////////////////// end of file //////////////////////////// */
