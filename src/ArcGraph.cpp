//
// Created by Moroz on 29.12.2020.
//

#include "../include/ArcGraph.h"

void ArcGraph::AddEdge(int from, int to) {
    std::pair<int, int> pair(from, to);
    bool flag = true;
    for (int i = 0; i < graph.size(); ++i)
        if (graph[i] == pair) {
            flag = false;
            break;
        }
    if (flag)
        graph.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (auto &i: graph){
        if (i.first == vertex) result.push_back(i.second);
    }
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (auto &i: graph){
        if (i.second == vertex) result.push_back(i.first);
    }
    return result;
}

ArcGraph::ArcGraph(const IGraph &iGraph) {
    for (int i = 0; i < iGraph.VerticesCount(); ++i){
        for (auto &to: iGraph.GetNextVertices(i))
            graph.emplace_back(i, to);
    }
    verticesCount = iGraph.VerticesCount();
}


