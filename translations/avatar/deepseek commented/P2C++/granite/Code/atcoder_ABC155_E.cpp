

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#include <bitset>
#include <stack>
#include <functional>
#include <random>
#include <cassert>
using namespace std;
typedef long long ll;

// Define possible input methods: clipboard, file, key
vector<string> input_methods = {"clipboard", "file", "key"};
// Indicate which input method to use, starting with 'clipboard'
int using_method = 0;
string input_method = input_methods[using_method];

// Define a lambda function to take integer inputs in space-separated format
auto IN = [](){
    string s;
    getline(cin, s);
    stringstream ss(s);
    int x;
    vector<int> v;
    while(ss >> x){
        v.push_back(x);
    }
    return v;
}();

// Define a modulo value
const ll mod = 1000000007;

// Main function for base case
void main_b(){
    // Take input string
    string s;
    cin >> s;
    // Initialize pp and na to 0
    ll pp = 0;
    ll na = 0;
    // Iterate over the string in reverse order
    for(int i = s.size() - 1; i >= 0; i--){
        ll cc = na + (s[i] - '0');
        na = 0;
        // If the sum is less than or equal to 4, add to pp
        if(cc <= 4){
            pp += cc;
        }else{
            na = 1;
            // If it's the last digit, add 1 to pp
            if(i == 0){
                pp += 1;
            }
            pp += 10 - cc;
        }
    }
    // Print the result
    cout << pp << endl;
}

// Main function for general case
ll main(){
    string s;
    cin >> s;
    ll pmin = 1000;
    ll mmin = 0;
    s = '0' + s;
    // Iterate over the string in reverse order
    for(char c : s){
        ll v = c - '0';
        ll npmin = min(pmin + 10 - (v + 1), mmin + 10 - v);
        ll nmmin = min(pmin + v + 1, mmin + v);
        pmin = npmin;
        mmin = nmmin;
    }
    // Return the minimum of pmin and mmin
    return min(pmin, mmin);
}

// Check if the script is running in test mode
bool isTest = false;
// Function to print values if in test mode
void pa(ll v){
    if(isTest){
        cout << v << endl;
    }
}

// Function to read input from clipboard if running on iOS
vector<string> input_clipboard(){
    vector<string> v;
    string s;
    while(getline(cin, s)){
        v.push_back(s);
    }
    return v;
}

// Main execution block
int main(){
    if(input_method == input_methods[0]){
        auto ic = input_clipboard();
        input = [&ic](){ return ic.back(); };
        ic.pop_back();
    }else if(input_method == input_methods[1]){
        freopen("inputFile.txt", "r", stdin);
    }else{
        // Do nothing
    }
    isTest = true;
    ll ret = main();
    if(ret!= -1){
        cout << ret << endl;
    }
    return 0;
}

