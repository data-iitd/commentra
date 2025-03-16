
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi być znany rozmiar wektora - nie można go zmienić
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vl vector<LL>
#define vii vector<vi>
#define vll vector<vl>

const double pi = 3.14159265358979323846264;
const int mod=1000000007;

// Main function starts here
int main(){
    // Initialize variables for number of students and classes
    int n,m;

    // Read input from the standard input stream
    cin>>n>>m;

    // Initialize vectors 's' and 'c' for storing student numbers and classes respectively
    vi s(m),c(m);

    // Read student numbers and classes from the standard input stream
    FOR(i,0,m){
        cin>>s[i]>>c[i];
        // Decrement student numbers by 1 as they are 1-indexed
        s[i]--;
    }

    // Check all strings of length 'n' for a valid combination of student numbers and classes
    FOR(i,0,1000){
        // Convert the current number to a string
        string st=to_string(i);

        // Check if the length of the string is equal to 'n'
        if(st.length()!=n){
            continue;
        }

        // Initialize a flag 'f' to check if the current combination is valid
        int f=1;

        // Check each combination of student number and class
        FOR(j,0,m){
            // Check if the current character in the string matches the expected class
            if(st[s[j]]==c[j]+'0'){
                // If yes, continue to the next check
            }else{
                // If no, set the flag 'f' to 0 and break the loop
                f=0;
                break;
            }
        }

        // If all checks passed, print the current number and exit the program
        if(f){
            cout<<i<<endl;
            return 0;
        }

    }

    // If no valid combination was found, print -1
    cout<<-1<<endl;
}

