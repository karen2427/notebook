#include <bits/stdc++.h>
using namespace std;

#define Node pair<int,long long> //(Vertice adyacente, peso)
#define INF 1000000000

int v,e; //v = cantidad de nodos, e = cantidad de aristas
const int MAX = 100001; //Cantidad Máxima de Nodos
vector<Node> ady[MAX]; //Lista de Adyacencia del grafo
bool marked[MAX]; //Estructura auxiliar para marcar los nodos visitados
long long dist[MAX]; //Estructura auxiliar para llevar las distancias a cada nodo
int previous[MAX]; //Estructura auxiliar para almacenar las rutas

class cmp{
public:
  bool operator()(Node n1, Node n2){
    return (n1.second>n2.second);
  }   
};

void init() {
    long long max = LLONG_MAX;

    for( int j = 0; j <= v; j++ ) {
        dist[j] = max; //Distancia a cada nodo (Dijkstra)
        marked[j] = 0; //Estructura auxiliar para marcar los nodos ya visitados
        previous[j] = -1;  //Estructura auxiliar para almacenar las rutas
    }
}

//El método debe llamarse con el indice del nodo inicial.
void dijkstra( int s ){
    priority_queue< Node , vector<Node> , cmp > pq;
    pq.push( Node(s, 0) );
    dist[s] = 0;
    int actual, j, adjacent;
    long long weight;

    while( !pq.empty() ){
      actual = pq.top().first;
      pq.pop();

      if( !marked[actual] ){
        marked[actual] = 1;
        for( j = 0; j < ady[actual].size(); j++ ){
          adjacent = ady[actual][j].first;
          weight = ady[actual][j].second;
          if( !marked[adjacent] ){
            if( dist[adjacent] > dist[actual] + weight ){
              dist[adjacent] = dist[actual] + weight;
              previous[adjacent] = actual;
              pq.push(Node( adjacent, dist[adjacent] ));
            }
          }
        }
      }
    }
}

int main(){
  int origen, destino;
  dijkstra(origen);
  //Para imprimir la distancia más corta desde el nodo inicial al nodo destino
  dist[destino];
  //Para imprimir la ruta más corta se debe imprimir de manera recursiva la estructura previous.
}
