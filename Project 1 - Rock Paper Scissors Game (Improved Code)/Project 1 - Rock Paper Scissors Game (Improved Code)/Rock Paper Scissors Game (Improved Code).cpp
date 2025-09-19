#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enAnswer { Stone = 1, Paper = 2, Scissor = 3 };

enum enWinner {Player1 = 1 , Computer = 2 , Draw = 3};

struct stRoundInfo
{
	short GameRound = 0;
	int PlAnswer = 0;
	int PcAnswer = 0;
};

struct stGameResult
{
	short PlayerWonTimes = 0;
	short PcWonTimes = 0;
	short DrawTimes = 0;
};

int RandomNumber(int From, int To)
{
	int randnum = rand() % (To - From + 1) + From;

	return randnum;
}

string Tap(int Number)
{
	string T = "";

	for (int i = 1; i <= Number; i++)
	{
		T = T + "\t";
	}

	return T;
}

int ReadHowManyRounds()
{
	int Number;
	do
	{
		cout << "How Many Rounds 1 to 10 ?" << endl;
		cin >> Number;
	} while (Number < 1 || Number > 10);


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

int GetComputerChoice()
{
	return RandomNumber(1, 3);
}

int ReadPlayAgin(char& PlayAginY_N)
{
	do
	{
		cout << "\n" << Tap(3) << "Do You Want To Play again ? Y / N ? ";
		cin >> PlayAginY_N;
	} while (PlayAginY_N != 'Y' && PlayAginY_N != 'y' && PlayAginY_N != 'N' && PlayAginY_N != 'n');

	return PlayAginY_N;
}

string ChoiceName(int number)
{
	if (number >= 1 && number <= 3)
	{
		string Choices[3] = { "Stone", "Paper", "Scissor" };
		return Choices[number - 1];
	}
	return "Unknown";
}

string WinnerName(enWinner Winer)
{
	
	string Choices [3] = {"Player1" ,"Computer" ,"No Winner"};
	return Choices[Winer - 1];

}

void SetWnnierScreenColore(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player1:
		system("color 2F"); //green
		break;

	case enWinner::Computer:
		system("color 4F"); //Red
		cout << "\a";
		break;

	default:
		system("color 6F"); //Yallow
		break;
	}
}

enWinner CheckWinnerTheRound(enAnswer Pl1Answer, enAnswer PcAnswer )
{

	if (Pl1Answer == PcAnswer)
	{
		SetWnnierScreenColore(enWinner::Draw);
		return enWinner::Draw;
	}
	
	switch (Pl1Answer)
	{
	case enAnswer::Stone:
		if (PcAnswer == enAnswer::Paper)
		{
			SetWnnierScreenColore(enWinner::Computer);
			return enWinner::Computer;
		}
		break;

	case enAnswer::Paper:
		if (PcAnswer == enAnswer::Scissor)
		{
			SetWnnierScreenColore(enWinner::Computer);
			return enWinner::Computer;
		}
		break;

	case enAnswer::Scissor:
		if (PcAnswer == enAnswer::Stone)
		{
			SetWnnierScreenColore(enWinner::Computer);
			return enWinner::Computer;
		}
		break;
	}
	//if you reach here then player1 is the winner
	SetWnnierScreenColore(enWinner::Player1);
	return enWinner::Player1;

}

string WhoWonTheGame(stGameResult& GameResult)
{
	if (GameResult.DrawTimes > GameResult.PlayerWonTimes && GameResult.DrawTimes > GameResult.PcWonTimes)
	{
		SetWnnierScreenColore(enWinner::Draw);
			return "No Winner";
	}
	else if (GameResult.PlayerWonTimes == GameResult.PcWonTimes)
	{
		SetWnnierScreenColore(enWinner::Draw);
		return "No Winner";
	}
	else if (GameResult.PlayerWonTimes > GameResult.PcWonTimes)
	{
		SetWnnierScreenColore(enWinner::Player1);
		return "Player1";
	}
	else if (GameResult.PcWonTimes > GameResult.PlayerWonTimes)
	{
		SetWnnierScreenColore(enWinner::Computer);
		return "Computer";
	}
	else
	{
		return "Unknown";
	}
}

void PrintRounds(stRoundInfo& Info,stGameResult& GameResult)
{

	Info.GameRound = ReadHowManyRounds();
	

	for (int i = 1; i <= Info.GameRound; i++)
	{
		cout << "\nRound [" << i << "] begins: " << endl;;

		Info.PlAnswer = ReadPlayerAnswer();
		Info.PcAnswer = GetComputerChoice();
		enWinner winner = CheckWinnerTheRound(enAnswer(Info.PlAnswer), enAnswer(Info.PcAnswer));

		cout << "\n________________Round [" << i << "]________________\n" << endl;
		
		cout << "Player1  Choice: " << ChoiceName(Info.PlAnswer) << endl;
		cout << "Computer Choice: " << ChoiceName(Info.PcAnswer) << endl;
		cout << "Round Winer    : " << WinnerName (winner) << endl;

		cout << "\n------------------------------------------\n" << endl;


		switch (winner)
		{
		case enWinner::Player1:
			GameResult.PlayerWonTimes ++;
			break;

		case enWinner::Computer:
			GameResult.PcWonTimes ++;
			break;

		default:
			GameResult.DrawTimes ++;
			break;
		} 
	}
}

void ShowGameOverScreen()
{
	cout << "\n" << Tap(3) << "---------------------------------------------------------" << endl;
	cout << "\n" << Tap(5) << " +++ G a m e O v e r +++" << endl;
	cout << "\n" << Tap(3) << "---------------------------------------------------------" << endl;
	cout << "\n" << Tap(3) << "---------------------[Game Results ]---------------------\n" << endl;
}

void ShowFinalGameResult(stGameResult& GameResult , stRoundInfo& Info)
{
	ShowGameOverScreen();

	cout << Tap(3) << "Game Rounds        : " << Info.GameRound << endl;
	cout << Tap(3) << "Player1 Won Times  : " << GameResult.PlayerWonTimes << endl;
	cout << Tap(3) << "Computer Won Times : " << GameResult.PcWonTimes << endl;
	cout << Tap(3) << "Drwa Won Times     : " << GameResult.DrawTimes << endl;
	cout << Tap(3) << "Final Winner       : " << WhoWonTheGame(GameResult) << endl;

	cout << "\n" << Tap(3) << "---------------------------------------------------------" << endl;

}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAginY_N = 'Y';
	while (PlayAginY_N == 'Y' || PlayAginY_N == 'y')
	{
		ResetScreen();

		stRoundInfo Info;

		stGameResult GameResult;

		PrintRounds(Info,GameResult);

		ShowFinalGameResult(GameResult , Info);
		
		
		PlayAginY_N = ReadPlayAgin(PlayAginY_N);
	}

}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}
