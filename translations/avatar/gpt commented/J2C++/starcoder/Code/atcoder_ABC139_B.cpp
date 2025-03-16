#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <climits>
#include <cfloat>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <typeinfo>
#include <bitset>
#include <climits>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <typeinfo>
#include <bitset>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int result = (b-1)/(a-1);
    int amari = (b-1)%(a-1);
    if(amari!=0)
        result+=1;
    cout<<result<<endl;
    return 0;
}

