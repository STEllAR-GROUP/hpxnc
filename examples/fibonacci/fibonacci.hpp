//********************************************************************************
// Copyright (c) 2007-2014 Intel Corporation. All rights reserved.              **
//                                                                              **
// Redistribution and use in source and binary forms, with or without           **
// modification, are permitted provided that the following conditions are met:  **
//   * Redistributions of source code must retain the above copyright notice,   **
//     this list of conditions and the following disclaimer.                    **
//   * Redistributions in binary form must reproduce the above copyright        **
//     notice, this list of conditions and the following disclaimer in the      **
//     documentation and/or other materials provided with the distribution.     **
//   * Neither the name of Intel Corporation nor the names of its contributors  **
//     may be used to endorse or promote products derived from this software    **
//     without specific prior written permission.                               **
//                                                                              **
// This software is provided by the copyright holders and contributors "as is"  **
// and any express or implied warranties, including, but not limited to, the    **
// implied warranties of merchantability and fitness for a particular purpose   **
// are disclaimed. In no event shall the copyright owner or contributors be     **
// liable for any direct, indirect, incidental, special, exemplary, or          **
// consequential damages (including, but not limited to, procurement of         **
// substitute goods or services; loss of use, data, or profits; or business     **
// interruption) however caused and on any theory of liability, whether in      **
// contract, strict liability, or tort (including negligence or otherwise)      **
// arising in any way out of the use of this software, even if advised of       **
// the possibility of such damage.                                              **
//********************************************************************************

#ifndef EXAMPLES_FIBONACCI
#define EXAMPLES_FIBONACCI

#include <hpxnc/hpxnc.hpp>

// Forward declaration of the context class (also known as graph)
struct fib_context;

// let's use a large type to store fib numbers
typedef unsigned long long fib_type;

// The step classes
struct fib_step
{
    int execute(int const& tag, fib_context& ctx) const;
};

// The context class
struct fib_context : public hpxnc::context<fib_context>
{
    // step collections
    hpxnc::step_collection<fib_step> steps_;

    // Item collections
    hpxnc::item_collection<int, fib_type> fibs_;

    // Tag collections
    hpxnc::tag_collection<int> tags_;

    // The context class constructor
    fib_context()
      : hpxnc::context<fib_context>(),
        steps_(*this),      // Initialize each step collection
        fibs_(*this),       // Initialize each item collection
        tags_(*this)        // Initialize each tag collection
    {
        tags_.prescribes(steps_, *this);        // Prescriptive relations
        steps_.consumes(fibs_);                 // Consumer relations
        steps_.produces(fibs_);                 // Producer relations
    }
};

HPX_REGISTER_UNORDERED_MAP_DECLARATION(int, fib_type);

#endif
