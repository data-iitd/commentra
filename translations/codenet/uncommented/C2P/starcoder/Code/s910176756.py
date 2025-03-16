a,b,c=0,0,0
while True:
    a,op,b=map(int,input().split())
    if op=='+':
        c=a+b
    elif op=='-':
        c=a-b
    elif op=='*':
        c=a*b
    elif op=='/':
        c=a/b
    else:
        break
    print(c)
#