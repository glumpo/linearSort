/*
 * 2-4
 * BTree
 * WORD : [0; 2^64 - 1]
 * WORD <= 256
 */

#include <iostream>

#include "tvector.h"
#include "tvector.cpp"

int main() {
    const auto n = 10000;
    TVector<int> test;
    for (int i = 0; i < n; ++i) {
        test.PushBack(i);
    }
    return 0;
}
