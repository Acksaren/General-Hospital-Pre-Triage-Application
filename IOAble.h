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
#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_


namespace sdds
{
	class IOAble

	{

	public:

		virtual std::istream& csvRead(std::istream& istr) = 0;
		virtual std::ostream& csvWrite(std::ostream& os)const = 0;

		virtual std::ostream& write(std::ostream& os)const = 0;
		virtual std::istream& read(std::istream& istr) = 0;

		virtual ~IOAble() {}
	};

	std::ostream& operator<<(std::ostream& os, const IOAble& X);
	std::istream& operator>>(std::istream& istr, IOAble& Y);
}

#endif 
