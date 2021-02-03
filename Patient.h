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
#include "Ticket.h"

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_

namespace sdds

{

    class Patient : public IOAble

    {
        char* m_patname = nullptr;
        int long m_ohipnum = 0;
        nextTriageTicket m_ticket;
        bool fileIOfalse = false;

    public:

        Patient(int tic = 0, bool result = false);
        Patient(const Patient& Patienty) = delete;
        Patient& operator=(const Patient& Patientx) = delete;

       
        virtual char type() const = 0;
        bool fileIO() const;
        void fileIO(bool value);

        bool operator==(char value) const;
        bool operator==(Patient const& Patientz)const;

        ~Patient();
        void setArrivalTime();
        operator Time() const;
        int number() const;

        std::ostream& csvWrite(std::ostream& os) const;
        std::istream& csvRead(std::istream& is);

        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& is);
    };

} 
#endif // !SDDS_PATIENT_H_
