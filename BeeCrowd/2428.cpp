#include <bits/stdc++.h>

using namespace std;

int main(){
    int vetor[4];

    for (int i = 0; i < 4; i++) {
        cin >> vetor[i];
    }

    sort(vetor, vetor + 4);

    if (vetor[0] * vetor[3] == vetor[1] * vetor[2]) {
        cout << 'S' << "\n";
    } else {
        cout << 'N' << "\n";
    }

    return 0;
}