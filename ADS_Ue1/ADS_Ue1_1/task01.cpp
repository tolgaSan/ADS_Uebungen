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
////// Task01
////// =================================================


// # include "ads_excercise01/ListE.hpp"
// # include "ads_excercise01/ListD.hpp"
# include "../include/ads_excercise01/ListE.hpp"
# include "../include/ads_excercise01/ListD.hpp"



bool ListE::swap(const int& index)
{
    /*NodeE* node = m_head;

    //Liste leer, da head auf nullptr zeigt
    if(m_head == nullptr) {
        return false;
    }
    //traversieren: Nachfolger sowie Tauschpartner darf kein nullptr sein
    for(int i = 0; i > index ; i++) {
        if(node->next != nullptr && node->next->next != nullptr) {
            node = node->next; 
        } else {
            return false;
        }
    }
    NodeE* tmp = m_head;
    //tmp auf den prev von Node/Index setzen
    for(int i = 0; i > index-1 ; i++) {
        if(node->next != nullptr && node->next->next != nullptr) {
            tmp = tmp->next; 
        } else {
            return false;
        }
    }
    //Listenbeispiel mit 1 - 2 - 3 - 4
    //tmp ist node-1, node steht bei 2
    //tmp zeigt auf 2 (aktueller node)
    tmp->next = node;
    //node ist jetzt sein tauschpartner
    node = node->next;
    //node tauschpartner nimmt den node
    node->next = tmp->next;
    //um die Liste zu erhalten, soll tmp den Index 3 zeigen 
    tmp->next->next = node;

    //somit ist Liste 1 - 3 - 2 - 4 */
    // TODO: Solution for (single) linked list.
    //Überprüfung auf leere Liste oder ob Index angegeben ist
    if (m_head == nullptr || index < 0 || index >= m_length - 1) {
        return false;
    }

    //node (current) Listenanfang initialisieren
    NodeE* current = m_head;
    NodeE* prev = m_head;
    //traversieren durch die Liste um Position zu finden
    for(int i = 0; i < index && current != nullptr; i++) {
        if(current->next != nullptr && current->next->next != nullptr) {
            prev = current;
            current = current->next;    
        } else { 
            return false;
        }
    }
    
    if(current->next == m_tail) {
        m_tail = current;
    }
    if(prev == m_head) {
        m_head = current->next;
    } else {
        prev->next = current->next; 
    }
        prev = current->next;
        current->next = prev->next;
        prev->next = current;
    


    return true;

}



bool ListD::swap(const int& index)
{
    // TODO: Solution for (double) linked list.
    if(m_head == nullptr){
        return false;
    }

    NodeD* current = m_head;
    for(int i = 0; i < index; i++){
        if(current->next != nullptr && current->next->next != nullptr){
            current = current->next;
        }
        else{
            return false;
        }
    }
    // Fall 1: Tauschpartner ist tail
    if(current->next == m_tail){
        m_tail = current;
    }
    // Falls 2: Current ist head
    if(current->prev == nullptr){
        m_head = current->next;
    }else{
        // current hat Vorgänger
        current->prev->next = current->next;
    }
    //Pointer umbiegen
    current->next->prev = current->prev;

    current->prev = current->next;

    current->next = current->next->next;

    current->prev->next = current;

    // Fall Tauschpartner hat nachfolger
    if(current->next != nullptr){
        current->next->prev = current;
    }

    return true;

}



int main()
{
    //// Example lists for the task

    ListE list_singleLinkedexmpl_init = ListE({0,1,2,3,4,5,6,7,8,9});
    ListD list_doubleLinkedexmpl_init = ListD({0,1,2,3,4,5,6,7,8,9});
 
    //std::cout << "default";
    //list_singleLinkedexmpl_init.print();
    std::cout << "Default: ";
    //list_doubleLinkedexmpl_init.print();
    /*
    for (int i = 0; i < list_doubleLinkedexmpl_init.length() - 1; i++)
    {
        list_doubleLinkedexmpl_init.swap(i);
        std::cout << "After swap index " << i << ": ";
        list_doubleLinkedexmpl_init.print();
    }*/

    

    for(int i = 0; i < list_singleLinkedexmpl_init.length(); i++) {
         list_singleLinkedexmpl_init.print();
         list_singleLinkedexmpl_init.swap(i);
         list_singleLinkedexmpl_init.print();
    }


    //std::cout << "Reversed: ";
   // list_doubleLinkedexmpl_init.print_reversed();

    system("PAUSE");
    // TODO: Execute swap for double-linked list
    return 0;

}