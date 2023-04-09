#include <iostream>
#include <vector>

class edge{
private:
    int value;
public:
    edge(){

    }

    edge(int v){
        this->value = v;
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
            std::cout << "[" << v.getValue() << "]";
        }

    }

};

class Graph{

private:
    bool checkVertex(vertex v){

        for(std::size_t i{0} ; i < graphs.size() ; i+=1){

            if(graphs.at(i).getDenomination() == v.getDenomination())
                return true;

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

    void printAllVertex(){

        for(auto v : graphs){

            std::cout << v.getDenomination() << " --> ";
            v.printEdgeList();

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
    while (true){

        std::cout << "what operation: ";
        std::cout << "\n1 - add vertex\n";
        std::cout << "2 - delete vertex\n";
        std::cout << "3 - print all vertex\n";
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
        }
        std::cout << "continue [0 for exit]: ";
        std::cin >> operation;
        if(operation == 0){
            break;
        }
    }

    return 0;
}
