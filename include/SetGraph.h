//
// Created by Moroz on 29.12.2020.
//

#ifndef ALG_31_SETGRAPH_H
#define ALG_31_SETGRAPH_H



#include "IGraph.h"


class SetGraph : public IGraph {
public:

    SetGraph(size_t verticesCount);

    SetGraph(const IGraph&iGraph);

    virtual ~SetGraph() {}

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const  override;

    std::vector<int> GetPrevVertices(int vertex) const override;


private:
    std::vector<std::unordered_set<int>> graph;
};


#endif //ALG_31_SETGRAPH_H
