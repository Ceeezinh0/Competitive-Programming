#include <bits/stdc++.h>

#define PI 3.1415

using namespace std;

int main() {
    int R;
    double volume;
    long long L, num_baloes;
    
    cin >> R >> L;

    volume = (4.0 / 3.0) * PI * pow(R, 3);

    num_baloes = L / volume;

    cout << num_baloes << "\n";

    return 0;
}
