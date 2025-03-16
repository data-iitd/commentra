/*Lucky_Glass*/
import java.util.*; // Include the standard utility library for input/output operations.

// Define a structure QUEUE to store the values of a, b, c, and the total number of operations.
class QUEUE
{
	int a,b,c,tot;
	public QUEUE(int a,int b,int c,int tot)
	{
		this.a=a;this.b=b;this.c=c;this.tot=tot;
	}
}

// Define a transformation matrix F with six possible transformations.
int F[][]={{1,1,0},{1,0,1},{0,1,1},{2,0,0},{0,2,0},{0,0,2}};

// Define a hash table as an array of vectors to store unique states.
Vector<Integer> Hash[]=new Vector[7007];

// Function to check if a state has been visited before.
boolean HASH(int n)
{
	for(int i=0;i<Hash[n%7007].size();i++) // Iterate through the hash table.
		if(n==Hash[n%7007].get(i)) // Check if the state is already present.
			return false; // Return false if the state is already visited.
	Hash[n%7007].add(n); // Add the state to the hash table.
	return true; // Return true if the state is new.
}

// Main function to execute the program.
public static void main(String[] args)
{
	QUEUE Push=new QUEUE(0,0,0,0); // Initialize the initial state.
	Queue<QUEUE> que=new LinkedList<QUEUE>(); // Create a queue of QUEUE structures.
	Scanner scan=new Scanner(System.in); // Create a scanner to read input from stdin.
	Push.a=scan.nextInt();Push.b=scan.nextInt();Push.c=scan.nextInt(); // Read the initial values of a, b, and c.
	que.add(Push); // Push the initial state into the queue.
	while(!que.isEmpty()) // Continue until the queue is empty.
	{
		QUEUE Fro=que.peek(); // Retrieve the front element of the queue.
		if(Fro.a==Fro.b && Fro.b==Fro.c) // Check if the current state is the goal state.
		{
			System.out.println(Fro.tot); // Print the total number of operations and exit.
			return;
		}
		for(int i=0;i<6;i++) // Apply each transformation to the current state.
		{
			Push=Fro; // Copy the current state to Push.
			Push.tot++; // Increment the total number of operations.
			Push.a+=F[i][0];Push.b+=F[i][1];Push.c+=F[i][2]; // Apply the transformation.
			int n=Push.a*10000+Push.b*100+Push.c; // Create a unique identifier for the state.
			if(!HASH(n)) continue; // Check if the state has been visited before.
			que.add(Push); // Push the new state into the queue.
		}
		que.remove(); // Remove the front element from the queue.
	}
}

