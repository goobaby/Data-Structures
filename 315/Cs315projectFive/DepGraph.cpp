#include<iostream>
#include<cstring>
#include<queue>

#include "DepGraph.hpp"
#include "Token.hpp"
#include "Tokenizer.hpp"
#include "systemInterface.hpp"

void Graph::parseDepGraph()
{
    Tokenizer tokenizer = Tokenizer(_fileToMake);
    std::vector<Token *> line;
    Token *token = tokenizer.getToken();
    bool colonERROR = true;
    bool tabERROR = true;
    bool eolERROR = true;
    while( !token->eof())
    {
        line.push_back(token);
        if(token->eoc())
        {
            for(int i = 0; i < line.size(); i++)
            {
                if(line.at(i)->getFileName() == ":")
                {
                    colonERROR = false;
                }
                if(line.at(i)->getFileName() == "\t")
                {
                    tabERROR = false;
                }
                if(line.at(i)->getFileName() == "EOL")
                {
                    eolERROR = false;
                }

            }
            if(colonERROR)
            {
                std::cerr << "EXITING....NO COLON DETECTED" << std::endl;
                exit(1);
            }
            if(tabERROR)
            {
                std::cerr << "EXITING....NO TAB DETECTED" << std::endl;
                exit(1);
            }
            if(eolERROR)
            {
                std::cerr << "EXITING....NO EOL DETECTED" << std::endl;
                exit(1);
            }
            colonERROR = true;
            tabERROR = true;
            eolERROR = true;
            if(line.at(0)->isTarget())
            {
            }
            else
            {
                while(!line.at(0)->isTarget())
                    line.erase(line.begin());
            }
         
            for(int i = 1; i < line.size()-1; i++)
            {
                while(line.at(i)->getFileName() == "")
                {
                    line.erase(line.begin()+i);
                }  
            }
            
            //Parse
            if(_tree->find(line.at(0)->getFileName()) != nullptr)
            {
                GraphNode* existingtarget = _tree->find(line.at(0)->getFileName());
                for(int i = 1; i < line.size()-1; i++)
                {
                    if(line.at(i)->getFileName() != ":" and line.at(i)->getFileName() != "EOL" and line.at(i)->getFileName() != "\t")
                    {
                        if(_tree->find(line.at(i)->getFileName()) != nullptr)
                        {
                            GraphNode* existingDep = _tree->find(line.at(i)->getFileName());
                            existingtarget->addDependentNode(existingDep);
                        }
                        else
                        {
                            GraphNode* child = new GraphNode(line.at(i)->getFileName());
                            existingtarget->addDependentNode(child);
                            _tree->insert(child);
                        }
                    }
                }
                existingtarget->setCommand(line.back()->getCommand().c_str());
            }
            else
            {
                GraphNode* target = new GraphNode(line.at(0)->getFileName());
                target->isATarget(true);
                _tree->insert(target);
            
                for(int i = 1; i < line.size()-1; i++)
                {
                    if(line.at(i)->getFileName() != ":" and line.at(i)->getFileName() != "EOL" and line.at(i)->getFileName() != "\t")
                    {
                        if(_tree->find(line.at(i)->getFileName()) != nullptr)
                        {
                            GraphNode* existingDep = _tree->find(line.at(i)->getFileName());
                            target->addDependentNode(existingDep);
                        }
                        else
                        {
                            GraphNode* child = new GraphNode(line.at(i)->getFileName());
                            target->addDependentNode(child);
                            _tree->insert(child);
                        }
                    }
                }
                target->setCommand(line.back()->getCommand().c_str());
            }
            line.clear();
        }
        token = tokenizer.getToken();
    }

}

void Graph::print()
{
    TreeNode *printRoot = _tree->getRoot();
    if(printRoot == nullptr)
        return;
    std::queue<TreeNode *> queue;
    queue.push(printRoot);

    while(!queue.empty())
    {
        int size = queue.size();
        while(size > 0)
        {
            TreeNode* front = queue.front();
            front->print();
            queue.pop();
            if(front->left() != nullptr)
            {
                queue.push(front->left());
            }
            if(front->right() != nullptr)
            {
                queue.push(front->right());
            }
            size--;
        }
    }
}

