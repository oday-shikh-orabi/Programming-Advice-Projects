#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

enum enMainMenue { eShowClientList = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdetClientInfo = 4, eFindClilent = 5, eExit = 6 };

string Tap(int Number)
{
	string T = "";

	for (int i = 1; i <= Number; i++)
	{
		T = T + "\t";
	}

	return T;
}

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

/////////Functions shared with more than one list/////////

vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord;

	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word

		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S1.erase(0, pos + Delim.length());
	}

	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string
	}

	return vString;
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string> vClientData;

	vClientData = SplitString(Line, Seperator);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]); // cast string to double

	return Client;
}

vector<sClient> LoadCleintsDataFromFile(string FileName)
{
	vector<sClient> vClients;
	fstream MyFile;

	MyFile.open(FileName, ios::in); // read mode

	if (MyFile.is_open())
	{
		string Line;
		sClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLinetoRecord(Line);
			vClients.push_back(Client);
		}

		MyFile.close();
	}

	return vClients;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;
		MyFile.close();
	}
}

string ReadClientAccountNumber()
{
	string AccountNumber = "";

	cout << "\nEnter Account Number? ";
	cin >> AccountNumber;

	return AccountNumber;
}

bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients)
{
	for (sClient C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			return true;
		}
	}
	return false;
}

bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient& Client)
{
	for (sClient C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "-----------------------------------------";
	cout << "\nAccount Number : " << Client.AccountNumber;
	cout << "\nPin Code       : " << Client.PinCode;
	cout << "\nName           : " << Client.Name;
	cout << "\nPhone          : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
	cout << "\n-----------------------------------------\n";
}


//////////////////////Show Client List////////////////////

void PrintClientRecord(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientsData(vector<sClient> vClients)
{
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n"
		<< endl;

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n"
		<< endl;

	for (sClient Client : vClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n"
		<< endl;
}

//////////////////////Add New Client////////////////////

sClient ReadNewClient(vector<sClient> vClients)
{
	sClient Client;

	cout << "\nEnter Account Number? ";
	getline(cin >> ws ,Client.AccountNumber);
	

	while (FindClientByAccountNumber(Client.AccountNumber,vClients ))
	{

		cout << "Client With [" << Client.AccountNumber << "] already exists , Enter Anothe Accout Number? ";
		getline(cin >> ws, Client.AccountNumber);
	}

	cout << "Enter PinCode? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter Account Balance? ";
	cin >> Client.AccountBalance;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');



	return Client;
}

void AddNewClient(vector<sClient>& vClients)
{
	sClient Client = ReadNewClient(vClients);

	vClients.push_back(Client);
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void PrintAddNewClientScreen()
{
	cout << "-----------------------------------------\n";
	cout << Tap(1) << "Add New Client Screen\n";
	cout << "-----------------------------------------\n";
	cout << "Adding New Client:\n" << endl;

}

void AddClients(vector<sClient>& vClients)
{
	char AddMore = 'Y';


	do
	{
		system("cls");

		PrintAddNewClientScreen();

		AddNewClient(vClients);

		cout << "\nClient Added Successfully, ";
		do
		{
			cout << "do you want to add more clients? Y/N? ";
			cin >> AddMore;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		} while (toupper(AddMore) != 'Y' && toupper(AddMore) != 'N');

	} while (toupper(AddMore) == 'Y');



}

//////////////////////Delete Client////////////////////

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}
	}
	return false;
}

vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out); // overwrite mode

	string DataLine;

	if (MyFile.is_open())
	{
		for (sClient C : vClients)
		{
			if (C.MarkForDelete == false)
			{
				// we only write records that are not marked for delete
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}

	return vClients;
}

void PrintDeleteClientScreen()
{
	cout << "-----------------------------------------\n";
	cout << Tap(1) << "Delete Client Screen\n";
	cout << "-----------------------------------------\n";

}

bool DeleteClientByAccountNumber(vector<sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	PrintDeleteClientScreen();

	string AccountNumber = ReadClientAccountNumber();

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		do
		{
			cout << "\n\nAre you sure you want delete this client? y/n ? ";
			cin >> Answer;

		} while (toupper(Answer) != 'Y' && toupper(Answer) != 'N');

		if (toupper(Answer) == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
			SaveCleintsDataToFile(ClientsFileName, vClients);

			// Refresh Clients
			vClients = LoadCleintsDataFromFile(ClientsFileName);

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}

	return false;
}

//////////////////////Updet Client Info////////////////////

void PrintUpdetClientInfoScreen()
{
	cout << "-----------------------------------------\n";
	cout << Tap(1) << "Updet Client Info Screen\n";
	cout << "-----------------------------------------\n";

}

sClient ChangeClientRecord(string AccountNumber)
{
	sClient Client;
	Client.AccountNumber = AccountNumber;

	cout << "\n\nEnter PinCode? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter Account Balance? ";
	cin >> Client.AccountBalance;

	return Client;
}

vector<sClient> SaveClientsDataToFile(string FileName, vector<sClient> vClients)
{
	fstream MyFile(FileName, ios::out);
	string DataLine;

	if (MyFile.is_open())
	{
		for (sClient C : vClients)
		{
			if (!C.MarkForDelete)
			{
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}

	return vClients;
}

bool UpdateClientByAccountNumber(vector<sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	PrintUpdetClientInfoScreen();

	string AccountNumber = ReadClientAccountNumber();


	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		do
		{
			cout << "\n\nAre you sure you want to update this client? (y/n): ";
			cin >> Answer;

		} while (toupper(Answer) != 'Y' && toupper(Answer) != 'N');


		if (toupper(Answer) == 'Y')
		{
			for (sClient& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}
			}

			SaveClientsDataToFile(ClientsFileName, vClients);

			cout << "\n\nClient Updated Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") was not found!";
	}

	return false;
}

//////////////////////Find Clilent////////////////////

void FindClientByAccountNumber(vector<sClient> vClients)
{
	string AccountNumber = ReadClientAccountNumber();

	sClient Client;

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
	}
}


