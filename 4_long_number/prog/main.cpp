#include <iostream>
#include <vector>

using namespace std;

// (a ^ p) mod m
int binpow(int a, int p, int m) {
    int cur = a;
    int ans = 1;
    while (p > 0) {
        if (p & 1) {
            ans = (ans * 1ll * cur) % m;
        }
        cur = (cur * 1ll * cur) % m;
        p >>= 1;
    }
    return ans;
}

int main() {
    for (int n = 1e8; n < 1e9; ++n) {
        if (n % 512 != 0) continue;
        if (binpow(2, n, 1e9) == n) {
            cout << n;
            break;
        }
    }
}
