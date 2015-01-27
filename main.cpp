#include <vector>
#include <random>
#include <cstdio>
#include <algorithm>

#include "podstuff.h"

using namespace std;

mt19937_64 gen;
normal_distribution<float>      nd(3,   1);
uniform_int_distribution<int>  uid(1,1000);
uniform_int_distribution<long> uld(1,1000);

struct mypod {
    int a;
    float b;
    long c;

    long d() const {
        return a+c;
    }
};

void printpod(const vector<mypod>& data) {
    for(const mypod& mp : data) {
        printf("%d\t%2.4f\t%d\t%d\n", mp.a, mp.b, mp.c, mp.d());
    }
    printf("\n");
}

int main(int argc, char** argv) {
    vector<mypod> data;
    int N = 100;
    for(int i = 0; i < N; i++) {
        mypod elem = {uid(gen), nd(gen), uld(gen)};
        data.emplace_back( elem );
    }

    printf("random\n");
    printpod(data);
    printf("sort by(a)\n");
    sort(begin(data),end(data), by(&mypod::a));
    printpod(data);
    printf("sort by(b)\n");
    sort(begin(data),end(data), by(&mypod::b));
    printpod(data);
    printf("sort by(c)\n");
    sort(begin(data),end(data), by(&mypod::c));
    printpod(data);
    printf("sort by(d)\n");
    sort(begin(data),end(data), by(&mypod::d));
    printpod(data);
}
