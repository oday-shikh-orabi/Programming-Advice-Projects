#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

const string UsersFileName = "Users.txt";

enum enMainMenueOptions { eShowClientList = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdetClientInfo = 4, eFindClilent = 5, eTransactions = 6, eMangeUser = 7, eLogout = 8 };

enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eMainMenue = 4 };

enum enMangeUserMenue { eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMineMenue = 6 };

enum enPermission
{
	//«“«Õ… ‰ »  ⁄·Ï «·Ì”«— ›Ì «·»«Ì‰—Ì
										 //‘·Ê‰ «‰   ﬁ—√Â«           ﬁÌ„ Â« ›Ì «·»«Ì‰—Ì                 ÀﬁÌ„ Â« Â·ﬁ »«·⁄‘—Ì
	ePerm_ShowClientList     = 1 << 0,               // 1                                0001            «·ŒÌ«— «·√Ê· „„À· »√Ê· » 
	ePerm_AddNewClient       = 1 << 1,               // 2                                0010            «·ŒÌ«— «·À«‰Ì „„À· »À«‰Ì » 
	ePerm_DeleteClient       = 1 << 2,               // 4                                0100
	ePerm_UpdateClientInfo   = 1 << 3,               // 8                                1000
	ePerm_FindClient         = 1 << 4,               // 16                             0001 0000
	ePerm_Transactions       = 1 << 5,               // 32                             0010 0000
	ePerm_ManageUser         = 1 << 6,               // 64                             0100 0000


};



struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

struct sUser
{
	string Username;
	string Password;
	int Permission;

	bool MarkForDelete = false;
};



sUser CurrentUser;



/////////Functions shared with more than one list/////////

string Tap(int Number)
{
	string T = "";

	for (int i = 1; i <= Number; i++)
	{
		T = T + "\t";
	}

	return T;
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

bool IsClientExist(string AccountNumber, vector<sClient> vClients)
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

bool FindClientAndGetHisData(string AccountNumber, vector<sClient> vClients, sClient& Client)
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

void ShowMainMenueScreen();


void Login();

sUser ConvertLinetoRecordForUser(string Line, string Seperator = "#//#")
{
	sUser User;
	vector<string> vUserData;

	vUserData = SplitString(Line, Seperator);

	if (vUserData.size() >= 3)
	{
		User.Username = vUserData[0];
		User.Password = vUserData[1];
		User.Permission = stoi(vUserData[2]);
	}
	

	return User;
}

string ConvertRecordToLine(sUser User, string Seperator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += User.Username + Seperator;
	stClientRecord += User.Password + Seperator;
	stClientRecord += to_string(User.Permission);

	return stClientRecord;
}

void AddDataLineToFileUser(string FileName, string stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;
		MyFile.close();
	}
	else
	{
		cout << "Error: Could not open file [" << FileName << "]\n";
	}
}


vector<sUser> LoadUsersDataFromFile(string FileName)
{
	vector<sUser> vUsers;
	fstream MyFile;

	MyFile.open(FileName, ios::in); // read mode

	if (MyFile.is_open())
	{
		string Line;
		sUser User;

		while (getline(MyFile, Line))
		{
			User = ConvertLinetoRecordForUser(Line);
			vUsers.push_back(User);
		}

		MyFile.close();
	}

	return vUsers;
}

bool FindUserByUsername(string Username)
{
	vector<sUser> vUser = LoadUsersDataFromFile(UsersFileName);


	for (sUser U : vUser)
	{
		if (U.Username == Username)
		{
			return true;
		}
	}
	return false;
}

void PrintUserCard(sUser User)
{
	cout << "\nThe following are the User details:\n";
	cout << "-----------------------------------------";
	cout << "\nUsername       : " << User.Username;
	cout << "\nPassowrd       : " << User.Password;
	cout << "\nPermissions    : " << User.Permission;
	cout << "\n-----------------------------------------\n";
}

string ReadUserName(string Massege = "Enter Username?")
{
	string UserName;
	cout << Massege;
	getline(cin, UserName);

	return UserName;
}

string ReadPassword(string Massege = "Enter Passowrd?")
{
	string Password;
	cout << Massege;
	getline(cin, Password);
	return Password;

}

