/*
 * 9:3
 * Bucket sort
 * Keys: Real [-100; 100]
 * Values: Numbers [0; 2^64 - 1]
 * */

/*
7.23 56
8.13 56
12.34 67
76.18 5
86.11 78
50.31 46
13.67 12
0.45 12
11.66 63
32 15

*/

#include <iostream>

#include "tvectorbacketsort.h"
#include "tvectoritem.h"

inline void read_input(TVectorBacketSort &inp) {
    double tmpKey = 0.0;
    unsigned long long int tmpVal = 0;
    while (scanf("%lf %llu", &tmpKey, &tmpVal) != EOF) {
        inp.PushBack(TVectorItem(tmpKey, tmpVal));
    }
}

/*
def f():
    for i in range(10):
        print("inp.PushBack(TVectorItem(" + str(uniform(-100, 100)) + ", " + str(randint(0, 200)) + "));")

*/
//inline void read_input(TVectorBacketSort &inp) {
//    inp.PushBack(TVectorItem(-62.418, 15));
//    inp.PushBack(TVectorItem(98.9, 58));
//    inp.PushBack(TVectorItem(-26.48, 97));
//    inp.PushBack(TVectorItem(85.07556872501999, 51));
//    inp.PushBack(TVectorItem(-69.01629690632045, 38));
//    inp.PushBack(TVectorItem(47.909106355143166, 112));
//    inp.PushBack(TVectorItem(-52.35925249586908, 91));
//    inp.PushBack(TVectorItem(-84.44638684337585, 120));
//    inp.PushBack(TVectorItem(14.210844612191394, 47));
//    inp.PushBack(TVectorItem(-2.0316282057300015, 197));
//}


int main() {
    TVectorBacketSort inp;
    read_input(inp);
    inp.Sort();
    for (auto i = 0; i < inp.Size(); ++i) {
        printf("%.6lf %llu\n", inp[i].Key, inp[i].Val);
    }
    return 0;
}
