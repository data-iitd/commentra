#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
def check(n,wei,book):
  tmp=wei
  n-=1
  for i in range(len(book)):
    if tmp<book[i]:
      if n>0:
	n-=1
	tmp=wei
	if tmp<book[i]:
	  return False
      else:
	return False
      #  cout<<n<<" "<<tmp<<" "<<book[i]<<endl; 
      tmp-=book[i]
  return True
if __name__=="__main__":
  m,n=map(int,input().split())
  for i in range(m):
    book=[]
    for j in range(n):
      tmp=int(input())
      book.append(tmp)
    #while True:
    #  tmp=int(input())
    #  if check(m,tmp,book):
    #      print("YES")
    #  else:
    #      print("NO")
    #  break
    l=0
    r=1500000
    ans=0
    while l<r:
      #  cout<<l<<" "<<r<<endl;
      # cout<<(l+r)/2<<endl;
      if check(m,(l+r)/2,book):
	ans=(l+r)/2
	if r==(l+r)/2:
	  break
	r=(l+r)/2
      else:
	if l==(l+r)/2:
	  break
	l=(l+r)/2
    print(ans)
#