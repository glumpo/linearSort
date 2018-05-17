#ifndef TBTREE_H
#define TBTREE_H

#include "tbtreeitem.h"
#include "tbtreenode.h"
#include "btree_options.h"

using namespace BTreeOptions;

class TBTreeNode;

class TBTree
{
private:
    TBTreeNode *root = nullptr;

    /*
     * Returns true if find ad false if not in tree
     * If not in tree, res, child_n and n point on place, where should be
     */
    bool FindParent(KeyType    key,
                    TBTreeNode *&res, TBTreeNode *&cur,
                    size_t     &child_n,
                    size_t     &n);

public:
    TBTree();
    ~TBTree();

    ValueType Search(KeyType k);
    ValueType    Pop(KeyType k);
    bool Insert(TBTreeItem item);
    bool Insert(KeyType k, ValueType v) {
        return Insert(TBTreeItem(k, v));
    }
};

#endif // TBTREE_H
