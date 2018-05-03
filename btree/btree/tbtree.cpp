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
    return (*root)[0].GetVal();
}

bool TBTree::Insert(TBTreeItem item) {
    if (!root) {
        root = new TBTreeNode();
        root->InsertInSorted(item);
        return true;
    }

}
