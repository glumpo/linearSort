#ifndef TVECTORNONLINERSORT_H
#define TVECTORNONLINERSORT_H

#include "tvector.h"
#include "tvector.cpp"
#include "tvectoritem.h"


class TVectorNonLinerSort : public TVector<TVectorItem>
{
public:
    TVectorNonLinerSort() {}
    TVectorNonLinerSort(const int size) {}
    virtual ~TVectorNonLinerSort() {}

    void Sort();
};

#endif // TVECTORNONLINERSORT_H
