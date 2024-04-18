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



#ifndef ListE_HPP
#define ListE_HPP



// includes
#include <iostream>
#include <list>
#include <stdexcept>
#include <stack>
#include <string>
#include <ctype.h>
#include <sstream>
#include <initializer_list>
#include "NodeE.hpp"
//#include "ads_excercise01/NodeE.hpp"

// Einfach VL
class ListE
{
public:
    // Konstruktor
    ListE();
    ListE(std::initializer_list<int> init);
    // Copy Konstruktor
    ListE(const ListE& other);

    // Dekonstruktor
    ~ListE();

    // Add Methode welche am Ende der Liste einen 
    // Knoten mit der Variable item anfuegt
    void add(const int& item);

    // Search Methode sucht das Element item in der Liste
    bool search(const int& item);

    // Print Methode um Liste auszugeben
    void print() const;

    // Gibt die Laenge der Liste zurueck
    int length() const;

    // remove Methode löscht das Element item in der Liste
    bool remove(const int& item);

    // Swap Methode welche den Knoten an der Stelle Index mit dem nächsten tauscht
    bool swap(const int& index);

    // Print Methode welche die Knoten rueckwaerts 
    // (in O(n)) ausgibt. Wird bei Aufgabe 4 implementiert.
    void print_reversed() const;

    // Loescht alle Elemente aus der Liste
    void clear();

    // Assignment (Copy) Operator
    ListE& operator=(const ListE& other);

private:
    // Hilf Methode fuer print reversed (wenn print reversed rekursiv 
    // implementiert wird)
    void print_reversed_helper(NodeE* node) const;

    NodeE* search_node(const int& item);

    NodeE* m_head;
    NodeE* m_tail;
    int m_length;
};

// #include "ads_excercise01/ListE_impl.hpp"
#include "ListE_impl.hpp"



#endif