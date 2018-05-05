#ifndef TBTREE_H
#define TBTREE_H

#include "tbtreeitem.h"
#include "tbtreenode.h"

class TBTree
{
public:
    static const size_t DEGREE = 2;
    inline size_t MaxNumOfElements() {
        return 2 * DEGREE - 1;
    }
    TBTree();
    ~TBTree();

    TBTreeItem::ValueType Search(TBTreeItem::KeyType k);
    TBTreeItem::ValueType    Pop(TBTreeItem::KeyType k);
    bool Insert(TBTreeItem item);
    bool Insert(TBTreeItem::KeyType k, TBTreeItem::ValueType v) {
        return Insert(TBTreeItem(k, v));
    }

private:
    TBTreeNode *root = nullptr;
};

#endif // TBTREE_H
