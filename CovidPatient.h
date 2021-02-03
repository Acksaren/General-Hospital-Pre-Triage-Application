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


#ifndef SDDS_COVID_PATIENT_H_
#define SDDS_COVID_PATIENT_H_

#include "Patient.h"

namespace sdds

{

	class CovidPatient : public Patient

	{

	public:

		CovidPatient();

		virtual char type()const;

		std::ostream& csvWrite(std::ostream& os)const;
		std::istream& csvRead(std::istream& istr);

		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& istr);


	};
}
#endif // !SDDS_COVIDPATIENT_H_



