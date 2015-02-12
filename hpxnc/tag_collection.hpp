//  Copyright (c) 2015 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(HPXNC_TAG_COLLECTION)
#define HPXNC_TAG_COLLECTION

#include <hpxnc/config.hpp>
#include <hpxnc/context.hpp>

namespace hpxnc
{
    template <typename UserStep>
    class step_collection;

    /// A step collection is logical set of step instances.
    ///
    /// A step-collection must be prescribed by a tag-collection and it can be
    /// part of consumer/producer relationships with item-collections.
    /// Additionally, it can be the controller in control-dependencies (e.g.
    /// produce tags).
    template <typename Tag>
    class tag_collection
    {
    public:
        typedef Tag tag_type;
        typedef std::vector<Tag> tag_table_type;

        typedef typename tag_table_type::const_iterator const_iterator;

        /// Constructor which registers collection with given context.
        template <typename Derived>
        tag_collection (context<Derived> &ctxt)
        {
        }
        template <typename Derived>
        tag_collection (context<Derived> &ctxt, std::string const& name)
        {
        }

        /// Declare the prescription relationship between the tag collection
        /// and a step collection.
        template <typename UserStep, typename Arg>
        error_type  prescribes (step_collection<UserStep> const &s, Arg &arg)
        {
            return success;
        }

        /// Prescribe the associated step. If we are preserving tags for this
        /// collection, make a copy of the tag and store it in the collection.
        void put (Tag const &t)
        {}

        /// Prescribe an entire range of tags.
        void put_range (tag_table_type const& r)
        {}

        /// Returns begin() as in STL containers
        const_iterator begin() const
        {
            return const_iterator();
        }
        /// Returns end() as in STL containers
        const_iterator end() const
        {
            return const_iterator();
        }

        /// Removes all of the tag instances from the collection
        void unsafe_reset()
        {}

        /// Returns number of elements in collection
        size_t size() const
        {
            return tags_.size();
        }

        /// Returns true if size()==0, false otherwise
        bool empty() const
        {
            return tags_.empty();
        }

//         void on_put (callback_type *cb)
//         {}

    private:
        tag_table_type tags_;
    };
}

#endif