//////////////////////Main Menue Scrren////////////////////

void PrintMainMenueScreen()
{
	cout << "============================================\n";
	cout << Tap(2) << "Main Menue Screen\n";
	cout << "============================================" << endl;
	cout << Tap(1) << "[1] Show Client List\n";
	cout << Tap(1) << "[2] Add New Client\n";
	cout << Tap(1) << "[3] Delete Client\n";
	cout << Tap(1) << "[4] Updet Client Info\n";
	cout << Tap(1) << "[5] Find Clilent\n";
	cout << Tap(1) << "[6] Exit\n";
	cout << "============================================" << endl;
}

void ShowEndScreen()
{
	cout << "-----------------------------------------\n";
	cout << Tap(1) << "Program Ends:-)\n";
	cout << "-----------------------------------------\n";

}

void UserChoeseFromMainMenue(enMainMenue Answer, vector<sClient>& vClients)
{

	switch (Answer)
	{
	case enMainMenue::eShowClientList:
	{
		PrintAllClientsData(vClients);
		break;
	}
	case enMainMenue::eAddNewClient:
	{
		AddClients(vClients);
		break;
	}
	case enMainMenue::eDeleteClient:
	{
		DeleteClientByAccountNumber(vClients);
		break;
	}
	case enMainMenue::eUpdetClientInfo:
	{
		UpdateClientByAccountNumber(vClients);
		break;
	}
	case enMainMenue::eFindClilent:
	{
		FindClientByAccountNumber(vClients);
		break;
	}
	case enMainMenue::eExit:
	{

		break;
	}
	}
}

short ReadUserChoiceInMainMenue()
{
	short Answer;
	do
	{
		cout << "chose what do you want to do? [1 to 6]? ";
		cin >> Answer;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (Answer < 1 || Answer > 6);

	return Answer;
}

void ShowMainMenueScreen()
{
	vector<sClient> vClients;

	enMainMenue enAnswer;
	do
	{
		system("cls");

		PrintMainMenueScreen();


		enAnswer = (enMainMenue)ReadUserChoiceInMainMenue();

		if (enAnswer >= 1 && enAnswer <= 5)
		{
			system("cls");

			vClients = LoadCleintsDataFromFile(ClientsFileName);

			UserChoeseFromMainMenue(enAnswer, vClients);

			cout << "\n\n\nPrees any key to go back to Main Menue...";

			system("pause>0");
		}
		else if (enAnswer == enMainMenue::eExit)
		{
			UserChoeseFromMainMenue(enAnswer, vClients);

			cout << "\n\nPrees any key to go back to Main Menue..." << endl;
		}


	} while (enAnswer != enMainMenue::eExit);

	system("pause>0");
}

int main()
{
	ShowMainMenueScreen();

	return 0;
}
