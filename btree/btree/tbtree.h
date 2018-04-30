#ifndef TBTREE_H
#define TBTREE_H

#include "tbtreeitem.h"
#include "tbtreenode.h"

class TBTree
{
public:
    const auto T_OF_TREE = 2;
    TBTree();
    ~TBTree() {
        if (root) {
            /* Every item has a correct destructor,
             * so it will delete every object in a tree
             * recursively
             * NOTE: May be its better to delete manualy, without recursion. */
            for (int i = 0; i < root.Size(); ++i) {
                delete root[i];
            }
        }
    }

    TBTreeItem::ValueType Search(TBTreeItem::KeyType k);
    TBTreeItem::ValueType    Pop(TBTreeItem::KeyType k);
    bool Insert(TBTreeItem item);
    bool Insert(TBTreeItem::KeyType k, TBTreeItem::ValueType v) :
        Insert(TBTreeItem(k, v)) {}

private:
    TBTreeNode root = nullptr;
};

#endif // TBTREE_H
