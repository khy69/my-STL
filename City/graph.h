#ifndef GRAPH_H
#define GRAPH_H
#include <QPoint>
#include <QVector>
#include <QQueue>
class Graph
{
private:
    int *VerticesList;
    int **Edge;
protected:
    int maxVertices;
    int numEdges;
    int numVertices;
    int getVertexPos(int vertex)
    {
        for(int i=0;i<numVertices;i++)
        {
            if(VerticesList[i]==vertex)
            {
                return i;
            }
        }
        return -1;

    }
public:
    Graph();
    Graph(int sz=11);
    ~Graph()
    {
        delete []VerticesList;
        delete []Edge;
    }
    bool insertVertex(const int& vertex);
    bool insertEdge(int v1,int v2,int weight);
    bool removeVertex(int v);
    bool removeEdge(int v1,int v2);
    bool isEmpty();
    int getFirstNeighbor(int v);
    int getNextNeighbor(int v,int w);
    const int maxWeight=9999;
    bool GraphEmpty() const
    { return numEdges==0;}
    bool GraphFull() const
    {
        if(numVertices==maxVertices&&numEdges==maxVertices*(maxVertices-1)/2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int NumberOfVertices()
    {
        return numVertices;
    }
    int NumberOfEdges()
    {
        return numEdges;
    }
    int getWeight(int v1,int v2)
    {
        return (v1!=-1&&v2!=-1)?Edge[v1][v2]:0;
    }
    void DFS(int loc,bool *visited);
    void dfsTraverse(const int &v)
    {
        int i=0;
        int loc=0;
        int n=numVertices;
        bool *visited=new bool[n];
        for(i=0;i<n;i++)
        {
            visited[i]=false;
        }
        loc=getVertexPos(v);
        DFS(loc,visited);
        delete []visited;
    }
    void BFS(const int &v);



};

#endif // GRAPH_H
