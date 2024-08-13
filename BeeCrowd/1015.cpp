#include <bits/stdc++.h>

using namespace std;
 
int main() {
    double X1, Y1, X2, Y2, DISTANCIA;

    cin >> X1 >> Y1 >> X2 >> Y2;

    DISTANCIA = sqrt( pow(X2 - X1, 2) + pow(Y2 - Y1, 2));

    cout << fixed << setprecision(4);
    cout << DISTANCIA << "\n";

    return 0;
}