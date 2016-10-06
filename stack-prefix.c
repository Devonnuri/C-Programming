#include <stdio.h>
#include <string.h>
#define STACK_SIZE 100
#define CALC_SIZE 100

char stack[STACK_SIZE];
char calc[CALC_SIZE]; 
int top=-1;

void push(char x);
void writeCalc(char ch);
char pop();
int isFull();
int isEmpty();
int getPrecedence(char oper);

int main(){
	int i;
	char str[100];
	scanf("%s", str);
	
	/*
	 * 후위표기식 변환
	 */
	for(i=0; i<strlen(str); i++){ //문자를 받아서
		char ch = str[i];
		switch(ch){
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0': writeCalc(ch); break; //만약 피연산자라면 출력 
			case '(': push(ch); break; //여는 괄호라면 push 
			case ')':
				while(stack[top] != '('){ // "("가 아닐때까지 스택에서 pop 
					writeCalc(pop());
				}
				pop(); //마지막 "(" 까지 pop 
				break;
			default:
				while(getPrecedence(stack[top]) > getPrecedence(ch)){ //만약 스택의 top의 우선순위가 문자의 우선순위보다 작을때 까지 계속 
					writeCalc(pop()); //스택에서 pop 
				}
				push(ch); //문자를 push 
				break;
		}
	}
	
	while(!isEmpty()){
		writeCalc(pop()); //스택에 있는 모든 문자를 pop 
	}
	
	
	/*
	 * 후위표기식 계산 
	 */
	
	
	
	return 0;
}

int getPrecedence(char oper){ //우선순위 얻기 
	switch(oper){
		case '(': return 0; //여는 괄호라면 0 
		case '+':
		case '-': return 1; //+,- 라면 1 
		case '*':
		case '/': return 2; //*,/ 라면 2
		default: return -1; //다 아니라면 -1 
	}
}

void writeCalc(char ch){
	int i;
	for(i=0; i<CALC_SIZE; i++){
		if(calc[i] == '\0'){
			calc[i] = ch;
			break;
		}else{
			continue;
		}
	}
}

void push(char x){
	if(isFull()){ //스택이 차있다면 
		printf("스택 오버플로우"); //오버플로우 발생
	}else{
		stack[++top] = x; //top변수를 1올리고 스택에 지정
	} 
}

char pop(){
	if(isEmpty()){ //스택이 비었다면 
		printf("스택 언더플로우"); //언더플로우 발생
	}else{
		return stack[top--]; //top변수를 1내린다.
	}
}

int isFull(){
	if(top >= STACK_SIZE){ //만약 top이 스택의 크기에 벗어난다면 
		return 1; //참 반환 
	}
	return 0; //아니라면 거짓 반환
}

int isEmpty(){
	if(top < 0){ //만약 top이 스택의 크기에 벗어난다면
		return 1; //참 반환 
	}
	return 0; //아니라면 거짓 반환 
}
