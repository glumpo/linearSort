#include "tbtree.h"

TBTree::TBTree() {

}

TBTree::~TBTree() {
    if (root) {
        /* Every item has a correct destructor,
             * so it will delete every object in a tree
             * recursively
             * NOTE: May be its better to delete manualy, without recursion. */
//        for (size_t i = 0; i < root->Size(); ++i) {
//            delete &((*root)[i]);
//        }
    }
}

// FIXME: Now searches only in first node
TBTreeItem::ValueType TBTree::Search(TBTreeItem::KeyType k) {
    auto curNode = root;

    while (true) {
        auto it = curNode->begin();
        for (; it != curNode->end(); ++it) {
            if ((*it).GetKey() >= k)
                break;
        }

        if (curNode->Size() == it.getIndex()) {
            curNode = curNode->RightChild(it.getIndex() - 1);
        }
        else if ((*it).GetKey() == k) {
            return (*it).GetVal();
        }
        else if ((*it).GetKey() > k) {
            curNode = curNode->LeftChild(it.getIndex());
        }
        else {
            curNode = curNode->RightChild(it.getIndex());
        }
    }
    return 0;
}

// TODO: Delete operator[], use iterator
bool TBTree::Insert(TBTreeItem item) {
    if (!root) {
        root = new TBTreeNode(true);
    }

    if (MaxNumOfElements() <= root->Size()) {
        root = root->Split(root->Leaf);
    }

    auto cur = root;
    auto prev = cur;
    while (true != cur->Leaf) {
        size_t i = 0;
        for (auto it : *cur) {
            if (item < it)
                break;
            ++i;
        }

        if (cur->Size() == i)
            --i;

        prev = cur;
        if (item < (*cur)[i]) {
            cur = cur->LeftChild(i);
            if (MaxNumOfElements() <= cur->Size()) {
                prev->SplitLeftChild(i);
                cur = prev;
                continue;
            }
        }
        else {
            cur = cur->RightChild(i);
            if (MaxNumOfElements() <= cur->Size()) {
                prev->SplitLeftChild(i + 1);
                cur = prev;
                continue;
            }
        }
    }
    cur->InsertInSorted(item);
    return true;
}
