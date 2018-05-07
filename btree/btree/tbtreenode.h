#ifndef TBTREENODE_H
#define TBTREENODE_H

#include "list.h"
#include "list.cpp"
#include "tbtreeitem.h"

class TBTreeNode
{
private:
    // WARNING: Be carefull with associated lists
    TList<TBTreeItem> items;
    TList<TBTreeNode*> children;

    /* Left Child Index */
    size_t LCI(size_t item_index);
    /* Right Child Index */
    size_t RCI(size_t item_index);

public:
    TBTreeNode(bool leaf);

//    TODO: Rewrite all using of operator[]
//    or make a cash for prev element of operator[]
//    to archive O(n) on search
    size_t Size();
    TBTreeItem& operator[] (size_t n);
    TBTreeNode* LeftChild(size_t n);
    TBTreeNode* RightChild(size_t n);

    // Throws
    TBTreeItem Pop(size_t n);
    bool InsertBefore(TBTreeItem val, size_t n);
    size_t InsertInSorted(TBTreeItem ins);
    void SplitLeftChild(size_t n);
    TBTreeNode *Split(bool leaf);

    // auto used to avoid usig TList realisation details
    decltype(items.begin()) begin();
    decltype(items.end())   end();

    bool Leaf;
};

#endif // TBTREENODE_H
