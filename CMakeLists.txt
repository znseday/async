cmake_minimum_required(VERSION 3.2)

if(WIN32 OR WIN64)
    message(STATUS "My Windows detected")
    project(async VERSION 0.0.1000)
    set(BOOST_ROOT "C:/Boost")
else()
    project(async VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
endif()

add_executable(async_cli main.cpp my_utils.h)

add_library(async SHARED async.cpp async.h bulk.cpp bulk.h my_utils.h)

if(WIN32 OR WIN64)
    set_target_properties(async async_cli PROPERTIES
            CXX_STANDARD 17
            CXX_STANDARD_REQUIRED ON
			COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra")
else()
    set_target_properties(async async_cli PROPERTIES
            CXX_STANDARD 17
            CXX_STANDARD_REQUIRED ON
            COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra")

    set(CMAKE_BUILD_TYPE Release)
endif()

target_link_libraries(async_cli
    async
    #Threads::Threads
)

#install(TARGETS async RUNTIME DESTINATION bin)
install(TARGETS async LIBRARY DESTINATION lib)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT "znseday")

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

#enable_testing()
#add_test(my_tests_ my_tests)
