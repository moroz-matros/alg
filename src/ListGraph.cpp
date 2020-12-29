//
// Created by Moroz on 29.12.2020.
//

#include "../include/ListGraph.h"

ListGraph::ListGraph(size_t verticesCount) {
    graph.resize(verticesCount);
}

void ListGraph::AddEdge(int from, int to) {
    graph[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return graph.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    result.resize(graph[vertex].size());
    std::copy(graph[vertex].begin(), graph[vertex].end(), result.begin());
    return result;
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (size_t i = 0; i < graph.size(); ++i) {
        for (auto child : graph[i]) {
            if (child == vertex) {
                result.push_back(i);
                break;
            }
        }
    }
    return result;
}

ListGraph::ListGraph(const IGraph &iGraph) {
    graph.resize(iGraph.VerticesCount());
    for (int i = 0; i < iGraph.VerticesCount(); ++i){
        for (auto &to: iGraph.GetNextVertices(i))
            graph[i].push_back(to);
    }
}





