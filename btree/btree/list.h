#ifndef LIST_H
#define LIST_H

#include <algorithm>
#include <stdexcept>

template <class T>
struct TListItem
{
    TListItem(T v) :
        Right(nullptr),
        val(v) {}
    TListItem* Right;
    T val;
};


template <class T>
class TList
{
public:
    TList() {
        base = nullptr;
        Size = 0;
    }

    bool       Push(const T v);
    T Pop(const size_t n); // throws
    T operator[] (const size_t n); // throws
    typeof(Size) GetSize();

private:
    size_t Size;
    TListItem *base;

};

#endif // LIST_H
