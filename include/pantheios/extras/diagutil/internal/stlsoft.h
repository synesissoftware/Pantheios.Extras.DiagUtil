/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/extras/diagutil/internal/stlsoft.h
 *
 * Purpose:     "Entry point" include into the STLSoft libraries.
 *
 * Created:     6th January 2011
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


/** \file pantheios/extras/diagutil/internal/stlsoft.h
 * [C, C++] "Entry point" include into the STLSoft libraries.
 */

#ifndef PANTHEIOS_EXTRAS_DIAGUTIL_INCL_PANTHEIOS_EXTRAS_DIAGUTIL_INTERNAL_H_STLSOFT
#define PANTHEIOS_EXTRAS_DIAGUTIL_INCL_PANTHEIOS_EXTRAS_DIAGUTIL_INTERNAL_H_STLSOFT

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_PANTHEIOS_EXTRAS_DIAGUTIL_INTERNAL_H_STLSOFT_MAJOR       1
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_PANTHEIOS_EXTRAS_DIAGUTIL_INTERNAL_H_STLSOFT_MINOR       0
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_PANTHEIOS_EXTRAS_DIAGUTIL_INTERNAL_H_STLSOFT_REVISION    2
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_PANTHEIOS_EXTRAS_DIAGUTIL_INTERNAL_H_STLSOFT_EDIT        2
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility checks
 */

/* STLSoft 1.9 check */

#if !defined(_STLSOFT_VER) || \
    _STLSOFT_VER < 0x010978ff
# error Requires STLSoft 1.9.120, or later. (www.stlsoft.org)
#endif /* STLSoft version */

/* STLSoft 1.10 check */

#if _STLSOFT_VER < 0x010a0000 && \
    defined(_STLSOFT_1_10_VER) && \
    _STLSOFT_1_10_VER < 0x010a0113

# error If you're using STLSoft 1.10 alpha you must use at least version 1.10.1 alpha 19

#endif /* STLSoft 1.10.1 alpha 1 - alpha 8 */

#if defined(__cplusplus) && \
    defined(_STLSOFT_NO_NAMESPACE)
# error Pantheios.Extras.DiagUtil requires that STLSoft`s namespace has not been disabled in C++ compilation
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_EXTRAS_DIAGUTIL_INCL_PANTHEIOS_EXTRAS_DIAGUTIL_INTERNAL_H_STLSOFT */

/* ///////////////////////////// end of file //////////////////////////// */
