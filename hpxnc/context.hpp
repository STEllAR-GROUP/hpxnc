//  Copyright (c) 2015 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(HPXNC_CONTEXT)
#define HPXNC_CONTEXT

#include <hpxnc/config.hpp>

#include <boost/serialization/serialization.hpp>

namespace hpxnc
{
    /// Error type used by hpxnc
    typedef int error_type;

    const error_type success = 0;
    const error_type failure = 1;

    /// HPXnC context bringing together collections (for steps, items and tags).
    ///
    /// The user needs to derive his or her own context from the hpxnc::context.
    /// The template argument to context is the user's context class itself.
    ///
    /// \code
    ///        struct my_context
    ///          : public hpxnc::context<my_context>
    ///        {
    ///            hpxnc::step_collection<find_primes> steps;
    ///            hpxnc::tag_collection<int> odd_nums;
    ///            hpxnc::item_collection<int, int> primes;
    ///
    ///            my_context()
    ///              : hpxnc::context<my_context>(),
    ///                steps(*this),
    ///                odd_nums(*this),
    ///                primes(*this)
    ///            {
    ///                odd_nums.prescribes(steps);
    ///            }
    ///        };
    /// \endcode
    ///
    template <typename Derived>
    class context
    {
    public:
        context() {}
        ~context() {}

        /// Wait until all the steps prescribed by this context have completed
        /// execution.
        error_type wait()
        {
            return success;
        }

        void flush_gets() {}

        /// Reset all collections of this context
        void unsafe_reset() {}

    private:
        friend class boost::serialization::access;

        template <typename Archive>
        void serialize(Archive& ar, unsigned version)
        {
        }
    };
}

#endif
