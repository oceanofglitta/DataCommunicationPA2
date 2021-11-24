#include<iostream>

using namespace std;

int main() {
    string message;
    string polynomial;

    cin >> message >> polynomial;

    message[0] = (message[0]-'0') ? '0' : '1';

    cout << message << endl << polynomial << endl;

    return 0;
}