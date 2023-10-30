#include <vector>
using namespace std;

// Remarque : le lazy bourrin n'utilise pas l'oracle de composition
template <class node, node (*op)(node, node), node (*neutre)(), class fun,
          node (*eval)(fun, node), fun (*composition)(fun, fun), fun (*id)()>
class lazy_segtree {
  public:
    lazy_segtree(vector<node> tableau) {
        N = tableau.size();
        noeuds = tableau;
    }
    /// a[deb] + a[deb+1] + ... + a[fin-1]
    node requete(int debutInclus, int finExclus) {
        node somme = neutre();
        for (int i = debutInclus; i < finExclus; ++i) {
            somme = op(somme, noeuds[i]);
        }
        return somme;
    }
    /// a[i] := f(a[i]) pour deb <= i <= fin
    void appliquer(int debutInclus, int finExclus, fun fct) {
        for (int i = debutInclus; i < finExclus; ++i) {
            noeuds[i] = eval(fct, noeuds[i]);
        }
    }

  private:
    int N;
    vector<node> noeuds;
};
