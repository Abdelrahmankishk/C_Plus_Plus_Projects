#include <iostream>
#include <string>
#include <Exception>
using namespace std;
#include "Shapes.h"

void StartMenu();
char Shapeschoice();
void OptionsMenu(char c);
int OptionsChoice(char c);
void Shape(char c, int x);
void Shape2d(char c, int x);
void Shape3d(char c, int x);
void ShapeOptions(char c, int x);
bool end();

void main() {
	cout << "Welcome to Shapes Program!!" << endl;
	char c;
	int x;
	bool check;
	do {
		StartMenu();
		try {
			c = Shapeschoice();
		}
		catch (exception e) {
			cout << e.what() << endl;
			break;
		}
		OptionsMenu(c);
		try {
			x = OptionsChoice(c);
		}
		catch (exception e) {
			cout << e.what() << endl;
			break;
		}
		ShapeOptions(c, x);
		check = end();
		if (check == true)
			break;
	} while (check == false);
	cout << "Thank you for Using the Program !!";
}

void StartMenu() {
	cout << "Choose a Shape the Shape: " << endl;
	cout << "{ 'l' for  a Line , 'p' for Point , 's' for a Square , 'r' for a Rectangle, 'c' for a Circle , '1' for a cube," << endl; 
	cout << "'2' for a Cubiod, '3' for a Cylinder }" << endl;
}

char Shapeschoice() {
	char choice;
	cout << "Your choice: ";
	cin >> choice;
	choice = tolower(choice);
	if (choice != 'l' && choice != 'p' && choice != 's' && choice != 'r' && choice != 'c' && choice != '1' && choice != '2' && choice != '3')
		throw exception("INVALID CHOICE");
	return choice;
}
void OptionsMenu(char c) {
	if (c == 'l' || c == 'p') {
		cout << "Enter 1 if you want to Draw" << endl;
	}
	else if (c == 's' || c == 'r' || c == 'c') {
		cout << "Enter 1 if you want to Draw" << endl;
		cout << "Enter 2 if you want to Calculate the Area" << endl;
		cout << "Enter 3 if you want to Calculate the Perimeter" << endl;
	}
	else {
		cout << "Enter 1 if you want to Draw" << endl;
		cout << "Enter 2 if you want to Calculate the Area" << endl;
		cout << "Enter 3 if you want to Calculate the Perimeter" << endl;
		cout << "Enter 4 if you want to Calculate the Volume" << endl;
	}
}
int OptionsChoice(char c) {
	int x;
	char q = c;
	cout << "Your Choice: ";
	cin >> x;
	if (c == 'l' || c == 'p') {
		if (x != 1)
			throw exception("INVALID CHOICE");
	}
	else if (c == 's' || c == 'r' || c == 'c') {
		if (x != 1 && x != 2 && x != 3)
			throw exception("INVALID CHOICE");
	}
	else {
		if (x != 1 && x != 2 && x != 3 && x != 4)
			throw exception("INVALID CHOICE");
	}
	return x;
}
void Shape(char c, int x) {
	shape* s;
	if (c == 'l') {
		if (x == 1) {
			s = new Line;
			s->Draw();
		}
	}
	else if (c == 'p') {
		if (x == 1) {
			s = new point;
			s->Draw();
		}
	}
}

void Shape2d(char c, int x) {
	Shape2D* s;
	if (c == 's') {
		if (x == 1) {
			s = new Square;
			s->Draw();
		}
		else if (x == 2) {
			s = new Square;
			s->Area();
		}
		else if (x == 3) {
			s = new Square;
			s->Perimeter();
		}
	}
	else if (c == 'r') {
		if (x == 1) {
			s = new Rectangle;
			s->Draw();
		}
		else if (x == 2) {
			s = new Rectangle;
			s->Area();
		}
		else if (x == 3) {
			s = new Rectangle;
			s->Perimeter();
		}
	}
	else if (c == 'c') {
		if (x == 1) {
			s = new Circle;
			s->Draw();
		}
		else if (x == 2) {
			s = new Circle;
			s->Area();
		}
		else if (x == 3) {
			s = new Circle;
			s->Perimeter();
		}
	}
}

void Shape3d(char c, int x) {
	Shape3D* s;
	if (c == '1') {
		if (x == 1) {
			s = new Cube;
			s->Draw();
		}
		else if (x == 2) {
			s = new Cube;
			s->Area();
		}
		else if (x == 3) {
			s = new Cube;
			s->Perimeter();
		}
		else if (x == 4) {
			s = new Cube;
			s->Volume();
		}
	}
	else if (c == '2') {
		if (x == 1) {
			s = new Cuboid;
			s->Draw();
		}
		else if (x == 2) {
			s = new Cuboid;
			s->Area();
		}
		else if (x == 3) {
			s = new Cuboid;
			s->Perimeter();
		}
		else if (x == 4) {
			s = new Cuboid;
			s->Volume();
		}
	}
	else if (c == '3') {
		if (x == 1) {
			s = new Cylinder;
			s->Draw();
		}
		else if (x == 2) {
			s = new Cylinder;
			s->Area();
		}
		else if (x == 3) {
			s = new Cylinder;
			s->Perimeter();
		}
		else if (x == 4) {
			s = new Cylinder;
			s->Volume();
		}
	}
}
void ShapeOptions(char c, int x) {
	switch (c)
	{
	case 'l':
		Shape(c, x);
		break;
	case 'p':
		Shape(c, x);
		break;
	case 's':
		Shape2d(c, x);
		break;
	case 'r':
		Shape2d(c, x);
		break;
	case 'c':
		Shape2d(c, x);
		break;
	case '1':
		Shape3d(c, x);
		break;
	case '2':
		Shape3d(c, x);
		break;
	case '3':
		Shape3d(c, x);
		break;
	default:
		break;
	}
}

bool end() {
	char choice;
	cout << "Do you Want to Exit ?" << endl;
	cout << "Write 'y if yes and n for 'No'" << endl;
	cout << "Your choice: ";
	cin >> choice;
	choice = tolower(choice);
	if (choice == 'y')
		return true;
	else
		return false;
}