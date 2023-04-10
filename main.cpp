#include <iostream>
#include <vector>

class edge{
private:
    int dest;
    int value;
public:
    edge(){

    }

    edge(int d, int v){
        this->value = v;
        this->dest = d;
    }

    int getDestination(){
        return this->dest;
    }

    int getValue(){
        return this->value;
    }

    void setValue(int v){
        this->value = v;
    }
};

class vertex{

private:
    int denomination;
public:
    std::vector<edge> listEdges;

    vertex(){

    }

    vertex(int d){
        this->denomination = d;
    }

    int getDenomination(){
        return this->denomination;
    }

    void setDenomination(int d){
        this->denomination = d;
    }

    void printEdgeList(){

        if(listEdges.empty()){
            std::cout << "[]\n";
        }

        for(auto v : listEdges){
            std::cout << "[" << "(" << v.getDestination() << ")" << v.getValue() << "]\n";
        }

    }

};

class Graph{

private:
    bool checkVertex(vertex v){

        std::vector<vertex>::iterator it;
        for(it = graphs.begin() ; it != graphs.end() ; it+=1){

            if(it->getDenomination() == v.getDenomination())
                return true;

        }
        return false;

    }

    bool checkVertexById(int valueVertex){

        std::vector<vertex>::iterator it;
        for(it = graphs.begin() ; it != graphs.end() ; it+=1){
            if(it->getDenomination() == valueVertex){
                return true;
            }
        }
        return false;
    }

public:
    std::vector<vertex> graphs;

    void deleteVertex(int v){

        std::vector<vertex>::iterator it;
        for(it = graphs.begin() ; it != graphs.end() ; it+=1){

            if(it->getDenomination() == v){

                std::cout << "vertex deleted\n";
                graphs.erase(it);
                return;

            }

        }
        std::cout << "vertex not found\n";

    }

    vertex getVertexById(int id){

        std::vector<vertex>::iterator it;
        for(int i = 0 ; i < graphs.size() ; i+=1){

            if(graphs.at(i).getDenomination() == id){

                return graphs.at(i);

            }

        }
        return -1;

    }

    void printAllVertex(){

        for(auto v : graphs){

            std::cout << v.getDenomination() << " --> ";
            v.printEdgeList();

        }

    }

    bool checkEdgeExists(int origin, int destination) {

        vertex v = getVertexById(origin);
        std::vector<edge> edge = v.listEdges;
        for(auto it = edge.begin() ; it != edge.end() ; it+=1){

            if(it->getValue() == destination){
                return true;
            }

        }
        return false;

    }

    void addEdgeOperation(int vertexOrigin, int vertexDestination, int valueEdge){

        bool check1 = checkVertexById(vertexOrigin);
        bool check2 = checkVertexById(vertexDestination);
        bool check3;

        if(check1 && check2){

            //checar se existe um edge entre eles.
            check3 = checkEdgeExists(vertexOrigin, vertexDestination);
            if(check3){
                std::cout << "edge already exists between vertex solicited";
                return;
            }
            else{

                std::size_t size = graphs.size();
                for(int i = 0 ; i < size ; i+=1){

                    if(graphs.at(i).getDenomination() == vertexOrigin){

                        edge e(vertexDestination,valueEdge);
                        graphs.at(i).listEdges.push_back(e);

                    }
                    if(graphs.at(i).getDenomination() == vertexDestination){

                        edge e(vertexOrigin,valueEdge);
                        graphs.at(i).listEdges.push_back(e);

                    }

                }

                std::cout << "edge added successfull";

            }

        }
        else{
            std::cout << "invalid vertex";
        }

    }

    void addVertex(vertex v){

        bool checkVertexExists = checkVertex(v.getDenomination());
        if(checkVertexExists){
            std::cout << "vertex already exists\n";
            return;
        }
        this->graphs.push_back(v);
        std::cout << "vertex add successfull\n";
    }

    //operations graph here

};

int main() {

    Graph g;
    vertex v;
    int vertexValue = 0;
    int operation {0};
    int vertexId1, vertexId2, edgeValue;
    while (true){

        std::cout << "what operation: ";
        std::cout << "\n1 - add vertex\n";
        std::cout << "2 - delete vertex\n";
        std::cout << "3 - print all vertex\n";
        std::cout << "4 - add edge vertex\n";
        std::cout << "what your option: ";
        std::cin >> operation;

        switch (operation) {

            case 1:
                std::cout << "operation for add vertex\n";
                std::cout << "vertex to add: ";
                std::cin >> vertexValue;
                v.setDenomination(vertexValue);
                g.addVertex(v);
                break;
            case 2:
                std::cout << "operation for delete vertex\n";
                std::cout << "vertex to delete: ";
                std::cin >> vertexValue;
                g.deleteVertex(vertexValue);
                break;
            case 3:
                std::cout << "printing all vertex\n";
                g.printAllVertex();
                break;
            case 4:
                std::cout << "operation for add edge\n";
                std::cout << "id for first vertex: ";
                std::cin >> vertexId1;
                std::cout << "id for second vertex: ";
                std::cin >> vertexId2;
                std::cout << "value for edge: ";
                std::cin >> edgeValue;
                g.addEdgeOperation(vertexId1, vertexId2, edgeValue);
                break;
        }
        std::cout << "continue [0 for exit]: ";
        std::cin >> operation;
        if(operation == 0){
            break;
        }
    }

    return 0;
}
