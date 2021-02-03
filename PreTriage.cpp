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
#include <fstream>
#include <cstring>
#include "PreTriage.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "Time.h"

using namespace std;

namespace sdds 

{

	PreTriage::PreTriage(const char* dataFilename)
	{
		if (m_dataFilename != nullptr)
		{
			delete[] m_dataFilename;
			m_dataFilename = nullptr;
		}

		if (dataFilename != nullptr && dataFilename[0] != '\0')

		{
			int len = strlen(dataFilename);

			m_dataFilename = new char[len + 1];
			strncpy(m_dataFilename, dataFilename, len);
			m_dataFilename[len] = '\0';

			new (&m_appMenu) Menu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2);
			new (&m_pMenu) Menu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2);

			m_averCovidWait = 15;
			m_averTriageWait = 5;
			load();
		}

		else
		{
			m_dataFilename = nullptr;
		}

	};

	PreTriage::~PreTriage()

	{
		ofstream myFile;

		myFile.open(m_dataFilename);

		myFile << m_averCovidWait << "," << m_averTriageWait << endl;

		cout << "Saving Average Wait Times," << endl; cout << "   COVID Test: "; m_averCovidWait.write(cout); cout << endl;

		cout << "   Triage: "; m_averTriageWait.write(cout); cout << endl;

		cout << "Saving m_lineup..." << endl;

		for (int i = 0; i < m_lineupSize; i++) 
		{
			m_lineup[i]->fileIO(true);
			m_lineup[i]->csvWrite(myFile);

			myFile << endl;

			m_lineup[i]->fileIO(false); cout << i + 1 << "- "; m_lineup[i]->csvWrite(cout); cout << endl;
		}

		myFile.close();

		for (int i = 0; i < m_lineupSize; i++) 
		{
			delete m_lineup[i];
		}

		delete[] m_dataFilename;
		m_dataFilename = nullptr;


		cout << "done!" << endl;
	}

	const Time PreTriage::getWaitTime(const Patient& p) const
	{
		int value = 0;
		int i = 0;

		for (int i = 0; i < m_lineupSize; i++)
		{

			if (m_lineup[i] == &p)
			{
				i++;
			}
		}

		if (p.type() == 'C') 

		{
			value = i * m_averCovidWait;
		}

		else 
		{
			value = i * m_averCovidWait;
		}

		return value;
	}

	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		int timeC = getTime();

		if (p.type() == 'C') 
		{
			m_averCovidWait = ((timeC - Time(p)) + (m_averCovidWait * (p.number() - 1))) / p.number();
		}

		else 
		
		{
			m_averTriageWait = ((timeC - Time(p)) + (m_averTriageWait * (p.number() - 1))) / p.number();
		}

	}

	int PreTriage::indexOfFirstInLine(char type) const
	{
		int result = -1;
		for (int i = 0; i < m_lineupSize && result == -1; i++)

		{
			if (m_lineup[i]->type() == type)
			{
				result = i;
			}
		}

		return result;
	}

	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}


	void PreTriage::load() 

	{
		bool result = false;
		Patient* pat = nullptr;

		char valie;
		int num = 0;

		cout << "Loading data..." << endl;

		std::ifstream fin(m_dataFilename);

		fin >> m_averCovidWait; fin.ignore(); fin >> m_averTriageWait; fin.ignore(2000, '\n');

		do
		{
			result = false;
			valie = '\0';

			fin.get(valie);
			fin.ignore(8, ',');

			if (toupper(valie) == 'C')

			{
				pat = new CovidPatient();
				result = true;
			}

			else if (toupper(valie) == 'T')
			{
				pat = new TriagePatient();
				result = true;
			}

			if (result)
			{
				pat->fileIO(true);
				pat->csvRead(fin);
				fin.ignore(8, '\n');
				pat->fileIO(false);

				m_lineup[m_lineupSize] = pat;
				m_lineupSize++;
				pat = nullptr;
				num++;
			}

		} while (result && num < maxNoOfPatients);

		fin.close();

		if (num >= maxNoOfPatients) 
		{
			cout << "Warning: number of records exceeded " << num << endl; cout << num << " Records imported..." << endl;
		}

		else if (num == 0) 
		{
			cout << "No data or bad data file!" << endl;
		}

		else 
		{
			cout << num << " Records imported..." << endl;
		}

		cout << endl;

	}


	void PreTriage::reg()
	{
		Patient* pat = nullptr;

		if (m_lineupSize == 100)
		{
			cout << "Line up full!" << endl;
		}
		else

		{
			m_pMenu.display();
			int choice = getIntInRange(0, 2);

			if (choice == 1)
			{
				pat = new CovidPatient();
			}
			else if (choice == 2)
			{
				pat = new TriagePatient();
			}
			else
			{
				exit(0);
			}

			pat->setArrivalTime();
			cout << "Please enter patient information: " << endl;
			pat->fileIO(false);
			pat->read(cin);

			cout << endl;
			cout << "******************************************" << endl;
			pat->write(cout);
			cout << "Estimated Wait Time: ";
			cout << getWaitTime(*pat) << endl;
			cout << "******************************************" << endl << endl;

			m_lineup[m_lineupSize] = pat;
			m_lineupSize++;
			pat = nullptr;

		}
	}


	void PreTriage::admit()
	{
		int selection, index;
		char type = 'x';

		m_pMenu >> selection;
		switch (selection)

		{
		case 1:
			type = 'C';
			break;
		case 2:
			type = 'T';
			break;
		}

		index = indexOfFirstInLine(type);

		if (index != -1)
		{
			cout << endl << "******************************************" << endl;
			cout << "Calling for " << *m_lineup[index]; cout << "******************************************" << endl << endl;
			setAverageWaitTime(*m_lineup[index]);

			removePatientFromLineup(index);
		}
	}

	void PreTriage::run(void)
	{
		int selection = 0;
		do 
		{
			m_appMenu >> selection;
			switch (selection)
			
			{

			case 1:
				reg();
				break;

			case 2:
				admit();
				break;

			case 0:
				break;

			}

		} 
		while (selection != 0);
	}



}