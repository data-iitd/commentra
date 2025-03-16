#include <cstdio>

const int MAXN = 1E5 + 10; // Define the maximum size for arrays

int n, m, Q; // Declare variables for the size of arrays and number of queries
int a[MAXN]; // Declare array a to store the input elements
int b[MAXN], id[MAXN]; // Declare arrays b and id for storing unique elements and their positions
bool vis[MAXN]; // Declare a boolean array vis to mark processed elements
int cnt[MAXN]; // Declare an array cnt to count elements in each position

int main(){
	scanf("%d%d", &n, &m); // Read the size of array a and the number of positions m
	scanf("%d", &Q); // Read the number of queries Q
	for (int i = 1; i <= Q; ++i)
		scanf("%d", &a[i]); // Read the elements of array a
	for (int k = 0, j = Q; j > 0; --j) // Process the elements of array a
		if (!vis[a[j]]) // If the element has not been processed
			b[++k] = a[j], vis[a[j]] = true; // Add the element to b and mark it as processed
	for (int j = m, i = m; i > 0; --i) // Fill the remaining positions in b
		if (!vis[i])
			b[j--] = i;
	for (int i = 1; i <= m; ++i)
		id[b[i]] = i; // Store the position of each element in b

	bool flag = true; // Initialize flag to true
	cnt[0] = n; // Initialize the count of elements in the first position
	for (int i = Q; i > 0; --i){ // Iterate through the elements of array a in reverse order
		int t = id[a[i]]; // Get the position of the current element in b
		if (cnt[t - 1] > 0){ // If there is a position available one less than the current position
			--cnt[t - 1]; // Decrease the count of the previous position
			++cnt[t]; // Increase the count of the current position
			vis[t] = true; // Mark the current position as processed
		}
		else if (!vis[t]){ // If the current position is not available and not yet marked as processed
			flag = false; // Set flag to false
			break; // Break out of the loop
		}
	}

	int l; // Declare variable l to find the smallest non-zero count
	for (l = 0; cnt[l] == 0; ++l); // Find the smallest index l with a non-zero count
	for (int i = l + 1; i < m; ++i) // Check if the elements in b are in strictly increasing order
		flag &= b[i] < b[i + 1];
	puts(flag ? "Yes" : "No"); // Print "Yes" if the conditions are met, otherwise print "No"
	return 0;
}
