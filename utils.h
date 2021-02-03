/* Citation and Sources...
Final Project Milestone 5
Module: Time
Filename: Time.h
Version 1.0
Author	Acksaren Ravinjan
Revision History
-----------------------------------------------------------
Date      Reason
2020/12/05  Preliminary release
2020/12/05  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>

namespace sdds

{
    int getInt();
    int getTime(); // returns the time of day in minutes

    extern bool debug; // this makes bool sdds::debug variable in utils.cpp global to
                       // all the files which include: "utils.h"
                       //(you will learn this in detail in oop345)

    int getIntInRange(int min, int max);

} 


template <typename type>
void removeDynamicElement(type* arraysize[], int value, int& result)


{
    delete arraysize[value];

    for (int i = value; i < result; i++)
    {
        arraysize[i] = arraysize[i + 1];
    }
    result--;
}

#endif // !SDDS_UTILS_H_
