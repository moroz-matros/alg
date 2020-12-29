//
// Created by Moroz on 29.12.2020.
//

#ifndef ALG_31_IGRAPH_H
#define ALG_31_IGRAPH_H



#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

struct IGraph {
    virtual ~IGraph() {}

    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const  = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;

    /*void PrintPrevNext(int vertex) const {
        std::cout << vertex << std::endl << "NEXT: ";
        for (auto &i: GetNextVertices(vertex)) std::cout << i << ' ';
        std::cout << std::endl << "PREV: ";
        for (auto &i: GetPrevVertices(vertex)) std::cout << i << ' ';
        std::cout << std::endl;
    }*/
};




#endif //ALG_31_IGRAPH_H
