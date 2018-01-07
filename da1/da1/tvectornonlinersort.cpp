#ifndef TVECTORNONLINERSORT_CPP
#define TVECTORNONLINERSORT_CPP

#include "tvectornonlinersort.h"

#include <vector>
#include "algorithm"

void TVectorNonLinerSort::Sort() {
    for (size_t i = 0; i < this->LastIndex; ++i) {
        size_t min_i = i;
        for (size_t j = i + 1; j < this->LastIndex; ++j) {
            if (this->Data[j] < this->Data[min_i]) {
                min_i = j;
            }
        }

        if (min_i != i) {
            auto tmp =  this->Data[i];
            this->Data[i] = this->Data[min_i];
            this->Data[min_i] = tmp;
        }
    }
}


#endif    // TVECTORNONLINERSORT_CPP
