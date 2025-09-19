#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


enum enLevel{Easy = 1 , Med = 2 , Hard = 3 , Mix = 4};

enum enOperationTybe {Add = 1 , Sup = 2 , Mul = 3 , Div = 4, mix = 5};

struct stCounters
{
	short NumberOfQuesthions = 0;
	short CorrectCounter = 0;
	short WrongCounter = 0;
};

int ReadPositiveNumber(string Message)
{
	int Number;
	do
	{
		cout << Message ;
		cin >> Number;
	} while (Number < 0);


	return Number;
}

enLevel ReadLevel()
{
	int Number;
	do
	{
		cout << "Enter Questhion Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? " ;
		cin >> Number;
	} while (Number < 1 || Number > 4);


	return enLevel(Number);
}

enOperationTybe ReadOperationTybe()
{
	int Number;
	do
	{
		cout << "Enter Questhion Level [1] Add, [2] Sup, [3] Mul, [4] Div, [5] Mix ? ";
		cin >> Number;
	} while (Number < 1 || Number > 5);


	return enOperationTybe(Number);
}

int ReadPlayAgin(char& PlayAginY_N)
{
	do
	{
		cout << "\n" << "Do You Want To Play again ? Y / N ? ";
		cin >> PlayAginY_N;
	} while (PlayAginY_N != 'Y' && PlayAginY_N != 'y' && PlayAginY_N != 'N' && PlayAginY_N != 'n');

	return PlayAginY_N;
}

int RandomNumber(int From, int To)
{
	int randnum = rand() % (To - From + 1) + From;

	return randnum;
}

int NumbersReturnedBy(enLevel Level)
{
	switch (Level)
	{
	case enLevel::Easy:
		return RandomNumber(1, 10);
		break;

	case enLevel::Med:
		return RandomNumber(10, 50);
		break;

	case enLevel::Hard:
		return RandomNumber(50, 100);
		break;

	default:
		return RandomNumber(10, 100);
		break;
	}
}

void IsAnswerCorrect(int Num1, int Num2, int Answer, enOperationTybe OpTybe , stCounters& AnswerCounter)
{
	switch (OpTybe)
	{
	case enOperationTybe::Add:
	{
		if (Answer == Num1 + Num2)
		{
			cout << "Right Answer :-) " << endl;
			system("color 2F");

			AnswerCounter.CorrectCounter++;
		}
		else
		{
			cout << "Wrong Answer :-( \a" << endl;
			cout << "The Right Answer Is : " << Num1 + Num2 << endl;
			system("color 4F");

			AnswerCounter.WrongCounter++;
		}
		break;
	}
	case enOperationTybe::Sup:
	{
		if (Answer == Num1 - Num2)
		{
			cout << "Right Answer :-) " << endl;
			system("color 2F");

			AnswerCounter.CorrectCounter++;
		}
		else
		{
			cout << "Wrong Answer :-( " << endl;
			cout << "The Right Answer Is : " << Num1 - Num2 << endl;
			system("color 4F");

			AnswerCounter.WrongCounter++;
		}
		break;
	}
	case enOperationTybe::Mul:
	{
		if (Answer == Num1 * Num2)
		{
			cout << "Right Answer :-) " << endl;
			system("color 2F");

			AnswerCounter.CorrectCounter++;
		}
		else
		{
			cout << "Wrong Answer :-( " << endl;
			cout << "The Right Answer Is : " << Num1 * Num2 << endl;
			system("color 4F");

			AnswerCounter.WrongCounter++;
		}
		break;
	}
	case enOperationTybe::Div:
	{
		if (Answer == Num1 / Num2)
		{
			cout << "Right Answer :-) " << endl;
			system("color 2F");

			AnswerCounter.CorrectCounter++;
		}
		else
		{
			cout << "Wrong Answer :-( " << endl;
			cout << "The Right Answer Is : " << Num1 / Num2 << endl;
			system("color 4F");

			AnswerCounter.WrongCounter++;
		}
		break;
	}
	default:
		break;
	}
}

