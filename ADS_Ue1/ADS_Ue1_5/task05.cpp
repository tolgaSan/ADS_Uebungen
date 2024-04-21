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
////// Task05
////// =================================================



// # include "ads_excercise01/DoubleStack.hpp"
# include "../include/ads_excercise01/DoubleStack.hpp"
#include <iostream>

DoubleStack::DoubleStack(int allocation_size = 10) {

    // TODO: Initialize all attributes depending on the allocation size for the array.
   

    m_allocation_size = allocation_size;
    m_array = new int[m_allocation_size];
    m_size = 0;
    m_i_stack0 = -1;
    m_i_stack1 = m_allocation_size;

    return;
}



void DoubleStack::push0(const int& item)
{
    // TODO: Add an item to the top of the stack 0.
    if(m_i_stack0 + 1 == m_i_stack1) {
        std::cout << "stack0 stößt an stack1, resize für anpassung" << std::endl;
        resize(); //implementiere resize noch
    }
    m_array[++m_i_stack0] = item;
    m_size++;
    return;
}



void DoubleStack::push1(const int& item)
{
    // TODO: Add an item to the top of the stack 1.
    //Wie push0, umgekehrt
    if(m_i_stack1 - 1 == m_i_stack0) {
        std::cout << "stack1 stößt an stack0, resize für anpassung" << std::endl;
        resize(); //implementiere resize noch
    }
    m_array[--m_i_stack1] = item;
    m_size++;
    return;
}



int DoubleStack::pop0()
{
    // TODO: Remove the item at the top of the stack 0 and return it.
    if(m_i_stack0 == -1) {
        std::cout << "stack0 leer" << std::endl;
        return -1;
    }

    int item = m_array[m_i_stack0--];
    m_size--;
    return item;
}



int DoubleStack::pop1()
{
    // TODO: Remove the item at the top of the stack 1 and return it.
    if(m_i_stack1 == m_allocation_size) {
        std::cout << "stack1 leer" << std::endl;
        return -1;
    }
    int item = m_array[m_i_stack1++];
    m_size--;
    return item;
}



void DoubleStack::resize()
{
    // TODO: Resize the internal array to get more memory for the stacks.
    int allocationSize = m_allocation_size * 2;
    int* new_array = new int[allocationSize];

    for(int i = 0; i < m_size; i++) {
        new_array[i] = m_array[i];
    }
    delete[] m_array;
    m_array = new_array;
    m_allocation_size = allocationSize;

    return;
}



int main()
{   
    DoubleStack doubleStack = DoubleStack();
    doubleStack.push0(5);
    doubleStack.push1(6);

    std::cout << "pop from stack0: " << doubleStack.pop0() << std::endl;
    std::cout << "pop from stack1: " << doubleStack.pop1() << std::endl;


    return 0;
}
