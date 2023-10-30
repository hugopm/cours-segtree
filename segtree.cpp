#include <vector>
using namespace std;

template <class node, node (*op)(node, node), node (*neutre)()> class segtree {
  public:
    segtree(vector<node> tableau) {
        N = 1;
        while (N < (int)tableau.size())
            N *= 2;
        noeuds.assign(2 * N, neutre());
        for (int i = 0; i < (int)tableau.size(); ++i) {
            noeuds[N + i] = tableau[i];
        }
        for (int i = N - 1; i >= 1; --i) {
            noeuds[i] = op(noeuds[2 * i], noeuds[2 * i + 1]);
        }
    }
    /// a[deb] + a[deb+1] + ... + a[fin-1]
    node requete(int debIn, int finEx) {
        debReq = debIn, finReq = finEx;
        return _req(1, 0, N);
    }
    /// a[indice] := valeur
    void affecter(int indice, node valeur) {
        indice += N;
        noeuds[indice] = valeur;
        // mettre à jour indice/2, indice/4, ...
    }

  private:
    int N;
    vector<node> noeuds;
    int debReq, finReq;
    node _req(int iNoeud, int debNoeud, int finNoeud) {
        // if disjoints : return neutre
        // if noeud inclus dans req : return noeuds[iNoeud]
        // sinon appeler _req sur les deux fils
    }
};
