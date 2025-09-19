#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


enum enQuestionsLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mix = 4 };

enum enOperationTybe { Add = 1, Sup = 2, Mul = 3, Div = 4, MixoOp = 5 };

struct stQuizz
{
	short NumberOfQuestions = 0;
	enQuestionsLevel QuestionsLevel;
	enOperationTybe OperationTybe;
	short CorrectCounter = 0;
	short WrongCounter = 0;
};

short ReadHowManyQuestions()
{
	short NumberOfQuestions;
	do
	{
		cout << "How Many Questions Do You Want To Answer ? ";
		cin >> NumberOfQuestions;
	} while (NumberOfQuestions < 1 || NumberOfQuestions > 10);


	return NumberOfQuestions;
}

enQuestionsLevel ReadQuestionsLevel()
{
	short QuestionsLevel;
	do
	{
		cout << "Enter Questhion Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
		cin >> QuestionsLevel;
	} while (QuestionsLevel < 1 || QuestionsLevel > 4);


	return enQuestionsLevel(QuestionsLevel);
}

enOperationTybe ReadOperationTybe()
{
	short OperationTybe;
	do
	{
		cout << "Enter Operation  Tybe [1] Add, [2] Sup, [3] Mul, [4] Div, [5] Mix ? ";
		cin >> OperationTybe;
	} while (OperationTybe < 1 || OperationTybe > 5);


	return enOperationTybe(OperationTybe);
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

int NumbersReturnedBy(enQuestionsLevel QuestionsLevel)
{
	switch (QuestionsLevel)
	{
	case enQuestionsLevel::EasyLevel:
		return RandomNumber(1, 10);
		break;

	case enQuestionsLevel::MedLevel:
		return RandomNumber(10, 50);
		break;

	case enQuestionsLevel::HardLevel:
		return RandomNumber(50, 100);
		break;

	default:
		return RandomNumber(10, 100);
		break;
	}
}

void IsAnswerCorrect(int Num1, int Num2, int Answer, enOperationTybe OpTybe , stQuizz& Quizz)
{
	switch (OpTybe)
	{
	case enOperationTybe::Add:
	{
		if (Answer == Num1 + Num2)
		{
			cout << "Right Answer :-) " << endl;
			system("color 2F");

			Quizz.CorrectCounter++;
		}
		else
		{
			cout << "Wrong Answer :-( \a" << endl;
			cout << "The Right Answer Is : " << Num1 + Num2 << endl;
			system("color 4F");

			Quizz.WrongCounter++;
		}
		break;
	}
	case enOperationTybe::Sup:
	{
		if (Answer == Num1 - Num2)
		{
			cout << "Right Answer :-) " << endl;
			system("color 2F");

			Quizz.CorrectCounter++;
		}
		else
		{
			cout << "Wrong Answer :-( " << endl;
			cout << "The Right Answer Is : " << Num1 - Num2 << endl;
			system("color 4F");

			Quizz.WrongCounter++;
		}
		break;
	}
	case enOperationTybe::Mul:
	{
		if (Answer == Num1 * Num2)
		{
			cout << "Right Answer :-) " << endl;
			system("color 2F");

			Quizz.CorrectCounter++;
		}
		else
		{
			cout << "Wrong Answer :-( " << endl;
			cout << "The Right Answer Is : " << Num1 * Num2 << endl;
			system("color 4F");

			Quizz.WrongCounter++;
		}
		break;
	}
	case enOperationTybe::Div:
	{
		if (Answer == Num1 / Num2)
		{
			cout << "Right Answer :-) " << endl;
			system("color 2F");

			Quizz.CorrectCounter++;
		}
		else
		{
			cout << "Wrong Answer :-( " << endl;
			cout << "The Right Answer Is : " << Num1 / Num2 << endl;
			system("color 4F");

			Quizz.WrongCounter++;
		}
		break;
	}
	default:
		break;
	}
}

enQuestionsLevel CheckIfLevelMix(stQuizz Quizz)
{
	if (Quizz.QuestionsLevel == enQuestionsLevel::Mix)
	{
		return enQuestionsLevel(RandomNumber(1, 3));
	}
	else
		return Quizz.QuestionsLevel;
}

enOperationTybe CheckIfOpeMix(stQuizz Quizz)
{
	if (Quizz.OperationTybe == enOperationTybe::MixoOp)
	{
		return enOperationTybe(RandomNumber(1, 4));
	}
	else
		return Quizz.OperationTybe;
}

void PrintCalculation(stQuizz& Quizz)
{

	enQuestionsLevel TempLevel;
	enOperationTybe TempLOperationTybe;

	if (Quizz.QuestionsLevel == enQuestionsLevel::Mix)
	{
		TempLevel = enQuestionsLevel(RandomNumber(1, 3));
	}
	if (Quizz.OperationTybe == enOperationTybe::MixoOp)
	{
		TempLOperationTybe = enOperationTybe(RandomNumber(1, 4));
	}
	else
	{
		TempLevel = Quizz.QuestionsLevel;
		TempLOperationTybe = Quizz.OperationTybe;
	}

	switch (TempLOperationTybe)
	{
	case enOperationTybe::Add:
	{
		int Num1 = NumbersReturnedBy(TempLevel), Num2 = NumbersReturnedBy(TempLevel);

		cout << Num1 << endl;
		cout << Num2 << " +\n" << endl;
		cout << "---------" << endl;
		int Answer = 0;
		cin >> Answer;

		IsAnswerCorrect(Num1, Num2, Answer, enOperationTybe::Add, Quizz);

		break;
	}
	case enOperationTybe::Sup:
	{
		int Num1 = NumbersReturnedBy(TempLevel), Num2 = NumbersReturnedBy(TempLevel);

		cout << Num1 << endl;
		cout << Num2 << " -\n" << endl;
		cout << "---------" << endl;
		int Answer = 0;
		cin >> Answer;

		IsAnswerCorrect(Num1, Num2, Answer, enOperationTybe::Sup, Quizz);

		break;
	}
	case enOperationTybe::Mul:
	{
		int Num1 = NumbersReturnedBy(TempLevel), Num2 = NumbersReturnedBy(TempLevel);

		cout << Num1 << endl;
		cout << Num2 << " X\n" << endl;
		cout << "---------" << endl;
		int Answer = 0;
		cin >> Answer;

		IsAnswerCorrect(Num1, Num2, Answer, enOperationTybe::Mul, Quizz);

		break;
	}
	case enOperationTybe::Div:
	{
		int Num1 = NumbersReturnedBy(TempLevel), Num2 = NumbersReturnedBy(TempLevel);

		cout << Num1 << endl;
		cout << Num2 << " /\n" << endl;
		cout << "---------" << endl;
		int Answer = 0;
		cin >> Answer;

		IsAnswerCorrect(Num1, Num2, Answer, enOperationTybe::Div, Quizz);

		break;
	}
	default:
		break;
	}
}

void CheckAnswer(stQuizz& Quizz)
{
	if (Quizz.CorrectCounter == Quizz.WrongCounter)
	{
		cout << " Final Result Is Draw :-|";
		system("color 6F"); //Yallow
	}
	if (Quizz.CorrectCounter > Quizz.WrongCounter)
	{
		cout << " Final Result Is Pass :-)";
		system("color 2F"); //green
	}
	if (Quizz.CorrectCounter < Quizz.WrongCounter)
	{
		cout << " Final Result Is Fail :-(\a";
		system("color 4F"); //Red
	}

}

string ConvertLevelFromEnToStr(stQuizz Quizz)
{
	switch (Quizz.QuestionsLevel)
	{
	case EasyLevel:
		return "Easy";
		break;
	case MedLevel:
		return "Med";
		break;
	case HardLevel:
		return "Hard";
		break;
	case Mix:
		return "Mix";
		break;
	default:
		break;
	}
}

string ConvertOpTybeFromEnToStr(stQuizz Quizz)
{
	switch (Quizz.OperationTybe)
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
	case enOperationTybe::MixoOp:
		return "Mix";
		break;
	}
}

