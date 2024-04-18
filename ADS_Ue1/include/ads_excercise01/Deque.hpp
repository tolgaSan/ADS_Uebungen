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



#ifndef Deque_HPP
#define Deque_HPP



#include <list>
// #include "ads_excercise01/NodeD.hpp"
#include "NodeD.hpp"

class Deque
{
public:
    // Konstruktor
    Deque() : m_head(nullptr), m_tail(nullptr) {};
    Deque(std::initializer_list<int> init) : m_head(nullptr), m_tail(nullptr)
    {
        for (const int& item : init) this->push_back(item);
    }
    // Hier gehoert eigentlich ein Copy Konstruktor hin
    // (der wird aber fuer uebersichtlicheren Code weggelassen)

    // Dekonstruktor
    ~Deque()
    {
        if (m_head == nullptr) return;
        while (m_head->next != nullptr)
        {
            m_head = m_head->next;
            delete m_head->prev;
        }
        delete m_head;
    }

    // Zu implementierende Methoden
    void push_front(const int& item);
    int pop_front();
    void push_back(const int& item);
    int pop_back();
    void print_all() const;

    // Hier gehoert eigentlich ein Assignment (copy) Operator hin
    // (der wird aber fuer uebersichtlicheren Code weggelassen)
private:
    NodeD* m_head;
    NodeD* m_tail;
};



#endif