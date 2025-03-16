
#include <bits/stdc++.h>

using namespace std;

// getScanner returns a new bufio.Scanner from the given file pointer
inline bufio::Scanner getScanner(FILE *fp) {
	return bufio::Scanner(fp);
}

// getNextString reads and returns the next string from the scanner
inline string getNextString(bufio::Scanner &scanner) {
	scanner.Scan();
	return scanner.Text();
}

// getNextInt reads and converts the next integer from the scanner
inline int getNextInt(bufio::Scanner &scanner) {
	int i;
	scanner.Scan();
	sscanf(scanner.Text().c_str(), "%d", &i);
	return i;
}

// getNextInt64 reads and converts the next int64 from the scanner
inline int64_t getNextInt64(bufio::Scanner &scanner) {
	int64_t i;
	scanner.Scan();
	sscanf(scanner.Text().c_str(), "%ld", &i);
	return i;
}

// getNextUint64 reads and converts the next uint64 from the scanner
inline uint64_t getNextUint64(bufio::Scanner &scanner) {
	uint64_t i;
	scanner.Scan();
	sscanf(scanner.Text().c_str(), "%lu", &i);
	return i;
}

// getNextFloat64 reads and converts the next float64 from the scanner
inline double getNextFloat64(bufio::Scanner &scanner) {
	double i;
	scanner.Scan();
	sscanf(scanner.Text().c_str(), "%lf", &i);
	return i;
}

// main function is the entry point of the program
int main() {
	// Open the standard input and output files
	FILE *fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
	FILE *wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");

	// Initialize scanner and writer
	bufio::Scanner scanner = getScanner(fp);
	bufio::Writer writer = bufio::Writer(wfp);

	// Read the first two strings from the input
	string s = getNextString(scanner);
	string t = getNextString(scanner);

	// Initialize variables and structures
	int ns = s.length();
	int nt = t.length();
	string *ss = new string[(nt-1)/ns+1];

	// Initialize ss with repeated string s
	for (int i = 0; i < (int)ss.length(); i++) {
		ss[i] = s;
	}

	// Combine all ss strings into one long string
	string sss = s + string(ss, ss.length());

	// Initialize boolean array ok to keep track of unique characters
	bool *ok = new bool[ns];

	// Initialize unordered map mp and array uni for suffix array calculation
	MP mp;
	mp.init(t);
	int m = 0;

	// Initialize uni array with indices from 0 to n-1
	int *uni = new int[ns];
	for (int i = 0; i < ns; i++) {
		uni[i] = i;
	}

	// Initialize variable o for checking if current and next characters match
	bool o = true;

	// Iterate through all characters in string s
	for (int i = 0; i < ns; i++) {
		// Initialize o to true
		o = true;

		// Iterate through all characters in string t
		for (m = 0; m < nt; m++) {
			// Check if current character in s matches the character at the same position in t
			if (t[m]!= sss[i+m]) {
				// If not, set o to false and break the loop
				o = false;
				break;
			}
		}

		// If all characters match, set ok[i] to true and update variables r and m accordingly
		if (o) {
			i += nt - mp.table[m];
			m = mp.table[m];
		}

		// While characters in s and t do not match, update i and m accordingly
		for (m >= 0 && t[m]!= sss[i+m]) {
			i += m - mp.table[m];
			m = mp.table[m];
		}

		// Decrement i and increment m to move to the next pair of characters
		i--;
		m++;
	}

	// Initialize variable ans to store the answer
	int ans = 0;

	// Initialize variables r and rr for root calculation
	int r, rr;

	// Iterate through all characters in string s again
	for (int i = 0; i < ns; i++) {
		// If ok[i] is false, continue to the next iteration
		if (!ok[i]) {
			continue;
		}

		// If ok[(i+nt)%ns] is false, continue to the next iteration
		if (!ok[(i+nt)%ns]) {
			continue;
		}

		// Calculate roots r and rr of indices i and (i+nt)%ns respectively
		r = root(i, uni);
		rr = root((i+nt)%ns, uni);

		// If roots r and rr are equal, print -1 and exit the program
		if (rr == r) {
			printf("%d\n", -1);
			return 0;
		}

		// Update uni array with root r
		uni[rr] = r;
	}

	// Initialize counter array to store the frequency of each root
	int *counter = new int[ns];

	// Iterate through all roots and update their frequencies in counter array
	for (int i = 0; i < ns; i++) {
		r = root(i, uni);
		if (!ok[r]) {
			continue;
		}
		counter[r]++;
	}

	// Find the maximum frequency in counter array and store it in variable ans
	for (int i = 0; i < ns; i++) {
		if (ans < counter[i]) {
			ans = counter[i];
		}
	}

	// Print the answer
	printf("%d\n", ans);

	// Flush the writer buffer
	writer.Flush();

	// Close the input and output files
	fclose(fp);
	fclose(wfp);

	// Delete dynamically allocated memory
	delete[] ss;
	delete[] ok;
	delete[] uni;
	delete[] counter;

	return 0;
}

// root function returns the root of the given index in uni array
int root(int i, int *uni) {
	// If index i is equal to its root, return i
	if (i == uni[i]) {
		return i;
	}

	// Recursively call root function with the root of index i
	return root(uni[i], uni);
}

