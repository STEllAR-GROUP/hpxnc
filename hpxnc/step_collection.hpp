//  Copyright (c) 2015 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(HPXNC_STEP_COLLECTION)
#define HPXNC_STEP_COLLECTION

#include <hpxnc/config.hpp>
#include <hpxnc/context.hpp>

namespace hpxnc
{
    ///////////////////////////////////////////////////////////////////////////
    template <typename Tag, typename Item> class item_collection;
    template <typename Tag> class tag_collection;

    /// A step collection is logical set of step instances.
    ///
    /// A step-collection must be prescribed by a tag-collection and it can be
    /// part of consumer/producer relationships with item-collections.
    /// Additionally, it can be the controller in control-dependencies (e.g.
    /// produce tags).
    template <typename UserStep>
    class step_collection
    {
    public:
        typedef UserStep step_type;

        /// Constructor which registers collection with given context.
        template <typename Derived>
        explicit step_collection (context<Derived> &ctxt)
        {
        }

        template <typename Derived>
        step_collection (context<Derived> &ctxt, std::string const& name)
        {
        }

        template <typename Derived>
        step_collection (context<Derived> &ctxt, std::string const& name,
            step_type const &user_step)
        {
        }

        template <typename DataTag , typename Item>
        void consumes (item_collection<DataTag, Item> & items)
        {}

        template <typename DataTag, typename Item>
        void produces (item_collection<DataTag, Item> & items)
        {}

        template<typename ControlTag>
        void controls (tag_collection<ControlTag> & tags)
        {}
    };
}

#endif
