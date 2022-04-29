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
	// 65 - 90 = A - Z; 
	// 97 - 122 = a-z;
	string invalidCharacterException = "\nError: Invalid character used. Please enter only alpha keys (A-Z,a-z)>";
	string invalidRangeException = "\nError: Invalid character range. Please try again (try a lower offset value)>";

	if (isdigit(start) || ispunct(start))
	{
		throw invalidCharacterException;
	}

	int ckStart = (start + offset);

	if ((start >= 65 && start <= 90) && (ckStart > 90 || ckStart < 65))
	{
		throw invalidRangeException;
	}
	else if ((start >= 97 && start <= 122) && (ckStart > 122 || ckStart < 97))
	{
		throw invalidRangeException;
	}

	start = (start + offset);
	return start;
}


int main()
{
	bool again = true;
	char ch;
	int offSet = 0;
	while (again)
	{
		try {
			cout << "\nEnter a letter>";
			cin >> ch;
			cin.ignore();

			cout << "Enter a offset number>";
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
	}
	
	cout << endl << endl;
	system("pause");
	return 0;
}

