// #include "hw1.h"

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;


string next_date(int month, int day, int year) {
	bool leap_year = false;
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		leap_year = true;

	unordered_set<int> short_months = { 4, 6, 9, 11 };
	unordered_set<int> long_months = { 1, 3, 5, 7, 8, 10, 12 };

	if (month < 1 || month > 12 || day > 31 || day < 1 || year < -1) {
		return string("Invalid input date");
	}

	int next_month, next_day, next_year;

	// February
	if (month == 2) {
		if (leap_year) {
			if (day > 29) {
				return string("Invalid input date");
			}

			if (day == 29) {
				next_month = month + 1;
				next_day = 1;
				next_year = year;
			}
			else {
				next_month = month;
				next_day = day + 1;
				next_year = year;
			}
		}
		else {
			if (day > 28) {
				return string("Invalid input date");
			}
			if (day == 28) {
				next_month = month + 1;
				next_day = 1;
				next_year = year;
			}
			else {
				next_month = month;
				next_day = day + 1;
				next_year = year;
			}
		}
	}
	// long months
	else if (long_months.find(month) != long_months.end()) {
		/* Already prevent day > 31 at line 11~13
		if (day > 31)
			return string("Invalid input date");
		*/

		if (day == 31) {
			if (month == 12) {
				next_month = 1;
				next_day = 1;
				next_year = year + 1;
			}
			else {
				next_month = month + 1;
				next_day = 1;
				next_year = year;
			}
		}
		else {
			next_month = month;
			next_day = day + 1;
			next_year = year;
		}
	}
	// short months
	else {
		if (day > 30)
			return string("Invalid input date");

		if (day == 30) {
			next_month = month + 1;
			next_day = 1;
			next_year = year;
		}
		else {
			next_month = month;
			next_day = day + 1;
			next_year = year;
		}
	}

	return to_string(next_month) + "/" + to_string(next_day) + "/" + to_string(next_year);
}


int main() {
	int m;
	int d;
	int y;
	cin >> m >> d >> y;
	cout << next_date(m, d, y) << endl;
	return 0;
}
