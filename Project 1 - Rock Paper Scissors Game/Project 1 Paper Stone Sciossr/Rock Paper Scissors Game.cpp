#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enAnswer {Stone = 1 ,Paper = 2 , Scissor = 3};

int PlayerWonTimes = 0,PcWonTimes = 0,DrawTimes = 0,RoundCount = 0;

int RandomNumber(int From, int To)
{
	int randnum = rand() % (To - From + 1) + From;

	return randnum;
}

int ReadPositiveNumber(string Message)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number < 0);


	return Number;
}

int ReadPlayerAnswer()
{
	int PlAnswer;
	do
	{
		cout << "\nYour Choice: [1]:Stone , [2]:Paper ,[3]:Scissor ? ";
		cin >> PlAnswer;
	} while (PlAnswer != 1 && PlAnswer != 2 && PlAnswer != 3);


	return PlAnswer;
}

enAnswer ConverAnswerToEnum(int number)
{
	if (number == 1)
		return enAnswer::Stone;
	if (number == 2)
		return enAnswer::Paper;
	if (number == 3)
		return enAnswer::Scissor;

	
}

string ConverAnswerToString(int number)
{
	if (number == 1)
		return "Stone";
	if (number == 2)
		return "Paper";
	if (number == 3)
		return "Scissor";

}

string WinnerCheck(enAnswer Pl1Answer , enAnswer PcAnswer)
{
	

	if (Pl1Answer == PcAnswer)
	{
		DrawTimes += 1;
		system("color 6F");
		return "[No Winer]";
	}
	else if (Pl1Answer == enAnswer::Stone && PcAnswer == enAnswer::Paper)
	{
		PcWonTimes += 1;
		system("color 4F");
		return "[Computer]\a";
	}
	else if (Pl1Answer == enAnswer::Stone && PcAnswer == enAnswer::Scissor)
	{
		PlayerWonTimes+=1;
		system("color 2F");
		return "[Player]";
	}
	else if (Pl1Answer == enAnswer::Paper && PcAnswer == enAnswer::Stone)
	{
		PlayerWonTimes+=1;
		system("color 2F");
		return "[Player]";
	}
	else if (Pl1Answer == enAnswer::Paper && PcAnswer == enAnswer::Scissor)
	{
		PcWonTimes++;
		system("color 4F");
		return "[Computer]\a";
	}
	else if (Pl1Answer == enAnswer::Scissor && PcAnswer == enAnswer::Stone)
	{
		PcWonTimes+=1;
		system("color 4F");
		return "[Computer]\a";
	}
	else if (Pl1Answer == enAnswer::Scissor && PcAnswer == enAnswer::Paper)
	{
		PlayerWonTimes+=1;
		system("color 2F");
		return "[Player]";
	}
	
}

string FinalWinner()
{
	if (DrawTimes > PlayerWonTimes && DrawTimes > PcWonTimes)
	{
		system("color 6F");
		return "No Winer";
	}
	else if (PlayerWonTimes == PcWonTimes)
	{
		system("color 6F");
		return "No Winner";
	}
	else if (PlayerWonTimes > PcWonTimes)
	{
		system("color 2F");
		return "Player1";
	}
	else if (PcWonTimes > PlayerWonTimes)
	{
		system("color 4F");
		return "Computer\a";
	}
}

void PrintRounds()
{
	RoundCount = ReadPositiveNumber("How Many Rounds 1 to 10 ?");
	int PlAnswer = 0 , PcAnswer = 0;

	for (int i = 1; i <= RoundCount; i++)
	{
		cout << "\nRound [" << i << "] begins: " << endl;;

		PlAnswer = ReadPlayerAnswer();
		PcAnswer = RandomNumber(1, 3);

		cout << "\n________________Round [" << i << "]________________\n" << endl;

		cout << "Player1  Choice: " << ConverAnswerToString(PlAnswer) << endl; 
		cout << "Computer Choice: " << ConverAnswerToString(PcAnswer) << endl;
		cout << "Round Winer    : " << WinnerCheck(ConverAnswerToEnum(PlAnswer), ConverAnswerToEnum(PcAnswer)) << endl;

		cout << "\n------------------------------------------\n" << endl;

	}
}

void PrintGameResult()
{
	cout << "\n\t\t\t----------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t +++ G a m e O v e r +++" << endl;
	cout << "\n\t\t\tÁ----------------------------------------------------------" << endl;
	cout << "\n\t\t\t--------------------------[Game Results ]--------------------------\n" << endl;

	cout << "\t\t\tGame Rounds        : " << RoundCount << endl;
	cout << "\t\t\tPlayer1 Won Times  : " << PlayerWonTimes << endl;
	cout << "\t\t\tComputer Won Times : " << PcWonTimes << endl;
	cout << "\t\t\tDrwa Won Times     : " << DrawTimes << endl;
	cout << "\t\t\tFinal Winner       : " << FinalWinner()  << endl;

	cout << "\n\t\t\t----------------------------------------------------------" << endl;

}

void PlayGame()
{
	char PlayAginY_N = 'Y';
	while (PlayAginY_N == 'Y' || PlayAginY_N == 'y')
	{
		system("cls");
		system("color 0F");
		PlayerWonTimes = 0, PcWonTimes = 0, DrawTimes = 0;

		PrintRounds();

		PrintGameResult();

		cout << "\n\t\t\tDo You Want To Play again? Y/N?";
		cin >> PlayAginY_N;
	}
	
}
int main()
{
	srand((unsigned)time(NULL));

	PlayGame();

	return 0;
}
