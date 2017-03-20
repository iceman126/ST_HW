#include "hw1.h"

string triangle(int a, int b, int c) {
	// invalid input
	vector<char> invalid_var;
	invalid_var.clear();
	if (a < 0 || a > 200)
		invalid_var.push_back('a');
	if (b < 0 || b > 200)
		invalid_var.push_back('b');
	if (c < 0 || c > 200)
		invalid_var.push_back('c');

	if (invalid_var.size() > 0) {
		string error_msg = "Value of ";
		for (int i = 0; i < invalid_var.size(); i++) {
			error_msg += invalid_var[i];
			if (i != invalid_var.size() - 1)
				error_msg += ",";
		}
		error_msg += " is not in the range of permitted values";
		return error_msg;
	}


	// not a triangle
	if ((a + b) < c || (b + c) < a || (c + a) < b)
		return string("Not a triangle");

	// triangle types
	if (a == b && b == c) {
		return string("Equilateral");
	}
	else if (a == b || b == c || c == a) {
		return string("Isosceles");
	}
	else {
		return string("Scalene");
	}
}

string commission(int locks, int stocks, int barrels) {
	if (locks == -1)
		return "";

	// invalid input
	vector<string> invalid_msg;
	invalid_msg.clear();
	if (locks == 0 || locks < -1 || locks > 70)
		invalid_msg.push_back("locks should be in range of 1~70");
	if (stocks < 1 || stocks > 80)
		invalid_msg.push_back("stocks should be in range of 1~80");
	if (barrels < 1 || barrels > 90)
		invalid_msg.push_back("barrels should be in range of 1~90");

	if (invalid_msg.size() > 0) {
		string error_msg = "";
		for (int i = 0; i < invalid_msg.size(); i++) {
			error_msg += invalid_msg[i];
			if (i != invalid_msg.size() - 1)
				error_msg += " & ";
		}
		return error_msg;
	}

	double c = 0;
	double total = locks * 45 + stocks * 30 + barrels * 25;

	if (total > 1800) {
		c = (total - 1800) * 0.2 + 800 * 0.15 + 1000 * 0.1;
	}
	else if (total > 1000) {
		c = (total - 1000) * 0.15 + 1000 * 0.1;
	}
	else {
		c = total * 0.1;
	}

	stringstream ss;
	ss << fixed << setprecision(2) << c;
	string result = "$" + ss.str();
	return result;
}

/*
int main() {
	return 0;
}
*/