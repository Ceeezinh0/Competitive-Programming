#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;

    while (cin >> N && N != 0) {

        vector<pair<int, int>> points(N);
        
        for (int i = 0; i < N; i++) {
            cin >> points[i].first >> points[i].second;
        }

        sort(points.begin(), points.end());

        //PD para encontrar a maior sequência válida

        vector<int> pd(N, 1);
        
        int max_len = 1;

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (points[i].first != points[j].first && abs(points[i].second - points[j].second) == 2) {
                    pd[i] = max(pd[i], pd[j] + 1);
                }
            }
            max_len = max(max_len, pd[i]);
        }
        
        cout << max_len << "\n";
    }
    
    return 0;
}
