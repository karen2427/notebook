#include <bits/stdc++.h>
using namespace std;

int v, e; //v = cantidad de nodos, e = cantidad de aristas
const int MAX = 5000; // Maxima cantidad de nodos
vector<int> ady[MAX]; //Lista de Adyacencia del grafo

static void init(){
    for(int i = 0; i < v; i++ ){
      ady[i].clear();
    }
}

int main() {
    int origen, destino,i;
    
    //Al iniciar cada caso de prueba
    cin >> v >> e;
    init();
    
    while( e > 0 ){
      cin >> origen >> destino;
      //origen--;destino--;  //Si los datos empiezan en 1 
      ady[origen].push_back(destino);
      ady[destino].push_back(origen);
      e--;
    }
	
    //Imprime la lista de adyacencia
    for(int i=1;i<=v;i++){
	cout<<i<<"\n";
	for(int j=0;j<ady[i].size();j++){
		cout<<ady[i][j]<<" ";
	}
	cout<<"\n";
     }
     return 0;
}
