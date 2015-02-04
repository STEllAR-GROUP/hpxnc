# Copyright (c) 2015 Hartmut Kaiser
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

set(example_programs
    fibonacci
   )

foreach(example_program ${example_programs})
  set(sources ${example_program}.cpp)

  source_group("Source Files" FILES ${sources})

  # add example executable
  add_hpx_executable(
    ${example_program}
    SOURCES ${sources}
    ${${example_program}_FLAGS}
    DEPENDENCIES hpxnc_lib
    FOLDER "Examples/Fibonacci/${example_program}"
    OUTPUT_SUFFIX bin
    NOHPXINIT)

  # add a custom target for this example
  add_hpx_pseudo_target(examples.threads.${example_program})

  # make pseudo-targets depend on master pseudo-target
  add_hpx_pseudo_dependencies(
    examples.threads
    examples.threads.${example_program})

  # add dependencies to pseudo-target
  add_hpx_pseudo_dependencies(
    examples.threads.${example_program}
    ${example_program}_exe)

endforeach()

