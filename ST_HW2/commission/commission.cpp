#include "hw1.h"

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