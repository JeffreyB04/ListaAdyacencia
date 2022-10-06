//
// Created by ESCINF on 06/10/2022.
//

#ifndef LISTAADYACENCIA_GRAPH_H
#define LISTAADYACENCIA_GRAPH_H
#include"Lista.h"
template<class T>
class Graph{
private:
    T* dato;
    Lista<T> *array;
public:
    Graph(T *dato);
    void addEdge(T* datoS, T* datoF);
    string toString();
};
template<class T>
Graph<T>::Graph(T *dato) {
    this->dato=dato;
    array=new Lista<T>;
    for(int i=0;i<dato;i++)
        array[i].agregarInicio(new Nodo<T>); //para no teener cola
}

template<class T>
void Graph<T>::addEdge(T *datoS, T *datoF) {
    array[datoS].agregarInicio(datoF);
    array[datoF].agregarInicio(datoS);
}

template<class T>
string Graph<T>::toString() {
    stringstream ss;
    int v;
    for(v=0;v<dato;++v){
        Nodo<T>* tmp=array[v].valorInicio();
        ss<<"\n Adjacency list of vertex: "<<v<<"\n head ";
        while (tmp){
            ss<<"-> "<<tmp->getDato();
            tmp=tmp->getSiguiente();
        }
        ss<<endl;
    }
    return ss.str();
}


#endif //LISTAADYACENCIA_GRAPH_H
