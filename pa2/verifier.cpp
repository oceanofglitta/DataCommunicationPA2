#include<iostream>
#include<cstring>

using namespace std;

int main() {
    int i, j;

    string message;
    string polynomial;
    string remain;

    int n, k;

    cin >> message >> polynomial;	// message와 polynomial을 입력받는다.

    n = message.length();	// message의 길이
    k = polynomial.length();	// polynomial의 길이

	// generator를 통해 산출된 message가 입력되기 때문에 generator에서 했던 message에 0을 붙이는 것을 하지 않는다.

    for(i=0; i<k; i++) remain += message[i];	// k만큼의 message를 remain에 넣는다.

    for(i=k; i<=n; i++) {	// 나머지를 구한다.
        if(remain[0] == '1') {	// remain의 첫번째 값이 1일 때
            for(j=0; j<k; j++)  remain[j] = (remain[j] == polynomial[j]) ? '0' : '1';	// xor 연산을 한다.
        }
        if(i != n) {	// n까지 오지 않았을 때
            for(j=0; j<k-1; j++)    remain[j] = remain[j+1];	// 나머지를 한 칸씩 앞으로 옮기고
            remain[j] = message[i];	// 나머지의 마지막 칸에 message의 다음 값을 넣는다.
        }
    }

    if(remain.find("1") == string::npos) cout << "Message is correct" << endl;	// 나머지에서 1을 발견하지 못하면 옳고
    else cout << "Error(message is incorrect)" << endl;	// 하나라도 발견된다면 에러가 발생한다.

    return 0;
}