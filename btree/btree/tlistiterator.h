#ifndef TLISTITERATOR_H
#define TLISTITERATOR_H

#include <stddef.h>

template <class node, class T>
class TListIterator
{
public:
    TListIterator(node *n) {
        this->curent_ptr = n;
        this->index = 0;
    }
    virtual ~TListIterator() {}

    // TODO: delete code duplication on * and ->
    T& operator *() {
        return this->curent_ptr->val;
    }

    T& operator ->() {
        return this->curent_ptr->val;
    }

    void step_forward() {
        curent_ptr = curent_ptr->Right;
    }

    TListIterator operator ++() {
        ++index;
        step_forward();
        return *this;
    }

    TListIterator operator ++(int) {
        auto cur = *this;
        ++index;
        step_forward();
        return cur;
    }

    bool operator ==(TListIterator r) {
        return this->curent_ptr == r.curent_ptr;
    }
    bool operator !=(TListIterator r) {
        return !(*this == r);
    }

    size_t getIndex() {
        return index;
    }

private:
    size_t index;
    node *curent_ptr;
};

#endif // TLISTITERATOR_H
