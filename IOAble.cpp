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


#include <iostream>
#include "IOAble.h"

using namespace std;


namespace sdds

{
	ostream& operator<<(ostream& os, const IOAble& X)

	{
		X.write(os);
		return os;
	};


	istream& operator>>(istream& istr, IOAble& Y)

	{
		Y.read(istr);
		return istr;
	};

}