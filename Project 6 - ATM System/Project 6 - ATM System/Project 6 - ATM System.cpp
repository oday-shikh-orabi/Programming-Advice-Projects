#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

enum enMainMenueOptions { eQuiqWithdraw = 1, eNormalWithdraw = 2, eDeposit = 3, eCheckBalance = 4, eLogout = 5 };

enum enQuickWithdrawMinue {eQW20 = 1 , eQW50 = 2, eQW100 = 3 , eQW200 = 4 , eQW400 = 5 , eQW600 = 6 , eQW800 = 7 , eQW1000 = 8, eExit = 9};

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

sClient CurrentClient;


void Login();

string Tap(int Number)
{
	string T = "";

	for (int i = 1; i <= Number; i++)
	{
		T = T + "\t";
	}

	return T;
}

string ReadAccountNumber()
{
	string AccountNumber;
	cout << "Enter Account Number? ";
	getline(cin, AccountNumber);

	return AccountNumber;
}

string ReadPinCode()
{
	string PinCode;
	cout << "Enter Pin? ";
	getline(cin, PinCode);
	return PinCode;

}

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

sClient ConvertLinetoRecordForClient(string Line, string Seperator = "#//#")
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
			Client = ConvertLinetoRecordForClient(Line);
			vClients.push_back(Client);
		}

		MyFile.close();
	}

	return vClients;
}

