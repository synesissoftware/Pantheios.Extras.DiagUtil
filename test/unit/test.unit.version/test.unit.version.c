/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.version.c
 *
 * Purpose: Unit tests for Pantheios.Extras.DiagUtil version macros.
 *
 * Created: 2nd September 2026
 * Updated: 4th September 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/extras/diagutil.h>

#include <xtests/xtests.h>

#include <stdlib.h>


static void
test_version_components(void)
{
    XTESTS_TEST_INTEGER_EQUAL(0, PANTHEIOS_EXTRAS_DIAGUTIL_VER_MAJOR);
    XTESTS_TEST_INTEGER_EQUAL(1, PANTHEIOS_EXTRAS_DIAGUTIL_VER_MINOR);
    XTESTS_TEST_INTEGER_EQUAL(3, PANTHEIOS_EXTRAS_DIAGUTIL_VER_REVISION);
}

static void
test_version_composite(void)
{
    int const alphabeta = PANTHEIOS_EXTRAS_DIAGUTIL_VER & 0xff;
    int const computed =
        (0
            |   (   PANTHEIOS_EXTRAS_DIAGUTIL_VER_MAJOR     << 24   )
            |   (   PANTHEIOS_EXTRAS_DIAGUTIL_VER_MINOR     << 16   )
            |   (   PANTHEIOS_EXTRAS_DIAGUTIL_VER_REVISION  <<  8   )
            |   (   alphabeta                               <<  0   )
        );

    XTESTS_TEST_INTEGER_EQUAL(0x42, alphabeta);
    XTESTS_TEST_INTEGER_EQUAL(computed, PANTHEIOS_EXTRAS_DIAGUTIL_VER);
    XTESTS_TEST_INTEGER_EQUAL(PANTHEIOS_EXTRAS_DIAGUTIL_VER_0_1_3_ALPHA_2, PANTHEIOS_EXTRAS_DIAGUTIL_VER);
    XTESTS_TEST_INTEGER_EQUAL(0x00010342, PANTHEIOS_EXTRAS_DIAGUTIL_VER);
}


int
main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.version", verbosity))
    {
        XTESTS_RUN_CASE(test_version_components);
        XTESTS_RUN_CASE(test_version_composite);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ///////////////////////////// end of file //////////////////////////// */
