#define LEN 300
#define TRUE 1
#define FALSE -1

def solve(i, m):
  if i>n:return FALSE
  elif m<0:return FALSE
  elif m==0 or m-A[i+1]==0:
    flag=TRUE
    return TRUE
  else:
    #not use A[i]
    solve(i+1, m)
    #use A[i]
    solve(i+1, m-A[i])

n=int(raw_input())
A=[0]*LEN
for i in range(n):A[i]=int(raw_input())
q=int(raw_input())
for i in range(q):
  M=int(raw_input())
  flag=FALSE
  solve(-1, M)
  if flag==TRUE:print "yes"
  else:print "no"

