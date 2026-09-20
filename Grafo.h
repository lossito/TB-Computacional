#pragma once
#include <vector>
#include <functional>
#include <queue>
#include <unordered_map>

// no dirigido
template <typename T>
class Grafo {
private:
    std::vector<T> vertices;
    std::unordered_map<T, std::vector<T>> matrizAdyacencia; //mas facil para mi

  //  int buscarVertice(T v) {

  //      for(auto& par : matrizAdyacencia) {
  //          if (par.first == v) {
  //              return 1;
  //          }
		//}
  //      return 0;

  //      /*for (int i = 0; i < matrizAdyacencia.size(); i++) {
  //          if (vertices[i] == v) {
  //              return i;
  //          }
  //      }
		//return T();*/
  //  }

public:
    void agregarVertice(T v) {
        if (!existeVertice(v)) { //ojito aca

			matrizAdyacencia[v];

            //vertices.push_back(v);  //agregar validacion?
            //for (auto& fila : matrizAdyacencia) { fila.push_back(0); }
            //matrizAdyacencia.push_back(std::vector<int>(vertices.size(), 0));
        }
    }

    void reiniciarMatriz() {
        vertices.clear();
        matrizAdyacencia.clear();
    }

    void agregarArista(T origen, T destino) {
        agregarVertice(origen);
        agregarVertice(destino);

		matrizAdyacencia[origen].push_back(destino); //agregue

        /*int i = buscarVertice(origen);
        int j = buscarVertice(destino);

        matrizAdyacencia[i][j] = 1;
        matrizAdyacencia[j][i] = 1;*/
    }

    bool existeVertice(T v) {
        /*return buscarVertice(v) != T();*/

		return matrizAdyacencia.find(v) != matrizAdyacencia.end();
    }

    int cantidadVertices() {
        return matrizAdyacencia.size();
    }

    int consultarPos(int i, int j) { //corregir
        int valor = matrizAdyacencia[i][j];
        return valor;
    }

    //corregir
    //void recorrerAmplitud(T origen, int profundidad, std::function<void(T)> accion) { //BFS
    //    int indiceOrigen = buscarVertice(origen);
    //    if (indiceOrigen == -1) { return; }

    //    std::vector<bool> visitado(vertices.size(), false);
    //    std::vector<int> distancia(vertices.size(), -1);
    //    std::queue<int> queue;

    //    queue.push(indiceOrigen);
    //    visitado[indiceOrigen] = true;
    //    distancia[indiceOrigen] = 0;

    //    while (!queue.empty()) {
    //        int actual = queue.front();
    //        queue.pop();
    //        if (distancia[actual] >= profundidad) { continue; }
    //        for (int vecino = 0; vecino < vertices.size(); vecino++) {
    //            if (!visitado[vecino] && matrizAdyacencia[actual][vecino] == 1) {
    //                visitado[vecino] = true;
    //                distancia[vecino] = distancia[actual] + 1;
    //                accion(vertices[vecino]);
    //                queue.push(vecino);
    //            }
    //        }
    //    }
    //}

    std::unordered_map <T, std::vector<T>> getMatrizAdyacencia() {
        return matrizAdyacencia;
	}
};