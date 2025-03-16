/*Lucky_Glass*/
#include<stdio.h> // Include the standard input/output library for input/output operations.
#include<string.h> // Include the C string library for string manipulation.
#include<stdlib.h> // Include the standard library for dynamic memory allocation.
#include<stdbool.h> // Include the standard boolean library for boolean operations.
#include<queue.h> // Include the queue library for queue operations.
#define MOD 7007 // Define a constant MOD with the value 7007.

// Define a structure QUEUE to store the values of a, b, c, and the total number of operations.
struct QUEUE
{
	int a,b,c,tot;
};

// Define a transformation matrix F with six possible transformations.
int F[6][3]={{1,1,0},{1,0,1},{0,1,1},{2,0,0},{0,2,0},{0,0,2}};

// Define a hash table as an array of vectors to store unique states.
int Hash[MOD][100000];

// Function to check if a state has been visited before.
bool HASH(int n)
{
	for(int i=0;i<Hash[n%MOD][0];i++) // Iterate through the hash table.
		if(n==Hash[n%MOD][i]) // Check if the state is already present.
			return false; // Return false if the state is already visited.
	Hash[n%MOD][0]++; // Add the state to the hash table.
	Hash[n%MOD][Hash[n%MOD][0]]=n; // Add the state to the hash table.
	return true; // Return true if the state is new.
}

// Main function to execute the program.
int main()
{
	struct QUEUE Push; // Create a structure QUEUE to store the values of a, b, c, and the total number of operations.
	struct QUEUE Fro; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro2; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro3; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro4; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro5; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro6; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro7; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro8; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro9; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro10; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro11; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro12; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro13; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro14; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro15; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro16; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro17; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro18; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro19; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro20; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro21; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro22; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro23; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro24; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro25; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro26; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro27; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro28; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro29; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro30; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro31; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro32; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro33; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro34; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro35; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro36; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro37; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro38; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro39; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro40; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro41; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro42; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro43; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro44; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro45; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro46; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro47; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro48; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro49; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro50; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro51; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro52; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro53; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro54; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro55; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro56; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro57; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro58; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro59; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro60; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro61; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro62; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro63; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro64; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro65; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro66; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro67; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro68; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro69; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro70; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro71; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro72; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro73; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro74; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro75; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro76; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro77; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro78; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro79; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro80; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro81; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro82; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro83; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro84; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro85; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro86; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro87; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro88; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro89; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro90; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro91; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro92; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro93; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro94; // Create a structure QUEUE to store the front element of the queue.
	struct QUEUE Fro95; // Create a structure QUEUE to store the front element of the 