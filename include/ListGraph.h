//
// Created by Moroz on 29.12.2020.
//

#ifndef ALG_31_LISTGRAPH_H
#define ALG_31_LISTGRAPH_H

#include "IGraph.h"


class ListGraph : public IGraph {
public:
    ListGraph(size_t verticesCount);

    ListGraph(const IGraph&iGraph);

    ~ListGraph() override {}

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const  override;

    std::vector<int> GetPrevVertices(int vertex) const override;


private:
    std::vector <std::vector<int> > graph;
};


#endif //ALG_31_LISTGRAPH_H
