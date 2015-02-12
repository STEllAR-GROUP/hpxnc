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

// compute Fibonacci numbers

#include <hpx/hpx_main.hpp>
#include <hpx/include/lcos.hpp>

#include <iostream>

#include "fibonacci.hpp"

// the actual step code computing the fib numbers goes here
int fib_step::execute(int const& tag, fib_context& ctxt) const
{
    switch(tag) {
    case 0: ctxt.fibs_.put(tag, 0); break;
    case 1: ctxt.fibs_.put(tag, 1); break;
    default:
        {
            // get previous 2 results
            hpx::lcos::local::dataflow(
                [tag, &ctxt](hpx::future<fib_type> f1, hpx::future<fib_type> f2)
                {
                    // put our result
                    ctxt.fibs_.put(tag, f1.get() + f2.get());
                },
                ctxt.fibs_.get(tag - 1),
                ctxt.fibs_.get(tag - 2));
        }
        break;
    }
    return hpxnc::success;
}

int main(int argc, char* argv[])
{
    int n = 42;

    // eval command line args
    if (argc < 2) {
        std::cerr
            << "usage: " << argv[0] << " n\n"
            << "Using default value " << n << std::endl;
    }
    else {
        n = atol(argv[1]);
    }

    // create context
    fib_context ctxt;

    // put tags to initiate evaluation
    for(int i = 0; i <= n; ++i)
        ctxt.tags_.put(i);

    // get result
    hpx::future<fib_type> res = ctxt.fibs_.get(n);

    // wait for completion and print result
    std::cout << "fib(" << n << "): " << res.get() << std::endl;

    return 0;
}
