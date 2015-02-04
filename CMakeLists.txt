# Copyright (c) 2015 Hartmut Kaiser
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

################################################################################
# Top level CMakeList.txt for HPXnC
################################################################################

cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)

project(hpxnc CXX)

# Project version.
set(HPXNC_MAJOR_VERSION 0)
set(HPXNC_MINOR_VERSION 1)
set(HPXNC_PATCH_LEVEL   0)
set(HPXNC_SOVERSION     ${HPXNC_MAJOR_VERSION})
set(HPXNC_VERSION
    "${HPXNC_MAJOR_VERSION}.${HPXNC_MINOR_VERSION}.${HPXNC_PATCH_LEVEL}")

set(CMAKE_MODULE_PATH
    ${HPX_ROOT}/share/cmake-${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}/Modules)

if(MSVC)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

find_package(HPX REQUIRED)

if(NOT MSVC)
  set(HPX_RPATH
      "${HPX_RPATH}:${CMAKE_INSTALL_PREFIX}/lib/hpx:${CMAKE_BINARY_DIR}/lib/hpx")
endif()

include_directories(${HPX_INCLUDE_DIR})
link_directories(${HPX_LIBRARY_DIR})

include_directories(${hpxnc_SOURCE_DIR})

add_subdirectory(src)

add_hpx_pseudo_target(examples)
add_subdirectory(examples)

