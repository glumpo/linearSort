#ifndef TBTREENODE_H
#define TBTREENODE_H

#include <algorithm>
#include "tbtreeitem.h"

struct TBTreeNodeItem
{
    TBTreeNodeItem(TBTreeItem v) :
        Right(nullptr),
        val(v) {}
    TBTreeNodeItem* Right;
    TBTreeItem val;
};


class TBTreeNode
{
public:
    TBTreeNode() {
        root = nullptr;
    }
    TBTreeNodeItem *root;
    bool Push(const TBTreeItem v) {
        if (!root) {
            root = new TBTreeNodeItem(v);
            return bool(root);
        }

        auto newItem = new TBTreeNodeItem(v);
        bool isAllocSucsess = bool(newItem);
        auto cur = root;

        while (cur->val < newItem->val) {
            cur = cur->Right;
        }
        if (newItem->val < cur->val) {
            std::swap(cur, newItem);
            newItem->Right = cur;
            return isAllocSucsess;
        }
        else {
            return false;
        }

        // NOTE: It`s not needed, couse of if hiegher
        return isAllocSucsess;
    }

};

#endif // TBTREENODE_H
