#pragma once
#include <algorithm>
#include <unordered_map>
#include <vector>

template <typename T>
class Grafo {
private:
    std::unordered_map<T, std::vector<T>> listaAdyacencia;

public:
    bool existeVertice(T vertice) {
        return listaAdyacencia.find(vertice) != listaAdyacencia.end();
    }

    void agregarVertice(T vertice) {
        if (!existeVertice(vertice)) {
            listaAdyacencia[vertice];
        }
    }

    bool existeArista(T origen, T destino) {
        auto posicion = listaAdyacencia.find(origen);

        if (posicion == listaAdyacencia.end()) { return false; }

        std::vector<T>& vecinos = posicion->second;

        return std::find(vecinos.begin(), vecinos.end(), destino) != vecinos.end();
    }

    void agregarArista(T origen, T destino) {
        agregarVertice(origen);
        agregarVertice(destino);

        if (origen == destino) { return; }

        if (!existeArista(origen, destino)) {
            listaAdyacencia[origen].push_back(destino);
        }

        if (!existeArista(destino, origen)) {
            listaAdyacencia[destino].push_back(origen);
        }
    }

    void reiniciar() {
        listaAdyacencia.clear();
    }

    int cantidadVertices() {
        return listaAdyacencia.size();
    }
};