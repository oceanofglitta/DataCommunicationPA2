#include<iostream>
#include<cstring>

using namespace std;


int main() {
    int i, j;
    string message;
    string polynomial;
    string remain = "";

    cin >> message >> polynomial;   // message와 polynomial을 입력받는다.

    int n = message.length();   // message의 길이
    int k = polynomial.length();    // polynomial의 길이

    for(i=0; i<k-1; i++) message += '0';    // message의 뒤에 polynomial의 최고차항만큼 0을 붙인다.

    for(i=0; i<k; i++) remain += message[i];    // 나머지를 구하기 위해 message를 k 까지 remain에 넣는다.
	

    for(i=k; i<=n+k-1; i++) {   // 나머지를 구한다.
        if(remain[0] == '1') {  // 나머지의 첫번째 값이 1일때
            for(j=0; j<k; j++)  remain[j] = (remain[j] == polynomial[j]) ? '0' : '1';   // xor 연산을 한다.
        }
        if(i != n+k-1) {    // i가 끝까지 가지 않았다면
            for(j=0; j<k-1; j++)    remain[j] = remain[j+1];    // remain을 한 칸씩 앞으로 당기고
            remain[j] = message[i]; // message의 다음 문자를 remain의 마지막에 넣는다.
        }
    }

	for(i=1; i<k; i++) {    // 나머지를 message에 붙인다.
		message[n] = remain[i];
		n++;
	}

    cout << message << endl << polynomial;  // message와 polynomial을 출력한다.

    return 0;
}