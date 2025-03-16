#Lucky_Glass
import sys
MOD=7007
F=[[1,1,0],[1,0,1],[0,1,1],[2,0,0],[0,2,0],[0,0,2]]
class QUEUE:
	def __init__(self):
		self.a=0
		self.b=0
		self.c=0
		self.tot=0
def HASH(n):
	global Hash
	for i in range(len(Hash[n%MOD])):
		if n==Hash[n%MOD][i]:
			return False
	Hash[n%MOD].append(n)
	return True
def main():
	global Push,Hash
	Push=QUEUE()
	sys.stdin.readline()
	Push.a,Push.b,Push.c=map(int,sys.stdin.readline().split())
	que=queue.Queue()
	que.put(Push)
	while not que.empty():
		Fro=que.get()
		if Fro.a==Fro.b and Fro.b==Fro.c:
			print(Fro.tot)
			return 0
		for i in range(6):
			Push=Fro
			Push.tot+=1
			Push.a+=F[i][0]
			Push.b+=F[i][1]
			Push.c+=F[i][2]
			n=Push.a*10000+Push.b*100+Push.c
			if not HASH(n): continue
			que.put(Push)
	return 0
if __name__=="__main__":
	Hash=[[] for i in range(MOD)]
	main()
