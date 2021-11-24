#include<iostream>
#include<cstring>

using namespace std;

int main() {
    int i, j;

    string message;
    string polynomial;
    string remain;

    int n, k;

    cin >> message >> polynomial;

    n = message.length();
    k = polynomial.length();

    for(i=0; i<k; i++) remain += message[i];

    for(i=k; i<=n; i++) {
        if(remain[0] == '1') {
            for(j=0; j<k; j++)  remain[j] = (remain[j] == polynomial[j]) ? '0' : '1';
        }
        if(i != n) {
            for(j=0; j<k-1; j++)    remain[j] = remain[j+1];
            remain[j] = message[i];
        }
    }

    if(remain.find("1") == string::npos) cout << "Message is correct" << endl;
    else cout << "Error(message is incorrect)" << endl;

    return 0;
}
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//문자열 XOR연산, 결과는 a문자열에 적용된다.
void strXOR(char* a, char* b, int size) {
	//size만 큼 a[i], b[i]이 다르면 '1'을 아니면 '0'을 저장한다.
	for (int i = 0; i < size; i++) {
		a[i] = a[i] == b[i] ? '0' : '1';
	}
}

//나머지를 구하는 함수
//입력: message, polynomial, n, k, result(출력에 해당하는 문자열)
void getRemainder(char* message, char* polynomial, int n, int k, char* result) {
	int i;
	//message의 k길이 만큼 result에 저장한다.
	for (i = 0; i < k; i++) {
		result[i] = message[i];
	}
	result[i] = '\0';
	//message의 k번째 문자부터 문자열 끝까지 (message[n]='\0'인 상태)
	for (i = k; i <= n; i++) {
		//현재 나머지의 첫 문자가 1인경우 -> 몫이 1이기 때문에 XOR연산을 진행
		if (result[0] == '1') {
			strXOR(result, polynomial, k);
		}
		//message의 다음위치에 해당하는 문자를 result에 추가한 후 result의 가장 앞에 있는 문자를 지운다.
		if (i != n) {
			int j;
			for (j = 0; j < k - 1; j++) {
				result[j] = result[j + 1];
			}
			result[j] = message[i];
		}
	}
	result[i] = '\0';
}

int main() {
	//message: 프레임에 해당하는 문자열, polynomial: 다항식에 해당하는 문자열, remainder: 나머지에 해당하는 문자열
	char message[50];
	char polynomial[50];
	char remainder[50];
	//프레임과 다항식을 입력받는다.
	scanf("%s", message);
	scanf("%s", polynomial);
	//프레임의 길이(n), 다항식의 길이(k)
	int n = strlen(message), k = strlen(polynomial), i, flag = 0;

	//verifier에서 받은 프레임은 generator에서 확장된 프레임이다.

	//나머지를 구한다. n은 이미 확장된 message의 길이이므로 n을 넘긴다.
	getRemainder(message, polynomial, n, k, remainder);

	//remainder에 '1'이 있으면 flag를 ON하고 반복문 탈출
	//i가 1부터인 이유는 getRemainder의 반환문자열 길이는 k-1이어야 하는데 k이기 때문에 제일 앞은 생략한다.
	//제일 앞은 연산상 무조건 '0'이기 때문에 생략가능하다.
	for (i = 1; i < k; i++) {
		if (remainder[i] == '1') {
			flag = 1;
			break;
		}
	}
	//remainder의 모든 문자가 '0'이면 correct
	if (flag == 0) {
		printf("correct message");
	}
	//remainder의 모든 문자가 '0'이 아니면 incorrect
	else {
		printf("incorrect message");
	}
	return 0;
}*/