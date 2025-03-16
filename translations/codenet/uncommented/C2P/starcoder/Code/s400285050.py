
def you(x,y):
    while(1):
        z=x%y
        x=y
        y=z
        if(y<=0):
            break
    return x

x,y=map(int,input().split())
if(x>=y):
    print(you(x,y))
else:
    print(you(y,x))

