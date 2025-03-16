n=int(input())
data=[input().split() for i in range(n)]
data.sort(key=lambda x:(x[1],x[0]))
for i in range(n):
	print(data[i][2])
#