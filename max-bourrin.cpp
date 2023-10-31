#include <bits/stdc++.h>
using namespace std;

const int HAUTEUR = 4;
const int MAX_N = 1 << HAUTEUR;
const int INFINI = 1e9 + 42; // 1 milliard
int tableau[MAX_N];
int arbre[2 * MAX_N];

void afficher() {
    for (int h = 0; h <= HAUTEUR; ++h) {
        int debut = (1 << h);
        int fin = debut * 2;
        for (int iNoeud = debut; iNoeud < fin; ++iNoeud) {
            cout << arbre[iNoeud] << " ";
        }
        cout << '\n';
    }
}
void construire(int iNoeud) {
    // Si iNoeud est une feuille : rien à faire
    // Sinon appel récursif
    if (iNoeud < MAX_N) {
        // construit le fils gauche
        construire(2 * iNoeud);
        // construit le fils droit
        construire(2 * iNoeud + 1);
        // calculer le max des deux fils
        arbre[iNoeud] = max(arbre[2 * iNoeud], arbre[2 * iNoeud + 1]);
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    for (int i = 0; i < 2 * MAX_N; ++i) {
        arbre[i] = -INFINI;
    }
    int nbValeurs;
    cin >> nbValeurs;
    for (int i = 0; i < nbValeurs; i++) {
        cin >> tableau[i];
        arbre[MAX_N + i] = tableau[i];
    }
    construire(1);
    cout << "max global : " << arbre[1] << '\n';
    afficher();
    int nbIntervalles;
    cin >> nbIntervalles;
    for (int iItv = 0; iItv < nbIntervalles; ++iItv) {
        int debut, fin;
        cin >> debut >> fin;
        --debut;
        --fin; // 1-index -> 0-index
        int maxi = -INFINI;
        for (int iElem = debut; iElem <= fin; ++iElem) {
            maxi = max(maxi, tableau[iElem]);
        }
        cout << maxi << '\n';
    }
}
