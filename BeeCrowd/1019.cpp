#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, H, M, S;

    cin >> N;

    H = N / 3600;
    M = (N / 60) % 60;
    S =((N % 60) % 60);

    cout << H << ":" << M << ":" << S << "\n";
    
    return 0;
}