// Michael McCain
// CIS 1202 
// 4/28/2022

#include <string>
#include<cstring>
#include <iostream>

using namespace std;

template<typename CHAR>
char Character(CHAR start, int offset)
{
	// 65 - 90 = A - Z; 97 - 122 = a-z;
	string invalidCharacterException = "\nError: Invalid character used. Please enter only alpha keys (A-Z,a-z)>";
	string invalidRangeException = "\nError: Invalid character used. Please enter only positive integers>";
	if (isdigit(start) || ispunct(start))
	{
		throw invalidCharacterException;
	}
	if (offset < 0)
	{
		throw invalidRangeException;
	}
	else 
	{
	start = (start + offset);
	}
	return start;
}


int main()
{
	bool again = true;
	char ch = ' ';
	int offSet = 0;
	while (again)
	{
		try {
			cout << "\nEnter a letter>";
			cin >> ch;

			cout << "\nEnter a offset number>";
			cin >> offSet;

			char letter = Character(ch, offSet);
			cout << letter;

			cout << "\nEnter 1 for another number, else enter 0>";
			cin >> again;
		}
		catch (string invalidCharacterException)
		{
			cout << invalidCharacterException;
		}

		//catch (string invalidRangeException) {
		//	cout << invalidRangeException;
		//}
	}

	char letter = Character('a', 1);
	cout << "\n" << letter;
	
	cout << endl << endl;
	system("pause");
	return 0;
}

