//  Copyright (c) 2015 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <hpxnc/config.hpp>

namespace hpxnc
{
    unsigned int major_version()
    {
        return HPXNC_VERSION_MAJOR;
    }

    unsigned int minor_version()
    {
        return HPXNC_VERSION_MINOR;
    }

    unsigned int subminor_version()
    {
        return HPXNC_VERSION_SUBMINOR;
    }

    unsigned long full_version()
    {
        return HPXNC_VERSION_FULL;
    }
}
