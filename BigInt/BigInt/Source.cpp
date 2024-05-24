#include<iostream>
#include<string>
using namespace std;

class BigInt{
	string num;
	string AddNumbers(string n1 , string n2) {
		int size = n1.size();
		if (n2.size() < n1.size())
			size = n2.size();
		int index1 = n1.size() - 1;
		int index2 = n2.size() - 1;
		int remainder=0;
		int total;
		int c1, c2,r;
		string result;
		while (size > 0) {
			c1 = n1[index1] - '0';
			c2 = n2[index2] - '0';
			total = c1 + c2 + remainder;
			remainder = total / 10;
			r = total % 10;
			string n(1, r + '0');
			result.insert(0, n);
			size--;
			index1--;
			index2--;
		}
		if (index1 >= 0 ) {
			if (remainder == 0) {
				result.insert(0, n1.substr(0, index1 + 1));
			}
			else {
				result.insert(0,AddNumbers(n1.substr(0, index1 + 1),string(1,remainder + '0')));
			}
		}
		else if(index2 >=0) {
			if(remainder == 0)
				result.insert(0, n2.substr(0, index2 + 1));
			else
				result.insert(0, AddNumbers(n2.substr(0, index2 + 1), string(1,remainder + '0')));
		}
		else if(remainder > 0){
			result.insert(0, string(1,remainder + '0'));
		}
		return result;
	}

public:
	BigInt() {
		num = "0";
	}
	BigInt(const char* x) {
		num = x;
	}
	BigInt(string x) {
		num = x;
	}
	BigInt operator+(BigInt x) {
		BigInt result;
		result.num = AddNumbers(num, x.num);
		return result;
	}
	BigInt operator+(int y) {
		BigInt result;
		result.num = AddNumbers(num, to_string(y));
		return result;
	}BigInt operator+= (int y) {
		BigInt result;
		result.num = AddNumbers(num, to_string(y));
		return result;
	}
	void operator++() {
		num = AddNumbers(this->num, string(1,1 + '0'));
	}
	void operator++(int) {
		num = AddNumbers(this->num, string(1, 1 + '0'));
	}
	friend BigInt operator+(int x, BigInt y) {
		BigInt result;
		result.num = result.AddNumbers(to_string(x), y.num);
		return result;
	}
	friend ostream& operator<<(ostream& out, BigInt x) {
		out << x.num;
		return out;
	}
};

void main() {
	BigInt n1("65496464684846131354685413654864");
	BigInt n2("49999999999999999999999999999999");
	BigInt result = n1 + n2;
	cout << result << endl;
	n2 = n2 + 1;
	cout << n2 << endl;
	result++;
	cout << result << endl;
}