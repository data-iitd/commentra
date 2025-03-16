
def linearsearch(S, n, key):
  i = 0
  count = 0
  while( S[i]!= key ):
    i = i + 1
    if( i >= n  ):
      count = 1
      return count
  return count

n = int(input())
S = [int(x) for x in input().split()]
q = int(input())
T = [int(x) for x in input().split()]

count = 0
for j in range(q):
  key = T[j]
  if(linearsearch(S, n, key) == 0):
    count = count + 1

print(count)