void PrintPassFailScreen(stQuizz& Quizz)
{
	cout << "\n\n---------------------------\n\n";
	CheckAnswer(Quizz);
	cout << "\n\n---------------------------\n";

}

void PrintResult(stQuizz& Quizz)
{
	cout << "Number Of Questions: " << Quizz.NumberOfQuestions << endl;
	cout << "Questions Level    : " << ConvertLevelFromEnToStr(Quizz) << endl;
	cout << "OpTybe             : " << ConvertOpTybeFromEnToStr(Quizz) << endl;
	cout << "Number Of Right Answer: " << Quizz.CorrectCounter << endl;
	cout << "Number Of Wrong Answer: " << Quizz.WrongCounter << endl;

}

void GeneratesQuizzQuestions(stQuizz& Quizz)
{

	for (int i = 1; i <= Quizz.NumberOfQuestions; i++)
	{
		cout << "\n\nQuesthion [" << i << "/" << Quizz.NumberOfQuestions << "]\n" << endl;

		PrintCalculation(Quizz);

	}

}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void ShowFinalGameResult()
{
	stQuizz Quizz;

	Quizz.NumberOfQuestions = ReadHowManyQuestions();
	Quizz.QuestionsLevel = ReadQuestionsLevel();
	Quizz.OperationTybe = ReadOperationTybe();



	GeneratesQuizzQuestions(Quizz);

	PrintPassFailScreen(Quizz);
	PrintResult(Quizz);
}

void StartGame()
{
	char PlayAginY_N = 'Y';

	do
	{

		ResetScreen();
		ShowFinalGameResult();


		PlayAginY_N = ReadPlayAgin(PlayAginY_N);

	} while (PlayAginY_N == 'Y' || PlayAginY_N == 'y');

}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}
