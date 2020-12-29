#include "include/ListGraph.h"
#include "include/MatrixGraph.h"
#include "include/ArcGraph.h"
#include "include/SetGraph.h"

int main() {
    size_t size = 10;

    MatrixGraph mgraph(size);

    // граф см png

    mgraph.AddEdge(3, 2);
    mgraph.AddEdge(5, 4);
    mgraph.AddEdge(5, 8);
    mgraph.AddEdge(6, 5);
    mgraph.AddEdge(0, 1);
    mgraph.AddEdge(1, 2);
    mgraph.AddEdge(0, 7);
    mgraph.AddEdge(9, 6);
    mgraph.AddEdge(2, 5);
    mgraph.AddEdge(7, 6);
    mgraph.AddEdge(8, 9);
    mgraph.AddEdge(4, 3);

    SetGraph sgraph = mgraph;

    ArcGraph agraph = sgraph;

    ListGraph lgraph = agraph;

    MatrixGraph m2graph = lgraph;
    for (int i = 0; i < size; ++i) {
        std::cout << i << std::endl;
        std::cout << ((mgraph.GetNextVertices(i) == sgraph.GetNextVertices(i)) &&
                      (sgraph.GetNextVertices(i) == agraph.GetNextVertices(i)) &&
                      (agraph.GetNextVertices(i) == lgraph.GetNextVertices(i)) &&
                      (lgraph.GetNextVertices(i) == m2graph.GetNextVertices(i)) &&
                      (m2graph.GetNextVertices(i) == mgraph.GetNextVertices(i))) << std::endl;
        std::cout << ((mgraph.GetPrevVertices(i) == sgraph.GetPrevVertices(i)) &&
                      (sgraph.GetPrevVertices(i) == agraph.GetPrevVertices(i)) &&
                      (agraph.GetPrevVertices(i) == lgraph.GetPrevVertices(i)) &&
                      (lgraph.GetPrevVertices(i) == m2graph.GetPrevVertices(i)) &&
                      (m2graph.GetPrevVertices(i) == mgraph.GetPrevVertices(i))) << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
