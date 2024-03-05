#include <iostream>
#include <string>

using namespace std;

int main() {
    string expressao;

    while(getline(cin, expressao)) { 
        int contador = 0;

        for(char c : expressao) {
            if(c == '(') {
                contador++; // Incrementa para um parêntese que abre
            } else if(c == ')') {
                if(contador == 0) { // Se não houver '(' correspondente
                    contador = -1; // Marca como incorreto
                    break; // Sai do loop, pois já encontrou erro
                }
                contador--; // Decrementa para um parêntese que fecha
            }
        }
        
        if(contador == 0) {
            cout << "correct" << endl;
        } else {
            cout << "incorrect" << endl;
        }
    }

    return 0;
}
