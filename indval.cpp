#include "segtree.cpp"
#include <bits/stdc++.h>
#include <random>
using namespace std;

struct node {
    int sumIndVal, sumVal, cnt;
};
node neutre() { return {0, 0, 0}; }
node sing(int x) { return {x, x, 1}; }
node op(node x, node y) {
    return {x.sumIndVal + y.sumIndVal + x.cnt * y.sumVal, x.sumVal + y.sumVal,
            x.cnt + y.cnt};
}

template <typename T> void print_vector(vector<T> v) {
    for (T &x : v)
        cout << x << ' ';
    cout << '\n';
}

int main() {
    mt19937 engine(42);
    int N = 10;
    vector<int> tableau(N);
    iota(tableau.begin(), tableau.end(), 0);
    print_vector(tableau);
    shuffle(tableau.begin(), tableau.end(), engine);
    print_vector(tableau);
    vector<node> segInit;
    for (int x : tableau)
        segInit.push_back(sing(x));
    segtree<node, op, neutre> seg(segInit);
    auto dbg = [&](int l, int r) {
        auto x = seg.requete(l, r);
        cout << "sumindval(" << l << ", " << r << ") : " << x.sumIndVal << '\n';
    };
    for (int i = 0; i < N; ++i)
        dbg(i, i + uniform_int_distribution<int>(0, N - i)(engine) % (N - i));
}
