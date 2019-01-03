#include <bits/stdc++.h>
using namespace std;

int v, e; //v = cantidad de nodos, e = cantidad de aristas
const int MAX=1000; //Cantidad Máxima de Nodos
int ady[MAX][MAX];
  
void init(){
  int i, j;
    for( i = 0; i < v; i++ ){
      for( j = 0; j < v; j++ ){
        ady[i][j] = 0;
      }
    }
}

int main() {
    int origen, destino;
    
    //Al iniciar cada caso de prueba
    cin>>v>>e;
    init();
    
    while( e > 0 ){
    	cin>>origen>>destino;
    	//origen--;destino--;  //Si los datos empiezan en 1 
      
    	ady[origen][destino] = 1;
    	ady[destino][origen] = 1;
    	e--;
    }
    
    //Imprime la matriz de adyacencia
    for(int i=0;i<v;i++){
	cout<<i<<"\n";
	for(int j=0;j<v;j++){
		cout<<ady[i][j]<<" ";
	}
	cout<<"\n";
    }
	
    return 0;
}
