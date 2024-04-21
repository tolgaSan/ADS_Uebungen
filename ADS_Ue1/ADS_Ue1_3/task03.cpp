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
////// Task03
////// =================================================



// # include "ads_excercise01/Deque.hpp"
# include "../include/ads_excercise01/Deque.hpp"
#include <iostream>

void Deque::push_front(const int& item)
{
    // TODO: Insert a new item at the beginning of the deque.

    NodeD* newNode = new NodeD();
    newNode->item = item;

    //bei leerer Deque newNode als neuen Knoten mit m_head einsetzen, sonst anfang der Deque hinterm head einsetzen und newNode als neuen Head
    if(m_head == nullptr) {
        m_head = newNode;
    }else{
        newNode->next = m_head;
        m_head->prev = newNode;
        m_head = newNode;
    }

    return;
}



int Deque::pop_front()
{
    // TODO: Remove an item from the beginning of the deque and return it.
    //leere Deque, return
    int itemValue = m_head->item;
    if(m_head == nullptr) {
        return false;
    }

    //Fall für einen Knoten in der Deque, ansonsten head auf den nächsten setzen und den hinteren auf nullpointer
    if(m_head == m_tail) {
        m_head = nullptr;
        m_tail = nullptr;
    } else {
        m_head = m_head->next;
        m_head->prev = nullptr;
    }

    return itemValue;
}




void Deque::push_back(const int& item)
{
    // TODO: Insert a new item at the ending of the deque.
    NodeD* newNode = new NodeD();
    newNode->item = item;

    //leere Deque, ansonsten ähnlich wie bei push_front
    if(m_head == nullptr) {
        m_tail = newNode;
        m_head = newNode;
    }else{
        m_tail->next = newNode;
        newNode->prev = m_tail;
        m_tail = newNode;
    }
    return;
}



int Deque::pop_back()
{
    // TODO: Remove an item from the ending of the deque and return it.
    //Fall wenn Deque leer
    if(m_head == nullptr){
        return false;
    }
    int itemValue = m_tail->item;
    //Flal wenn ein Knoten
    if(m_head == m_tail) {
        m_head = nullptr;
        m_tail = nullptr;
    } else {
        m_tail = m_tail->prev;
        m_tail->next = nullptr;
        // m_tail->prev->next = nullptr;
        // m_tail->prev = nullptr;

    }

    return itemValue;
}



void Deque::print_all() const
{
    // TODO: Print all items from the beginning to the end of the deque to the console.
    NodeD* current = m_head;
    while(current != nullptr) {
        std::cout << current->item << ":";
        current = current->next;
    }
    std::cout << std::endl;
    return;
}



int main()
{

    Deque deque;
    deque.push_back(1); // Deque muss jetzt eine 1 haben.
    deque.push_front(5); // Deque muss jetzt 5 1 sein
    deque.push_front(2); // Deque muss jetzt 2 5 1 sein
    deque.push_back(4); // 2 5 1 4
    deque.print_all();
    deque.pop_back(); // 2 5 1 
    deque.print_all();
    deque.pop_front(); // 5 1 
    deque.print_all(); 
    //cool

    return 0;
}