int ReadAnswerY_N(string Massege = "")
{
	char AnswerY_N;


	do
	{
		cout << Massege;
		cin >> AnswerY_N;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (toupper(AnswerY_N) != 'Y' && toupper(AnswerY_N) != 'N');


	return AnswerY_N;
}

sUser GetUserDate(string Username)
{
	vector<sUser> vUser = LoadUsersDataFromFile(UsersFileName);


	for (sUser U : vUser)
	{
		if (U.Username == Username)
		{
			return U;
		}
	}

	return sUser{};
}


//////////Permissions////////////

// -1 = Full Access (Admin)
const int FullAccess = -1;

bool HasPermission(int UserPermission, enPermission Permission)
{
	return (UserPermission == FullAccess) ||
		(UserPermission & Permission);
	//»œ· «·À«‰Ì… ·«‰ »⁄„·Ì… «·›Õ’ «·—ﬁ„ Ì·Ì —Õ Ì—Ã⁄ ÂÊ ‰›”Ê «·»—„Ì‘‰
	// ((UserPermission & Permission) == Permission ? true : false);
}

void AssigningPermissionsToUser(sUser& User)
{
	char Answer;

	User.Permission = 0; // „” Œœ„ ⁄«œÌ


	Answer = ReadAnswerY_N("\nDo You Want to give full access? y/n ?");
	if (toupper(Answer) == 'Y')
	{

		User.Permission = FullAccess;
	}
	else
	{

		cout << "\nDo You Want to give access to : \n" << endl;


		Answer = ReadAnswerY_N("\nShow Client List? y/n? ");
		if (toupper(Answer) == 'Y')
		{

			User.Permission |= ePerm_ShowClientList;
		}
		Answer = ReadAnswerY_N("\nAdd New Client? y/n? ");
		if (toupper(Answer) == 'Y')
		{

			User.Permission |= ePerm_AddNewClient;
		}
		Answer = ReadAnswerY_N("\nDelete Client? y/n? ");
		if (toupper(Answer) == 'Y')
		{

			User.Permission |= ePerm_DeleteClient;
		}
		Answer = ReadAnswerY_N("\nUpdate Client? y/n? ");
		if (toupper(Answer) == 'Y')
		{

			User.Permission |= ePerm_UpdateClientInfo;
		}
		Answer = ReadAnswerY_N("\nFind Client? y/n? ");
		if (toupper(Answer) == 'Y')
		{

			User.Permission |= ePerm_FindClient;
		}
		Answer = ReadAnswerY_N("\nTransactions? y/n? ");
		if (toupper(Answer) == 'Y')
		{

			User.Permission |= ePerm_Transactions;
		}
		Answer = ReadAnswerY_N("\nMange User? y/n? ");
		if (toupper(Answer) == 'Y')
		{

			User.Permission |= ePerm_ManageUser;
		}

		//if User Has Full Access From Step By Step Edit value From 127 To -1
		if (User.Permission == 127)
		{
			User.Permission = -1;
		}
	}
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
	getline(cin >> ws, Client.AccountNumber);


	while (IsClientExist(Client.AccountNumber, vClients))
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

	if (FindClientAndGetHisData(AccountNumber, vClients, Client))
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


	if (FindClientAndGetHisData(AccountNumber, vClients, Client))
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

void FindClient(vector<sClient> vClients)
{
	string AccountNumber = ReadClientAccountNumber();

	sClient Client;

	if (FindClientAndGetHisData(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
	}
}

/////////////////////+Transactions-Deposit+///////////////////

void PrintDepositScreen()
{
	cout << "-----------------------------------------\n";
	cout << Tap(1) << "Deposit Screen\n";
	cout << "-----------------------------------------\n";

}

void Deposit(vector<sClient>& vClients)
{
	PrintDepositScreen();

	string AccountNumber;

	sClient Client;

	double DepositNumber;

	char Answer;
	do
	{
		AccountNumber = ReadClientAccountNumber();


		if (FindClientAndGetHisData(AccountNumber, vClients, Client))
		{
			PrintClientCard(Client);


			cout << "Please Enter Deposit Amount? ";
			cin >> DepositNumber;
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
					if (C.AccountNumber == AccountNumber)
					{
						C.AccountBalance = C.AccountBalance + DepositNumber;

						cout << "\nDone Successfully. New Balance Is: " << C.AccountBalance;

						break;
					}
				}
				SaveClientsDataToFile(ClientsFileName, vClients);

				break;
			}
			else
			{
				break;
			}
		}
		else
		{
			cout << "\nClient With [" << AccountNumber << "] does not exist.\n";

		}
	} while (true);


}

/////////////////////+Transactions-Withdraw+///////////////////

void PrintWithdrawScreen()
{
	cout << "-----------------------------------------\n";
	cout << Tap(1) << "Withdraw Screen\n";
	cout << "-----------------------------------------\n";

}

void Withdraw(vector<sClient>& vClients)
{
	PrintWithdrawScreen();

	string AccountNumber;

	sClient Client;

	double WithdrawNumber;

	char Answer;


	do
	{
		AccountNumber = ReadClientAccountNumber();


		if (FindClientAndGetHisData(AccountNumber, vClients, Client))
		{
			PrintClientCard(Client);


			cout << "Please Enter Withdraw Amount? ";
			cin >> WithdrawNumber;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			while (Client.AccountBalance < WithdrawNumber)
			{
				cout << "\nAmount Exceeds the balance, you can withdraw up to :" << Client.AccountBalance;
				cout << "\nPlease Enter Withdraw Amount? ";
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
					if (C.AccountNumber == AccountNumber)
					{
						C.AccountBalance = C.AccountBalance - WithdrawNumber;

						cout << "\nDone Successfully. New Balance Is: " << C.AccountBalance;

						break;
					}
				}
				SaveClientsDataToFile(ClientsFileName, vClients);

				break;
			}
			else
			{
				break;
			}
		}
		else
		{
			cout << "\nClient With [" << AccountNumber << "] does not exist.\n";

		}
	} while (true);


}

