#include "lazy_bourrin.cpp"
#include <bits/stdc++.h>
#include <random>
using namespace std;

struct node {
    int somme, longueur;
};

node neutre() {
    // ?
}
node op(node x, node y) {
    // ?
}

struct fun {
    int delta;
};
node eval(fun f, node x) {
    // ?
}
fun composition(fun f, fun g) {
    // ?
}
fun id() {
    // ?
}

using Lazy = lazy_segtree<node, op, neutre, fun, eval, composition, id>;

void print_vector(vector<int> v) {
    for (auto &x : v)
        cout << (x < 10 ? "." : "") << x << ' ';
    cout << '\n';
}
int main() {
    mt19937 engine(42);
    int N = 10;
    vector<int> tableau(N);
    iota(tableau.begin(), tableau.end(), 0);
    auto tabId = tableau;
    shuffle(tableau.begin(), tableau.end(), engine);
    vector<node> segInit(N);
    for (int i = 0; i < N; i++) {
        segInit[i] = {tableau[i], 1};
    }
    Lazy seg(segInit);
    auto dbg = [&](int l, int r) {
        auto x = seg.requete(l, r);
        cout << "somme " << l << " " << r << " : somme=" << x.somme;
        cout << ", longueur=" << x.longueur << '\n';
        int sommeBrute = 0;
        for (int i = l; i < r; ++i)
            sommeBrute += tableau[i];
        assert(sommeBrute == x.somme);
        assert(x.longueur == r - l);
    };
    auto app = [&](int l, int r, int delta) {
        cout << "add " << delta << " to [" << l << ", " << r << ")\n";
        seg.appliquer(l, r, fun{delta});
        for (int j = l; j < r; ++j) {
            tableau[j] += delta;
        }
    };
    fun f{3};
    uniform_int_distribution<int> dist(0, N);
    for (int turn = 0; turn < 15; ++turn) {
        int l, r;
        do {
            l = dist(engine), r = dist(engine);
        } while (l >= r);

        app(l, r, dist(engine));
        print_vector(tabId);
        print_vector(tableau);
        do {
            l = dist(engine), r = dist(engine);
        } while (l >= r);
        if (l > r)
            swap(l, r);
        dbg(l, r);
        cout << "---\n";
    }
}