// MP type represents a suffix array data structure
struct MP {
	string s; // Input string
	int *table; // Suffix array
	int n; // Length of input string
	int m; // Length of suffix array
	int *uni; // Array of indices
	int *rank; // Array of rank values
	int *lcp; // Array of LCP values
	int *slink; // Array of slink values
	int *b; // Array of b values
	int *f; // Array of f values
	int *g; // Array of g values
	int *depth; // Array of depth values
	int *parent; // Array of parent values
	int *ancestor; // Array of ancestor values
	int *size; // Array of size values
	int *height; // Array of height values
	int *timestamp; // Array of timestamp values
	int *first; // Array of first values
	int *last; // Array of last values
	int *next; // Array of next values
	int *prev; // Array of prev values
	int *left; // Array of left values
	int *right; // Array of right values
	int *edge; // Array of edge values
	int *sigma; // Array of sigma values
	int *start; // Array of start values
	int *end; // Array of end values
	int *cnt; // Array of cnt values
	int *cnt2; // Array of cnt2 values
	int *cnt3; // Array of cnt3 values
	int *cnt4; // Array of cnt4 values
	int *cnt5; // Array of cnt5 values
	int *cnt6; // Array of cnt6 values
	int *cnt7; // Array of cnt7 values
	int *cnt8; // Array of cnt8 values
	int *cnt9; // Array of cnt9 values
	int *cnt10; // Array of cnt10 values
	int *cnt11; // Array of cnt11 values
	int *cnt12; // Array of cnt12 values
	int *cnt13; // Array of cnt13 values
	int *cnt14; // Array of cnt14 values
	int *cnt15; // Array of cnt15 values
	int *cnt16; // Array of cnt16 values
	int *cnt17; // Array of cnt17 values
	int *cnt18; // Array of cnt18 values
	int *cnt19; // Array of cnt19 values
	int *cnt20; // Array of cnt20 values
	int *cnt21; // Array of cnt21 values
	int *cnt22; // Array of cnt22 values
	int *cnt23; // Array of cnt23 values
	int *cnt24; // Array of cnt24 values
	int *cnt25; // Array of cnt25 values
	int *cnt26; // Array of cnt26 values
	int *cnt27; // Array of cnt27 values
	int *cnt28; // Array of cnt28 values
	int *cnt29; // Array of cnt29 values
	int *cnt30; // Array of cnt30 values
	int *cnt31; // Array of cnt31 values
	int *cnt32; // Array of cnt32 values
	int *cnt33; // Array of cnt33 values
	int *cnt34; // Array of cnt34 values
	int *cnt35; // Array of cnt35 values
	int *cnt36; // Array of cnt36 values
	int *cnt37; // Array of cnt37 values
	int *cnt38; // Array of cnt38 values
	int *cnt39; // Array of cnt39 values
	int *cnt40; // Array of cnt40 values
	int *cnt41; // Array of cnt41 values
	int *cnt42; // Array of cnt42 values
	int *cnt43; // Array of cnt43 values
	int *cnt44; // Array of cnt44 values
	int *cnt45; // Array of cnt45 values
	int *cnt46; // Array of cnt46 values
	int *cnt47; // Array of cnt47 values
	int *cnt48; // Array of cnt48 values
	int *cnt49; // Array of cnt49 values
	int *cnt50; // Array of cnt50 values
	int *cnt51; // Array of cnt51 values
	int *cnt52; // Array of cnt52 values
	int *cnt53; // Array of cnt53 values
	int *cnt54; // Array of cnt54 values
	int *cnt55; // Array of cnt55 values
	int *cnt56; // Array of cnt56 values
	int *cnt57; // Array of cnt57 values
	int *cnt58; // Array of cnt58 values
	int *cnt59; // Array of cnt59 values
	int *cnt60; // Array of cnt60 values
	int *cnt61; // Array of cnt61 values
	int *cnt62; // Array of cnt62 values
	int *cnt63; // Array of cnt63 values
	int *cnt64; // Array of cnt64 values
	int *cnt65; // Array of cnt65 values
	int *cnt66; // Array of cnt66 values
	int *cnt67; // Array of cnt67 values
	int *cnt68; // Array of cnt68 values
	int *cnt69; // Array of cnt69 values
	int *cnt70; // Array of cnt70 values
	int *cnt71; // Array of cnt71 values
	int *cnt72; // Array of cnt72 values
	int *cnt73; // Array of cnt73 values
	int *cnt74; // Array of cnt74 values
	int *cnt75; // Array of cnt75 values
	int *cnt76; // Array of cnt76 values
	int *cnt77; // Array of cnt77 values
	int *cnt78; // Array of cnt78 values
	int *cnt79; // Array of cnt79 values
	int *cnt80; // Array of cnt80 values
	int *cnt81; // Array of cnt81 values
	int *cnt82; // Array of cnt82 values
	int *cnt83; // Array of cnt83 values
	int *cnt84; // Array of cnt84 values
	int *cnt85; // Array of cnt85 values
	int *cnt86; // Array of cnt86 values
	int *cnt87; // Array of cnt87 values
	int *cnt88; // Array of cnt88 values
	int *cnt89; // Array of cnt89 values
	int *cnt90; // Array of cnt90 values
	int *cnt91; // Array of cnt91 values
	int *cnt92; // Array of cnt92 values
	int *cnt93; // Array of cnt93 values
	int *cnt94; // Array of cnt94 values
	int *cnt95; // Array of cnt95 values
	int *cnt96; // Array of cnt96 values
	int *cnt97; // Array of cnt97 values
	int *cnt98; // Array of cnt98 values
	int *cnt99; // Array of cnt99 values
	int *cnt100; // Array of cnt100 values
	int *cnt101; // Array of cnt101 values
	int *cnt102; // Array of cnt102 values
	int *cnt103; // Array of cnt103 values
	int *cnt104; // Array of cnt104 values
	int *cnt105; // Array of cnt105 values
	int *cnt106; // Array of cnt106 values
	int *cnt107; // Array of cnt107 values
	int *cnt108; // Array of c