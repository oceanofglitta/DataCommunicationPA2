#include<iostream>

using namespace std;

int main() {
    string message;
    string polynomial;

    cin >> message >> polynomial;   // message와 polynomial을 입력받는다.

    message[0] = (message[0]-'0') ? '0' : '1';  // message의 첫 번째 자리를 뒤집는다. 

    cout << message << endl << polynomial << endl;  // 결과를 출력한다.

    return 0;
}