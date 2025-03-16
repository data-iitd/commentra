#Lucky_Glass
#Include the standard input/output library for input/output operations.
#Include the C string library for string manipulation.
#Include the standard algorithm library for algorithmic operations.
#Include the queue library for queue operations.
#Include the vector library for dynamic array operations.
from __future__ import print_function
import sys

#Define a structure QUEUE to store the values of a, b, c, and the total number of operations.
class QUEUE:
	def __init__(self):
		self.a=0
		self.b=0
		self.c=0
		self.tot=0

#Define a transformation matrix F with six possible transformations.
F=[[1,1,0],[1,0,1],[0,1,1],[2,0,0],[0,2,0],[0,0,2]]

#Define a hash table as an array of vectors to store unique states.
Hash=[[] for i in range(7007)]

#Function to check if a state has been visited before.
def HASH(n):
	for i in range(len(Hash[n%7007])): #Iterate through the hash table.
		if(n==Hash[n%7007][i]): #Check if the state is already present.
			return False #Return false if the state is already visited.
	Hash[n%7007].append(n) #Add the state to the hash table.
	return True #Return true if the state is new.

#Main function to execute the program.
def main():
	que=QUEUE() #Create a queue of QUEUE structures.
	que.a,que.b,que.c=map(int,raw_input().split()) #Read the initial values of a, b, and c.
	que.tot=0 #Initialize the total number of operations to 0.
	que.tot+=1 #Increment the total number of operations.
	que.a+=F[0][0];que.b+=F[0][1];que.c+=F[0][2] #Apply the transformation.
	n=que.a*10000+que.b*100+que.c #Create a unique identifier for the state.
	if(HASH(n)): que.tot-=1 #Check if the state has been visited before.
	else: Hash[n%7007].append(n) #Add the state to the hash table.
	que.tot+=1 #Increment the total number of operations.
	que.a+=F[1][0];que.b+=F[1][1];que.c+=F[1][2] #Apply the transformation.
	n=que.a*10000+que.b*100+que.c #Create a unique identifier for the state.
	if(HASH(n)): que.tot-=1 #Check if the state has been visited before.
	else: Hash[n%7007].append(n) #Add the state to the hash table.
	que.tot+=1 #Increment the total number of operations.
	que.a+=F[2][0];que.b+=F[2][1];que.c+=F[2][2] #Apply the transformation.
	n=que.a*10000+que.b*100+que.c #Create a unique identifier for the state.
	if(HASH(n)): que.tot-=1 #Check if the state has been visited before.
	else: Hash[n%7007].append(n) #Add the state to the hash table.
	que.tot+=1 #Increment the total number of operations.
	que.a+=F[3][0];que.b+=F[3][1];que.c+=F[3][2] #Apply the transformation.
	n=que.a*10000+que.b*100+que.c #Create a unique identifier for the state.
	if(HASH(n)): que.tot-=1 #Check if the state has been visited before.
	else: Hash[n%7007].append(n) #Add the state to the hash table.
	que.tot+=1 #Increment the total number of operations.
	que.a+=F[4][0];que.b+=F[4][1];que.c+=F[4][2] #Apply the transformation.
	n=que.a*10000+que.b*100+que.c #Create a unique identifier for the state.
	if(HASH(n)): que.tot-=1 #Check if the state has been visited before.
	else: Hash[n%7007].append(n) #Add the state to the hash table.
	que.tot+=1 #Increment the total number of operations.
	que.a+=F[5][0];que.b+=F[5][1];que.c+=F[5][2] #Apply the transformation.
	n=que.a*10000+que.b*100+que.c #Create a unique identifier for the state.
	if(HASH(n)): que.tot-=1 #Check if the state has been visited before.
	else: Hash[n%7007].append(n) #Add the state to the hash table.
	print(que.tot) #Print the total number of operations and exit.

if __name__=="__main__":
	main()

