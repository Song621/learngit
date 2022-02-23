#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Node{
public:
    int value; // 点上的值
    int in; // 一个点的入度
    int out; // 一个点的出度
    vector<Node> nexts; // 由当前点出发，指向的邻居节点
    vector<Edge> edges; // 由当前节点引出的边
public:
    Node(){};
    Node(int val){
        value = val;
        in = 0;
        out = 0;
        nexts = vector<Node>();
        edges = vector<Edge>();
    };
};

class Edge{
public:
    int weight;
    Node from;
    Node to;

public:
    Edge(int wt, Node& f, Node& t){
        weight = wt;
        from = f;
        to = t;
    };
};

class Graph{
public:
    //点集和边集
    //比如：第零个城市int i=0,对应点的信息，封装成数据结构Node 0,即编号-实体结构
    //边集，所有的边
    unordered_map<int, Node> nodes;
    unordered_set<Edge> edges;
public:
    Graph(): nodes(unordered_map<int, Node>()), edges(unordered_set<Edge>()) {};
};

class GraphGenerator{
public:
    Graph createGraph(vector<vector<int> >& matrix){
        Graph graph;
        for(int i=0; i<matrix.size(); i++){
            int weight = matrix[i][0];
            int from = matrix[i][1];
            int to = matrix[i][2];
            if(graph.nodes.count(from) == 0){
                graph.nodes.insert(pair<int, Node>(from, Node(from)));
            }
            if(graph.nodes.count(to) == 0){
                graph.nodes.insert(pair<int, Node>(to, Node(to)));
            }

            Node fromNode = graph.nodes.at(from);
            Node toNode = graph.nodes.at(to);
            Edge newEdge = Edge(weight, fromNode, toNode);
            fromNode.nexts.push_back(toNode);
            fromNode.out++;
            toNode.in++;
            fromNode.edges.push_back(newEdge);
            graph.edges.insert(newEdge);
        }

        return graph;
    }
};