bool Graph::isCyclic()
{
    TreeNode* cur = _tree->getRoot();

    if(cur == nullptr)
        return false;
    std::queue<TreeNode *> queue;
    queue.push(cur);

    while(!queue.empty())
    {
        int size = queue.size();
        while(size > 0)
        {
            TreeNode* front = queue.front();
            
            front->graphNode()->onPath(true);
            for(int i = 0; i < front->graphNode()->dependentNodes()->size(); i++)
            {
                if(isCyclic(front->graphNode()->dependentNodes()->at(i)))
                    return true;
            }
            front->graphNode()->onPath(false);

            queue.pop();
            if(front->left() != nullptr)
            {
                queue.push(front->left());
            }
            if(front->right() != nullptr)
            {
                queue.push(front->right());
            }
            size--;
        }
    }

    return false;
}

bool Graph::isCyclic(GraphNode * graphNode)
{
    if(graphNode == nullptr)
    {
        return false;
    }
    if(graphNode->onPath())
    {
        std::cout<< "========" << std::endl;
        graphNode->print();
        return true;
    }
    if(graphNode->dependentNodes()->size() <= 0) //Child
    {
        graphNode->onPath(false); //no cycle
        return false;
    }
    else
    {
        graphNode->onPath(true);
        for(int i = 0; i < graphNode->dependentNodes()->size(); i++)
        {
            if(isCyclic(graphNode->dependentNodes()->at(i)))
                return true;
        }
        graphNode->onPath(false);
        return false;
    }

}

void Graph::runMake()
{
    runMake(_tree->getRoot()->graphNode());
    if(upToDate == false)
    {
        std::cout << "make: '" << _tree->getRoot()->graphNode()->getName() << "' is up to date." << std::endl;
    }
}

void Graph::runMake(GraphNode *graphNode)
{
    
    if(graphNode == nullptr)
    {
        return;
    }
    if(graphNode->wasMade())
    {
        return;
    }
    if(graphNode->dependentNodes()->size() <= 0) //Child
    {
        long childTS;
        if( ! timestamp(graphNode->getName().c_str(), &childTS) ) 
        {
            std::cerr << "Couldn't stat " << graphNode->getName() << "!\n";
            exit(2);
        }
        if( graphNode->getTimestamp() == -1 ) //This will be remove in future implementaions of make to allow arguments like "make clean" to run
        {
            std::cerr << "File " << graphNode->getName() << " does not exist!\n";
            exit(3);
        }
        graphNode->wasMade(true);
        return;
    }
    else
    {
        int largest = 0; //GRABS the largest TS of the dependency the LOGIC could be once we get anything larger we break and run command
        //Best Case O(n)
        //Worst Case O(n)
        //Other Logic if we break NOT IMPLIMENTED
        //Best Case O(1)
        //Worst Case O(n) 
        for(int i = 0; i < graphNode->dependentNodes()->size(); i++)
        {
            runMake(graphNode->dependentNodes()->at(i));
            //save largest ts
            if(largest < graphNode->dependentNodes()->at(i)->getTimestamp())
            {
                largest = graphNode->dependentNodes()->at(i)->getTimestamp();
            }
        }
        if( graphNode->getTimestamp() < largest) //if the parent Node is before any of the children then UPDATE!
        {
            if(!executeCommand(graphNode->getCommand().c_str())) 
            {
                std::cerr << "Couldn't run command of " << graphNode->getName() << "!\n";
                exit(3);
            }
            upToDate = true;
            long temp;
            if( ! timestamp(graphNode->getName().c_str(), &temp) ) 
            {
                std::cerr << "Couldn't stat " << graphNode->getName() << "!\n";
                exit(2);
            }
            if( temp == -1 ) {
                std::cerr << "File " << graphNode->getName() << " does not exist!\n";
                exit(3);
            }
            graphNode->setTimestamp((int)temp);
            graphNode->wasMade(true);
        }

        return;
    }
}