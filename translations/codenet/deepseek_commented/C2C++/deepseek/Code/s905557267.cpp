#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to return the smaller of two integers
int min(int a, int b)
{
	if (a <= b){
		return (a);
	}
	return (b);
}

// Function to remove chains of four or more consecutive identical elements
int Chain(vector<int>& b, int n)
{
	int i, j;
	int count; // To count the length of the chain
	int color; // To store the color of the chain
	vector<int> a(b); // Temporary vector to hold the modified sequence
	
	// Iterate through the array to find and remove chains of four or more elements
	for (i = 0; i < n - 4; i++){
		if (a[i] != 0 && a[i] == a[i + 1] && a[i] == a[i + 2] && a[i] == a[i + 3]){
			count = 0;
			color = a[i];
			
			// Remove the chain by setting all elements to 0
			for (j = i; a[j] == color; j++){
				a[j] = 0;
				count++;
			}
			
			// Shift the remaining elements to fill the gap left by the removed chain
			for (j = 0; i + j + count < n; j++){
				a[i + j] = a[i + j + count];
				a[i + j + count] = 0;
			}
			
			// Reset the index to start checking from the beginning
			i = 0;
		}
		
	}
	
	count = 0;
	while (a[count] != 0){
		count++;
	}
	
	// Check if the remaining sequence is a chain of four or more elements
	if (count == 4 && a[0] == a[1] && a[0] == a[2] && a[0] == a[3]){
		return (0);
	}
	
	return (count);
}

// Main function to read input, process it, and print the result
int main(void)
{
	int n;
	int i, j;
	vector<int> a;
	int ans;
	int color;
	
	while (true){
		// Initialize the vector with zeros
		a.clear();
		a.resize(10000, 0);
		
		// Read the number of elements
		cin >> n;
		if (n == 0){
			break;
		}
		ans = n;
		
		// Read the elements themselves
		for (i = 0; i < n; i++){
			cin >> a[i];
		}
		
		// Iterate over possible starting points for chains of four or more elements
		for (i = 0; i < n - 4; i++){
			int count[3] = {0, 0, 0}; // To count occurrences of each color
			for (j = i; j < i + 4; j++){
				if (a[j] - 1 >= 0){
					count[a[j] - 1]++;
				}
			}
			
			color = 0;
			for (j = 0; j < 3; j++){
				if (count[j] >= 3){
					color = j + 1;
					break;
				}
			}
			
			if (color != 0){
				for (j = i; j < i + 4; j++){
					int buf;
					buf = a[j];
					a[j] = color;
					ans = min(ans, Chain(a, n));
					a[j] = buf;
				}
			}
		}
		
		// Print the minimum length after processing
		cout << ans << endl;
	}
	
	return (0);
}
