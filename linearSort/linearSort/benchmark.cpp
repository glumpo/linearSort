#include <benchmark/benchmark.h>
#include <vector>
#include <algorithm>
#include <iostream>

#include "tvectorbacketsort.h"
#include "tvectoritem.h"

#include "includes/random.hpp"

const size_t NUMBER_OF_ELEMENTS = 100;

using Random = effolkronium::random_static;

void fill_random(TVectorBacketSort v, size_t n  = NUMBER_OF_ELEMENTS) {
    for (size_t i =  0; i < n; ++i) {
//        v.PushBack(TVectorItem(Random::get<double>(0.0, 100.0), 0));
        v.PushBack(TVectorItem(double(i), 0));
    }
}

void fill_random(std::vector<TVectorItem> v, size_t n = NUMBER_OF_ELEMENTS) {
    for (size_t i =  0; i < n; ++i) {
//        v.push_back(TVectorItem(Random::get<double>(0.0, 100.0), 0));
        v.push_back(TVectorItem(double(i), 0));
    }
}

static void BM_LinerSort(benchmark::State& state) {
    TVectorBacketSort v;
    fill_random(v, state.range(0));
    for (auto _ : state) {
        v.Sort();
    }
}
BENCHMARK(BM_LinerSort)->Arg(1000000000)->Iterations(1);

static void BM_QuickSort(benchmark::State& state) {
    std::vector<TVectorItem> v;
    fill_random(v, state.range(0));
    for (auto _ : state) {
        std::sort(v.begin(), v.end());
    }
}
BENCHMARK(BM_QuickSort)->Arg(1000000000)->Iterations(1);

BENCHMARK_MAIN()
