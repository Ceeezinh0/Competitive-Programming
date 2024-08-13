#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;

    while(cin >> N && N != 0){
        int SUM =0;

        while(N > 0){
            SUM += N * N;
            N--;
        }
        cout << SUM << "\n";
    }

    return 0;
}
