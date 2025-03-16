#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;

int main(){
    // Initialize variables
    int a, t = 0, h = 0, lt, lh, tt, hh, l;
    cin >> a;
    string taro, hana;

    // Loop through the number of games
    for(int i = 0; i < a; ++i){
        // Read the names of Taro and Hana
        cin >> taro >> hana;
        
        // Get the lengths of the names
        lt = taro.length();
        lh = hana.length();
        
        // Determine the maximum length of the names
        if(lt > lh){
            l = lt;
        }
        else{
            l = lh;
        }
        
        // Initialize score counters for this round
        tt = 0;
        hh = 0;

        // Compare the names and update the scores
        if(taro > hana){
            t = t + 3;
        }
        else if(hana > taro){
            h = h + 3;
        }
        else if(hana == taro){
            h = h + 1;
            t = t + 1;
        }
    }
    
    // Output the final scores
    cout << t << " " << h << endl;

    return 0;
}