/* /////////////////////////////////////////////////////////////////////////
 * File:    test/scratch/versions/main.cpp
 *
 * Purpose: Prints Pantheios.Extras.DiagUtil and its efferent
 *          dependency versions.
 *
 * Created: 9th October 2026
 * Updated: 4th November 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <pantheios/extras/diagutil.h>

#include <pantheios/pantheios.h>

#include <stlsoft/stlsoft.h>

#ifdef HAS_b64
# include <b64/b64.h>
#endif

#include <woad/woad.h>

#ifdef HAS_xTests
# include <xtests/xtests.h>
#endif

#include <iomanip>
#include <iostream>

#include <stdio.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

template<
    typename T_stream
,   typename T_integer
>
void
version(
    T_stream&   stm
,   FILE*       file
,   char const* prefix
,   char const* libname
,   char const* macroname
,   T_integer   libver
,   char const* version_string = nullptr
)
{
    stm
        << prefix
        << WOAD_FG_BLUE_FOR(file)
        << libname
        << WOAD_RESET_FOR(file)
        << ": "
        << WOAD_FG_GREEN_FOR(file)
        << 'v'
        ;

    if (nullptr != version_string)
    {
        stm << version_string;
    }
    else
    {
        stm
            << ((libver >> 24) & 0xFF)
            << '.'
            << ((libver >> 16) & 0xFF)
            << '.'
            << ((libver >> 8) & 0xFF)
            << '.'
            << ((libver >> 0) & 0xFF)
            ;
    }

    stm
        << WOAD_RESET_FOR(file)
        << " ("
        << WOAD_FG_CYAN_FOR(file)
        << macroname
        << WOAD_RESET_FOR(file)
        << " = "
        << WOAD_FG_GREEN_FOR(file)
        << "0x"
        << std::hex << std::setfill('0') << std::setw(8)
        << static_cast<unsigned>(libver)
        << std::dec
        << WOAD_RESET_FOR(file)
        << ")"
        << std::endl
        ;
}


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int /*argc*/, char* /*argv*/[])
{
    int efferents_count = 0;

    {
        unsigned const libver = PANTHEIOS_EXTRAS_DIAGUTIL_VER;

        version(std::cout, stdout, "", "Pantheios.Extras.DiagUtil", "PANTHEIOS_EXTRAS_DIAGUTIL_VER", libver);
    }

#ifdef HAS_b64

    if (0 == efferents_count++)
    {
        std::cout << "\n" << "efferent dependencies:" << std::endl;
    }

    {
        unsigned const libver = B64_VER;

        version(std::cout, stdout, "\t", "b64", "B64_VER", libver);
    }
#endif

    if (0 == efferents_count++)
    {
        std::cout << "\n" << "efferent dependencies:" << std::endl;
    }

    {
        unsigned const libver = PANTHEIOS_VER;

        version(std::cout, stdout, "\t", "Pantheios", "PANTHEIOS_VER", libver);
    }

    if (0 == efferents_count++)
    {
        std::cout << "\n" << "efferent dependencies:" << std::endl;
    }

    {
        unsigned const libver = _STLSOFT_VER;

        version(std::cout, stdout, "\t", "STLSoft", "_STLSOFT_VER", libver);
    }

    if (0 == efferents_count++)
    {
        std::cout << "\n" << "efferent dependencies:" << std::endl;
    }

    {
        unsigned const libver = WOAD_VER;

        version(std::cout, stdout, "\t", "woad", "WOAD_VER", libver, woad::version_string());
    }

#ifdef HAS_xTests

    if (0 == efferents_count++)
    {
        std::cout << "\n" << "efferent dependencies:" << std::endl;
    }

    {
        unsigned const libver = _XTESTS_VER;

        version(std::cout, stdout, "\t", "xTests", "_XTESTS_VER", libver);
    }
#endif

    return EXIT_SUCCESS;
}

/* ///////////////////////////// end of file //////////////////////////// */

