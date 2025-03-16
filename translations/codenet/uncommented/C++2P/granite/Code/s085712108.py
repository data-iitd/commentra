
#Lucky_Glass
import sys
sys.setrecursionlimit(100000)
def HASH(n):
	for i in range(len(Hash[n%MOD])):
		if n==Hash[n%MOD][i]:
			return False
	Hash[n%MOD].append(n)
	return True
def BFS():
	que=[[Push.a,Push.b,Push.c,Push.tot]]
	while que:
		Fro=que.pop(0)
		if Fro[0]==Fro[1] and Fro[1]==Fro[2]:
			print(Fro[3])
			sys.exit(0)
		for i in range(6):
			Push=Fro[:]
			Push[3]+=1
			Push[0]+=F[i][0]
			Push[1]+=F[i][1]
			Push[2]+=F[i][2]
			n=Push[0]*10000+Push[1]*100+Push[2]
			if HASH(n): que.append(Push)
F=[[1,1,0],[1,0,1],[0,1,1],[2,0,0],[0,2,0],[0,0,2]]
MOD=7007
Hash=[[] for i in range(MOD)]
Push=[int(i) for i in input().split()]
Push+=[0]
BFS()

Translate the above Python code to Java and end with comment "