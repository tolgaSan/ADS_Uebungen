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



#ifndef ListD_HPP
#define ListD_HPP



// includes
#include <iostream>
#include <list>
#include <stdexcept>
#include <stack>
#include <string>
#include <ctype.h>
#include <sstream>

// #include "ads_excercise01/NodeD.hpp"
#include "NodeD.hpp"


// Doppelt VL
class ListD
{
public:
    // Konstruktor
    ListD();
    ListD(std::initializer_list<int> init);

    // Copy Konstruktor
    ListD(const ListD& other);

    // Dekonstruktor
    ~ListD();

    // Add Methode welche am Ende der Liste einen Knoten mit der 
    // Variable item anfuegt
    void add(const int& item);

    // Search Methode sucht das Element item in der Liste
    bool search(const int& item) const;

    // Print Methode um Liste auszugeben
    void print() const;

    // Print Methode um Liste rueckwaerts auszugeben
    void print_reversed() const;

    // gibt die Laenge der Liste zurueck
    int length() const;
    
    // remove Methode löscht das Element item in der Liste
    bool remove(const int& item);

    // Swap Methode welche den Knoten an der stelle 
    // Index mit dem naechsten tauscht
    bool swap(const int& index);

    // Loescht alle Elemente aus der Liste
    void clear();

    // Assignment (Copy) Operator
    ListD& operator=(const ListD& other);

private:
    NodeD* search_node(const int& item) const;

    NodeD* m_head;
    NodeD* m_tail;
    int m_length;
};



// #include "ads_excercise01/ListD_impl.hpp"
#include "ListD_impl.hpp"



#endif