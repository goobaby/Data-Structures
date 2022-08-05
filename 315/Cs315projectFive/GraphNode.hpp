#include<iostream>
#include<string>
#include<vector>

#include "systemInterface.hpp"

class GraphNode {
public:
    GraphNode( std::string name ) 
    {
        _name = name; _listOfDependentNodes = new std::vector<GraphNode *>; 
        _onPath = false;
        long temp;
        if(!timestamp(this->getName().c_str(), &temp))
        {
            std::cerr << "Couldn't stat " << this->getName() << "!\n";
            exit(2);
        }
        this->setTimestamp((int)temp);
        this->wasMade(false);
        //std::cout << "getting timestamp: " << this->getTimestamp()  << ": inserted" << (int)temp <<  std::endl;
    }
    std::string getName(){ return _name;}
    void setName( std::string name ) { _name = name; } //Change Name????
    void setTimestamp(int ts) { _timestamp = ts;}
    int getTimestamp() {return _timestamp;}
    std::vector<GraphNode *> *dependentNodes() {return _listOfDependentNodes;}
    void setCommand(std::string cmnd) { _command = cmnd;}
    std::string getCommand() {return _command;}
    void runCommand();  // execute the command associated with this node. Only for target nodes.
    void addDependentNode(GraphNode *child) {_listOfDependentNodes->push_back(child);} //after you add child
    bool onPath() {return _onPath;}
    void onPath(bool v) {_onPath = v;} //Setter helps to catch loops/cyclics in BST like ladder if reach true then cyclic, if reach false then set to true. 
    bool wasMade() {return _wasMade;} //already made object
    void wasMade(bool v) {_wasMade = v;} //Setter checks tree
    bool isATarget() {return _isATarget;}
    void isATarget(bool v) {_isATarget = v;} //Setter
    int numDependentNodes() {return _listOfDependentNodes->size();} //size of vector elements
    void print()
    {
        std::cout << "Name: " << _name << std::endl;
        std::cout << "Command: " << _command << std::endl;
        std::cout << "Timestamp: " << _timestamp << std::endl;
        std::cout << "Dependents: ";
        if(_listOfDependentNodes->size() == 0)
        {
            std::cout << "No Dependents" << std::endl;
        }
        else
        {
            for(int i=0; i < _listOfDependentNodes->size(); i++)
            {
                std::cout << _listOfDependentNodes->at(i)->getName() << ", ";
            }
            std::cout << std::endl;
        }
        std::cout << "---------------------" << std::endl;
    }

private:
    std::string _name, _command; //make.x g++..blah
    int _timestamp;
    std::vector<GraphNode *> *_listOfDependentNodes; //.push(child)

    bool _onPath, _isATarget, _wasMade;
};
