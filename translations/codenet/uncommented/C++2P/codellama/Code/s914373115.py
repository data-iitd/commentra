#include <iostream>
#include <vector>
using namespace std;
void A(void);
void B(void);
void C(void);
void D(void);

int main(void){
    B();
}

def B():
    x = int(input())
    sum = 100
    i = 0
    while sum < x:
        sum += sum / 100
        i += 1
    print(i)

