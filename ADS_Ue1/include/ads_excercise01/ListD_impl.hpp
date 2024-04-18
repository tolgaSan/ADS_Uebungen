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



#ifndef ListD_IMPL_HPP
#define ListD_IMPL_HPP



// # include "ads_excercise01/ListD.hpp"
# include "ListD.hpp"


 // Konstruktor
ListD::ListD() : m_length(0), m_head(nullptr), m_tail(nullptr) { };


ListD::ListD(std::initializer_list<int> init) : m_length(0), m_head(nullptr), m_tail(nullptr)
{
    for (const int& item : init) this->add(item);
}



// Copy Konstruktor
ListD::ListD(const ListD& other) : m_length(0), m_head(nullptr), m_tail(nullptr) { *this = other; }



// Dekonstruktor
ListD::~ListD()
{
    if (m_head == nullptr) return;
    while (m_head->next != nullptr)
    {
        m_head = m_head->next;
        delete m_head->prev;
    }
    delete m_head;
}



// Add Methode welche am Ende der Liste einen Knoten mit der 
// Variable item anfuegt
void ListD::add(const int& item)
{
    m_length++;

    NodeD* new_node = new NodeD();
    new_node->item = item;
    new_node->prev = m_tail;

    if (m_tail == nullptr) m_head = new_node;
    else m_tail->next = new_node;

    m_tail = new_node;
}



// Search Methode sucht das Element item in der Liste
bool ListD::search(const int& item) const
{
    NodeD* search_node = this->search_node(item);
    if (search_node == nullptr) {
        std::cout << "Wert " << item << " ist nicht in der Liste vorhanden!" << std::endl;
        return false;
    }
    else {
        std::cout << "Wert " << item << " wurde in der Liste gefunden!" << std::endl;
        return true;
    }
}



// Print Methode um Liste auszugeben
void ListD::print() const
{
    NodeD* current = m_head;
    std::cout << "[";
    while (current != nullptr)
    {
        std::cout << current->item;
        if (current->next != nullptr)
        {
            std::cout << ", ";
            current = current->next;
        }
        else break;
    }
    std::cout << "]" << std::endl;
}



// Print Methode um Liste rueckwaerts auszugeben
void ListD::print_reversed() const
{
    NodeD* current = m_tail;
    std::cout << "[";
    while (current != nullptr)
    {
        std::cout << current->item;
        if (current->prev != nullptr)
        {
            std::cout << ", ";
            current = current->prev;
        }
        else break;
    }
    std::cout << "]" << std::endl;
}



// gibt die Laenge der Liste zurueck
int ListD::length() const { return m_length; }



// remove Methode löscht das Element item in der Liste
bool ListD::remove(const int& item)
{
    NodeD* del_node = search_node(item);
    if (del_node != nullptr) {
        if (del_node == m_head) m_head = del_node->next;
        if (del_node == m_tail) m_tail = del_node->prev;

        if (del_node->prev != nullptr) del_node->prev->next = del_node->next;
        if (del_node->next != nullptr) del_node->next->prev = del_node->prev;

        delete del_node;

        std::cout << "Element " << item << " erfolgreich aus der Liste entfernt!" << std::endl;
        return true;
    }
    else {
        std::cout << "Element " << item << " konnte nicht geloescht werden!" << std::endl;
        return false;
    }
}



// Loescht alle Elemente aus der Liste
void ListD::clear()
{
    if (m_head == nullptr) return;
    // delete all nodes
    while (m_head->next != nullptr)
    {
        m_head = m_head->next;
        delete m_head->prev;
    }
    delete m_head;

    // cleanup
    this->m_head = nullptr;
    this->m_tail = nullptr;
    this->m_length = 0;
}



// Assignment (Copy) Operator
ListD& ListD::operator=(const ListD& other)
{
    this->clear();
    // copy nodes
    NodeD* current = other.m_head;
    while (current != nullptr)
    {
        this->add(current->item);
        current = current->next;
    }
    return *this;
}



NodeD* ListD::search_node(const int& item) const
{
    NodeD* tmp = m_head;
    while (tmp != nullptr && tmp->item != item) tmp = tmp->next;
    return tmp;
}



#endif