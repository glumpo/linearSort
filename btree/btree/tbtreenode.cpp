#include "tbtreenode.h"


size_t TBTreeNode::Size() {
    return this->items.GetSize();
}

TBTreeItem &TBTreeNode::operator[](size_t n) {
    return items[n];
}

TBTreeNode TBTreeNode::LeftChild(size_t n) {
    return children[this->LCI(n)];
}

TBTreeNode TBTreeNode::RightChild(size_t n) {
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
    auto l = new TBTreeNode();
    auto r = new TBTreeNode();
    this->children.InsertBefore(l, this->LCI(n));
    this->children.InsertBefore(r, this->RCI(n));
    return true;
}

bool TBTreeNode::InsertInSorted(const TBTreeItem val) {
    size_t i = 0;
    for (; i < items.GetSize() && val < items[i]; ++i)
        ;
    InsertBefore(val, i);
    return true;
}

void TBTreeNode::SplitLeftChild(size_t n) {
    auto left = new TBTreeNode();
    auto right= new TBTreeNode();
    auto oldChild = this->children.Pop(LCI(n));

    left->items.TakeAway(oldChild->items, 0, oldChild->items.GetSize() / 2 - 1);
    left->children.TakeAway(oldChild->children, 0, oldChild->children.GetSize() / 2 - 1);

    this->InsertBefore(oldChild->Pop(0), n);

    right->items.TakeAway(oldChild->items, 0, oldChild->items.GetSize());
    right->children.TakeAway(oldChild->children, 0, oldChild->children.GetSize());
}

size_t TBTreeNode::LCI(size_t item_index) {
    return item_index;
}

size_t TBTreeNode::RCI(size_t item_index) {
    return item_index + 1;
}
