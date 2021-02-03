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

#include "Patient.h"
#include "CovidPatient.h"

using namespace std;

namespace sdds
{
	int nextCovidTicket = 1;
	CovidPatient::CovidPatient() : Patient(nextCovidTicket)

	{
		nextCovidTicket++;
	}

	char CovidPatient::type() const
	{
		return 'C';
	}


	ostream& CovidPatient::csvWrite(ostream& os) const
	{
		Patient::csvWrite(os);
		return os;
	}


	istream& CovidPatient::csvRead(istream& istr)
	{
		Patient::csvRead(istr);
		nextCovidTicket = number() + 1;
		return istr;

	}


	ostream& CovidPatient::write(ostream& os) const
	{

		if (fileIO() == true)
		{
			csvWrite(os);
		}

		else

		{
			os << "COVID TEST" << '\n'; Patient::write(os);
			os << '\n';
		}

		return os;
	}


	istream& CovidPatient::read(istream& istr)
	{
		if (fileIO() == true)
		{
			csvRead(istr);
		}

		else

		{
			Patient::read(istr);
		}


		return istr;
	}

}