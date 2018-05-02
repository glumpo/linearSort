#include "list.h"

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
T& TList<T>::operator[](const size_t n) {
    if (this->GetSize() <= n) {
        throw std::out_of_range("TBTreeNode::operator[]: size of list <= n");
    }

    auto cur = this->base;
    for (size_t i = 0; i < n; ++i) {
        cur = cur->Right;
    }
    return cur->val;
}

template<class T>
bool TList::InsertBefore(T val, size_t n) {
    auto new_el = new TListItem<T>(v);
    if (!new_el) {
        return false;
    }

    if (0 == n) {
        new_el->Right = base;
        base = new_el;
        return true;
    }

    // if (n != 0)
    auto pre = base;
    for (int i = 0; i < n-1; ++i) {
        pre = pre->Right;
    }
    new_el->Right = pre->Right;
    pre->Right = new_el;

    return true;
}

template <class T>
size_t TList<T>::GetSize() {
    return this->Size;
}
