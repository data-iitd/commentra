#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <iomanip>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cctype>
#include <climits>
#include <cfloat>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a=0,b=0,c=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a+=x;
    }
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        b+=x;
    }
    for(int i=0;i<n-2;i++){
        int x;
        cin>>x;
        c+=x;
    }
    cout<<a-b<<endl;
    cout<<b-c<<endl;
    return 0;
}

