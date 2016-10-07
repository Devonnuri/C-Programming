#include <stdio.h>
#include <string.h>
#define STACK_SIZE 100
#define CALC_SIZE 100

char stack[STACK_SIZE];
char calc[CALC_SIZE];
int top = -1;

void push(char x);
void writeCalc(char ch);
char pop();
int isFull();
int isEmpty();
int getPrecedence(char oper);

void printStack() {
	int i;
	printf("[");
	for (i = 0; i <= top; i++) {
		printf("%c,", stack[i]);
	}
	printf("]\n");
}

int main() {
	int i;
	char str[100];
	gets(str);

	/*
	* 후위표기식 변환
	*/
	for (i = 0; i < strlen(str); i++) { //문자를 받아서
		char ch = str[i];
		if (ch >= '0' && ch <= '9') {
			writeCalc(ch);
		} else if (ch == '(') {
			push(ch);
		} else if (ch == ')') {
			while (stack[top] != '(') { // "("가 아닐때까지 스택에서 pop 
				writeCalc(pop());
			}
			pop(); //마지막 "(" 까지 pop 
		} else {
			while (getPrecedence(stack[top]) > getPrecedence(ch)) { //만약 스택의 top의 우선순위가 문자의 우선순위보다 작을때 까지 계속 
				writeCalc(pop()); //스택에서 pop 
			}
			push(ch); //문자를 push 
		}
	}

	while (!isEmpty()) {
		writeCalc(pop()); //스택에 있는 모든 문자를 pop 
	}


	/*
	* 후위표기식 계산
	*/

	//printf("%s\n", calc);
	
	for (i = 0; i<strlen(calc); i++) { //문자를 받아서
		char ch = calc[i];
		if (ch >= '0' && ch <= '9') { //만약 피연산자라면
			push(ch-48); //스택에 push
		} else { //만약 연산자라면
			int b = pop(); //후자를 스택에서 pop해서 가져옴 
			int a = pop(); //전자를 스택에서 pop해서 가져옴
			if (ch == '+') push(a + b); //만약 연산자가 더하기면 전자와 후자를 더해서 push 
			else if (ch == '-') push(a - b); //만약 연산자가 빼기면 전자와 후자를 빼서 push
			else if (ch == '*') push(a * b); //만약 연산자가 곱하기면 전자와 후자를 곱해서 push
			else if (ch == '/') push(a / b); //만약 연산자가 나누기면 전자와 후자를 나누어서 push
		}
	}

	printf("%d", pop());

	return 0;
}

int getPrecedence(char oper) { //우선순위 얻기 
	switch (oper) {
	case '(': return 0; //여는 괄호라면 0 
	case '+':
	case '-': return 1; //+,- 라면 1 
	case '*':
	case '/': return 2; //*,/ 라면 2
	default: return -1; //다 아니라면 -1 
	}
}

void writeCalc(char ch) {
	int i;
	for (i = 0; i<CALC_SIZE; i++) {
		if (calc[i] == '\0') {
			calc[i] = ch;
			break;
		}
		else {
			continue;
		}
	}
}

void push(char x) {
	if (isFull()) { //스택이 차있다면 
		printf("스택 오버플로우"); //오버플로우 발생
	}
	else {
		stack[++top] = x; //top변수를 1올리고 스택에 지정
	}
}

char pop() {
	if (isEmpty()) { //스택이 비었다면 
		printf("스택 언더플로우"); //언더플로우 발생
	}
	else {
		return stack[top--]; //top변수를 1내린다.
	}
}

int isFull() {
	if (top >= STACK_SIZE) { //만약 top이 스택의 크기에 벗어난다면 
		return 1; //참 반환 
	}
	return 0; //아니라면 거짓 반환
}

int isEmpty() {
	if (top < 0) { //만약 top이 스택의 크기에 벗어난다면
		return 1; //참 반환 
	}
	return 0; //아니라면 거짓 반환 
}
