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



#ifndef DoubleStack_HPP
#define DoubleStack_HPP



class DoubleStack
{
public:
    DoubleStack(int allocation_size);

    // Fuegt ein Element zu Stack 0 hinzu
    void push0(const int& item);
    // Fuegt ein Element zu Stack 1 hinzu
    void push1(const int& item);

    // Entfernt ein Element von Stack 0
    int pop0();
    // Entfernt ein Element von Stack 1
    int pop1();

    // Hier gehoert eigentlich ein Assignment (copy) Operator hin
    // (der wird aber fuer uebersichtlicheren Code weggelassen)
private:
    // Ihre Variablen hier:
    int* m_array;
    int m_allocation_size;  // Wie viel Speicher allokiert werden soll, 
    // bei einer vergroeßerung des Arrays
    int m_size; // Groeße des Arrays
    int m_i_stack0;  // Index von Stack 0
    int m_i_stack1;  // Index von Stack 1

    // Interne Resize Methode um bei vollem Array mehr 
    // Speicher zu allokieren:
    void resize();
};



#endif