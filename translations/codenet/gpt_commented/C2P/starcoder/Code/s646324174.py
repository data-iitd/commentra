#include<stdio.h>
#include<stdlib.h>

#define MAX 10000

int stack[MAX];
int top = -1;

void push(int x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

int main(){
    int a, b;
    char s[200];
    while(scanf("%s", s)!= EOF){
        if(s[0] == '+'){
            b = pop();
            a = pop();
            push(a + b);
        }
        else if(s[0] == '-'){
            b = pop();
            a = pop();
            push(a - b);
        }
        else if(s[0] == '*'){
            b = pop();
            a = pop();
            push(a * b);
        }
        else{
            push(atoi(s));
        }
    }
    printf("%d\n", pop());
    return 0;
}

