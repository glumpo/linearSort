#include "list.h"


template <class T>
bool TList<T>::Push(const T v) {
    if (!base) {
        base = new TListItem(v);
        ++Size;
        return bool(base);
    }

    auto newItem = new TListItem(v);
    bool isAllocSucsess = bool(newItem);
    auto cur = base;

    while (cur->val < newItem->val) {
        cur = cur->Right;
    }
    if (newItem->val < cur->val) {
        std::swap(cur, newItem);
        newItem->Right = cur;

        ++Size;
        return isAllocSucsess;
    }
    else {
        return false;
    }

    // NOTE: It`s not needed, couse of if hiegher
    return isAllocSucsess;
}


/*
 * Throws
 */
template <class T>
TListItem TList<T>::Pop(const size_t n) {
    if (this->GetSize() <= n) {
        throw std::out_of_range("TBTreeNode::Pop: size of list <= n");
    }

    if (0 == n) {
        auto      res = this->base->val;
        auto oldBase = this->base->val;
        this->base = this->base->Right;

        delete oldBase;
        return res;
    }

    // if n > 0
    auto preCur = this->base;
    for (size_t i = 0; i < n - 1; ++i) {
        preCur = preCur->Right;
    }
    auto cur = preCur->Right;
    auto res = cur->val;

    preCur->Right = cur->Right;
    delete cur;
    return res;

}

/*
 * Throws
 */
template <class T>
TListItem TList<T>::operator[](const size_t n) {
    if (this->GetSize() <= n) {
        throw std::out_of_range("TBTreeNode::operator[]: size of list <= n");
    }

    auto cur = this->base;
    for (size_t i = 0; i < n; ++i) {
        cur = cur->Right;
    }
    return cur->val;
}

template <class T>
size_t TList<T>::GetSize() {
    return this->Size;
}
