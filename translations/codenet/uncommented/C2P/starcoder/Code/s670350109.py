
str1=input()
str2=input()
if(len(str1)!=len(str2)):
    print("NO")
else:
    temp=str1[::-1]
    t=0
    for i in range(len(str2)):
        if(temp[i]==str2[i]):
            t+=1
    if(t==len(str2)):
        print("YES")
    else:
        print("NO")

