

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getScanner initializes a new scanner for reading from the provided file pointer.
FILE *getScanner(FILE *fp) {
	return fp;
}

// getNextString retrieves the next string from the scanner.
char *getNextString(FILE *fp) {
	char *s = NULL;
	if (fscanf(fp, "%ms", &s)!= 1) {
		return NULL;
	}
	return s;
}

// getNextInt retrieves the next integer from the scanner.
int getNextInt(FILE *fp) {
	int i = 0;
	fscanf(fp, "%d", &i);
	return i;
}

// getNextInt64 retrieves the next int64 from the scanner.
int64_t getNextInt64(FILE *fp) {
	int64_t i = 0;
	fscanf(fp, "%lld", &i);
	return i;
}

// getNextUint64 retrieves the next uint64 from the scanner.
uint64_t getNextUint64(FILE *fp) {
	uint64_t i = 0;
	fscanf(fp, "%llu", &i);
	return i;
}

// getNextFloat64 retrieves the next float64 from the scanner.
double getNextFloat64(FILE *fp) {
	double i = 0;
	fscanf(fp, "%lf", &i);
	return i;
}

int main() {
	// Initialize file pointers for input and output
	FILE *fp = stdin;
	FILE *wfp = stdout;

	// Check for environment variables to override input and output file pointers
	if (getenv("MASPY") == "ますピ") {
		fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r"); // Open specified input file
	}
	if (getenv("MASPYPY") == "ますピッピ") {
		wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w"); // Create specified output file
	}

	// Create a scanner for reading input and a writer for output
	FILE *scanner = getScanner(fp);
	FILE *writer = wfp;

	// Read two strings from input
	char *s = getNextString(scanner);
	char *t = getNextString(scanner);

	// Calculate lengths of the input strings
	int ns = strlen(s);
	int nt = strlen(t);

	// Create a slice to hold repeated instances of string s
	char **ss = (char **)malloc(sizeof(char *) * ((nt-1)/ns+1));
	for (int i = 0; i < (nt-1)/ns+1; i++) {
		ss[i] = (char *)malloc(sizeof(char) * ns);
		strcpy(ss[i], s); // Fill the slice with string s
	}

	// Concatenate the repeated strings to form a new string
	char *sss = (char *)malloc(sizeof(char) * (nt+nt));
	sprintf(sss, "%s%s", strcat(strcat(ss[0], ss[1]), ss[2]), strcat(strcat(ss[0], ss[1]), ss[2]));

	// Initialize a boolean slice to track matches
	bool *ok = (bool *)malloc(sizeof(bool) * ns);

	// Initialize a unique index array and a pattern matching structure
	int *uni = (int *)malloc(sizeof(int) * ns);
	MP mp;
	mp.init(t); // Initialize the pattern matching table with string t
	int m = 0;
	for (int i = 0; i < ns; i++) {
		uni[i] = i; // Set each index to itself initially
	}
	bool o = true;

	// Check for matches of string t in the concatenated string sss
	for (int i = 0; i < ns; i++) {
		o = true;
		for (m = 0; m < nt; m++) {
			if (t[m]!= sss[i+m]) { // Compare characters
				o = false;
				break;
			}
		}
		ok[i] = o; // Store the result of the match
		if (o) {
			i += nt - mp.table[m]; // Update index based on the pattern table
			m = mp.table[m]; // Update match index
		}
		for (m >= 0 && t[m]!= sss[i+m]) {
			i += m - mp.table[m]; // Update index if mismatch occurs
			m = mp.table[m]; // Update match index
		}
		i--; // Adjust index for the next iteration
		m++; // Move to the next character
	}

	// Calculate the answer based on the matches found
	int ans = 0;
	int r, rr;
	for (int i = 0; i < ns; i++) {
		if (!ok[i]) {
			continue; // Skip if no match
		}
		if (!ok[(i+nt)%ns]) {
			continue; // Skip if no match for the next index
		}
		r = root(i, uni); // Find the root of the current index
		rr = root((i+nt)%ns, uni); // Find the root of the next index
		if (rr == r) {
			fprintf(wfp, "-1\n"); // Output -1 if they are in the same component
			return 0;
		}
		uni[rr] = r; // Union the two components
	}

	// Count the number of matches for each unique root
	int *counter = (int *)malloc(sizeof(int) * ns);
	for (int i = 0; i < ns; i++) {
		r = root(i, uni); // Find the root for the current index
		if (!ok[r]) {
			continue; // Skip if no match
		}
		counter[r]++; // Increment the count for the root
	}
	for (int i = 0; i < ns; i++) {
		if (ans < counter[i]) {
			ans = counter[i]; // Update the answer with the maximum count
		}
	}

	// Output the final answer
	fprintf(wfp, "%d\n", ans);

	return 0;
}

