n=int(input())
while n:
    s=input()
    while "Hoshino" in s:
        s=s.replace("Hoshino","Hoshina")
    print(s)
    n-=1
#