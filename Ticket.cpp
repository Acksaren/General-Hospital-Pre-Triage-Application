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

#include "Ticket.h"
namespace sdds {
    nextTriageTicket::nextTriageTicket(int number) {
        m_number = number;
    }
    nextTriageTicket::operator Time() const {
        return m_time;
    }
    int nextTriageTicket::number() const {
        return m_number;
    }
    void nextTriageTicket::resetTime() {
        m_time.reset();
    }
    std::ostream& nextTriageTicket::csvWrite(std::ostream& ostr) const {
        return ostr << m_number << "," << m_time;
    }
    std::istream& nextTriageTicket::csvRead(std::istream& istr) {
        istr >> m_number;
        istr.ignore();
        return istr >> m_time;
    }
    std::ostream& nextTriageTicket::write(std::ostream& ostr) const {
        return ostr << "Ticket No: " << m_number << ", Issued at: " << m_time;
    }
    std::istream& nextTriageTicket::read(std::istream& istr) {
        return csvRead(istr);
    }
}
