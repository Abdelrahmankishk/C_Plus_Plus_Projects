#pragma once
class shape {
protected:
	virtual string name() = 0;
	virtual void ReadInput() = 0;
public:
	virtual void Draw() = 0;
};

class Shape2D : public shape {
public:
	virtual void Area() = 0;
	virtual void Perimeter() = 0;
};

class Shape3D : public Shape2D {
public:
	virtual void Volume() = 0;
};

class point : public shape{
	int count;
protected:
	virtual string name() {
		return "Point";
	}
	virtual void ReadInput() {
		cout << "Enter the number of Points you want to Draw: ";
		cin >> count;
	}
public:
	point() {
		cout << "This is a " << name() <<endl ;
		ReadInput();
	}
	virtual void Draw() {
		for (int i = 0; i < count; i++)
			cout << "*" << endl;
	}
};

class Line : public shape {
	int lenght;
protected:
	virtual string name() {
		return "Line";
	}
	virtual void ReadInput() {
		cout << "Enter The Lenght of the " << name() << ": ";
		cin >> lenght;
	}
public:
	Line() {
		ReadInput();
	}
	virtual void Draw() {
		for (int i = 0; i < lenght; i++)
			cout << "-";
	}
};

class Square : public Shape2D {
	int s;
protected:
	virtual string name() {
		return "Square";
	}
	virtual void ReadInput() {
		cout << "Enter The Side lenght of the " << name() << ": ";
		cin >> s;
	}
public:
	Square() {
		ReadInput();
	}
	virtual void Draw() {
		int choice;
		cout << "Do you want to a Filled " << name() << " or a Empty " << name() << "?" << endl;
		cout << "Enter 1 for Filled and 2 for Empty"<< endl;
		cout << "Your Choice: ";
		cin >> choice;
		switch (choice) {
			case 1:
				for (int i = 0; i < s; i++) {
					for (int j = 0; j < s ; j++) {
						cout << "-";
					}
					cout << endl;
				}
				break;
			case 2 :
				for (int i = 0; i < s; i++) {
					for (int j = 0; j < s; j++) {
						if (i == 0 || i == s-1 || j == 0 || j == s-1) {
							cout << "*";

						}
						else
						{
							cout << " ";
						}
					}
					cout << endl;
				}
				break;
			default:
				cout << "INVALID CHOICE!!" << endl;
				break;
		}
	}
	virtual void Perimeter() {
		cout << "The Perimeter of The " << name() <<" is " << 4 * s << endl;
	}
	virtual void Area() {
		cout << "The Area of The Square " << name() <<" is " << s * s << endl;
	}
};

class Rectangle : public Shape2D {
	int l,w;
protected:
	virtual string name() {
		return "Rectangle";
	}
	virtual void ReadInput() {
		cout << "Enter The lenght and Width of the " << name() << ": ";
		cin >> l >> w;
	}
public:
	Rectangle() {
		ReadInput();
	}
	virtual void Perimeter() {
		cout << "The Perimeter of The "<<name() <<" is " << 2 * (l + w) << endl;
	}
	virtual void Area() {
		cout << "The Area of The " << name() << " is " << l * w << endl;
	}
	virtual void Draw() {
		int choice;
		cout << "Do you want to a Filled " << name() << " or a Empty " << name() << "?" << endl;
		cout << "Enter 1 for Filled and 2 for Empty" << endl;
		cout << "Your Choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			for (int i = 0; i < l; i++) {
				for (int j = 0; j < w+5; j++) {
					cout << "-";
				}
				cout << endl;
			}
			break;
		case 2:
			for (int i = 0; i < l; i++) {
				for (int j = 0; j < w+5; j++) {
					if (i == 0 || i == l-1 || j == 0 || j == w+5-1) {
						cout << "*";

					}
					else
					{
						cout << " ";
					}
				}
				cout << endl;
			}
			break;
		default:
			cout << "INVALID CHOICE!!" << endl;
			break;
		}
	}
		

};

class Circle : public Shape2D {
	int r;
protected:
	virtual string name() {
		return "Circle";
	}
	virtual void ReadInput() {
		cout << "Enter The Raduis of the " << name() << " : ";
		cin >> r;
	}
public:
	Circle (){
		ReadInput();
	}
	virtual void Perimeter() {
		cout << "The Perimeter of The " << name() << " is " << 2 * 3.14f * r << endl;
	}
	virtual void Area() {
		cout << "The Area of The " << name() << " is " << 3.14f * r * r << endl;
	}
	virtual void Draw() {
		cout << "Can Not Draw a " << name() << endl;
	}
};

class Cube : public Shape3D {
	int s;
protected:
	virtual string name() {
		return "Cube";
	}
	virtual void ReadInput() {
		cout << "Enter The Side lenght of the " << name() << ": ";
		cin >> s;
	}

public:
	Cube() {
		ReadInput();
	}
	virtual void Perimeter() {
		cout << "The Perimeter of The " << name() << " is " << 12 * s << endl;
	}
	virtual void Area() {
		cout << "The Area of The " << name() << " is " << 6 * s * s << endl;
	}
	virtual void Volume() {
		cout << "The Volume of The " << name() << " is "<< s * s * s << endl;
	}
	virtual void Draw() {
		cout << "Can Not Draw a " << name() << endl;
	}
};

class Cuboid : public Shape3D {
	int l, w, h;
protected:
	virtual string name() {
		return "Cuboid";
	}
	virtual void ReadInput() {
		cout << "Enter The lenght , width and the height of the " << name() << ": ";
		cin >> l>>w>>h;
	}
public:
	Cuboid() {
		ReadInput();
	}
	virtual void Perimeter() {
		cout << "The Perimeter of The " << name() << " is " << 4 * (l + w + h) << endl;
	}
	virtual void Area() {
		cout << "The Area of The " << name() << " is " << (2 * l * w) + (2 * l * h) + (2 * h * w) << endl;
	}
	virtual void Volume() {
		cout << "The Volume of The " << name() << " is " << l * w * h << endl;
	}
	virtual void Draw() {
		cout << "Can Not Draw a " << name() << endl;
	}
};

class Cylinder : public Shape3D {
	int r, h;
protected:
	virtual string name() {
		return "Cylinder";
	}
	virtual void ReadInput() {
		cout << "Enter The raduis the height of the " << name() << ": ";
		cin >> r >> h;
	}
public:
	Cylinder() {
		ReadInput();
	}
	virtual void Perimeter() {
		cout << "The Perimeter of The " << name() << " is " << 2 * 3.14f * r * h;
	}
	virtual void Area() {
		cout << "The Area of The " << name() << " is " << (2 * 3.14f * r * h) + (2 * 3.14f * r * r);
	}
	virtual void Volume() {
		cout << "The Volume of The " << name() << 3.14f * r * r * h;
	}
	virtual void Draw() {
		cout << "Can Not Draw a " << name() << endl;
	}
};
