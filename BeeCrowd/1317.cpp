#include <bits/stdc++.h>

using namespace std;

int estado[30];
int sai[30];

vector<int> v[30];
vector<string> res[30];

void bfs(int a){
    estado[a] = 1;

    for(auto it : v[a]){
        if(estado[it]==0){
           bfs(it);
        }
    }     
}

int main(){
    int viz, n;

    while(scanf("%d", &n), n){
        memset(sai, 0, sizeof sai);

        for(int i=0; i<=30; i++){
            v[i].clear();
            res[i].clear();
        }

        for(int i=1; i<=n; i++){
            while(scanf("%d", &viz), viz){
                v[i].push_back(viz);
                sai[i]++;
            }
        }

    int p, t1, t2;
    char a1[30], a2[30], a3[30];
    
    while(scanf("%d", &p), p){ 
        memset(estado, 0, sizeof estado);

	    scanf("%d %d", &t1, &t2);

        bfs(p);
		
        scanf("%s %s %s", a1, a2, a3);

		for(int i=1; i<=n; i++){
			if(estado[i]==0){
                 res[i].push_back(a1);
            }else{
				if(sai[i]<t1){
                    res[i].push_back(a1);
                }else if(sai[i] < t2){
                    res[i].push_back(a2);
                }else{
                    res[i].push_back(a3);
                }
			}
		}
    }
	char nome[30];
	
    for(int i=1; i<=n; i++){
		scanf("%s", nome);
		cout << nome << ": ";

		for(auto it : res[i]){
			cout << it << " ";
		}
		cout << "\n";
	}
  }
  
  return 0;
}
