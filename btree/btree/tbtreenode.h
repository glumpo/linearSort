#ifndef TBTREENODE_H
#define TBTREENODE_H

#include "list.h"
#include "tbtreeitem.h"

class TBTreeNode
{
public:
    size_t Size();
    TBTreeItem& operator[] (size_t n);
    TBTreeNode LeftChild(size_t n);
    TBTreeNode RightChild(size_t n);

    // Throws
    TBTreeItem Pop(size_t n);
    bool InsertBefore(TBTreeItem val, size_t n);
    bool InsertInSorted(const TBTreeItem val);


private:
    // WARNING: Be carefull with associated lists
    TList<TBTreeItem> items;
    TList<TBTreeNode*> children;

    /* LeftChildIndex */
    size_t LCI(size_t item_index);
    /* RightChildIndex */
    size_t RCI(size_t item_index);
};

#endif // TBTREENODE_H
