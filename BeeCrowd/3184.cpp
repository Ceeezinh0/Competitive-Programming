#include <bits/stdc++.h>

using namespace std;

int n, m, ouro = 0;
vector<vector<char>> mapa;
vector<vector<bool>> visitado;

void explorar(int x, int y){
    if(x < 0 || x >= m || y <0 || y>= n|| visitado[x][y] || mapa[x][y] == '#'){
        return;
    }

    visitado[x][y] = true;

    if(mapa[x][y] == 'G'){
        ouro++;
    }

    if((x > 0 && mapa[x - 1][y] == 'T') || (x < m - 1 && mapa[x + 1][y] == 'T') || (y > 0 && mapa[x][y - 1] == 'T') || (y < n - 1 && mapa[x][y + 1] == 'T')){
        return;
    }

    explorar(x - 1, y);
    explorar(x + 1, y);
    explorar(x, y - 1);
    explorar(x, y + 1);
}

int main(){ 
    int n, m;

    return 0;
}
