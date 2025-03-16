
#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;

int main(){
    int a, t = 0, h = 0, lt, lh, tt, hh, l; // Initialize variables

    cin >> a; // Read number of strings from user

    for(int i = 0; i < a; ++i){ // Loop through each string pair
        cin >> taro >> hana; // Read two strings from user
        lt = taro.length(); // Get length of first string
        lh = hana.length(); // Get length of second string

        if(lt > lh){ // Check if first string is longer
            l = lt; // Set length to be the maximum length
        }
        else{
            l = lh; // Set length to be the minimum length
        }

        tt = 0; // Initialize variables for comparing characters
        hh = 0;

        if(taro > hana){ // Check if first string is greater lexicographically
            t = t + 3; // Increment t if true
        }
        else if(hana > taro){
            h = h + 3; // Increment h if true
        }
        else if(hana == taro){ // Check if strings are equal
            h = h + 1; // Increment h if true
            t = t + 1; // Increment t if true
        }
    }

    cout<<t<<" "<<h<<endl; // Output the result

    return 0;
}