bool FindClientAndGetHisData()
{

	vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

	for (sClient C : vClients)
	{
		if ((C.AccountNumber == CurrentClient.AccountNumber) && (C.PinCode == CurrentClient.PinCode))
		{
			CurrentClient = C;
			return true;
		}
	}
	return false;
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



/////////////////////+Quick Withdraw+///////////////////

void PrintQuickWithdrawScreen()
{
	cout << "=========================================\n";
	cout << Tap(1) << "Quick Withdraw Screen\n";
	cout << "=========================================\n";
	cout << Tap(1) << "[1] 20"  << Tap(1) << "[2] 50" << endl;
	cout << Tap(1) << "[3] 100" << Tap(1) << "[4] 200" << endl;
	cout << Tap(1) << "[5] 400" << Tap(1) << "[6] 600" << endl;
	cout << Tap(1) << "[7] 800" << Tap(1) << "[8] 1000" << endl;
	cout << Tap(1) << "[9] Exit"  << endl;
	cout << "=========================================\n";


}

int getQuickWithDrawAmount(enQuickWithdrawMinue Answer)
{
	switch (Answer)
	{
	case::eQW20:
	{
		return 20;
	}
	case::eQW50:
	{
		return 50;

	}
	case::eQW100:
	{
		return 100;

	}
	case::eQW200:
	{
		return 200;

	}
	case::eQW400:
	{
		return 400;

	}
	case::eQW600:
	{
		return 600;

	}
	case::eQW800:
	{
		return 800;

	}
	case::eQW1000:
	{
		return 1000;

	}
	}
}

void QuickWithdraw()
{
	vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);


	short Answer;

	char AnswerY_N;

	int WithdrawNumber;

	PrintQuickWithdrawScreen();

	cout << "Your Balance Is " << CurrentClient.AccountBalance << endl;
	cout << "Choose what to Withdraw from [1] to [8] ? ";
	cin >> Answer;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (Answer >= 1 && Answer <= 8)
	{
		WithdrawNumber = getQuickWithDrawAmount(enQuickWithdrawMinue(Answer));

		while (CurrentClient.AccountBalance < WithdrawNumber)
		{
			cout << "\nThe Amount Exceeds Your balance, make another choice." << endl;
			cout << "Choose what to Withdraw from [1] to [8] ? ";
			cin >> WithdrawNumber;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		do
		{
			cout << "\n\nAre You Sure You want perform this transaction? y/n ?";
			cin >> AnswerY_N;

		} while (toupper(AnswerY_N) != 'Y' && toupper(AnswerY_N) != 'N');


		if (toupper(AnswerY_N) == 'Y')
		{

			for (sClient& C : vClients)
			{
				if (C.AccountNumber == CurrentClient.AccountNumber)
				{
					C.AccountBalance = C.AccountBalance - WithdrawNumber;

					CurrentClient.AccountBalance = C.AccountBalance;

					cout << "\nDone Successfully. New Balance Is: " << C.AccountBalance;

					break;
				}
			}

			SaveClientsDataToFile(ClientsFileName, vClients);

		}
		else
		{
			return;
		}
	}
}


/////////////////////+Normal Withdraw+///////////////////

void PrintNormalWithdrawScreen()
{
	cout << "=========================================\n";
	cout << Tap(1) << "Normal Withdraw Screen\n";
	cout << "=========================================\n";
}

void NormalWithdraw()
{
	vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);


	int WithdrawNumber;
	char Answer;

	PrintNormalWithdrawScreen();


	cout << "Please Enter Withdraw Amount Multible of 5's ? ";
	cin >> WithdrawNumber;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');



	while ((CurrentClient.AccountBalance < WithdrawNumber))
	{
		cout << "\nThe Amount Exceeds Your balance, make another choice." << endl;
		cout << "Please Enter Withdraw Amount ? ";
		cin >> WithdrawNumber;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	while ((WithdrawNumber % 5 != 0))
	{
		cout << "\nPlease Enter Withdraw Amount Multible of 5's ? ";
		cin >> WithdrawNumber;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	do
	{
		cout << "\n\nAre You Sure You want perform this transaction? y/n ?";
		cin >> Answer;

	} while (toupper(Answer) != 'Y' && toupper(Answer) != 'N');


	if (toupper(Answer) == 'Y')
	{

		for (sClient& C : vClients)
		{
			if (C.AccountNumber == CurrentClient.AccountNumber)
			{
				C.AccountBalance = C.AccountBalance - WithdrawNumber;

				cout << "\nDone Successfully. New Balance Is: " << C.AccountBalance;

				break;
			}
		}
		SaveClientsDataToFile(ClientsFileName, vClients);

	}

}


/////////////////////+Deposit+///////////////////

void PrintDepositScreen()
{
	cout << "=========================================\n";
	cout << Tap(1) << "Deposit Screen\n";
	cout << "=========================================\n";

}

void Deposit()
{
	vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

	double DepositNumber;
	char Answer;

	PrintDepositScreen();


	cout << "Please Enter Positive Deposit Amount? ";
	cin >> DepositNumber;

	while (DepositNumber <= 0)
	{
		cout << "Please Enter Positive Deposit Amount? ";
		cin >> DepositNumber;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	do
	{
		cout << "\n\nAre You Sure You want perform this transaction? y/n? ";
		cin >> Answer;

	} while (toupper(Answer) != 'Y' && toupper(Answer) != 'N');


	if (toupper(Answer) == 'Y')
	{
		for (sClient& C : vClients)
		{
			if (C.AccountNumber == CurrentClient.AccountNumber)
			{
				C.AccountBalance = C.AccountBalance + DepositNumber;

				cout << "\nDone Successfully. New Balance Is: " << C.AccountBalance;

				break;
			}
		}
		SaveClientsDataToFile(ClientsFileName, vClients);

	}
	
}

/////////////////////+Total Balance+///////////////////

void PrintTotalBalanceScreen()
{
	cout << "=========================================\n";
	cout << Tap(1) << "Total Balance Screen\n";
	cout << "=========================================\n";


	cout << "Your Balance Is " << CurrentClient.AccountBalance << endl;

	system("pause>0");
}

//////////////////////Main Menue Scrren////////////////////

void PrintMainMenueScreen()
{
	cout << "============================================\n";
	cout << Tap(2) << "ATM Main Menue Screen\n";
	cout << "============================================" << endl;
	cout << Tap(1) << "[1] Quiq Withdraw.\n";
	cout << Tap(1) << "[2] Normal Withdraw.\n";
	cout << Tap(1) << "[3] Deposit.\n";
	cout << Tap(1) << "[4] Check Balance.\n";
	cout << Tap(1) << "[5] Logout.\n";
	cout << "============================================" << endl;
}

void UserChoeseFromMainMenue(enMainMenueOptions Answer, vector<sClient>& vClients)
{

	switch (Answer)
	{
	case enMainMenueOptions::eQuiqWithdraw:
	{
		QuickWithdraw();
		break;
	}
	case enMainMenueOptions::eNormalWithdraw:
	{
		NormalWithdraw();
		break;
	}
	case enMainMenueOptions::eDeposit:
	{
		Deposit();
		break;
	}
	case enMainMenueOptions::eCheckBalance:
	{
		PrintTotalBalanceScreen();
		break;
	}
	case enMainMenueOptions::eLogout:
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
		cout << "chose what do you want to do? [1 to 5]? ";
		cin >> Answer;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (Answer < 1 || Answer > 5);

	return Answer;
}

void ShowMainMenueScreen()
{
	vector<sClient> vClients;

	enMainMenueOptions enAnswer;

	do
	{
		system("cls");

		PrintMainMenueScreen();


		enAnswer = (enMainMenueOptions)ReadUserChoiceInMainMenue();

		if (enAnswer >= 1 && enAnswer <= 4)
		{
			system("cls");

			vClients = LoadCleintsDataFromFile(ClientsFileName);


			UserChoeseFromMainMenue(enAnswer, vClients);

			cout << "\n\n\nPrees any key to go back to Main Menue...";

			system("pause>0");
		}

	} while (enAnswer != enMainMenueOptions::eLogout);



	//Logout
	Login();
}

//----------------------Login----------------------//

void PrintLoginScreen()
{
	cout << "--------------------------------------------\n";
	cout << Tap(2) << "Login Screen\n";
	cout << "--------------------------------------------" << endl;
}

void Login()
{
	system("cls");

	PrintLoginScreen();
	CurrentClient.AccountNumber = ReadAccountNumber();
	CurrentClient.PinCode = ReadPinCode();

	if (FindClientAndGetHisData())
	{
		ShowMainMenueScreen();
	}
	else
	{
		do
		{
			system("cls");
			PrintLoginScreen();

			cout << "Invilad Account Number/PinCode!\n";

			CurrentClient.AccountNumber = ReadAccountNumber();
			CurrentClient.PinCode = ReadPinCode();


		} while (!FindClientAndGetHisData());

		ShowMainMenueScreen();
	}

}

int main()
{
	Login();

	return 0;
}
