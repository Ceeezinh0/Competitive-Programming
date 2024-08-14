#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;

    while(cin >> N && N != 0){
        for(int i = 1; i <= N; i++){
            int A, B, C, D, E;

            cin >> A >> B >> C >> D >> E;

            if(A <= 127 && B > 127 && C > 127 && D > 127 && E > 127){
                cout << "A" << "\n";
            }else if(B <= 127 && A > 127 && C > 127 && D > 127 && E > 127){
                cout << "B" << "\n";
            }else if(C <= 127 && A > 127 && B > 127 && D > 127 && E > 127){
                cout << "C" << "\n";
            }else if(D <= 127 && A > 127 && C > 127 && B > 127 && E > 127){
                cout << "D" << "\n";
            }else if(E <= 127 && A > 127 && C > 127 && D > 127 && B > 127){
                cout << "E" << "\n";
            }else{
                cout << "*" << "\n";
            }
        }

    }

    return 0;
}
