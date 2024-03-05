#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    for(int i = 0; i < N; i++) {
        string mina;
        getline(cin, mina);

        int contador = 0; 
        int diamantes = 0;

        for(char c : mina) {
            if(c == '<') {
                contador++;
            } else if(c == '>' && contador > 0) {
                contador--;
                diamantes++;
            }
        }

        cout << diamantes << endl; 
    }

    return 0;
}
