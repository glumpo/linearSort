#ifndef TVECTOR_H
#define TVECTOR_H

#include <malloc.h>
#include <exception>

#include "tvectoritem.h"

template <class T>
class TVector
{
public:
    TVector(const int size);
    TVector() : TVector(0) {}
    virtual ~TVector();

    bool PushBack(T el);
    T &operator [](unsigned int index);
    size_t Size();

protected:
    T *Data;
    unsigned int RealSize;
    unsigned int LastIndex;
    static const unsigned int STEP = 2;
};

#endif // TVECTOR_H
