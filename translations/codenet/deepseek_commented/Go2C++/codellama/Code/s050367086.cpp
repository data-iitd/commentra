
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// getScanner Function
// Purpose: Initializes a scanner for the given file pointer.
// Details: Creates a new scanner and sets it to scan words.
void getScanner(FILE *fp) {
	// <START-OF-CODE>
	// Go:
	// scanner := bufio.NewScanner(fp)
	// scanner.Split(bufio.ScanWords)
	// scanner.Buffer(make([]byte, 500001), 500000)
	// return scanner
	// 