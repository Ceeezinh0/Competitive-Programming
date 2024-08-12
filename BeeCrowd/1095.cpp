#include <bits/stdc++.h>

using namespace std;
 
int main() {
    int i = 1, j = 60;
    while(j >= 0){
        cout << "I=" << i << " J=" << j << "\n";
        i = i + 3;
        j = j - 5;
    }
 
    return 0;
}