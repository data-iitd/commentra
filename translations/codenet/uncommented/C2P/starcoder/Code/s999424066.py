a,b,c,x,y=map(int,input().split())
c*=2
if a+b<=c:
    print(a*x+b*y)
else:
    if x<=y:
        if b<=c:
            print(c*x+(y-x)*b)
        else:
            print(c*y)
    else:
        if a<=c:
            print(c*y+(x-y)*a)
        else:
            print(c*x)
#