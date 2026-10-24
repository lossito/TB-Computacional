//Grafo.h:
#pragma once
#include <vector>

// Una "foto" del calculo de la matriz de caminos (paso 2)
// tipo 0: matriz inicial (con 1 en la diagonal)
// tipo 1: se selecciono un 1 (fila, columna) que todavia no estaba visitado
// tipo 2: se copiaron los 1 de la fila 'columna' a la fila 'fila' (nuevos = columnas que pasaron de 0 a 1)
// tipo 3: la fila 'fila' ya no tiene 1 sin visitar
struct PasoCamino {
    std::vector<std::vector<int>> matriz;
    int tipo;
    int fila;
    int columna;
    std::vector<int> nuevos;
};

template <typename T>
class Grafo {
private:
    std::vector<T> vertices;
    std::vector<std::vector<int>> matrizAdyacencia;

public:
    void agregarVertice(T vertice) {
        if (buscarIndice(vertice) != -1) { return; }

        vertices.push_back(vertice);
        int cantidadFilas = matrizAdyacencia.size();

        for (int i = 0; i < cantidadFilas; i++) { matrizAdyacencia[i].push_back(0); }

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
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i] == vertice) {
                return i;
            }
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

        // grafo DIRIGIDO: solo origen -> destino
        matrizAdyacencia[indiceOrigen][indiceDestino] = 1;
    }

    void reiniciar() {
        vertices.clear();
        matrizAdyacencia.clear();
    }

    std::vector<std::vector<int>> obtenerMatrizAdyacencia() {
        return matrizAdyacencia;
    }

    // PASO 1: matriz de adyacencia con 1 en la diagonal
    std::vector<std::vector<int>> obtenerMatrizAdyacenciaConDiagonal() {
        std::vector<std::vector<int>> m = matrizAdyacencia;
        for (int i = 0; i < (int)m.size(); i++) m[i][i] = 1;
        return m;
    }

    // PASO 2 (version completa, de golpe). Se deja por si se necesita.
    std::vector<std::vector<int>> calcularMatrizCaminos() {
        std::vector<PasoCamino> pasos = calcularPasosMatrizCaminos();
        return pasos[pasos.size() - 1].matriz;
    }

    // PASO 2 (version paso a paso): devuelve todas las "fotos" del proceso
    std::vector<PasoCamino> calcularPasosMatrizCaminos() {
        std::vector<PasoCamino> pasos;
        std::vector<std::vector<int>> m = obtenerMatrizAdyacenciaConDiagonal();
        int n = (int)m.size();

        PasoCamino inicio;
        inicio.matriz = m; inicio.tipo = 0; inicio.fila = -1; inicio.columna = -1;
        pasos.push_back(inicio);

        for (int i = 0; i < n; i++) {
            // visitados[k] = 1 si el 1 de la columna k de la fila i ya fue usado
            std::vector<int> visitados(n, 0);
            visitados[i] = 1; // la diagonal se ignora

            while (true) {
                // se vuelve a recorrer la fila desde el inicio: puede haber 1 recien agregados
                int j = -1;
                for (int k = 0; k < n; k++) {
                    if (m[i][k] == 1 && visitados[k] == 0) { j = k; break; }
                }
                if (j == -1) break;

                visitados[j] = 1;

                PasoCamino seleccion;
                seleccion.matriz = m; seleccion.tipo = 1; seleccion.fila = i; seleccion.columna = j;
                pasos.push_back(seleccion);

                PasoCamino copia;
                copia.tipo = 2; copia.fila = i; copia.columna = j;
                for (int k = 0; k < n; k++) {
                    if (m[j][k] == 1 && m[i][k] == 0) {
                        m[i][k] = 1;
                        copia.nuevos.push_back(k);
                    }
                }
                copia.matriz = m;
                pasos.push_back(copia);
            }

            PasoCamino fin;
            fin.matriz = m; fin.tipo = 3; fin.fila = i; fin.columna = -1;
            pasos.push_back(fin);
        }
        return pasos;
    }

    // PASO 3: orden de las filas (mayor cantidad de 1 primero; empate: el 1 mas cercano a la primera columna)
    std::vector<int> calcularOrdenFilas(const std::vector<std::vector<int>>& m) {
        int n = (int)m.size();
        std::vector<int> orden(n), cantidad(n, 0), primero(n, n);

        for (int i = 0; i < n; i++) {
            orden[i] = i;
            for (int k = 0; k < n; k++) {
                if (m[i][k] == 1) {
                    cantidad[i]++;
                    if (primero[i] == n) primero[i] = k;
                }
            }
        }

        // ordenamiento por insercion (estable)
        for (int a = 1; a < n; a++) {
            int actual = orden[a];
            int b = a - 1;
            while (b >= 0 && (cantidad[orden[b]] < cantidad[actual] ||
                (cantidad[orden[b]] == cantidad[actual] && primero[orden[b]] > primero[actual]))) {
                orden[b + 1] = orden[b];
                b--;
            }
            orden[b + 1] = actual;
        }
        return orden;
    }

    // PASO 4: bloques diagonales -> componentes conexas (lista de indices de vertices)
    // En un grafo dirigido, dos vertices pertenecen a la misma componente si cada uno
    // alcanza al otro (m[u][v] == 1 y m[v][u] == 1). Se recorre en el orden de las filas,
    // asi que los miembros de cada componente quedan juntos (bloque diagonal).
    std::vector<std::vector<int>> calcularComponentes(const std::vector<int>& orden, const std::vector<std::vector<int>>& m) {
        std::vector<std::vector<int>> componentes;
        int n = (int)orden.size();
        std::vector<int> usado(n, 0);

        for (int p = 0; p < n; p++) {
            int v = orden[p];
            if (usado[v] == 1) continue;

            std::vector<int> componente;
            for (int q = p; q < n; q++) {
                int u = orden[q];
                if (usado[u] == 0 && m[v][u] == 1 && m[u][v] == 1) {
                    usado[u] = 1;
                    componente.push_back(u);
                }
            }
            componentes.push_back(componente);
        }
        return componentes;
    }
};