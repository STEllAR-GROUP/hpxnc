//  Copyright (c) 2015 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(HPXNC_CONFIG_VERSION)
#define HPXNC_CONFIG_VERSION

///////////////////////////////////////////////////////////////////////////////
//  The version of HPXnC
//
//  HPXNC_VERSION_FULL & 0x0000FF is the sub-minor version
//  HPXNC_VERSION_FULL & 0x00FF00 is the minor version
//  HPXNC_VERSION_FULL & 0xFF0000 is the major version
//
//  HPXNC_VERSION_DATE   YYYYMMDD is the date of the release
//                               (estimated release date for master branch)
//
#define HPXNC_VERSION_FULL         0x000001

#define HPXNC_VERSION_MAJOR        0
#define HPXNC_VERSION_MINOR        0
#define HPXNC_VERSION_SUBMINOR     1

#define HPXNC_VERSION_DATE         20150203

namespace hpxnc
{
    // return version of this library
    HPXNC_EXPORT unsigned int major_version();
    HPXNC_EXPORT unsigned int minor_version();
    HPXNC_EXPORT unsigned int subminor_version();
    HPXNC_EXPORT unsigned long full_version();
}

#endif
