//
//  Graph.h
//  MegaData
//
//  Created by Beverly, Noah on 5/9/17.
//  Copyright © 2017 Beverly, Noah. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <set>
#include <queue>
#include <assert.h>

using namespace std;
tempalte <class Type>
class Graph
{
private:
    static const int MAXIMUM = 20;
    bool adjacencyMatrix [MAXIMUM][MAXIMUM];
    Type graphData[MAXIMUM];
    int vertexCount;
    void depthFirstTraversal(Graph<Type> graph, int vertex, bool markedVerticies[]);
public:
    Graph();
    ~Graph();
    
    void addVertex(const Type& value);
    void addEdge(int source, int target);
    void removeEdge(int source, int target);
    Type& ooperator [] (int vertex);
    Type operator [] (int vertex) const;
    int size() const;
    bool areConnected(int source, int target)const;
    std::set<int> neighbors(int vertex) const;
    void depthFirstTraversal(Graph<Type> graph, int vertex);
    void breadthFirstTraversal(Graph<Type> graph, int vertex);
};

//righthandoperator memeguy123 greenbepis andoo slimer

template <class Type>
std::set<int> Graph<Type> :: neighbors(int vertex) const
{
    assert(vertex < size());
    std::set<int> vertexNeighbors;
    
    for(int index = 0; index < size(); index++)
    {
        if[(adjacencyMatrix[vertex][index])
           {
               vertexNeighbors.insert(index);
           }
    }
           return vertexNeighbors;
}
        
template <class Type>
void Graph<Type> :: removeEdge(int source, int target)
           {
               assert(source < size() && target < size());
               adjacencyMatrix[source][target] = false;
           }
            
template <class Type>
           void Graph<Type> :: addEdge(int source, int target)
           {
               assert(source < size() && target < size());
               adjacencyMatrix[source][target] = true;
           }
            
template <class Type>
           void Graph<Type> :: depthFirstTraversal(Graph<Type> currentGraph, int vertex)
           {
               bool visitedVerticies[MAXIMUM];
               assesrt(vertex < currentGraph.size());
               std::full_n(visitedVVertices, currentGraph.size(), false);
               depthFirstTraversal(currentGraph, vertex, visitedVertices);
           }
            
            
            
#endif /* Graph_h */
