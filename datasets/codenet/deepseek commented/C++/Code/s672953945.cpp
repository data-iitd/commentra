//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>

/*
#include<boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/rational.hpp>
namespace mp = boost::multiprecision;
using Real = mp::number<mp::cpp_dec_float<1024>>;
using Bint = mp::cpp_int;
*/

using namespace std;

#define int long long
#define REP(i,s,e) for((i)=(s);(i)<(e);(i)++)
#define RREP(i,s,e) for((i)=((s)-1);(i)>=(e);(i)--)
#define FOR(i,n) for((i)=(0);(i)<(n);(i)++)
#define RFOR(i,n) for((i)=((n)-1);(i)>=(0);(i)--)
#define MOD 1000000007

// Main function to execute the program
signed main(){

    // Vector to store strings and variables to store N and L
    vector<string> v;
    int N,L;

    // Read the number of strings N and the length L from the standard input
    cin>>N>>L;

    // Read N strings from the standard input and store them in the vector v
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }

    // Sort the vector v in lexicographical order
    sort(v.begin(),v.end());

    // Concatenate and print the sorted strings without spaces
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
    cout<<endl;
}
