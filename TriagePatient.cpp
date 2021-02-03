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


#include <cstring>
#include "TriagePatient.h"
#include<iostream>
#include<iomanip>


using namespace std;

namespace sdds
{
	int nextTriageTicket = 1;
	TriagePatient::TriagePatient() : Patient(nextTriageTicket), m_symp(nullptr)
	{

		nextTriageTicket++;

	}

	char TriagePatient::type()const
	{
		return 'T';
	}

	ostream& TriagePatient::csvWrite(ostream& os) const
	{
		Patient::csvWrite(os); os << ','; os << m_symp;
		return os;
	}


	istream& TriagePatient::csvRead(istream& istr)
	{
		int const array = 512;
		char array_symp[array];
		delete[] m_symp;

		m_symp = nullptr;
		Patient::csvRead(istr);
		istr.ignore(1000, ',');
		istr.get(array_symp, array, '\n');

		m_symp = new char[strlen(array_symp) + 1];
		strcpy(m_symp, array_symp);

		nextTriageTicket = Patient::number() + 1;
		return istr;
	}


	ostream& TriagePatient::write(ostream& os) const
	{
		if (fileIO())

		{
			csvWrite(os);
		}

		else

		{
			os << "TRIAGE" << '\n';
			Patient::write(os); os << '\n'; os << "Symptoms: "; os << m_symp; os << '\n';
		}
		return os;
	}


	istream& TriagePatient::read(istream& istr)
	{
		int const arrayTotal = 512;
		char arrayTotalSym[arrayTotal];
		if (fileIO())

		{
			csvRead(istr);
		}


		else
		{
			delete[] m_symp;
			m_symp = nullptr;

			Patient::read(istr);
			cout << "Symptoms: ";
			istr.get(arrayTotalSym, arrayTotal, '\n');
			istr.ignore();

			m_symp = new char[strlen(arrayTotalSym) + 1];
			strcpy(m_symp, arrayTotalSym);
		}
		return istr;
	}

	TriagePatient::~TriagePatient()
	{
		delete[] m_symp;
		m_symp = nullptr;
	}
}