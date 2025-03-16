n=int(input())
while n:
    s=input()
    while "Hoshino" in s:
        s=s.replace("Hoshino","a",1)
    print(s,end="")
    n-=1
print("