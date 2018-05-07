/*
 * 2-4
 * BTree
 * WORD : [0; 2^64 - 1]
 * WORD <= 256
 */

#include <iostream>

#include "tbtree.h"
#include "list.h"

int main() {
    std::cout << "Starting test" << std::endl;
    TBTree test = TBTree();
    std::cout << "Created" <<  std::endl;
    test.Insert(4,4.4);
    test.Insert(2,2.2);
    test.Insert(3,3.3);
    test.Insert(1,1.1);
    test.Insert(5,5.5);

    test.Insert(6,6.6);
    test.Insert(7,6.6);
    std::cout << "Iserted" <<  std::endl;;
    std::cout << test.Search(7) <<  std::endl;
    std::cout << "Exiting" <<  std::endl;

//    TList<TBTreeItem> test;
//    test.InsertBefore(TBTreeItem(0,0), 0);
//    test.InsertBefore(TBTreeItem(1,1), 1);
//    test.InsertBefore(TBTreeItem(2,2), 2);
//    test.InsertBefore(TBTreeItem(3,3), 3);

    return 0;
}
