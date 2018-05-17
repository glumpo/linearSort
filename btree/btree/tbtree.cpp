#include "tbtree.h"


// That will split all full nodes on the way
bool TBTree::FindParent(KeyType    key,
                        TBTreeNode *(&res),
                        TBTreeNode *(&cur),
                        size_t     &childN,
                        size_t     &n) {
    res    = nullptr;
    cur    = root;
    childN = 0;
    n      = 0;

    if (nullptr == root) {
        return false;
    }

    if (0 == root->Size()) {
        return false;
    }

    if (MAX_NUM_OF_ELEMENTS <= root->Size()) {
        auto newRoot = root->Split();
        root = newRoot;
        cur = root;
    }
    // TODO: Add spliting
    // returns nullptr if element in root
    childN = root->Search(key);
    if (childN < root->Size() && (*root)[childN].GetKey() == key) {
        n = childN;
        return true;
    }

    if (root->Leaf) {
        n = childN;
        return false;
    }

    cur = root->LeftChild(childN);
    n   = cur->Search(key);
    res = root;

    while ((*cur)[n].GetKey() != key && cur->Leaf == false) {
        res     = cur;
        childN = n;
        cur = cur->LeftChild(childN);
        n = cur->Search(key);
    }
    return true;
}

TBTree::TBTree() {}

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

ValueType TBTree::Search(KeyType k) {
    TBTreeNode *parent = nullptr, *cur = nullptr;
    size_t childN = 0, n = 0;

    FindParent(k, parent, cur, childN, n);
    return (*cur)[n].GetVal();
}

bool TBTree::Insert(TBTreeItem item) {
    if (!root) {
        root = new TBTreeNode(true);
    }

    if (MAX_NUM_OF_ELEMENTS <= root->Size()) {
        root = root->Split();
    }

    TBTreeNode *parent = nullptr, *cur = nullptr;
    size_t childN = 0, n = 0;

    FindParent(item.GetKey(), parent, cur, childN, n);
    cur->Insert(item);

    if (MAX_NUM_OF_ELEMENTS <= cur->Size()) {
        if (parent)
            parent->SplitLeftChild(childN);
    }

    return true;
}
