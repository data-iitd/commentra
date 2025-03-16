
n=int(input())
t=[]
h=[]
for i in range(n):
    t.append(input())
    h.append(input())
taro=0
hanako=0
for i in range(n):
    if t[i]<h[i]:
        taro+=3
    elif t[i]>h[i]:
        hanako+=3
    else:
        taro+=1
        hanako+=1
print(taro,hanako)

