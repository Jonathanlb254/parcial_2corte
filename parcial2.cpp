#include <iostream>


struct TreeNode {
    int valor;
    TreeNode* izquierda;
    TreeNode* derecha;
    TreeNode(int val) : valor(val), izquierda(nullptr), derecha(nullptr) {}
};


TreeNode* insertar(TreeNode* raiz, int valor) {
    if (raiz == nullptr) {
        return new TreeNode(valor);
    }
    if (valor < raiz->valor) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    } else {
        raiz->derecha = insertar(raiz->derecha, valor);
    }
    return raiz;
}


void imprimirEnOrden(TreeNode* raiz) {
    if (raiz != nullptr) {
        imprimirEnOrden(raiz->izquierda);
        printf("%d ", raiz->valor);
        imprimirEnOrden(raiz->derecha);
    }
}


TreeNode* pilaAArbol(int* pila, int tamano) {
    TreeNode* raiz = nullptr;
    for (int i = tamano - 1; i >= 0; --i) {
        raiz = insertar(raiz, pila[i]);
    }
    return raiz;
}

TreeNode* colaAArbol(int* cola, int tamano) {
    TreeNode* raiz = nullptr;
    for (int i = 0; i < tamano; ++i) {
        raiz = insertar(raiz, cola[i]);
    }
    return raiz;
}


void imprimirListaCircular(int* lista, int tamano, int inicio) {
    if (tamano == 0) {
        printf("Lista circular vacia.\n");
        return;
    }

    printf("Elementos de la lista circular: ");
    int indice = inicio;
    do {
        printf("%d ", lista[indice]);
        indice = (indice + 1) % tamano;
    } while (indice != inicio);
    printf("\n");
}

int main() {

    int tamanoPila;
    printf("Ingrese el tamaño de la pila: ");
    scanf("%d", &tamanoPila);
    int miPila[tamanoPila];
    printf("Ingrese los elementos de la pila: ");
    for (int i = 0; i < tamanoPila; ++i) {
        scanf("%d", &miPila[i]);
    }

    printf("Pila original: ");
    for (int i = tamanoPila - 1; i >= 0; --i) {
        printf("%d ", miPila[i]);
    }
    printf("\n");

    
    TreeNode* raizPila = pilaAArbol(miPila, tamanoPila);

    printf("Arbol  resultante de la pila (en orden): ");
    imprimirEnOrden(raizPila);
    printf("\n");

  
    int tamanoCola;
    printf("Ingrese el tamaño de la cola: ");
    scanf("%d", &tamanoCola);
    int miCola[tamanoCola];
    printf("Ingrese los elementos de la cola: ");
    for (int i = 0; i < tamanoCola; ++i) {
        scanf("%d", &miCola[i]);
    }

    printf("Cola original: ");
    for (int i = 0; i < tamanoCola; ++i) {
        printf("%d ", miCola[i]);
    }
    printf("\n");


    TreeNode* raizCola = colaAArbol(miCola, tamanoCola);

    printf("Arbol  resultante de la cola (en orden): ");
    imprimirEnOrden(raizCola);
    printf("\n");


    int listaCircular[tamanoCola];
    for (int i = 0; i < tamanoCola; ++i) {
        listaCircular[i] = miCola[i];
    }
    listaCircular[tamanoCola - 1] = listaCircular[0];
    printf("Lista circular creada.\n");


    imprimirListaCircular(listaCircular, tamanoCola, 0);


    delete raizPila;
    delete raizCola;

    return 0;
}
