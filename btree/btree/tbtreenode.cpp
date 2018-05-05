#include "tbtreenode.h"


TBTreeNode::TBTreeNode(bool leaf) {
    this->Leaf = leaf;
}

size_t TBTreeNode::Size() {
    return this->items.GetSize();
}

TBTreeItem &TBTreeNode::operator[](size_t n) {
    return items[n];
}

TBTreeNode* TBTreeNode::LeftChild(size_t n) {
    return children[this->LCI(n)];
}

TBTreeNode* TBTreeNode::RightChild(size_t n) {
    return children[RCI(n)];
}

TBTreeItem TBTreeNode::Pop(size_t n) {
    auto l = this->LCI(n);
    auto r = this->RCI(n);

    children.Pop(l);
    children.Pop(r);
    return items.Pop(n);
}

bool TBTreeNode::InsertBefore(TBTreeItem val, size_t n) {
    this->items.InsertBefore(val, n);
    this->children.InsertBefore(nullptr, this->LCI(n));
    this->children.InsertBefore(nullptr, this->RCI(n));
    return true;
}

size_t TBTreeNode::InsertInSorted(TBTreeItem ins) {
    size_t i = 0;
    for (; i < items.GetSize() && ins < items[i]; ++i)
        ;
    InsertBefore(ins, i);
    return i;
}

TBTreeNode* TBTreeNode::Split(bool leaf) {
    auto newRoot = new TBTreeNode(false);
    auto left    = new TBTreeNode(leaf);
    auto right   = this;
    right->Leaf  = leaf;

    left->items.TakeAway(items, 0, items.GetSize() / 2 - 1);
    left->children.TakeAway(children, 0, children.GetSize() / 2 - 1);

    newRoot->InsertInSorted(this->Pop(0));
    newRoot->children[LCI(0)] = left;
    newRoot->children[RCI(0)] = right;

    return newRoot;
}

void TBTreeNode::SplitLeftChild(size_t n) {
    auto left     = new TBTreeNode(true);
    auto right    = this;
    auto oldChild = this->children.Pop(LCI(n));

    left->items.TakeAway(oldChild->items, 0, oldChild->items.GetSize() / 2 - 1);
    left->children.TakeAway(oldChild->children, 0, oldChild->children.GetSize() / 2 - 1);

    this->InsertBefore(oldChild->Pop(0), n);
    this->children[LCI(n)] = left;
    this->children[RCI(n)] = right;
}

size_t TBTreeNode::LCI(size_t item_index) {
    return item_index;
}

size_t TBTreeNode::RCI(size_t item_index) {
    return item_index + 1;
}
