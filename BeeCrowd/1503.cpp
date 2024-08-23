#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAXS 600009
#define ALFA 26
#define MAXN 50009

using namespace std;

int proximo[MAXS][ALFA], tamanho[MAXS];
int link[MAXS], num[MAXS];
int contador = 0;

class ArvorePalindromica {
private:
	string s;
	int suf;
	char reduzir(char c) { return c - 'a'; }
	
	int obterLink(int u, int posicao) {
		
		for(; true; u = link[u]) {
			int st = posicao - 1 - tamanho[u];
			
			if (st >= 0 && s[st] == s[posicao])
				return u;
		}
	}
	
public:
	int raiz1, raiz2;
	
	ArvorePalindromica() {
		raiz1 = ++contador; raiz2 = ++contador;
		suf = raiz2;
		tamanho[raiz1] = -1; link[raiz1] = raiz1;
		tamanho[raiz2] = 0; link[raiz2] = raiz1;
	}
	
	int estender(char c) {
		int posicao = s.size(); s.push_back(c);
		
		c = reduzir(c);
		
		int u = obterLink(suf, posicao);
		
		if (proximo[u][c]) {
			suf = proximo[u][c];
			return 0;
		}
		
		int v = suf = ++contador;
		
		tamanho[v] = tamanho[u] + 2;
		proximo[u][c] = v;
		
		if (tamanho[v] == 1) {
			link[v] = raiz2;
			return num[v] = 1;
		}
		
		u = obterLink(link[u], posicao);
		link[v] = proximo[u][c];           
		return num[v] = 1 + num[link[v]];
	}
};

int n, resposta;
ArvorePalindromica arvore[10];

void buscaProfundidade(vector<int> &u) {
	
	if (tamanho[u[0]] > resposta) 
		resposta = tamanho[u[0]];
		
	vector<int> v(n);
	
	for(char c = 0; c < ALFA; c++) {
		bool ok = true;
		
		for(int i = 0; i < n && ok; i++) {
			v[i] = proximo[u[i]][c];
			
			if (!proximo[u[i]][c])
				ok = false;
		}
		
		if (!ok) 
			continue;
		
		buscaProfundidade(v);
	}
}

char s[MAXN];

int main() {
	while(scanf("%d", &n) != EOF) {
		contador = 0;
		vector<int> raiz1(n), raiz2(n);
		memset(&proximo, 0, sizeof proximo);
		
		for(int i = 0; i < n; i++) {
			arvore[i] = ArvorePalindromica();
			raiz1[i] = arvore[i].raiz1;
			raiz2[i] = arvore[i].raiz2;
			
			scanf(" %s", s);
			
			int tamanho = strlen(s);
			
			for(int j = 0; j < tamanho; j++) {
				arvore[i].estender(s[j]);
			}
		}
		
		resposta = 0;
		buscaProfundidade(raiz1);
		buscaProfundidade(raiz2);
		
		printf("%d\n", resposta);
	}
	return 0;
}
