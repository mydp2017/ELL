////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  [projectName]
//  File:     StlIndexValueIterator.h (types)
//  Authors:  Chuck Jacobs
//
//  [copyright]
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "types.h"

// stl
#include <vector>

namespace types
{
    /// <summary> A read-only forward index-value iterator for an STL container </summary>

    template <typename IteratorType, typename ValueType = decltype(*std::declval<IteratorType>())>
    class StlIndexValueIterator: public IIndexValueIterator
    {
    public:
        /// <summary> Constructs an instance of StlIndexValueIterator. </summary>
        ///
        /// <param name="begin"> STL iterator pointing at beginning of range to iterate over </param>
        /// <param name="end"> STL iterator pointing at end of range to iterate over </param>
        StlIndexValueIterator(const IteratorType& begin, const IteratorType& end);

        /// <summary> \returns True if the iterator is currently pointing to a valid iterate. </summary>
        ///
        /// <returns> True if the iterator is currently pointing to a valid iterate. </returns>
        bool IsValid() const;

        /// <summary> Proceeds to the Next iterate </summary>
        void Next();

        /// <summary> \returns The current index-value pair </summary>
        ///
        /// <returns> The current index-value pair </returns>
        IndexValue Get() const;

    protected:
        IteratorType _begin;
        IteratorType _end;
        uint64 _index = 0;
        void SkipZeros();
    };

    /// <summary> Handy type alias for a StlIndexValueIterator over a std::vector </summary>
    template <typename ValueType>
    using VectorIndexValueIterator = StlIndexValueIterator<typename std::vector<ValueType>::const_iterator, ValueType>;

    /// <summary> Creates an StlIndexValueIteratorAdapter for a std::vector </summary>
    ///
    /// <param name="container"> A std::vector to iterate over </param>
    /// <returns> An StlIndexValueIteratorAdapter that iterates over the given vector </returns>
    template <typename ValueType>
    VectorIndexValueIterator<ValueType> MakeStlIndexValueIterator(const std::vector<ValueType>& container);
}


#include "../tcc/StlIndexValueIterator.tcc"