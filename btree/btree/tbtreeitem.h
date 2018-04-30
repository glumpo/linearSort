#ifndef TBTREEITEM_H
#define TBTREEITEM_H

#include "tbtreenode.h"

class TBTreeItem
{
public:
    typedef int    KeyType;
    typedef double ValueType;

    TBTreeItem(KeyType key, ValueType val):
        Key(key),
        Value(val) {}
    ~TBTreeItem() {
        // NOTE: Checkes is redundant since C++14 can deal with delete nullptr
        if (Left)
            delete Left;
        if (Right)
            delete Right;
    }

    bool operator< (const TBTreeItem &l, const TBTreeItem &r) {
        return l.Key < r.Key;
    }
    bool operator== (const TBTreeItem &r) {
        return this->Key == r.Key;
    }
    bool operator!= (const TBTreeItem &r) {
        return !(*this == r);
    }

    TBTreeNode *Left;
    TBTreeNode *Right;

private:
    KeyType Key;
    ValueType Value;
};

#endif // TBTREEITEM_H
