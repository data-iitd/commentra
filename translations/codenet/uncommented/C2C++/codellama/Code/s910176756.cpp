#include<iostream>
using namespace std;
int main(){
int a, b, c;
char op;
cin >> a >> op >> b;
while( 1 ){
if ( op == '+' ){
c = a + b;
cout << c << endl;
} 
else if ( op == '-' ){
c = a - b;
cout << c << endl;
} 
else if ( op == '*' ){
c = a * b;
cout << c << endl;
} 
else if ( op == '/' ){
c = a / b;
cout << c << endl;
} 
else {
break;
}
cin >> a >> op >> b;
}
return 0;
}
