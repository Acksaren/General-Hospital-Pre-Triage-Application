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


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "utils.h"


using namespace std;

namespace sdds

{
	Patient::Patient(int tic, bool result) :m_ticket(tic)
	{

		fileIOfalse = result;
	};

	bool Patient::fileIO()const
	{
		return fileIOfalse;
	};

	void Patient::fileIO(bool value)
	{
		fileIOfalse = value;
	};


	bool Patient::operator==(char value)const
	{
		return type() == value;
	};


	bool Patient:: operator==(Patient const& Patientx)const
	{
		return type() == Patientx.type();

	};

	void Patient::setArrivalTime()
	{

		m_ticket.resetTime();
	};

	Patient::operator Time ()const
	{
		return m_ticket;
	};

	int Patient::number()const
	{
		return m_ticket.number();
	};


	//destructor
	Patient::~Patient()
	{

		delete[] m_patname;
		m_patname = nullptr;
	};


	//cvswrite
	ostream& Patient::csvWrite(std::ostream& ostr) const
	{
		ostr << type()
			<< ',' << m_patname << ','
			<< m_ohipnum << ',';

		m_ticket.csvWrite(ostr);
		return ostr;

	};

	//cvsread
	istream& Patient::csvRead(std::istream& istr)
	{
		char nOfPatient[51];
		istr.get(nOfPatient, 51, ',');

		delete[] m_patname;

		m_patname = nullptr;
		m_patname = new char[strlen(nOfPatient) + 1];

		strcpy(m_patname, nOfPatient);

		istr.ignore(1000, ',');
		istr >> m_ohipnum;
		istr.ignore(1000, ',');

		m_ticket.csvRead(istr);
		return istr;
	};


	//write
	ostream& Patient::write(std::ostream& ostr) const
	{
		ostr << m_ticket
			<< '\n' << m_patname
			<< ", OHIP: " << m_ohipnum;

		return ostr;
	};


	//read

	istream& Patient::read(std::istream& istr)
	{
		cout << "Name: ";

		char numOfPat[51];
		bool result = true;

		istr.get(numOfPat, '\n');

		delete[]m_patname;

		m_patname = nullptr;
		m_patname = new char[strlen(numOfPat) + 1];

		strcpy(m_patname, numOfPat);

		istr.ignore(1000, '\n');
		cout << "OHIP: ";


		while (result)
		{
			if ((m_ohipnum = getInt()))
			{
				result = !(m_ohipnum >= 100000000 && m_ohipnum <= 999999999);

				if (result)
				{
					cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
				}

			}
			else
			{
				result = false;
			}

		}
		return istr;
	};
}