//  Copyright (c) 2015 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(HPXNC_ITEM_COLLECTION)
#define HPXNC_ITEM_COLLECTION

#include <hpxnc/config.hpp>
#include <hpxnc/context.hpp>

#include <hpx/include/lcos.hpp>
#include <hpx/include/unordered_map.hpp>

namespace hpxnc
{
    /// An item collection is a mapping from tags to items.
    ///
    /// Tag and Item must provide copy and default constructors and the
    /// assignment operator.
    ///
    /// The HPXnC runtime will make a copy of your item when it is 'put' into
    /// the item_collection. The HPXnC runtime will delete the copied item copy
    /// once the get-count reaches 0 (or, if no get-count was provided, once
    /// the collection is destroyed). If the item-type is a pointer type, the
    /// runtime will not delete the memory the item points to. If you store
    /// pointers, you have to care for the appropriate garbage collection,
    /// e.g. you might consider using smart pointers.
    template <typename Tag, typename Item>
    class item_collection
    {
    public:
        template <typename Derived>
        explicit item_collection (context<Derived> &ctxt)
        {
        }
        template <typename Derived>
        item_collection (context<Derived> &ctxt, std::string const& name)
        {
        }

        /// Declares the maximum tag value.
        void set_max(std::size_t max_tag_value) {}

        /// make copies of the item and the tag and store them in the
        /// collection.
        hpx::future<void> put(Tag const& tag, Item const& item)
        {
            return hpx::make_ready_future();
        }
        hpx::future<void> put(Tag const& tag, hpx::future<Item> && item)
        {
            return hpx::make_ready_future();
        }
        hpx::future<void> put(Tag const& tag, hpx::shared_future<Item> item)
        {
            return hpx::make_ready_future();
        }

        /// get an item
        hpx::future<Item> get(Tag const& tag) const
        {
            return hpx::make_ready_future(Item());
        }

        /// try to get an item and store it in given object (non-blocking)
        bool unsafe_get(Tag const& tag, Item& item) const { return false; }

        /// removes all of the item instances from the collection
        void unsafe_reset() {}

        /// returns number of elements in collection
        std::size_t size() const { return 0; }

        /// returns true if size() == 0, false otherwise
        bool empty() const { return true; }

    private:
        hpx::unordered_map<Tag, Item> items_;
    };
}

#endif
