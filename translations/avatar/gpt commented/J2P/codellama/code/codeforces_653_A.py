import sys 

n = int(input()) 
a = list(map(int, input().split())) 

a = list(set(a)) 
a.sort() 

found = False 
for i in range(len(a)): 
    if i + 2 < len(a): 
        if a[i] + 1 == a[i + 1] and a[i + 1] + 1 == a[i + 2]: 
            found = True 

print("YES" if found else "NO") 

