#include <bits/stdc++.h>

using namespace std;

int main(){
    int A[10], chave, i;

    for(int i = 0; i < 10; i++){
        cin >> A[i];
    }

    // Insertion Sort
    for(int j = 1; j < 10; j++){// Esse for percorre o vetor;
        chave = A[j];
        i = j - 1;

        while(i >= 0 && A[i] > chave){// Esse while encontra a posição onde deverá ser adicionado a chave
            A[i + 1] = A[i];
            i--;
        }

        A[i + 1] = chave;// Insere a chave no endereço certo do vetor
    }

    for(int i = 0; i < 10; i++){
        cout << A[i] << "\t";
    } 

    cout << "\n";

    return 0;
}
