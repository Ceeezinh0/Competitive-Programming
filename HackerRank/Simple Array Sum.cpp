#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, SUM = 0;

    cin >> N;

    vector<int> Vetor(N);
    
    for(int i = 0; i < N; i++){
        cin >> Vetor[i];
        SUM += Vetor[i];
    }
    
    cout << SUM << "\n";
    
    return 0;
}
