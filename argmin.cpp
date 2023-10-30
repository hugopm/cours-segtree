#include "segtree_bourrin.cpp"
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
struct node {
    int valeur, indice;
};

node neutre() {
    // return {???, ???};
}
node op(node x, node y) {
    // ???
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
    vector<node> segInit(N);
    for (int i = 0; i < N; i++) {
        segInit[i].valeur = /*???*/;
        segInit[i].indice = /*???*/;
        // ou segInit[i] = {.., ..}
    }
    segtree<node, op, neutre> seg(segInit);
    auto dbg = [&](int l, int r) {
        auto x = seg.requete(l, r);
        cout << "argmin " << l << " " << r << " : valeur=" << x.valeur;
        cout << ", indice=" << x.indice << '\n';
    };
    for (int i = 0; i + 3 <= N; ++i)
        dbg(i, i + 3);
}
