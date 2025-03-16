# Define a struct QUEUE to store the current state and the total number of steps taken
class QUEUE:
	def __init__(self,a,b,c,tot):
		self.a=a; self.b=b; self.c=c; self.tot=tot;

# Initialize an empty hash table to store visited states
Hash=[[] for i in range(MOD)]

# Function to check if a state is already in the hash table
def HASH(n):
	for i in range(len(Hash[n%MOD])):
		if(n==Hash[n%MOD][i]):
			return False
	Hash[n%MOD].append(n)
	return True

# Function to find the solution
def main():
	# Initialize some variables and read input data
	Push=QUEUE(0,0,0,0)
	que=queue.Queue()
	a,b,c=map(int,input().split())
	Push.a=a; Push.b=b; Push.c=c
	que.put(Push)

	# Main loop to find the solution
	while(not que.empty()):
		Fro=que.get() # Dequeue the front element from the queue

		# Check if the current state is the goal state
		if(Fro.a==Fro.b and Fro.b==Fro.c):
			print(Fro.tot) # Print the total number of steps taken and exit the program
			return 0

		# Try all six possible moves and check if the resulting state is already in the hash table
		for i in range(6):
			Push=Fro # Copy the current state into a new variable Push
			Push.tot+=1 # Increment the total number of steps taken
			Push.a+=F[i][0]; Push.b+=F[i][1]; Push.c+=F[i][2] # Apply the move to the new state
			n=Push.a*10000+Push.b*100+Push.c # Calculate the hash code of the new state
			if(not HASH(n)): continue # If the new state is already in the hash table, skip it
			que.put(Push) # Otherwise, push it into the queue and continue the search

		# Dequeue the front element from the queue to continue the search
		que.get()

	# Return 0 to indicate that the program has finished running
	return 0

