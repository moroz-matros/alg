//
// Created by Moroz on 29.12.2020.
//

#include "../include/SetGraph.h"

SetGraph::SetGraph(size_t verticesCount) {
    graph.resize(verticesCount);
}

void SetGraph::AddEdge(int from, int to) {
    graph[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return graph.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (auto &i: graph[vertex]) result.push_back(i);
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < graph.size(); ++i)
        if (graph[i].find(vertex) != graph[i].end())
            result.push_back(i);
    return result;
}

SetGraph::SetGraph(const IGraph &iGraph) {
    graph.resize(iGraph.VerticesCount());
    for (int i = 0; i < iGraph.VerticesCount(); ++i){
        for (auto &to: iGraph.GetNextVertices(i))
            graph[i].insert(to);
    }
}

