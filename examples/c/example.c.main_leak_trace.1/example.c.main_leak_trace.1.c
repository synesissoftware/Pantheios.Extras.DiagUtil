/* /////////////////////////////////////////////////////////////////////////
 * File:    example.c.main_leak_trace.1.c
 *
 * Purpose: Implementation file for the example.c.main_leak_trace.1 library.
 *
 * Created: 6th January 2011
 * Updated: 23rd October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Pantheios.Extras.DiagUtil header files */
#include <pantheios/extras/diagutil.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <platformstl/platformstl.h>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main0(int argc, char* argv[])
{
#ifdef _DEBUG
    malloc(1);
    malloc(10);
    malloc(100);
    malloc(1000);
    malloc(10000);
#endif /* _DEBUG */

    ((void)&argc);
    ((void)&argv);

    return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
    return pantheios_extras_diagutil_main_leak_trace_invoke(argc, argv, main0);
}


/* ///////////////////////////// end of file //////////////////////////// */

