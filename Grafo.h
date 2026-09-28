#pragma once
#include <vector>

template <typename T>
class Grafo {
private:
    std::vector<T> vertices;
    std::vector<std::vector<int>> matrizAdyacencia;

public:
    void agregarVertice(T vertice) {
        if (buscarIndice(vertice) != -1) { return; }
        vertices.push_back(vertice);

        for (std::vector<int>& fila : matrizAdyacencia) {
            fila.push_back(0);
        }

        std::vector<int> nuevaFila(vertices.size(), 0);
        matrizAdyacencia.push_back(nuevaFila);
    }

    bool existeArista(T origen, T destino) {
        int indiceOrigen = buscarIndice(origen);
        int indiceDestino = buscarIndice(destino);

        if (indiceOrigen == -1 || indiceDestino == -1) { return false; }
        return matrizAdyacencia[indiceOrigen][indiceDestino] == 1;
    }

    int buscarIndice(T vertice) {
        int indice = 0;
        for (T actual : vertices) {
            if (actual == vertice) {
                return indice;
            }
            indice++;
        }
        return -1;
    }

    void agregarArista(T origen, T destino) {
        if (origen == destino) {
            return;
        }

        agregarVertice(origen);
        agregarVertice(destino);

        int indiceOrigen = buscarIndice(origen);
        int indiceDestino = buscarIndice(destino);

        matrizAdyacencia[indiceOrigen][indiceDestino] = 1;
        matrizAdyacencia[indiceDestino][indiceOrigen] = 1;
    }

    void reiniciar() {
        vertices.clear();
        matrizAdyacencia.clear();
    }

    std::vector<std::vector<int>> obtenerMatrizAdyacencia() {
        return matrizAdyacencia;
    }

    std::vector<std::vector<int>> calcularMatrizCaminos() {
        std::vector<std::vector<int>> matrizCaminos = matrizAdyacencia;
        int cantidad = (int)vertices.size();

        for (int i = 0; i < cantidad; i++) {
            matrizCaminos[i][i] = 1;
        }

        for (int i = 0; i < cantidad; i++) {
            std::vector<int> procesados(cantidad, 0);
            bool verticeDetectado = true;

            while (verticeDetectado) {
                verticeDetectado = false;

                for (int j = 0; j < cantidad; j++) {
                    if (matrizCaminos[i][j] == 1 && procesados[j] == 0) {
                        procesados[j] = 1;

                        for (int k = 0; k < cantidad; k++) {
                            if (matrizCaminos[j][k] == 1) {
                                matrizCaminos[i][k] = 1;
                            }
                        }
                        verticeDetectado = true;
                    }
                }
            }
        }

        return matrizCaminos;
    }
};