#include <iostream>
using namespace std;

int fromDecimalToBinary(int number) {
	int result = 0;
	int mul = 1;
	while (number != 0) {
		int mod = number % 2;
		result += mod * mul;
		mul *= 10;
		number /= 2;
	}
	return result;
}

int fromBinaryToDecimal(int number) {
	int result = 0;
	int mul = 1;
	while (number != 0) {
		int mod = number % 10;
		result += mod * mul;
		mul *= 2;
		number /= 10;
	}
	return result;
}

int fromDecimalToOcta(int number) {
	int result = 0;
	int mul = 1;
	while (number != 0) {
		int mod = number % 8;
		result += mod * mul;
		mul *= 10;
		number /= 8;
	}
	return result;
}

int fromOctaToDecimal(int number) {
	int result = 0;
	int mul = 1;
	while (number != 0) {
		int mod = number % 10;
		result += mod * mul;
		mul *= 8;
		number /= 10;
	}
	return result;
}

int FromBinaryToOCTAL(int number) {
	int x = fromBinaryToDecimal(number);
	int y = fromDecimalToOcta(x);
	return y;
}

int fromOCTALtoBinary(int number){
	int x = fromOctaToDecimal(number);
	int y = fromDecimalToBinary(x);
	return y;
}


void choice() {	
	char choice;
	int num;
	char choice1;
	cout << "Enter The Number: ";
	cin >> num;
	cout << "What is The type of the number you  entered?" << endl;
	cout << "Enter 'B' for Binary ,'D' for Decimal , 'O' for Octal" << endl;
	cout << "Your Choice: ";
	cin >> choice1;

	cout << endl;
	choice1 = toupper(choice1);

	switch (choice1) {
	case 'B':
		cout << "To What do you want to convert This Binary Number ?"<< endl;
		cout << "Enter 'D' to convert to Decimal or Enter 'O' to convert to octal" << endl;
		cout << "Your choice: ";
		cin >> choice;
		cout << endl;
		choice = toupper(choice);
			switch (choice)
			{
			case 'D':
				cout << "The Result of converting The number to Decimal: " << fromBinaryToDecimal(num)<<endl ;
				break;
			case 'O':
				cout << "The Result of converting The number to Octal: " << FromBinaryToOCTAL(num)<< endl;
				break;
			default:
				cout << "INVALID INPUT PLEASE TRY AGIAN!" <<endl;
				break;
			}
		break;
	case 'D':
		cout << "To What do you want to convert This Decimal Number ?" << endl;
		cout << "Enter 'B' to convert to Binary or Enter 'O' to convert to octal" << endl;
		cout << "Your choice: ";
		cin >> choice;
		cout << endl;
		choice = toupper(choice);
			switch (choice)
			{
			case 'B':
				cout << "The Result of converting The number to Binary: " << fromDecimalToBinary(num) << endl;
				break;
			case 'O':
				cout << "The Result of converting The number to Octal: " << fromDecimalToOcta(num) << endl;
				break;
			default:
				cout << "INVALID INPUT PLEASE TRY AGIAN!"<< endl;
				break;
			}
		break;
	case 'O':
		cout << "To What do you want to convert This Octal Number ?" << endl;
		cout << "Enter 'D' to convert to Decimal or Enter 'B' to convert to Binary" << endl;
		cout << "Your choice: ";
		cin >> choice;
		cout << endl;
		choice = toupper(choice);
			switch (choice)
			{
			case 'B':
				cout << "The Result of converting The number to Binary: " << fromOCTALtoBinary(num) << endl;
				break;
			case 'D':
				cout << "The Result of converting The number to Decimal: " << fromOctaToDecimal(num) << endl;
				break;
			default:
				cout << "INVALID INPUT PLEASE TRY AGIAN!" <<endl;
				break;
			}
		break;
	default:
		cout << "INVALID INPUT PLEASE TRY AGIAN!" << endl;
		cout << endl;
		break;
	}
}

char check_Repeat() {
	char i;
	while (true){
		cout << "Do you want to enter another number?" << endl;
		cout << "Enter '1' to continue or '2' to Exit" <<endl;
		cout << "Your choice: ";
		cin >> i;
		cout << endl;
		switch (i)
		{
		case '1':
			choice();
			break;
		case '2':
			cout << endl;
			cout << "Thanks For Using My Base Conversion Program!" << endl;
			break;
		default:
			cout << "INVALID INPUT PLEASE TRY AGIAN!" << endl;
			break;
		}
		cout << endl;
		if (i == '2') {
			return i;
			break;
		}
	} 
	
}

int main() {
	bool x = true;
	cout << "Welcome to My Base Conversion Program" << endl;
	cout << endl << endl;

	choice();
	cout << endl;
	while (x) {

		char y = check_Repeat();
		if (y == '2') {
			x = false;
		}
		else {
			continue;
		}
		cout << endl;
		}

}