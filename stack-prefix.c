#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100

char stack[STACK_SIZE], str[STACK_SIZE];
int top=-1;

void push(char x);
char pop();
int isFull();
int isEmpty();


int main(){
	scanf("%s", str);
	
	int i;
	for(i=0; i<strlen(str); i++){
		char ch = str[i];
		if(isdigit(ch)){
			printf("%c", str[i]);
		}else if(ch == '('){
			push('(');
		}else if(ch == ')'){
			char temp;
			while((temp = pop()) != "("){
				printf("%c", temp);
			}
		}else{
			while(){
				
			}
		} 
	}
	
	return 0;
}

int precedence(char a, char b){
	int aHigh = 0, bHigh = 0;
	if(a == '*' || a == '/'){
		aHigh = 1;
	}
	if(b == '*' || b == '/'){
		bHigh = 1;
	}
	
	if(a == b){
		return 0;
	}else if(a > b){
		return 1;
	}else if(b > a){
		return 2;
	}else{
		return 0;
	}
}

void push(char x){
	if(isFull()){
		printf("스택 오버플로우");
	}else{
		top++;
		stack[top] = x;
	} 
}

char pop(){
	if(isEmpty()){
		printf("스택 언더플로우");
	}else{
		return stack[top--];
	}
}

int isFull(){
	if(top > STACK_SIZE) return 1;
	else return 0;
}

int isEmpty(){
	if(top < 0) return 1;
	else return 0;
}
