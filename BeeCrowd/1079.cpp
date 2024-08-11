#include <bits/stdc++.h>

#define p1 2
#define p2 3
#define p3 5

using namespace std;

int main(){
    int N;
    double M1, M2, M3;

    cin >> N;

    while( N!= 0){
        cin >> M1 >> M2 >> M3;

        cout << fixed << setprecision(1);
        cout << ((p1 * M1) + (p2 * M2) + (p3 * M3)) / (p1 + p2 + p3) << "\n";

        N--;
    }
    return 0;
}