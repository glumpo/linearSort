#include "tbtree.h"

TBTree::TBTree() {

}

bool TBTree::Insert(TBTreeItem item) {
    if (!root) {
        root = new TBTreeNode();
        return root.Push(item);
    }


}
