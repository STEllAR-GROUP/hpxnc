# Copyright (c) 2015 Hartmut Kaiser
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

include_directories(${HPX_INCLUDE_DIR})
link_directories(${HPX_LIBRARY_DIR})

add_definitions("-DHPXNC_EXPORTS")

add_hpx_library(
  hpxnc SHARED
  SOURCE_ROOT "${hpxnc_SOURCE_DIR}/src"
  HEADER_ROOT "${hpxnc_SOURCE_DIR}/hpxnc"
  OUTPUT_SUFFIX .
  AUTOGLOB)

# Don't cause our applications to link against hpx_init.
set_target_properties(hpxnc_lib PROPERTIES LINK_INTERFACE_LIBRARIES "")

set_target_properties(hpxnc_lib PROPERTIES
  VERSION ${HPXNC_VERSION}
  SOVERSION ${HPXNC_SOVERSION}
  CLEAN_DIRECT_OUTPUT 1
  OUTPUT_NAME hpxnc${HPX_DEBUG_POSTFIX}
  FOLDER "Core")

