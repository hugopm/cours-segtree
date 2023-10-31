#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100 * 1000 + 42;
const int INFINI = 1e9 + 42; // 1 milliard
int tableau[MAX_N];

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int nbValeurs;
    cin >> nbValeurs;
    for (int i = 0; i < nbValeurs; i++) {
        cin >> tableau[i];
    }
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
