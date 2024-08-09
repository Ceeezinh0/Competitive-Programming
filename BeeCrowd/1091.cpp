#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); // desvencula a sincronização com stdio
    cin.tie(0);// desvencula cin de cout

    int K;

    while (cin >> K && K != 0) {
        int N, M;
        cin >> N >> M;

        while (K--) {
            int X, Y;
            cin >> X >> Y;

            if (X == N || Y == M)
                cout << "divisa\n";
            else if (X > N && Y > M)
                cout << "NE\n";
            else if (X < N && Y > M)
                cout << "NO\n";
            else if (X < N && Y < M)
                cout << "SO\n";
            else
                cout << "SE\n";
        }
    }

    return 0;
}
