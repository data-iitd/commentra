#include<stdio.h>

def kansu(a,b):
	i=1
	j=1
	x=0
	y=0
	n=0
	suu=[[0 for i in range(17)] for j in range(17)]
	kouji=[[0 for i in range(17)] for j in range(17)]
	while(a!=0 and b!=0):
		n=int(input())
		for i in range(1,a+1):
			for j in range(1,b+1):
				kouji[i][j]=0
		for i in range(0,n):
			x,y=map(int,input().split())
			kouji[x][y]=1
		for i in range(1,a+1):
			for j in range(1,b+1):
				if(kouji[i][j]==1):
					suu[i][j]=0
				else:
					if(i==1 and j==1):
						suu[i][j]=1
					else:
						if(i==1):
							suu[i][j]=suu[i][j-1]
						else:
							if(j==1):
								suu[i][j]=suu[i-1][j]
							else:
								suu[i][j]=suu[i][j-1]+suu[i-1][j]
		print(suu[a][b])
		a,b=map(int,input().split())

kansu(int(input()),int(input()))

