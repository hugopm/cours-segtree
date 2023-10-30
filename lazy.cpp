#include <vector>
using namespace std;

template <class node, node (*op)(node, node), node (*neutre)(), class fun,
          node (*eval)(fun, node), fun (*composition)(fun, fun), fun (*id)()>
class lazy_segtree {
  public:
    lazy_segtree(vector<node> tableau) {
        N = 1;
        while (N < (int)tableau.size())
            N *= 2;
        noeuds.assign(2 * N, neutre());
        lazy.assign(2 * N, id());
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
    /// a[i] := f(a[i]) pour deb <= i <= fin
    void appliquer(int debIn, int finEx, fun fct) {
        debReq = debIn, finReq = finEx, toApply = fct;
        _app(1, 0, N);
    }

  private:
    int N;
    vector<node> noeuds;
    vector<fun> lazy;
    void push(int i) {
        // ?
    }
    int debReq, finReq;
    fun toApply;
    node _req(int iNoeud, int debNoeud, int finNoeud) {
        push(iNoeud);
        // ?
    }
    void _app(int iNoeud, int debNoeud, int finNoeud) {
        push(iNoeud);
        // ?
        // ne pas oublier de push après lazy[iNoeud] = ... dans le cas inclus
    }
};
