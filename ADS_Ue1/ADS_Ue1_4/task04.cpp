/*
    Algorithms and data structures - Summer Semester 2024
    Exercise01 - Basic data structures and their operations and input processing
    ---
    © FH Aachen - Facultie 5, Electrical Engineering and Information Technology - Insitute for Mobile Autonomous Systems and Cognitive Robotics
    Prof. Ingrid Scholl - scholl@fh-aachen.de
    ---
    Please refer to the tasks provided in the PDF for this exercise. 
    The PDF for this exercise can be found in the ILIAS course at https://www.ili.fh-aachen.de/.
*/



////// =================================================
////// Task04
////// =================================================



// # include "ads_excercise01/ListE.hpp"
# include "../include/ads_excercise01/ListE.hpp"



void ListE::print_reversed() const
{
    // TODO: Process the list recursively or iteratively.
    //Mithilfe von Stack als Reserve ausgeben: FirstInLastOut

    NodeE* node = m_head;
    std::stack<NodeE*> stackWithNode;
    while(node != nullptr){
        stackWithNode.push(node);
        node = node->next;
    } 

    while(!stackWithNode.empty()){
        node = stackWithNode.top();
        std::cout << node->item;
        stackWithNode.pop();
        if(!stackWithNode.empty()) {
            std::cout << ":";
        }
    }

    std::cout << "\n";





    return;
}



// NOTE: If the algorithm is implemented recursively, the following method should be used as a helper
void ListE::print_reversed_helper(NodeE* node) const
{
    // TODO, OPTIONAL: Process current sublist recursively

    return;
}



int main()
{

    ListE list_singleLinkedexmpl_init = ListE({0,1,2,3,4,5,6,7,8,9});
    list_singleLinkedexmpl_init.print_reversed();

    return 0;
}