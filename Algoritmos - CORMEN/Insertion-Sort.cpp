#include <bits/stdc++.h>

using namespace std;

int main(){
    int A[10], chave, i;

    for(int i = 0; i < 10; i++){
        cin >> A[i]; 
    }

    // Insertion Sort
    for(int j = 1; j < 10; j++){
        chave = A[j];
        i = j - 1;

        while(i >= 0 && A[i] > chave){
            A[i + 1] = A[i];
            i--;
        }

        A[i + 1] = chave;
    }

    for(int i = 0; i < 10; i++){
        cout << A[i] << "\t";
    } 

    cout << "\n";

    return 0;
}
