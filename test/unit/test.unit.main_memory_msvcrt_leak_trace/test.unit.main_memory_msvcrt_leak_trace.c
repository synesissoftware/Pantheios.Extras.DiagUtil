/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.main_memory_msvcrt_leak_trace.c
 *
 * Purpose: Unit tests for
 *          pantheios_extras_diagutil_main_memory_msvcrt_leak_trace_invoke()
 *          and the deprecated
 *          pantheios_extras_diagutil_main_leak_trace_invoke() alias.
 *
 * Created: 2nd September 2026
 * Updated: 4th September 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/extras/diagutil.h>

#include <xtests/xtests.h>

#include <stdlib.h>


static int
program_returns_42(
    int     argc
,   char**  argv
)
{
    ((void)argc);
    ((void)argv);

    return 42;
}

static int
program_returns_exit_failure(
    int     argc
,   char**  argv
)
{
    ((void)argc);
    ((void)argv);

    return EXIT_FAILURE;
}


static void
test_invoke_propagates_success_code(void)
{
    char* argv[] = { "test.unit.main_memory_msvcrt_leak_trace", NULL };

    XTESTS_TEST_INTEGER_EQUAL(
        42
    ,   pantheios_extras_diagutil_main_memory_msvcrt_leak_trace_invoke(1, argv, program_returns_42)
    );
}

static void
test_invoke_propagates_failure_code(void)
{
    char* argv[] = { "test.unit.main_memory_msvcrt_leak_trace", NULL };

    XTESTS_TEST_INTEGER_EQUAL(
        EXIT_FAILURE
    ,   pantheios_extras_diagutil_main_memory_msvcrt_leak_trace_invoke(1, argv, program_returns_exit_failure)
    );
}

static void
test_deprecated_alias_propagates_success_code(void)
{
    char* argv[] = { "test.unit.main_memory_msvcrt_leak_trace", NULL };

#if defined(_MSC_VER) && \
    _MSC_VER >= 1400
# pragma warning(push)
# pragma warning(disable : 4996)
#endif

    XTESTS_TEST_INTEGER_EQUAL(
        42
    ,   pantheios_extras_diagutil_main_leak_trace_invoke(1, argv, program_returns_42)
    );

#if defined(_MSC_VER) && \
    _MSC_VER >= 1400
# pragma warning(pop)
#endif
}


int
main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.main_memory_msvcrt_leak_trace", verbosity))
    {
        XTESTS_RUN_CASE(test_invoke_propagates_success_code);
        XTESTS_RUN_CASE(test_invoke_propagates_failure_code);
        XTESTS_RUN_CASE(test_deprecated_alias_propagates_success_code);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ///////////////////////////// end of file //////////////////////////// */