/////////////////////+Transactions-Total Balances+///////////////////

void PrintTotalBalancesInfo(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintTotalBalances(vector<sClient> vClients)
{
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n"
		<< endl;

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n"
		<< endl;

	double TotalBalances = 0;
	for (sClient Client : vClients)
	{
		PrintTotalBalancesInfo(Client);
		cout << endl;

		TotalBalances += Client.AccountBalance;
	}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n"
		<< endl;

	cout << "\t\t\t\t\tTotal Balances = " << TotalBalances << endl;
}

/////////////////////Transactions///////////////////

void PrintTransactionsMenueScreen()
{
	cout << "============================================\n";
	cout << Tap(2) << "Transactions Menue Screen\n";
	cout << "============================================" << endl;
	cout << Tap(1) << "[1] Deposit.\n";
	cout << Tap(1) << "[2] Withdraw.\n";
	cout << Tap(1) << "[3] Total Balances.\n";
	cout << Tap(1) << "[4] Main Menue.\n";
	cout << "============================================" << endl;


}

short ReadUserChoiceInTransactionsMenue()
{
	short Answer;
	do
	{
		cout << "chose what do you want to do? [1 to 4]? ";
		cin >> Answer;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (Answer < 1 || Answer > 4);

	return Answer;
}

void UserChoeseFromTransactionsMenue(enTransactionsMenueOptions Answer, vector<sClient>& vClients)
{

	switch (Answer)
	{
	case enTransactionsMenueOptions::eDeposit:
	{
		Deposit(vClients);
		break;
	}
	case enTransactionsMenueOptions::eWithdraw:
	{
		Withdraw(vClients);
		break;
	}
	case enTransactionsMenueOptions::eTotalBalances:
	{
		PrintTotalBalances(vClients);
		break;
	}
	case enTransactionsMenueOptions::eMainMenue:
	{
		break;
	}
	}

}

void Transactions(vector<sClient>& vClients)
{
	enTransactionsMenueOptions enAnswer;

	do
	{
		system("cls");

		PrintTransactionsMenueScreen();


		enAnswer = (enTransactionsMenueOptions)ReadUserChoiceInTransactionsMenue();

		if (enAnswer >= 1 && enAnswer <= 3)
		{
			system("cls");

			vClients = LoadCleintsDataFromFile(ClientsFileName);

			UserChoeseFromTransactionsMenue(enAnswer, vClients);

			cout << "\n\n\nPrees any key to go back to Transactions Menue...";

			system("pause>0");
		}

	} while (enAnswer != enTransactionsMenueOptions::eMainMenue);


}

////////////////////+List Users+//////////////////

void PrintUserRecord(sUser User)
{
	cout << "| " << setw(15) << left << User.Username;
	cout << "| " << setw(10) << left << User.Password;
	cout << "| " << setw(40) << left << User.Permission;
}

void PrintAllUsersData()
{

	vector<sUser> vUsers = LoadUsersDataFromFile(UsersFileName);

	cout << "\n\t\t\t\t\tUser List (" << vUsers.size() << ") User(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n"
		<< endl;

	cout << "| " << left << setw(15) << "User Name";
	cout << "| " << left << setw(10) << "Password";
	cout << "| " << left << setw(40) << "Permissions";
	//cout << "| " << left << setw(12) << "Phone";
	//cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n"
		<< endl;

	for (sUser User : vUsers)
	{
		PrintUserRecord(User);
		cout << endl;
	}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n"
		<< endl;
}


////////////////////+Add New User+//////////////////

void PrintAddNewUserScreen()
{
	cout << "--------------------------------------------\n";
	cout << Tap(2) << "Add New User Screen\n";
	cout << "--------------------------------------------" << endl;
}

void ReadNewUser()
{

	char Answer;

	do
	{
		sUser User;

		cout << "Adding New User:" << endl;


		cout << "\nEnter Username? ";
		getline(cin >> ws, User.Username);

		while (FindUserByUsername(User.Username))
		{

			cout << "User With [" << User.Username << "] already exists , Enter Anothe Username? ";
			getline(cin >> ws, User.Username);
		}


		cout << "Enter Password? ";
		getline(cin >> ws, User.Password);



		// ⁄ÌÌ‰ «·’·«Õ·«  ··„” Œœ„
		AssigningPermissionsToUser(User);


		AddDataLineToFileUser(UsersFileName, ConvertRecordToLine(User));

		cout << "\nUser Added Successfully, Do You Want To Add More Users? y/n? ";
		Answer = ReadAnswerY_N();

	} while (toupper(Answer) == 'Y');



}

void AddNewUser()
{


	PrintAddNewUserScreen();
	ReadNewUser();

}

////////////////////+Delete User+//////////////////

bool MarkUserForDeleteByUsername(string Username, vector<sUser>& vUsers)
{

	for (sUser& U : vUsers)
	{
		if (U.Username == Username)
		{
			U.MarkForDelete = true;
			return true;
		}
	}
	return false;
}

void SaveUsersDataToFile(vector<sUser> vUser)
{

	fstream MyFile;
	MyFile.open(UsersFileName, ios::out); // overwrite mode

	string DataLine;

	if (MyFile.is_open())
	{
		for (sUser U : vUser)
		{
			if (U.MarkForDelete == false)
			{
				// we only write records that are not marked for delete
				DataLine = ConvertRecordToLine(U);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}

}

void PrintDeleteUserScreen()
{
	cout << "-----------------------------------------\n";
	cout << Tap(1) << "Delete User Screen\n";
	cout << "-----------------------------------------\n";

}

bool DeleteUserByUsername()
{
	vector<sUser> vUsers = LoadUsersDataFromFile(UsersFileName);


	sUser User;
	char Answer = 'n';

	PrintDeleteClientScreen();


	do
	{
		User.Username = ReadUserName();
		if (User.Username == "Admin")
		{
			cout << "You Cant Delete Admin, Pleaes Enter Onther Username.";
		}

	} while (User.Username == "Admin");


	if (FindUserByUsername(User.Username))
	{
		User = GetUserDate(User.Username);
		PrintUserCard(User);

		do
		{
			cout << "\n\nAre you sure you want delete this User? y/n ? ";
			cin >> Answer;

		} while (toupper(Answer) != 'Y' && toupper(Answer) != 'N');

		if (toupper(Answer) == 'Y')
		{
			MarkUserForDeleteByUsername(User.Username, vUsers);

			//Refrsh File
			SaveUsersDataToFile(vUsers);

			cout << "\n\nUser Deleted Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nUser with Username  (" << User.Username << ") is Not Found!";
		return false;
	}

	return false;
}


////////////////////+Update User+//////////////////

void PrintUpdetUserInfoScreen()
{
	cout << "-----------------------------------------\n";
	cout << Tap(1) << "Updet User Info Screen\n";
	cout << "-----------------------------------------\n";

}

vector<sUser> SaveUsersDataToFile(string FileName, vector<sUser> vUsers)
{
	fstream MyFile(FileName, ios::out);
	string DataLine;

	if (MyFile.is_open())
	{
		for (sUser U : vUsers)
		{
			if (!U.MarkForDelete)
			{
				DataLine = ConvertRecordToLine(U);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}

	return vUsers;
}

sUser ChangeUserRecord(string Username)
{
	sUser User;
	User.Username = Username;

	cout << "\n\nEnter Password? ";
	cin >> User.Password;


	AssigningPermissionsToUser(User);


	return User;
}

bool UpdateUserByUsername()
{

	vector<sUser> vUsers = LoadUsersDataFromFile(UsersFileName);

	sUser User;
	char Answer = 'n';

	PrintUpdetUserInfoScreen();

	do
	{
		User.Username = ReadUserName();
		if (User.Username == "Admin")
		{
			cout << "You Cant Update Admin, Pleaes Enter Onther Username.";
		}

	} while (User.Username == "Admin");



	if (FindUserByUsername(User.Username))
	{
		User = GetUserDate(User.Username);
		PrintUserCard(User);

		do
		{
			cout << "\n\nAre you sure you want to update this user? (y/n): ";
			cin >> Answer;

		} while (toupper(Answer) != 'Y' && toupper(Answer) != 'N');


		if (toupper(Answer) == 'Y')
		{
			for (sUser& U : vUsers)
			{
				if (U.Username == User.Username)
				{
					U = ChangeUserRecord(User.Username);
					break;
				}
			}

			//Refrsh 
			SaveUsersDataToFile(vUsers);

			cout << "\n\nClient Updated Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nUser with Account Number (" << User.Username << ") was not found!";
	}

	return false;
}


////////////////////+Find User+//////////////////

void FindUser()
{
	vector<sUser> vUsers = LoadUsersDataFromFile(UsersFileName);

	sUser User;

	User.Username = ReadUserName("\nPlease enter Username? ");



	if (FindUserByUsername(User.Username))
	{
		User = GetUserDate(User.Username);
		PrintUserCard(User);
	}
	else
	{
		cout << "\nUser with Username (" << User.Username << ") is Not Found!";
	}
}

/////////////////////Mange User///////////////////

void PrintMangeUsersMenueScreen()
{
	cout << "============================================\n";
	cout << Tap(2) << "Mange Users Menue Screen\n";
	cout << "============================================" << endl;
	cout << Tap(1) << "[1] List Users.\n";
	cout << Tap(1) << "[2] Add New User.\n";
	cout << Tap(1) << "[3] Delete User.\n";
	cout << Tap(1) << "[4] Updet User Info.\n";
	cout << Tap(1) << "[5] Find User.\n";
	cout << Tap(1) << "[6] Mine Menue.\n";
	cout << "============================================" << endl;
}

short ReadUserChoiceInMangeUsersMenue()
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

void UserChoeseFromMangeUsesrMenue(enMangeUserMenue Answer)
{

	switch (Answer)
	{
	case enMangeUserMenue::eListUsers:
	{
		system("cls");
		PrintAllUsersData();
		break;
	}
	case enMangeUserMenue::eAddNewUser:
	{
		system("cls");
		AddNewUser();
		break;
	}
	case enMangeUserMenue::eDeleteUser:
	{
		system("cls");
		DeleteUserByUsername();
		break;
	}
	case enMangeUserMenue::eUpdateUser:
	{
		system("cls");
		UpdateUserByUsername();
		break;
	}
	case enMangeUserMenue::eFindUser:
	{
		system("cls");
		FindUser();
		break;
	}
	case enMangeUserMenue::eMineMenue:
	{
		break;
	}
	}
}

void MangeUsers()
{
	enMangeUserMenue Answer;


	do
	{
		system("cls");

		PrintMangeUsersMenueScreen();


		Answer = (enMangeUserMenue)ReadUserChoiceInMangeUsersMenue();

		if (Answer >= 1 && Answer <= 5)
		{

			UserChoeseFromMangeUsesrMenue(Answer);

			cout << "\n\n\nPrees any key to go back to Mange User Menue...";

			system("pause>0");
		}



	} while (Answer != enMangeUserMenue::eMineMenue);

}


//////////////////////Main Menue Scrren////////////////////

void PrintMainMenueScreen()
{
	cout << "============================================\n";
	cout << Tap(2) << "Main Menue Screen\n";
	cout << "============================================" << endl;
	cout << Tap(1) << "[1] Show Client List.\n";
	cout << Tap(1) << "[2] Add New Client.\n";
	cout << Tap(1) << "[3] Delete Client.\n";
	cout << Tap(1) << "[4] Updet Client Info.\n";
	cout << Tap(1) << "[5] Find Client.\n";
	cout << Tap(1) << "[6] Transactions.\n";
	cout << Tap(1) << "[7] Mange User.\n";
	cout << Tap(1) << "[8] Logout.\n";
	cout << "============================================" << endl;
}

void PrintAccessDenied()
{
	cout << "--------------------------------------------\n";
	cout << "Access Denied\n";
	cout << "You Dont Have Permission To Do This\n";
	cout << "Please Conect Your Admin.\n";
	cout << "--------------------------------------------" << endl;
}

void UserChoeseFromMainMenue(enMainMenueOptions Answer, vector<sClient>& vClients)
{

	switch (Answer)
	{
	case enMainMenueOptions::eShowClientList:
	{
		if (HasPermission(CurrentUser.Permission, ePerm_ShowClientList))
		{
			PrintAllClientsData(vClients);
			break;
		}
		else
		{
			PrintAccessDenied();
			break;
		}

	}
	case enMainMenueOptions::eAddNewClient:
	{
		if (HasPermission(CurrentUser.Permission, ePerm_AddNewClient))
		{
			AddClients(vClients);
			break;
		}
		else
		{
			PrintAccessDenied();
			break;
		}
	}
	case enMainMenueOptions::eDeleteClient:
	{
		if (HasPermission(CurrentUser.Permission, ePerm_DeleteClient))
		{
			DeleteClientByAccountNumber(vClients);
			break;
		}
		else
		{
			PrintAccessDenied();
			break;
		}
	}
	case enMainMenueOptions::eUpdetClientInfo:
	{
		if (HasPermission(CurrentUser.Permission, ePerm_UpdateClientInfo))
		{
			UpdateClientByAccountNumber(vClients);
			break;
		}
		else
		{
			PrintAccessDenied();
			break;
		}
	}
	case enMainMenueOptions::eFindClilent:
	{
		if (HasPermission(CurrentUser.Permission, ePerm_FindClient))
		{
			FindClient(vClients);
			break;
		}
		else
		{
			PrintAccessDenied();
			break;
		}
	}
	case enMainMenueOptions::eTransactions:
	{
		if (HasPermission(CurrentUser.Permission, ePerm_Transactions))
		{
			Transactions(vClients);
			break;
		}
		else
		{
			PrintAccessDenied();
			break;
		}
	}
	case enMainMenueOptions::eMangeUser:
	{
		if (HasPermission(CurrentUser.Permission, ePerm_ManageUser))
		{
			MangeUsers();
			break;
		}
		else
		{
			PrintAccessDenied();
			break;
		}
	}
	}
}

short ReadUserChoiceInMainMenue()
{
	short Answer;
	do
	{
		cout << "chose what do you want to do? [1 to 8]? ";
		cin >> Answer;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (Answer < 1 || Answer > 8);

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

		if (enAnswer >= 1 && enAnswer <= 7)
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

bool CheckUserAndGetPermissions(sUser& User)
{
	vector<sUser> vUsers;

	vUsers = LoadUsersDataFromFile(UsersFileName);

	for (sUser& User : vUsers)
	{
		if (User.Username == User.Username)
		{
			if (User.Password == User.Password)
			{
				User.Permission = User.Permission;
				return true;
			}
		}

	}

	return false;
}

void Login()
{
	system("cls");

	PrintLoginScreen();
	CurrentUser.Username = ReadUserName("Enter Username? ");
	CurrentUser.Password = ReadPassword("Enter Password? ");

	if (CheckUserAndGetPermissions(CurrentUser))
	{
		ShowMainMenueScreen();
	}
	else
	{
		do
		{
			system("cls");
			PrintLoginScreen();

			cout << "Invilad Username/Password!\n";

			CurrentUser.Username = ReadUserName("Enter Username? ");
			CurrentUser.Password = ReadPassword("Enter Password? ");


		} while (!CheckUserAndGetPermissions(CurrentUser));

		ShowMainMenueScreen();
	}

}

int main()
{
	Login();

	return 0;
}
