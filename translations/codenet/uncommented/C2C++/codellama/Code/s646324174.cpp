#include<iostream>
#include<cstdlib>
 
using namespace std;
 
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
   
  while(cin>>s){
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
  cout<<pop()<<endl;
  return 0;
}
