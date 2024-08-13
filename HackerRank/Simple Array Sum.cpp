#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, sum = 0;

    cin >> N;

    vector<int> Vetor(N);
    
    for(int i = 0; i < N; i++){
        cin >> Vetor[i];
        sum += Vetor[i];
    }
    
    cout << sum << "\n";
    
    return 0;
}
