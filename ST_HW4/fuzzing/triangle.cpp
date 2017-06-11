#include <iostream>
#include <vector>
#include <string>

using namespace std;

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


int main(){
    short a, b, c;
    cin >> a >> b >> c;
    cout << triangle(a, b, c) << endl;
    return 0;
}
