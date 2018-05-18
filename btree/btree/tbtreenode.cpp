#include "tbtreenode.h"


TBTreeNode::TBTreeNode(bool leaf) :
    Leaf(leaf)
{
    this->Items = (TNodeItem*)  malloc(sizeof(TNodeItem)  * ItemsSize);
    ItemsCount = 0;
}

size_t TBTreeNode::Size() {
    return ItemsCount;
}

TBTreeItem &TBTreeNode::operator[](const size_t n) {
    return Items[n].item;
}

TBTreeNode* TBTreeNode::LeftChild(const size_t n) {
    if (n == ItemsCount)
        return BiggestChild;
    return Items[n].child;
}

TBTreeNode* TBTreeNode::RightChild(const size_t n) {
    if (n == ItemsCount - 1)
        return BiggestChild;
    return Items[n].child;
}

/*
 * Binary Search
 * NOTE: If element not found,
 * Search returns index where element should be
 */
size_t TBTreeNode::Search(KeyType k) {
    if (0 == ItemsCount)
        return 0;

    // if not in items
    if (k < Items[0].Key()) {
        return 0;
    }
    else if (k > Items[ItemsCount - 1].Key()) {
        return ItemsCount;
    }

    /*
     *  NOTE: Bin search should return the right (the last) candidate, when not found
     */
    size_t l = 0;
    size_t r = ItemsCount - 1;
    size_t m = 0;
    while (l < r) {
        m = l + (r - l) / 2;
        if (k <= Items[m].Key())
            r = m;
        else
            l = m + 1;
    }
    return r;
}


size_t TBTreeNode::Insert(TBTreeItem ins) {
    size_t index = Search(ins.GetKey());
    AddItems(index);
    Items[index] = TNodeItem(ins, nullptr);
    return index;
}

TBTreeNode* TBTreeNode::Split() {
    auto newRoot = new TBTreeNode(false);
    auto left    = new TBTreeNode(this->Leaf);
    auto right   = this;

    const size_t n = (ItemsCount % 2 == 1)
                 ?   (ItemsCount / 2)
                 : ( (ItemsCount - 1) / 2);
    for (size_t i = 0; i <= n; ++i) {
        left->Items[i] = this->Items[i];
    }
    left->BiggestChild = this->Items[n].child;
    DelItems(0, n);

    newRoot->Insert(Items[0].item);
    DelItems(0);

    left->ItemsCount = n;
    newRoot->BiggestChild   = right;
    newRoot->Items[0].child = left;
    return newRoot;
}

void TBTreeNode::SplitLeftChild(size_t n) {
    auto tmpNode = LeftChild(n)->Split();
    AddItems(n);
    Items[n] = tmpNode->Items[0];
    if (n == ItemsCount - 1)
        BiggestChild = tmpNode->BiggestChild;
    else
        Items[n + 1].child = tmpNode->BiggestChild;
//    delete tmpNode;
}


bool TBTreeNode::DelItems(const size_t n, const size_t count /* count = 1 */) {
    size_t i = n;
    for (; i < ItemsCount - count; ++i) {
        Items[i] = Items[i + count];
    }
    ItemsCount -= count;
    return true;
}

bool TBTreeNode::AddItems(const size_t n,  const size_t count /* count = 1 */) {
    if (0 == ItemsCount) {
        ItemsCount += count;
        return true;
    }

    // FUCK THE UNSIGNED
    signed long long int i = ItemsCount - 1, signedN = n;
    for (; i >= signedN; --i) {
        Items[i + count] = Items[i];
    }
    ItemsCount += count;
    return true;
}
