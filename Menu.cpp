/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author
Student#
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/09  Preliminary release
2020/11/11  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
----------------------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "utils.h"
#include "Menu.h"
using namespace std;
namespace sdds
{

    Menu::Menu(const char* Menucontent, int NoOfSelections)
    {
        m_text = nullptr;
        if (Menucontent[0] != '\0' && Menucontent != nullptr && NoOfSelections > 0)
        {
            m_noOfSel = NoOfSelections;
            m_text = new char[strlen(Menucontent) + 1];
            strcpy(m_text, Menucontent);
        }
        else
        {
            m_text = nullptr;
            m_noOfSel = 0;
        }
    }

    Menu::~Menu()
    {
        delete[] m_text;
        m_text = nullptr;
    }

    std::ostream& Menu::display(std::ostream& ostr) const
    {
        if (m_text[0] != '\0' && m_noOfSel > 0)
        {
            ostr << m_text << endl;
        }
        ostr << "0- Exit" << endl;
        ostr << "> ";
        return ostr;
    }

    int& Menu::operator>>(int& Selection)
    {
        display();
        Selection = getIntInRange(0, m_noOfSel);

        return Selection;
    }
} // namespace sdds