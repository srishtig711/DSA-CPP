#include<iostream>
#include<limits>
using namespace std;
int main() {
    string str;
    cout << "Enter input: ";
    getline(cin, str, ',');
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << endl << "Output is: ";
    cout << str << endl;
    char st[15];
    cout << "Enter input: ";
    cin.getline(st, 15, ',');
    cout << endl << "Output is: " << endl;
    cout << st << endl;
    return 0;
}