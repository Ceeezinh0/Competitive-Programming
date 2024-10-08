#include<bits/stdc++.h>

using namespace std;

int t[1010];
int b[1010];
pair<int,int> coord[1010];

int main() {
    int n, x, y;

    while(cin >> n) {
        for(int i = 0; i < n; i++) {
            cin >> x >> y;

            coord[i] = make_pair(x, y);
        }

        sort(coord, coord + n);

        t[0] = 1;
        b[0] = 1;

        for(int i = 1; i < n; i++) {
            int maxtop = 1, maxbot = 1;

            for(int j = 0; j < i; j++) {
                // Verifica se eu posso colocar o ponto i depois do j em cima
                if (coord[i].first > coord[j].first && coord[i].second == coord[j].second + 2){
                    maxtop = max(maxtop, b[j] + 1);
                }
                    
                // Verifica se eu posso colocar o ponto i depois do j em baixo
                if (coord[i].first > coord[j].first && coord[i].second == coord[j].second - 2){
                    maxbot = max(maxbot, t[j] + 1);
                }
            }
            t[i] = maxtop;
            b[i] = maxbot;
        }
        int maximo = 1;

        for(int i = 0; i < n; i++) {
            maximo = max(maximo, t[i]);
            maximo = max(maximo, b[i]);
        }

        cout << maximo << "\n";
    }

    return 0;
}
