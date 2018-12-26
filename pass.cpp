/*
You are developing a software package that requires users to enter their own passwords.
Your software requires that user passwords meet the following criteria:
the password should be at least 6 characters long and no more than 15 characters
the password should contain at least one uppercase and at at least one lowercase letter
the password should have at least one digit.
the password should contain one of the following characters:
! @ # $ % but no other special characters
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <cctype>
using namespace std;

bool testLength(char pass[]);
bool checkUpperLower(char pass[]);
bool checkDigit(char pass[]);
bool checkSpecial(char pass[]);


int main() {
	//Max characters for a password
	const int MAX = 1000;
	char passWord[MAX];

	do {
		cout << "\nEnter a password: ";
		cin.getline(passWord, MAX);

	} while (!(testLength(passWord) & checkUpperLower(passWord) & checkDigit(passWord) & checkSpecial(passWord)));

    cout << "Password has met the requirements!\n";
	return 0;
}

bool testLength(char pass[]) {

	if (strlen(pass) >= 6 && strlen(pass) <= 15)
		return true;

	cout << "Password did not pass the length test!\n";
	cout << "Hint: Your password must be between 6 - 15 characters!\n\n";

	return false;
}

bool checkUpperLower(char pass[]) {
	//Counter to keep track of upper / lowercase letters
	int upperCount = 0;
	int lowerCount = 0;

	//Using "for" loop to iterate through each char to check for lower and upper case letters
	for (int i = 0; i < strlen(pass); i++) {
		if (isupper(pass[i])) {
			upperCount++; //Increment each time if condition is true

		} else if (islower(pass[i])) {
			lowerCount++;
		}

		if (upperCount > 0 && lowerCount > 0)
			return true;
	}

	cout << "Password did not pass either the uppercase and/or the lowercase test!\n";
	cout << "Hint: Your password must contain at least 1 uppercase letter and at least 1 lowercase letter!\n\n";

	return false;
}

bool checkDigit(char pass[]) {

    cout <<  "strlen(pass) is: " << strlen(pass);
	for (int i = 0; i < strlen(pass); i++) {
		if (isdigit(pass[i]))
			return true;
	}

	cout << "Password did not pass the digit test!\n";
	cout << "Hint: Your password must contain at least one numerical digit!\n\n";

	return false;
}

bool checkSpecial(char pass[]) {

	for (int i = 0; i < strlen(pass); i++) {
		// Check if there any special characters
		if ((pass[i] == '$' || pass[i] == '@' || pass[i] == '#' || pass[i] == '!' || pass[i] == '%'))
			return true;
	}

	cout << "Password did not pass the special character test!\n";
	cout << "Hint: Your password must contain at least one of the following special characters ... $ @ # ! %\n\n";

	return false;
}
