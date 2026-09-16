#pragma once
#include <vector>
#include <functional>
#include <queue>

// no dirigido
template <typename T>
class Grafo {
private:
    std::vector<T> vertices;
    std::vector<std::vector<int>> matrizAdyacencia;

    int buscarIndice(T v) {
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i] == v) {
                return i;
            }
        }
        return -1;
    }

public:
    void agregarVertice(T v) {
        if (buscarIndice(v) == -1) {
            vertices.push_back(v);
            for (auto& fila : matrizAdyacencia) { fila.push_back(0); }
            matrizAdyacencia.push_back(std::vector<int>(vertices.size(), 0));
        }
    }

    void reiniciarMatriz() {
        vertices.clear();
        matrizAdyacencia.clear();
    }

    void agregarArista(T origen, T destino) {
        agregarVertice(origen);
        agregarVertice(destino);

        int i = buscarIndice(origen);
        int j = buscarIndice(destino);

        matrizAdyacencia[i][j] = 1;
        matrizAdyacencia[j][i] = 1;
    }

    bool existeVertice(T v) {
        return buscarIndice(v) != -1;
    }

    int cantidadVertices() {
        return vertices.size();
    }

    int consultarPos(int i, int j) {
        int valor = matrizAdyacencia[i][j];
        return valor;
    }

    void recorrerAmplitud(T origen, int profundidad, std::function<void(T)> accion) { //BFS
        int indiceOrigen = buscarIndice(origen);
        if (indiceOrigen == -1) { return; }

        std::vector<bool> visitado(vertices.size(), false);
        std::vector<int> distancia(vertices.size(), -1);
        std::queue<int> queue;

        queue.push(indiceOrigen);
        visitado[indiceOrigen] = true;
        distancia[indiceOrigen] = 0;

        while (!queue.empty()) {
            int actual = queue.front();
            queue.pop();
            if (distancia[actual] >= profundidad) { continue; }
            for (int vecino = 0; vecino < vertices.size(); vecino++) {
                if (!visitado[vecino] && matrizAdyacencia[actual][vecino] == 1) {
                    visitado[vecino] = true;
                    distancia[vecino] = distancia[actual] + 1;
                    accion(vertices[vecino]);
                    queue.push(vecino);
                }
            }
        }
    }
};