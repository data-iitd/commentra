a=[0,0,0]
b=[0,0,0]
c=[[0,0,0],[0,0,0],[0,0,0]]
for i in range(3):
    c[i][0],c[i][1],c[i][2]=map(int,input().split())
for i in range(3):
    b[i]=c[0][i]
for i in range(1,3):
    a[i]=c[i][0]-b[0]
for i in range(3):
    for j in range(3):
        if c[i][j]!=a[i]+b[j]:
            print("No")
            break
    else:
        continue
    break
else:
    print("Yes")

