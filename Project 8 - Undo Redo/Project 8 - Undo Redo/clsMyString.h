#pragma once

#include <stack>
using namespace std;

class clsMyString
{
private:
	string _value = "";
	stack<string> _UndoStack;

	stack<string> _RedoStack;



public:

	void SetValue(string value)
	{
		if (_UndoStack.empty())
		{
			_UndoStack.push(_value);
			_RedoStack.push(_value);

		}

		_value = value;

		_UndoStack.push(_value);

		_RedoStack = _UndoStack;
	}

	string GetValue()
	{
		return _value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;


	void Undo()
	{
		_RedoStack.push(_value);

		_UndoStack.pop();

		_value = _UndoStack.top();

	}

	void Redo()
	{
		_value = _RedoStack.top();

		_RedoStack.pop();

	}

};

