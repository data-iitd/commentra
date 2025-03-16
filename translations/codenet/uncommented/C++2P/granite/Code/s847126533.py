
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
    tmp-=book[i]
  return True

while True:
  m,n=map(int,raw_input().split())
  if m==0 and n==0:
    break
  book=[]
  for i in range(n):
    book.append(input())
  l=0
  r=1500000
  ans=0
  while l<r:
    if check(m,(l+r)/2,book):
      ans=(l+r)/2
      if r==(l+r)/2:
        break
      r=(l+r)/2
    else:
      if l==(l+r)/2:
        break
      l=(l+r)/2
  print ans

