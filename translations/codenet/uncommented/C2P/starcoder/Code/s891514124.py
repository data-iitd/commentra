
S = int(input())

if S < 60:
    print("0:0:%d" % S)

elif S < 3600:
    print("0:%d:%d" % (S//60, S%60))

else:
    print("%d:%d:%d" % (S//3600, (S%3600)//60, (S%60)%60))

#