// root function finds the root of the given index using path compression.
int root(int i, int *uni) {
	if (i == uni[i]) {
		return i; // Return if the index is its own root
	}

	uni[i] = root(uni[i], uni); // Path compression
	return uni[i]; // Return the root
}

// MP struct holds the string and its pattern matching table.
typedef struct {
	char *s;
	int *table;
} MP;

// init initializes the pattern matching table for the string.
void MP_init(MP *mp, char *s) {
	mp->s = s;
	int n = strlen(s);
	mp->table = (int *)malloc(sizeof(int) * (n+1));
	mp->table[0] = -1; // Initialize the first value of the table
	int j = -1;
	for (int i = 0; i < n; i++) {
		for (j = j; j >= 0 && s[i]!= s[j]; j = mp->table[j]) {
			; // Update j based on the table
		}
		j++;
		mp->table[i+1] = j; // Fill the table with the length of the longest prefix
	}
}

// Translate the above C code to Python.

import os
import sys

# Check for environment variables to override input and output file pointers
if os.getenv("MASPY") == "ますピ":
	sys.stdin = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"), "r") # Open specified input file
if os.getenv("MASPYPY") == "ますピッピ":
	sys.stdout = open(os.getenv("NGTKANA_IS_GENIUS10"), "w") # Create specified output file

# Create a scanner for reading input and a writer for output
scanner = sys.stdin
writer = sys.stdout

# Read two strings from input
s = next(scanner).rstrip()
t = next(scanner).rstrip()

# Calculate lengths of the input strings
ns = len(s)
nt = len(t)

# Create a slice to hold repeated instances of string s
ss = [s] * ((nt-1)//ns+1)

# Concatenate the repeated strings to form a new string
sss = "".join(ss) + "".join(ss)

# Initialize a boolean slice to track matches
ok = [False] * ns

# Initialize a unique index array and a pattern matching structure
uni = [i for i in range(ns)]
mp = MP()
MP_init(mp, t) # Initialize the pattern matching table with string t
m = 0
for i in range(ns):
	uni[i] = i # Set each index to itself initially
o = True

# Check for matches of string t in the concatenated string sss
for i in range(ns):
	o = True
	for m in range(nt):
		if t[m]!= sss[i+m]: # Compare characters
			o = False
			break
	ok[i] = o # Store the result of the match
	if o:
		i += nt - mp.table[m] # Update index based on the pattern table
		m = mp.table[m] # Update match index
	for m >= 0 and t[m]!= sss[i+m]:
		i += m - mp.table[m] # Update index if mismatch occurs
		m = mp.table[m] # Update match index
	i -= 1 # Adjust index for the next iteration
	m += 1 # Move to the next character

# Calculate the answer based on the matches found
ans = 0
r, rr = 0, 0
for i in range(ns):
	if not ok[i]:
		continue # Skip if no match
	if not ok[(i+nt)%ns]:
		continue # Skip if no match for the next index
	r = root(i, uni) # Find the root of the current index
	rr = root((i+nt)%ns, uni) # Find the root of the next index
	if rr == r:
		print(-1) # Output -1 if they are in the same component
		return
	uni[rr] = r # Union the two components

# Count the number of matches for each unique root
counter = [0] * ns
for i in range(ns):
	r = root(i, uni) # Find the root for the current index
	if not ok[r]:
		continue # Skip if no match
	counter[r] += 1 # Increment the count for the root
for i in range(ns):
	if ans < counter[i]:
		ans = counter[i] # Update the answer with the maximum count

# Output the final answer
print(ans)
