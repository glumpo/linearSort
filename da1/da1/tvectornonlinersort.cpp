#ifndef TVECTORNONLINERSORT_CPP
#define TVECTORNONLINERSORT_CPP

#include "tvectornonlinersort.h"

#define SWAP(x,y) do { \
    auto tmp = (x); \
    (x) = (y); \
    (y) = tmp; \
    } while(0);

/*
 * Selection Sort.
 * UNSTABLE!!!
 */
//void TVectorNonLinerSort::Sort() {
//    for (size_t i = 0; i < this->LastIndex; ++i) {
//        size_t min_i = i;
//        for (size_t j = i + 1; j < this->LastIndex; ++j) {
//            if (this->Data[j] < this->Data[min_i]) {
//                min_i = j;
//            }
//        }

//        if (min_i != i) {
//            auto tmp =  this->Data[i];
//            this->Data[i] = this->Data[min_i];
//            this->Data[min_i] = tmp;
//        }
//    }
//}

/*
 * Shaker Sort.
 */
void TVectorNonLinerSort::Sort() {
    if (this->Size() <= 1) {
        return;
    }
    for (size_t li = 0, ri = this->Size() - 1; li < ri;) {
        for (size_t i = li; i < ri; ++i) {
            if (this->Data[i + 1] < this->Data[i]) {
                SWAP(this->Data[i + 1], this->Data[i]);
            }
        }
        --ri;

        for (size_t i = ri; i > li; --i) {
            if (this->Data[i - 1] > this->Data[i]) {
                SWAP(this->Data[i - 1], this->Data[i]);
            }
        }
        ++li;
    }
}


#endif    // TVECTORNONLINERSORT_CPP
