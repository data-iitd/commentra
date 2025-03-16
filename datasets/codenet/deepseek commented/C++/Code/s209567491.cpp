#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <set>
using namespace std;
typedef long long ll;

/*
1. Include necessary headers: The code starts by including several headers, including standard libraries for input/output operations, string manipulation, mathematical operations, and container classes.
*/

int main(int argc, char *args[]) {
    /*
    2. Main function: The main function is defined to execute the program. It initializes variables and processes input to compute the number of chocolates needed.
    */
    int N, D, X;
    int num_of_chocolate;
    int counter;
    int days;
    int A[101];
    
    /*
    3. Input reading: The program reads three integers N, D, and X from the standard input.
    */
    cin >> N >> D >> X;
    
    /*
    4. Array initialization: An array A of size 101 is declared to store the values of A[i] for each i from 0 to N-1.
    */
    
    /*
    5. Reading values into array A: The program reads N values into the array A.
    */
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    /*
    6. Calculating the number of chocolates: The program calculates the number of chocolates needed by iterating through each value in A and counting how many days it takes to consume all chocolates for each A[i].
    */
    num_of_chocolate = 0;
    for (int i = 0; i < N; i++) {
        days = 0;
        counter = 0;
        for (int j = 0;; j++) {
            days = j * A[i] + 1;
            if (days <= D) {
                counter++;
            }
            else {
                break;
            }
        }
        num_of_chocolate = num_of_chocolate + counter;
    }
    
    /*
    7. Adding extra chocolates: The program adds the number of extra chocolates X to the total number of chocolates calculated.
    */
    num_of_chocolate = num_of_chocolate + X;
    
    /*
    8. Output the result: Finally, the program prints the total number of chocolates to the standard output.
    */
    cout << num_of_chocolate << endl;
}
