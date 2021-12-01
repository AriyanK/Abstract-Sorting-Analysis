#ifndef Algorithms
#define Algorithms

template <class ForwardIterator, class T>
ForwardIterator find( ForwardIterator first, ForwardIterator last, const T& value )
{
    while( first != last ) {
        if( *first == value ) {
            return first;
        }
        ++first;
    }
    return last;
}

template <typename RAiterator>
void myInsertionSort(RAiterator begin, RAiterator end){
    std::iter_swap(begin, std::min_element(begin, end));
    for (RAiterator it = begin; ++it < end; begin = it)
        for (RAiterator c = it; *c < *begin; --c, --begin)
            std::iter_swap(begin, c);
}

template <typename RAiterator>
void myQuickSort(RAiterator begin, RAiterator end) {
    if (end <= begin)
        return;
    RAiterator pivot = begin;
    RAiterator middle = begin + 1;
    for (RAiterator i = begin + 1; i < end; i++) {
        if (*i < *pivot) {
            std::iter_swap(i, middle);
            middle++;
        }
    }
    std::iter_swap(begin, middle - 1);
    myQuickSort(begin, middle - 1);
    myQuickSort(middle, end);
}

template <typename RAiterator>
void myHeapSort(RAiterator begin, RAiterator end) {
    while (begin != end)
        std::pop_heap(begin, end--);
}


#endif //Algorithms
