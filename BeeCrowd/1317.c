#include <stdio.h>

int estado[30], sai[30], v[30];
char res[30];

void bfs(int a){
    estado[a] = 1;

    for(int i = 0; i < v[a]; i++){
        if(estado[i] == 0){
            bfs(i);
        }
    }
}

int main (){

    return 0;
}