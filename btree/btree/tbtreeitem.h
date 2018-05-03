#ifndef TBTREEITEM_H
#define TBTREEITEM_H

class TBTreeItem
{
public:
    typedef int    KeyType;
    typedef double ValueType;

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

    ValueType GetVal() {
        return this->Value;
    }

private:
    KeyType Key;
    ValueType Value;
};

#endif // TBTREEITEM_H
