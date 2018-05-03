#include "tbtree.h"

TBTree::TBTree() {

}

TBTree::~TBTree() {
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

bool TBTree::Insert(TBTreeItem item) {
    if (!root) {
        root = new TBTreeNode();
    }

}
