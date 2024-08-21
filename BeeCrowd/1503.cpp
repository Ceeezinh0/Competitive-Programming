#include <bits/stdc++.h>

using namespace std;

bool Palindromo(const string& s){
	int tam = s.size();
	
	for(int i =0; i< tam; i++){
		if(s[i] != s[tam -i -1]){
			return false;
		}
	}
	return true;
}

int main(){
	int N;
	
	while(cin >> N){
		vector<string>Palavra(N);
		
		for(int i =0; i< N; i++){
			cin >> Palavra[i];
		}
		
		string primeira_palavra = Palavra[0];
		int tam_max = 0;
		
		for(int i = 0; i< primeira_palavra.size(); i++){
			for(int j = i; j <primeira_palavra.size(); j++){
				string sub = primeira_palavra.substr(i, j - 1 +1);
				
				if(Palindromo(sub)){
					bool comum = true;
					for(int k =1; k< N; k++){
						if(Palavra[k].find(sub) == string::npos){
							comum = false;
							break;
						}
					}
					if(comum){
						tam_max = max(tam_max, (int)sub.size());
					}
				}
			}
		}
		
		cout << tam_max << "\n";
	}
	
	return 0;
}
