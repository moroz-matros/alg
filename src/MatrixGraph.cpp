//
// Created by Moroz on 29.12.2020.
//

#include "../include/MatrixGraph.h"

MatrixGraph::MatrixGraph(size_t verticesCount) {
    graph.resize(verticesCount);
    for (auto &i: graph) i.resize(verticesCount);
}

void MatrixGraph::AddEdge(int from, int to) {
    graph[from][to] += 1;
}

int MatrixGraph::VerticesCount() const {
    return graph.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i<graph[vertex].size(); ++i){
        if (graph[vertex][i] > 0) result.push_back(i);
    }
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i<graph.size(); ++i){
        if (graph[i][vertex] > 0) result.push_back(i);
    }
    return result;
}

MatrixGraph::MatrixGraph(const IGraph &iGraph) {
    graph.resize(iGraph.VerticesCount());
    for (auto &i: graph) i.resize(iGraph.VerticesCount());
    for (int i = 0; i < iGraph.VerticesCount(); ++i){
        for (auto &to: iGraph.GetNextVertices(i))
            graph[i][to] += 1;
    }
}




