#include<bits/stdc++.h>

#define pa 2
#define pb 3
#define pc 5

using namespace std;

int main(){
    double A, B, C, MEDIA;

    cin >> A >> B >> C;

    MEDIA = ((pa * A)+(pb * B)+(pc * C))/ 10;

    cout << fixed << setprecision(1);
    cout << "MEDIA = " << MEDIA << "\n";
    return 0;
}