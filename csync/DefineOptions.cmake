if ( NOT WIN32 )
    option(WITH_ICONV "Build csync with iconv support" ON)
endif()
option(UNIT_TESTING "Build with unit tests" OFF)
option(MEM_NULL_TESTS "Enable NULL memory testing" OFF)