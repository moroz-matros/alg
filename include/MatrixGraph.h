//
// Created by Moroz on 29.12.2020.
//

#ifndef ALG_31_MATRIXGRAPH_H
#define ALG_31_MATRIXGRAPH_H

#include "IGraph.h"

class MatrixGraph : public IGraph {
public:

    MatrixGraph(size_t verticesCount);

    MatrixGraph(const IGraph&iGraph);

    ~MatrixGraph() override{}

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const  override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector <std::vector<int> > graph;
};


#endif //ALG_31_MATRIXGRAPH_H