void PrintCalculation(enLevel Level , enOperationTybe OpTybe , stCounters& AnswerCounter)
{
	if (Level == enLevel::Mix)
	{
		Level = enLevel(RandomNumber(1, 3));
	}
	if (OpTybe == enOperationTybe::mix)
	{
		OpTybe = enOperationTybe(RandomNumber(1, 4));
	}

	switch (OpTybe)
	{
	case enOperationTybe::Add:
	{
		int Num1 = NumbersReturnedBy(Level), Num2 = NumbersReturnedBy(Level) ;

		cout << Num1 << endl;
		cout << Num2 << " +\n" << endl;
		cout << "---------" << endl;
		int Answer = 0;
		cin >> Answer;

		IsAnswerCorrect(Num1, Num2, Answer, enOperationTybe::Add , AnswerCounter);

		break;
	}
	case enOperationTybe::Sup:
	{
		int Num1 = NumbersReturnedBy(Level), Num2 = NumbersReturnedBy(Level);

		cout << Num1 << endl;
		cout << Num2 << " -\n" << endl;
		cout << "---------" << endl;
		int Answer = 0;
		cin >> Answer;

		IsAnswerCorrect(Num1, Num2, Answer, enOperationTybe::Sup, AnswerCounter);

		break;
	}
	case enOperationTybe::Mul:
	{
		int Num1 = NumbersReturnedBy(Level), Num2 = NumbersReturnedBy(Level);

		cout << Num1 << endl;
		cout << Num2 << " X\n" << endl;
		cout << "---------" << endl;
		int Answer = 0;
		cin >> Answer;

		IsAnswerCorrect(Num1, Num2, Answer, enOperationTybe::Mul, AnswerCounter);

		break;
	}
	case enOperationTybe::Div:
	{
		int Num1 = NumbersReturnedBy(Level), Num2 = NumbersReturnedBy(Level);

		cout << Num1 << endl;
		cout << Num2 << " /\n" << endl;
		cout << "---------" << endl;
		int Answer = 0;
		cin >> Answer;

		IsAnswerCorrect(Num1, Num2, Answer, enOperationTybe::Mul, AnswerCounter);

		break;
	}
	default:
		break;
	}
}

void CheckAnswer(stCounters& AnswerCounter)
{
	if (AnswerCounter.CorrectCounter == AnswerCounter.WrongCounter)
	{
		cout << " Final Result Is Draw :-|";
		system("color 6F"); //Yallow
	}
	if (AnswerCounter.CorrectCounter > AnswerCounter.WrongCounter)
	{
		cout << " Final Result Is Pass :-)";
		system("color 2F"); //green
	}
	if (AnswerCounter.CorrectCounter < AnswerCounter.WrongCounter)
	{
		cout << " Final Result Is Fail :-(\a";
		system("color 4F"); //Red
	}

}

string ConvertLevelFromEnToStr(enLevel Level)
{
	switch (Level)
	{
	case Easy:
		return "Easy";
		break;
	case Med:
		return "Med";
		break;
	case Hard:
		return "Hard";
		break;
	case Mix:
		return "Mix";
		break;
	default:
		break;
	}
}

string ConvertOpTybeFromEnToStr(enOperationTybe OpTybe)
{
	switch (OpTybe)
	{
	case enOperationTybe::Add:
		return "Add";
		break;
	case enOperationTybe::Sup:
		return "Sub";
		break;
	case enOperationTybe::Mul:
		return "Mul";
		break;
	case enOperationTybe::Div:
		return "Div";
		break;
	case enOperationTybe::mix:
		return "Mix";
		break;
	}
}

void PrintPassFailScreen(stCounters& AnswerCounter)
{
	cout << "\n\n---------------------------\n\n";
	CheckAnswer(AnswerCounter);
	cout << "\n\n---------------------------\n";

}

void PrintResult(stCounters& AnswerCounter , enLevel Level , enOperationTybe OpTybe)
{
	cout << "Number Of Questhions: " << AnswerCounter.NumberOfQuesthions << endl;
	cout << "Questhions Level    : " << ConvertLevelFromEnToStr(Level) << endl;
	cout << "OpTybe             : " << ConvertOpTybeFromEnToStr(OpTybe) << endl;
	cout << "Number Of Right Answer: " << AnswerCounter.CorrectCounter << endl;
	cout << "Number Of Wrong Answer: " << AnswerCounter.WrongCounter << endl;

}

void PrintRoundOfQuesthions(stCounters& AnswerCounter, enLevel Level, enOperationTybe OpTybe)
{
	
	for (int i = 1; i <= AnswerCounter.NumberOfQuesthions; i++)
	{
		cout << "\n\nQuesthion [" << i << "/" << AnswerCounter.NumberOfQuesthions << "]\n" << endl;

		PrintCalculation(Level, OpTybe, AnswerCounter);
		
	}

}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void ShowFinalGameResult()
{
	stCounters AnswerCounter;

	AnswerCounter.NumberOfQuesthions = ReadPositiveNumber("How Many Questions Do You Want To Answer ? ");
	enLevel Level = ReadLevel();
	enOperationTybe OpTybe = ReadOperationTybe();

	PrintRoundOfQuesthions(AnswerCounter, Level, OpTybe);

	PrintPassFailScreen(AnswerCounter);
	PrintResult(AnswerCounter, Level, OpTybe);
}

void StartGame()
{
	char PlayAginY_N = 'Y';
	while (PlayAginY_N == 'Y' || PlayAginY_N == 'y')
	{
		ResetScreen();

		ShowFinalGameResult();


		PlayAginY_N = ReadPlayAgin(PlayAginY_N);
	}

}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}
