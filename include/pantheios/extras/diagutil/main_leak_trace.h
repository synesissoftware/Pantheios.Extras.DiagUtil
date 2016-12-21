/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/extras/diagutil/main_leak_trace.h
 *
 * Purpose:     Definition of the pantheios_extras_diagutil_main_leak_trace_invoke() function.
 *
 * Created:     28th December 2010
 * Updated:     21st December 2016
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2011-2016, Matthew Wilson and Synesis Software
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
 * [C only] Definition of the pantheios_extras_diagutil_main_leak_trace_invoke() function,
 *   as part of the
 *   \ref group__library__pantheios_extras_diagutil "Pantheios.Extras.DiagUtil" library.
 */

#ifndef PANTHEIOS_EXTRAS_DIAGUTIL_INCL_PANTHEIOS_EXTRAS_DIAGUTIL_H_MAIN_LEAK_TRACE
#define PANTHEIOS_EXTRAS_DIAGUTIL_INCL_PANTHEIOS_EXTRAS_DIAGUTIL_H_MAIN_LEAK_TRACE

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_PANTHEIOS_EXTRAS_DIAGUTIL_H_MAIN_LEAK_TRACE_MAJOR    1
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_PANTHEIOS_EXTRAS_DIAGUTIL_H_MAIN_LEAK_TRACE_MINOR    1
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_PANTHEIOS_EXTRAS_DIAGUTIL_H_MAIN_LEAK_TRACE_REVISION 3
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_PANTHEIOS_EXTRAS_DIAGUTIL_H_MAIN_LEAK_TRACE_EDIT     6
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <pantheios/extras/diagutil/internal/common.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER && _DEBUG */

#ifdef __cplusplus
# include <exception>
#endif /* __cplusplus */

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
    malloc(1);

    return EXIT_SUCCESS;
  }

  int main(int argc, char** argv)
  {
      return pantheios_extras_diagutil_main_leak_trace_invoke(argc, argv, main0);
  }
</pre>
\endhtmlonly
 *
 * The memory leaked by the call to <code>malloc()</code> will be reported by
 * pantheios_extras_diagutil_main_leak_trace_invoke().
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
STLSOFT_INLINE
int
pantheios_extras_diagutil_main_leak_trace_invoke(
    int                 argc
,   char**              argv
,   int (STLSOFT_CDECL* pfnMain)(int, char**)
)
{
#if defined(_MSC_VER) && \
    defined(_DEBUG)

    int             r;
    _CrtMemState    memState;

    _CrtMemCheckpoint(&memState);

# ifdef __cplusplus
    try
    {
# endif /* __cplusplus */

        r = pfnMain(argc, argv);

        _CrtMemDumpAllObjectsSince(&memState);
# ifdef __cplusplus
    }
    catch(std::exception&)
    {
        _CrtMemDumpAllObjectsSince(&memState);

        throw;
    }
# endif /* __cplusplus */

    return r;

#else /* ? _MSC_VER && _DEBUG */

    return pfnMain(argc, argv);

#endif /* _MSC_VER && _DEBUG */
}

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_EXTRAS_DIAGUTIL_INCL_PANTHEIOS_EXTRAS_DIAGUTIL_H_MAIN_LEAK_TRACE */

/* ///////////////////////////// end of file //////////////////////////// */
