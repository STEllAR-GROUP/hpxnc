//  Copyright (c) 2015 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(HPXNC_CONFIG_EXPORT_DEFINITIONS)
#define HPXNC_CONFIG_EXPORT_DEFINITIONS

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
# define HPXNC_SYMBOL_EXPORT      __declspec(dllexport)
# define HPXNC_SYMBOL_IMPORT      __declspec(dllimport)
# define HPXNC_SYMBOL_INTERNAL    /* empty */
# define HPXNC_APISYMBOL_EXPORT   __declspec(dllexport)
# define HPXNC_APISYMBOL_IMPORT   __declspec(dllimport)
#else
# define HPXNC_SYMBOL_EXPORT      __attribute__((visibility("default")))
# define HPXNC_SYMBOL_IMPORT      __attribute__((visibility("default")))
# define HPXNC_SYMBOL_INTERNAL    __attribute__((visibility("hidden")))
# define HPXNC_APISYMBOL_EXPORT   __attribute__((visibility("default")))
# define HPXNC_APISYMBOL_IMPORT   __attribute__((visibility("default")))
#endif

// make sure we have reasonable defaults
#if !defined(HPXNC_SYMBOL_EXPORT)
# define HPXNC_SYMBOL_EXPORT      /* empty */
#endif
#if !defined(HPXNC_SYMBOL_IMPORT)
# define HPXNC_SYMBOL_IMPORT      /* empty */
#endif
#if !defined(HPXNC_SYMBOL_INTERNAL)
# define HPXNC_SYMBOL_INTERNAL    /* empty */
#endif
#if !defined(HPXNC_APISYMBOL_EXPORT)
# define HPXNC_APISYMBOL_EXPORT   /* empty */
#endif
#if !defined(HPXNC_APISYMBOL_IMPORT)
# define HPXNC_APISYMBOL_IMPORT   /* empty */
#endif

///////////////////////////////////////////////////////////////////////////////
// define the export/import helper macros used by the core library
#if defined(HPXNC_EXPORTS)
# define  HPXNC_EXPORT             HPXNC_SYMBOL_EXPORT
# define  HPXNC_EXCEPTION_EXPORT   HPXNC_SYMBOL_EXPORT
# define  HPXNC_API_EXPORT         HPXNC_APISYMBOL_EXPORT
#else
# define  HPXNC_EXPORT             HPXNC_SYMBOL_IMPORT
# define  HPXNC_EXCEPTION_EXPORT   HPXNC_SYMBOL_IMPORT
# define  HPXNC_API_EXPORT         HPXNC_APISYMBOL_IMPORT
#endif

///////////////////////////////////////////////////////////////////////////////
// define the export/import helper macros used by applications
#if defined(HPXNC_APPLICATION_EXPORTS)
# define  HPXNC_APPLICATION_EXPORT HPXNC_SYMBOL_EXPORT
#else
# define  HPXNC_APPLICATION_EXPORT HPXNC_SYMBOL_IMPORT
#endif

///////////////////////////////////////////////////////////////////////////////
// define the export/import helper macros for exceptions
#if defined(HPXNC_EXPORTS)
# define HPXNC_ALWAYS_EXPORT       HPXNC_SYMBOL_EXPORT
#else
# define HPXNC_ALWAYS_EXPORT       HPXNC_SYMBOL_IMPORT
#endif

#endif
