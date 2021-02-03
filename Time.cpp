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

#include "Time.h"
#include "utils.h"

using namespace std;

namespace sdds

{
    Time& Time::reset()
    {
        m_min = getTime();
        return *this;
    }


    Time::Time(unsigned int min)
    {
        m_min = min;
    }

    ostream& Time::write(ostream& ostr) const
    {
        ostr.width(2);
        ostr.fill('0');
        ostr << m_min / 60;
        ostr << ":";
        ostr.width(2);
        ostr << m_min % 60;
        return ostr;
    }

    istream& Time::read(istream& istr)
    {
        int hours, minutes = 0;
        int letters;

        istr >> hours;
        letters = istr.get();

        if (letters == ':')
        {
            istr >> minutes;
            m_min = hours * 60 + minutes;
        }

        else
        {

            istr.setstate(ios::failbit);
        }

        return istr;

    }

    Time::operator int() const
    {
        return m_min;
    }

    Time& Time::operator*=(int val)
    {
        m_min *= val;
        return *this;
    }

    Time& Time::operator-= (const Time& D)
    {
        if (D < int(m_min)) {
            m_min -= D;
        }
        else {
            m_min += 1440;
            m_min -= D;
        }
        return *this;
    }

    ostream& operator<< (ostream& os, const Time& T)
    {
        T.write(os);
        return os;
    }


    istream& operator>>(istream& in, Time& T)
    {
        T.read(in);
        return in;
    }

};