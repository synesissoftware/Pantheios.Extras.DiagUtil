/* /////////////////////////////////////////////////////////////////////////
 * File:        example.cpp.main_leak_trace.1.cpp
 *
 * Purpose:     Implementation file for the example.cpp.main_leak_trace.1 library.
 *
 * Created:     6th January 2011
 * Updated:     10th September 2015
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2011-2015, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Pantheios::Extras::DiagUtil header files */
#include <pantheios/extras/diagutil.hpp>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <platformstl/platformstl.h>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ////////////////////////////////////////////////////////////////////// */

int main0(int argc, char** argv)
{
#ifdef _DEBUG
    malloc(1);
    malloc(10);
    malloc(100);
    malloc(1000);
    malloc(10000);
#endif /* _DEBUG */

    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    return ::pantheios::extras::diagutil::main_leak_trace::invoke(argc, argv, main0);
}

/* ///////////////////////////// end of file //////////////////////////// */
