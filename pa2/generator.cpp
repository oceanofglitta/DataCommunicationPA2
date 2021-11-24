#include<iostream>
#include<cstring>

using namespace std;


int main() {
    int i, j;
    string message;
    string polynomial;
    string remain = "";

    cin >> message >> polynomial;

    int n = message.length();
    int k = polynomial.length();

    for(i=0; i<k-1; i++) message += '0';

    for(i=0; i<k; i++) remain += message[i];
	

    for(i=k; i<=n+k-1; i++) {
        if(remain[0] == '1') {
            for(j=0; j<k; j++)  remain[j] = (remain[j] == polynomial[j]) ? '0' : '1';
        }
        if(i != n+k-1) {
            for(j=0; j<k-1; j++)    remain[j] = remain[j+1];
            remain[j] = message[i];
        }
    }

	for(i=1; i<k; i++) {
		if(remain[i] == '1')
		message[n] = '1';
		else message[n] = '0';
		n++;
	}


    cout << message << endl << polynomial;

    return 0;
}