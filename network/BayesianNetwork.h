//
// Created by S290225 on 11/08/2021.
//

#ifndef OUR_BAYESIANNETWORK_H
#define OUR_BAYESIANNETWORK_H

#include "../graph/Graph.h"

template <class T>
class BayesianNetwork {
private:
    NodeId counter = 0;
    std::shared_ptr<Graph<T>> graph;
    std::map<std::string, Node<T>> nodeMap;

public:
    //constructor
    BayesianNetwork() : graph(std::make_shared<Graph<T>>()) {

    }
    //copy constructor
    BayesianNetwork(const BayesianNetwork& bn) {
        bn = bn.graph;
    }

    //destructor
    ~BayesianNetwork() {
        graph.reset();
    }

    //copy operator
    BayesianNetwork& operator=(const BayesianNetwork& bn) {
        if (this != &bn) {
            graph = bn.graph;
        }
        return *this;
    }

    std::map<std::string, Node<T>> getNodeMap(){
        return nodeMap;
    };

    std::shared_ptr<Graph<T>> getGraph(){
        return graph;
    }

    //boolean operator
    bool operator==(const BayesianNetwork& bn) const {
        if (*bn == *(bn.graph))
            return true;
        else
            return false;
    }
    void addNode(Node<T>& n){
        n.setId(counter);
        counter++;
        nodeMap.insert(std::pair<std::string,Node<T>>(n.getName(),n));  //TODO Make shared?
        graph->addNode(n);
    }
    NodeId idFromName(const std::string& variableName) {
        auto x=nodeMap.find(variableName);
        if(x !=nodeMap.end())
            return x->second.getId();
        else
            return -1;
    }
    std::vector<Status> getStatesById(NodeId parent){
        return graph->getNodeById(parent).getStatuses();
    }
    void addArcs(Node<T> n,std::vector<NodeId> parentsId){
        for (auto &pId : parentsId)
            graph->addArc(Arc(graph->getNodeById(pId),n));
    }

};

#endif //OUR_BAYESIANNETWORK_H
