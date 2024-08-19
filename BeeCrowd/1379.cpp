#include <bits/stdc++.h>

using namespace std;

int main(){
    int A, B;

    cin >> A >> B ;

    while(A != 0 && B != 0){
        int C = 0, Val = 0;

        Val = B - A;
        C = A - Val;

        cout << C << "\n";

        cin >> A >> B;
    }

    return 0;
}