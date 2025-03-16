
#include <iostream>
#include <cstring>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <queue>
#include <list>
#include <numeric>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <stack>
#include <climits>
#include <bitset>
#include <utility>


using namespace std;
typedef long long ll;

#最小公倍数
def gcd(x,y):
  tmp = 0
  if x<y:
    tmp=x
    x=y
    y=tmp
  while y>0:
    r = x%y
    x = y
    y = r
  return x

#最大公倍数
def lcm(x,y):
  return x/gcd(x,y)*y

#階乗
def kaijo(k):
    sum = 1
    for i in range(1,k+1):
        sum *= i
        sum%=1000000000+7
    return sum

#for(int i = ; i < ; i++){}

def lmax(s,t):
  if s>t:
    return s
  else:
    return t

def lmin(s,t):
  if s<t:
    return s
  else:
    return t

# ここから開始

n,k = map(int,input().split())
sum = 0
for b in range(1,n+1):
  cnt = (n+1)//b
  md = (n+1)%b
  sum+=cnt*max((b-k),0)+max((md-k),0)
  if k==0: sum-=1
print(sum)

