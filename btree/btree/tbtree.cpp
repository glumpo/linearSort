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

TBTreeItem::ValueType TBTree::Search(TBTreeItem::KeyType k) {
    auto cur = root;
    TBTreeItem::ValueType candidateVal;
    TBTreeItem::KeyType   candidateKey;
    do {
        size_t i = 0;
        for (; i < cur->Size() && k > (*cur)[i].GetKey(); ++i)
            ;
        candidateKey = (*cur)[i].GetKey();
        candidateVal = (*cur)[i].GetVal();
    } while (k != candidateKey);
    return candidateVal;
}

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
        for (; i < cur->Size() && (*cur)[i] < item; ++i)
            ;
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
