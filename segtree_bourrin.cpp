#include <vector>
using namespace std;

template <class node, node (*op)(node, node), node (*neutre)()>
class segtree {
  public:
    segtree(vector<node> tableau) {
        N = tableau.size();
        noeuds.assign(N, neutre());
        for (int i = 0; i < N; ++i) {
            affecter(i, tableau[i]);
        }
    }
    /// a[deb] + a[deb+1] + ... + a[fin-1]
    node requete(int debutInclus, int finExclus) {
        node somme = neutre();
        for (int i = debutInclus; i < finExclus; ++i) {
            somme = op(somme, noeuds[i]);
        }
        return somme;
    }
    /// a[indice] := valeur
    void affecter(int indice, node valeur) { noeuds[indice] = valeur; }

  private:
    int N;
    vector<node> noeuds;
};
