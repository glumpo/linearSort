#include "tvectorbacketsort.h"

const double TVectorBacketSort::MAX_KEY = 100.0;
const double TVectorBacketSort::MIN_KEY = -100.0;

void TVectorBacketSort::Sort() {
    const size_t n = this->Size();
    TVector<TVectorNonLinerSort> buckets(n + 1);

    for (auto i = 0; i < n; ++i) {
        size_t index = (size_t) n * ((this->Data[i].Key - MIN_KEY) / (MAX_KEY - MIN_KEY));
        buckets[index].PushBack(TVectorItem(this->Data[i].Key, this->Data[i].Val));
    }

    for (auto i = 0; i < buckets.Size(); ++i) {
        buckets[i].Sort();
    }

    this->LastIndex = 0;
    for (auto i = 0; i < buckets.Size(); ++i) {
        for (auto j = 0; j < buckets[i].Size(); ++j) {
            this->PushBack(buckets[i][j]);
        }
    }
}

