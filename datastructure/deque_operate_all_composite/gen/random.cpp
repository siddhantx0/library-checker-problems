#include "random.h"
#include <iostream>

using namespace std;

const int MOD = 998244353;
const int Q_MAX = 500'000;

int main(int, char* argv[]) {
    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    int q = gen.uniform(1, Q_MAX);
    printf("%d\n", q);

    int length = 0;
    for (int i = 0; i < q; i++) {
        const int table[4] = { 0, 0, 1, 2 };
        int t = table[gen.uniform(0, 4 - 1)];
        int t2 = gen.uniform(0, 1);
        if (length == 0 and t == 1) {
            t = 0;
        }
        t = t * 2 + t2; if(t == 5) t = 4;
        printf("%d", t);
        if (t == 0 || t == 1) {
            int a = gen.uniform(1, MOD - 1);
            int b = gen.uniform(0, MOD - 1);
            printf(" %d %d", a, b);
            length++;
        } else if (t == 2 || t == 3) {
            length--;
        } else {
            int x = gen.uniform(0, MOD - 1);
            printf(" %d", x);
        }
        printf("\n");
    }
    return 0;
}
