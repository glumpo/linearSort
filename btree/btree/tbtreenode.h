#ifndef TBTREENODE_H
#define TBTREENODE_H

#include "list.h"
#include "list.cpp"
#include "tbtreeitem.h"


struct TNodeItem
{
    TNodeItem(TBTreeItem i, TBTreeNode *ch) :
        item(i),
        child(ch)
    {}
    TBTreeItem item;
    TBTreeNode *child;

    inline TBTreeItem::KeyType Key() {
        return item.GetKey();
    }
    inline TBTreeItem::ValueType Val() {
        return item.GetVal();
    }
};

class TBTreeNode
{
private:
    // WARNING: Be carefull with associated arrays
    TNodeItem Items[];
    TBTreeNode *BiggestChild;

    const size_t ItemsSize;
    size_t       ItemsCount;

    bool DelItems(size_t n, size_t count = 1);
    bool AddItems(size_t n, size_t count = 1);
public:
    TBTreeNode(size_t size, bool leaf);

    size_t Size();
    TBTreeItem& operator[] (const size_t n);
    TBTreeItem Pop(size_t n);

    TBTreeNode* LeftChild(const size_t n);
    TBTreeNode* RightChild(const size_t n);

    size_t Search(TBTreeItem::KeyType k);
    size_t Insert(TBTreeItem ins);

    void SplitLeftChild(size_t n);
    TBTreeNode *Split(bool leaf);

    // decltype used to avoid usig TList realisation details
    decltype(items.begin()) begin();
    decltype(items.end())   end();

    bool Leaf;
};

#endif // TBTREENODE_H
