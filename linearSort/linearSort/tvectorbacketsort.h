#ifndef TVECTORBACKETSORT_H
#define TVECTORBACKETSORT_H

#include "tvector.h"
#include "tvector.cpp"

#include "tvectornonlinersort.h"


class TVectorBacketSort : public TVector<TVectorItem>
{
public:
    TVectorBacketSort() {}
    TVectorBacketSort(const int size) {}
    virtual ~TVectorBacketSort() {}

    void Sort();
    static const double MIN_KEY;
    static const double MAX_KEY;

};

#endif // TVECTORBACKETSORT_H
