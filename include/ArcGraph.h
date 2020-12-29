//
// Created by Moroz on 29.12.2020.
//

#ifndef ALG_31_ARCGRAPH_H
#define ALG_31_ARCGRAPH_H

#include "IGraph.h"


class ArcGraph : public IGraph {
public:
    ArcGraph(size_t verticesCount) : verticesCount(verticesCount){};

    ArcGraph(const IGraph&iGraph);

    virtual ~ArcGraph() {}

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const  override;

    std::vector<int> GetPrevVertices(int vertex) const override;


private:
    size_t verticesCount;
    std::vector <std::pair<int, int> > graph;
};



#endif //ALG_31_ARCGRAPH_H
