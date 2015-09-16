/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/extras/diagutil/internal/common.h
 *
 * Purpose:     Definition of common features header for the
 *              Pantheios.Extras.DiagUtil library.
 *
 * Created:     6th January 2011
 * Updated:     17th September 2015
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


/** \file pantheios/extras/diagutil/internal/common.h
 * [C, C++] Definition of common features header for the
 *   \ref group__library__pantheios_extras_diagutil "Pantheios.Extras.DiagUtil" library.
 */

#ifndef PANTHEIOS_EXTRAS_DIAGUTIL_INCL_PANTHEIOS_EXTRAS_DIAGUTIL_INTERNAL_H_COMMON
#define PANTHEIOS_EXTRAS_DIAGUTIL_INCL_PANTHEIOS_EXTRAS_DIAGUTIL_INTERNAL_H_COMMON

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_PANTHEIOS_EXTRAS_DIAGUTIL_INTERNAL_H_COMMON_MAJOR    1
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_PANTHEIOS_EXTRAS_DIAGUTIL_INTERNAL_H_COMMON_MINOR    0
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_PANTHEIOS_EXTRAS_DIAGUTIL_INTERNAL_H_COMMON_REVISION 4
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_PANTHEIOS_EXTRAS_DIAGUTIL_INTERNAL_H_COMMON_EDIT     4
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <pantheios/pantheios.h>

#include <pantheios/extras/diagutil/internal/stlsoft.h>

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility checks
 */

#if PANTHEIOS_VER < 0x010001d7
# error Pantheios.Extras.DiagUtil required Pantheios 1.0.1 beta 215, or later
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

/** \def PANTHEIOS_EXTRAS_DIAGUTIL_VER_MAJOR
 * The major version number of Pantheios.Extras.DiagUtil
 */

/** \def PANTHEIOS_EXTRAS_DIAGUTIL_VER_MINOR
 * The minor version number of Pantheios.Extras.DiagUtil
 */

/** \def PANTHEIOS_EXTRAS_DIAGUTIL_VER_REVISION
 * The revision version number of Pantheios.Extras.DiagUtil
 */

/** \def PANTHEIOS_EXTRAS_DIAGUTIL_VER
 * The current composite version number of Pantheios.Extras.DiagUtil
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_0_1_1_ALPHA_1        0x00010101
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_0_1_1_ALPHA_2        0x00010102
# define PANTHEIOS_EXTRAS_DIAGUTIL_VER_0_1_1                0x000101ff
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

#define PANTHEIOS_EXTRAS_DIAGUTIL_VER_MAJOR                 0
#define PANTHEIOS_EXTRAS_DIAGUTIL_VER_MINOR                 1
#define PANTHEIOS_EXTRAS_DIAGUTIL_VER_REVISION              1

#define PANTHEIOS_EXTRAS_DIAGUTIL_VER                       PANTHEIOS_EXTRAS_DIAGUTIL_VER_0_1_1

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_EXTRAS_DIAGUTIL_INCL_PANTHEIOS_EXTRAS_DIAGUTIL_INTERNAL_H_COMMON */

/* ///////////////////////////// end of file //////////////////////////// */
