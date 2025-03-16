
# Enter your code here. Read input from STDIN. Print output to STDOUT

N = int(raw_input())
X = map(int, raw_input().split())
Y = sorted(X)
y = Y[N/2]
for i in X:
    if i < y:
        print y
    else:
        print Y[N/2-1]

