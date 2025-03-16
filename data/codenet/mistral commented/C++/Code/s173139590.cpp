
#include <iostream>
#include <string>
using namespace std;

// Initialize variables to store the number of each contest result
int n; // number of contest results to be read
int ac_count = 0; // number of AC (Accepted) results
int wa_count = 0; // number of WA (Wrong Answer) results
int tle_count = 0; // number of TLE (Time Limit Exceeded) results
int re_count = 0; // number of RE (Runtime Error) results

int main(){
    // Read the number of contest results from the standard input
    cin >> n;

    // Read each contest result and update the corresponding counter
    for (int i = 0; i < n; ++i){
        string s; // string to store the contest result (AC, WA, TLE, or RE)
        cin >> s;
        if (s=="AC"){ // if the contest result is AC
            ac_count+=1; // increment the number of AC results
        }else if(s=="WA"){ // if the contest result is WA
            wa_count+=1; // increment the number of WA results
        }else if(s=="TLE"){ // if the contest result is TLE
            tle_count+=1; // increment the number of TLE results
        }else if(s=="RE"){ // if the contest result is RE
            re_count+=1; // increment the number of RE results
        }
    }

    // Print the number of each contest result to the standard output
    cout << "AC x " << ac_count << endl;
    cout << "WA x " << wa_count << endl;
    cout << "TLE x " << tle_count << endl;
    cout << "RE x " << re_count << endl;
}