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

#ifndef SDDS_TRIAGE_PAT_H
#define SDDS_TIRAGE_PAT_H

#include "Patient.h"
#include <iostream>


namespace sdds
{
	class TriagePatient : public Patient

	{
		char* m_symp;

	public:

		TriagePatient();
		~TriagePatient();

		virtual char type() const;

		std::ostream& csvWrite(std::ostream& os)const;
		std::istream& csvRead(std::istream& istr);

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& os)const;


	};

}
#endif // !SDDS_


