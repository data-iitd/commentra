
#include<iostream>
#include<cstdlib>
 
int top,S[10000];
 
void push(int x){
  S[++top]=x;
}
 
int pop(){
 return S[top--];
}
 
int main(){
  int a,b;
  char s[200];
  top=0;
   
  while(std::cin>>s){
    if(s[0]=='+'){
      b=pop();
      a=pop();
      push(a+b);
    }else if(s[0]=='-'){
      b=pop();
      a=pop();
      push(a-b);
    }else if(s[0]=='*'){
      b=pop();
      a=pop();
      push(a*b);
    }else{
      push(atoi(s));
    }
  }
  std::cout<<pop()<<std::endl;
  return 0;
}
