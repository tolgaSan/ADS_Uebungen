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
////// Task02
////// =================================================


#include <iostream>
# include <list>



std::list<int> union_of_lists(
        const std::list<int> &l1,
        const std::list<int> &l2) {

    std::list<int> result_union;
    auto l1Index = l1.begin();
    auto l2Index = l2.begin();

    //Listen durchlaufen mit bedingungen
    while (l1Index != l1.end() && l2Index != l2.end()) {
        if (*l1Index > *l2Index) {
            result_union.push_back(*l2Index);
            l2Index++;
        } else if (*l1Index < *l2Index) {
            result_union.push_back(*l1Index);
            l1Index++;
        } else if (*l1Index == *l2Index) {
            result_union.push_back(*l2Index);
            l1Index++;
            l2Index++;
        }
    }
    //Falls eine Liste leer ist, die andere volle Liste zurückgeben
    if (l1Index == l1.end()) {
        while (l2Index != l2.end()) {
            result_union.push_back(*l2Index);
            l2Index++;
        }
    }
    if (l2Index == l2.end()) {
        while (l1Index != l1.end()) {
            result_union.push_back(*l1Index);
            l1Index++;
        }
    }
    return result_union;
}




std::list<int> intersection_of_lists(const std::list<int>& l1,
    const std::list<int>& l2)
{
    std::list<int> result_intersection;

    auto l1Index = l1.begin();
    auto l2Index = l2.begin();  
    while(l1Index != l1.end() && l2Index != l2.end()) {
        if((*l1Index > *l2Index)) {
            l2Index++;
        } else if (*l1Index < *l2Index) {
            l1Index++;
        } else if (*l1Index == *l2Index) {
            result_intersection.push_back(*l1Index);
            l1Index++;
            l2Index++;
        }
    }

    // TODO: Solution for intersection

    return result_intersection;
}



int main()
{
    // Given example lists from the task describtion
    std::list<int> l1 = { 10, 11, 13, 15, 18, 20, 21 };
    std::list<int> l2 = { 4, 8, 10, 12, 14, 15, 18, 23 };


    // Call your implementation of the union_of_lists function and output the list
    std::list<int> list_unionResult = union_of_lists(l1, l2);
    for(auto i: list_unionResult) {
        std::cout << i << ":";
    }



    /*for(int i = 0; i < list_unionResult.size(); i++) {
        std::cout << list_unionResult(i) << ":" << std::endl; 
    }*/


    // Call your implementation of the list_intersectionResult function and output the list
    std::list<int> list_intersectionResult = intersection_of_lists(l1, l2);
    std::cout << "\n";
    for(auto i: list_intersectionResult) {
        
        std::cout << i << ":";
    }

    return 0;
}