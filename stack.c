#include <stdio.h>
#include <string.h>
#define STACK_SIZE 100

char stack[STACK_SIZE], top=-1;

void push(char x);
char pop();

int main(){
	return 0;
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

bool isFull(){
	if(top > MAX_SIZE) return true;
	else return false;
}

bool isEmpty(){
	if(top < 0) return true;
	else return false;
}
