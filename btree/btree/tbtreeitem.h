#ifndef TBTREEITEM_H
#define TBTREEITEM_H

#include "btree_options.h"

using namespace BTreeOptions;

class TBTreeItem
{
public:    
    TBTreeItem(KeyType key, ValueType val):
        Key(key),
        Value(val) {}
    ~TBTreeItem() {}

    bool operator< (const TBTreeItem &r) {
        return Key < r.Key;
    }
    bool operator== (const TBTreeItem &r) {
        return this->Key == r.Key;
    }
    bool operator!= (const TBTreeItem &r) {
        return !(*this == r);
    }

    inline ValueType GetVal() {
        return this->Value;
    }
    inline KeyType GetKey() {
        return this->Key;
    }

private:
    KeyType Key;
    ValueType Value;
};


#endif // TBTREEITEM_H
