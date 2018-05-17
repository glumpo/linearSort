#ifndef BTREE_OPTIONS_H
#define BTREE_OPTIONS_H

#include <stddef.h>

namespace BTreeOptions {

const size_t DEGREE = 2;
const size_t MAX_NUM_OF_ELEMENTS = 2 * DEGREE - 1;

typedef int     KeyType;
typedef double  ValueType;
const KeyType   KEY_NULL   = 0;
const ValueType VALUE_NULL = 0.0;

template <class T>
inline T GetNull() {
    return 0;
}

template <>
inline KeyType GetNull() {
    return KEY_NULL;
}

template <>
inline ValueType GetNull() {
    return VALUE_NULL;
}
}

#endif // BTREE_OPTIONS_H
