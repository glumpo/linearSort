#include "tbtreenode.h"


TBTreeNode::TBTreeNode(size_t size, bool leaf) :
    Leaf(leaf),
    ItemsSize(size)
{
    this->Items = malloc(sizeof(TNodeItem)  * ItemsSize);
    ItemsCount  = 0;
}

size_t TBTreeNode::Size() {
    return ItemsCount;
}

TBTreeItem &TBTreeNode::operator[](const size_t n) {
    return Items[n].item;
}

TBTreeNode* TBTreeNode::LeftChild(const size_t n) {
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
size_t TBTreeNode::Search(TBTreeItem::KeyType k) {
    if (0 == ItemsCount)
        return 0;

    // if not in items
    if (k < Items[0].Key()) {
        return 0;
    }
    else if (k > Items[ItemsCount - 1].Key()) {
        return ItemsCount;
    }

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
    return last;
}

TBTreeItem TBTreeNode::Pop(size_t n) {
    auto res = items[n];
    DelItems(n);
    --ItemsCount;
    return res;
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
        left->Insert(Items[i]);
    }
    DelItems(0, n);
    left->ItemsCount += n;
    this->ItemsCount -= n;

    newRoot->Insert(Items[0]);
    DelItems(0);

    newRoot->BiggestChild   = right;
    newRoot->Items[0].child = left;
    return newRoot;
}

void TBTreeNode::SplitLeftChild(size_t n) {
    auto tmpNode = LeftChild(n)->Split();
    AddItems(n);
    Items[n] = tmpNode->Items[0];
    Items[n + 1].child = tmpNode->BiggestChild;
    delete tmpNode;
}


bool TBTreeNode::DelItems(size_t n, size_t count = 1) {
    size_t i = n;
    for (; i < ItemsCount - count; ++i) {
        Items[i] = Items[i + count];
    }
    ItemsCount -= count;
    return true;
}

bool TBTreeNode::AddItems(size_t n, size_t count = 1) {
    size_t i = ItemsCount - 1;
    for (; i >= n; --i) {
        Items[i + count] = Items[i];
    }
    ItemsCount += count;
    return true;
}
