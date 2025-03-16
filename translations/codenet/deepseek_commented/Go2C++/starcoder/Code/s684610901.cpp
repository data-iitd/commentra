#include <bits/stdc++.h>

using namespace std;

/*==========================================
 *             Custom Sorting Types
 *==========================================*/
// pair struct holds two values and an index for sorting.
struct pair {
	int64_t index;
	int64_t p1, p2;
};

// pairs is a slice of pair structs for sorting.
typedef pair* pairs;

// Len returns the length of the pairs slice.
int Len(pairs slice) {
	return sizeof(slice) / sizeof(pair);
}

// Less compares two pairs based on their index.
bool Less(pair a, pair b) {
	return a.index < b.index;
}

// Swap exchanges two pairs in the slice.
void Swap(pair a, pair b) {
	pair temp = a;
	a = b;
	b = temp;
}

// Int64Slice is a type alias for sorting slices of int64.
typedef int64_t* Int64Slice;

// Len returns the length of the Int64Slice.
int Len(Int64Slice slice) {
	return sizeof(slice) / sizeof(int64_t);
}

// Less compares two int64 values.
bool Less(int64_t a, int64_t b) {
	return a < b;
}

// Swap exchanges two int64 values in the slice.
void Swap(int64_t a, int64_t b) {
	int64_t temp = a;
	a = b;
	b = temp;
}

// Int64s sorts a slice of int64.
void Int64s(Int64Slice a) {
	sort(a, a + Len(a));
}

// Int64sSliceAreSorted checks if a slice of int64 is sorted.
bool Int64sSliceAreSorted(Int64Slice a) {
	return is_sorted(a, a + Len(a));
}

/*==========================================
 *             Constants and Variables
 *==========================================*/
// initialBufSize and maxBufSize define the buffer sizes for scanning input.
const int64_t initialBufSize = 1e4;
const int64_t maxBufSize = 1e8;
const int64_t INF = 1e8;

// scanner and writer are initialized for reading from standard input and writing to standard output.
std::unique_ptr<std::stringstream> ss;
std::unique_ptr<std::stringstream> out;
std::unique_ptr<std::stringstream> out2;
std::unique_ptr<std::stringstream> out3;
std::unique_ptr<std::stringstream> out4;
std::unique_ptr<std::stringstream> out5;
std::unique_ptr<std::stringstream> out6;
std::unique_ptr<std::stringstream> out7;
std::unique_ptr<std::stringstream> out8;
std::unique_ptr<std::stringstream> out9;
std::unique_ptr<std::stringstream> out10;
std::unique_ptr<std::stringstream> out11;
std::unique_ptr<std::stringstream> out12;
std::unique_ptr<std::stringstream> out13;
std::unique_ptr<std::stringstream> out14;
std::unique_ptr<std::stringstream> out15;
std::unique_ptr<std::stringstream> out16;
std::unique_ptr<std::stringstream> out17;
std::unique_ptr<std::stringstream> out18;
std::unique_ptr<std::stringstream> out19;
std::unique_ptr<std::stringstream> out20;
std::unique_ptr<std::stringstream> out21;
std::unique_ptr<std::stringstream> out22;
std::unique_ptr<std::stringstream> out23;
std::unique_ptr<std::stringstream> out24;
std::unique_ptr<std::stringstream> out25;
std::unique_ptr<std::stringstream> out26;
std::unique_ptr<std::stringstream> out27;
std::unique_ptr<std::stringstream> out28;
std::unique_ptr<std::stringstream> out29;
std::unique_ptr<std::stringstream> out30;
std::unique_ptr<std::stringstream> out31;
std::unique_ptr<std::stringstream> out32;
std::unique_ptr<std::stringstream> out33;
std::unique_ptr<std::stringstream> out34;
std::unique_ptr<std::stringstream> out35;
std::unique_ptr<std::stringstream> out36;
std::unique_ptr<std::stringstream> out37;
std::unique_ptr<std::stringstream> out38;
std::unique_ptr<std::stringstream> out39;
std::unique_ptr<std::stringstream> out40;
std::unique_ptr<std::stringstream> out41;
std::unique_ptr<std::stringstream> out42;
std::unique_ptr<std::stringstream> out43;
std::unique_ptr<std::stringstream> out44;
std::unique_ptr<std::stringstream> out45;
std::unique_ptr<std::stringstream> out46;
std::unique_ptr<std::stringstream> out47;
std::unique_ptr<std::stringstream> out48;
std::unique_ptr<std::stringstream> out49;
std::unique_ptr<std::stringstream> out50;
std::unique_ptr<std::stringstream> out51;
std::unique_ptr<std::stringstream> out52;
std::unique_ptr<std::stringstream> out53;
std::unique_ptr<std::stringstream> out54;
std::unique_ptr<std::stringstream> out55;
std::unique_ptr<std::stringstream> out56;
std::unique_ptr<std::stringstream> out57;
std::unique_ptr<std::stringstream> out58;
std::unique_ptr<std::stringstream> out59;
std::unique_ptr<std::stringstream> out60;
std::unique_ptr<std::stringstream> out61;
std::unique_ptr<std::stringstream> out62;
std::unique_ptr<std::stringstream> out63;
std::unique_ptr<std::stringstream> out64;
std::unique_ptr<std::stringstream> out65;
std::unique_ptr<std::stringstream> out66;
std::unique_ptr<std::stringstream> out67;
std::unique_ptr<std::stringstream> out68;
std::unique_ptr<std::stringstream> out69;
std::unique_ptr<std::stringstream> out70;
std::unique_ptr<std::stringstream> out71;
std::unique_ptr<std::stringstream> out72;
std::unique_ptr<std::stringstream> out73;
std::unique_ptr<std::stringstream> out74;
std::unique_ptr<std::stringstream> out75;
std::unique_ptr<std::stringstream> out76;
std::unique_ptr<std::stringstream> out77;
std::unique_ptr<std::stringstream> out78;
std::unique_ptr<std::stringstream> out79;
std::unique_ptr<std::stringstream> out80;
std::unique_ptr<std::stringstream> out81;
std::unique_ptr<std::stringstream> out82;
std::unique_ptr<std::stringstream> out83;
std::unique_ptr<std::stringstream> out84;
std::unique_ptr<std::stringstream> out85;
std::unique_ptr<std::stringstream> out86;
std::unique_ptr<std::stringstream> out87;
std::unique_ptr<std::stringstream> out88;
std::unique_ptr<std::stringstream> out89;
std::unique_ptr<std::stringstream> out90;
std::unique_ptr<std::stringstream> out91;
std::unique_ptr<std::stringstream> out92;
std::unique_ptr<std::stringstream> out93;
std::unique_ptr<std::stringstream> out94;
std::unique_ptr<std::stringstream> out95;
std::unique_ptr<std::stringstream> out96;
std::unique_ptr<std::stringstream> out97;
std::unique_ptr<std::stringstream> out98;
std::unique_ptr<std::stringstream> out99;
std::unique_ptr<std::stringstream> out100;
std::unique_ptr<std::stringstream> out101;
std::unique_ptr<std::stringstream> out102;
std::unique_ptr<std::stringstream> out103;
std::unique_ptr<std::stringstream> out104;
std::unique_ptr<std::stringstream> out105;
std::unique_ptr<std::stringstream> out106;
std::unique_ptr<std::stringstream> out107;
std::unique_ptr<std::stringstream> out108;
std::unique_ptr<std::stringstream> out109;
std::unique_ptr<std::stringstream> out110;
std::unique_ptr<std::stringstream> out111;
std::unique_ptr<std::stringstream> out112;
std::unique_ptr<std::stringstream> out113;
std::unique_ptr<std::stringstream> out114;
std::unique_ptr<std::stringstream> out115;
std::unique_ptr<std::stringstream> out116;
std::unique_ptr<std::stringstream> out117;
std::unique_ptr<std::stringstream> out118;
std::unique_ptr<std::stringstream> out119;
std::unique_ptr<std::stringstream> out120;
std::unique_ptr<std::stringstream> out121;
std::unique_ptr<std::stringstream> out122;
std::unique_ptr<std::stringstream> out123;
std::unique_ptr<std::stringstream> out124;
std::unique_ptr<std::stringstream> out125;
std::unique_ptr<std::stringstream> out126;
std::unique_ptr<std::stringstream> out127;
std::unique_ptr<std::stringstream> out128;
std::unique_ptr<std::stringstream> out129;
std::unique_ptr<std::stringstream> out130;
std::unique_ptr<std::stringstream> out131;
std::unique_ptr<std::stringstream> out132;
std::unique_ptr<std::stringstream> out133;
std::unique_ptr<std::stringstream> out134;
std::unique_ptr<std::stringstream> out135;
std::unique_ptr<std::stringstream> out136;
std::unique_ptr<std::stringstream> out137;
std::unique_ptr<std::stringstream> out138;
std::unique_ptr<std::stringstream> out139;
std::unique_ptr<std::stringstream> out140;
std::unique_ptr<std::stringstream> out141;
std::unique_ptr<std::stringstream> out142;
std::unique_ptr<std::stringstream> out143;
std::unique_ptr<std::stringstream> out144;
std::unique_ptr<std::stringstream> out145;
std::unique_ptr<std::stringstream> out146;
std::unique_ptr<std::stringstream> out147;
std::unique_ptr<std::stringstream> out148;
std::unique_ptr<std::stringstream> out149;
std::unique_ptr<std::stringstream> out150;
std::unique_ptr<std::stringstream> out151;
std::unique_ptr<std::stringstream> out152;
std::unique_ptr<std::stringstream> out153;
std::unique_ptr<std::stringstream> out154;
std::unique_ptr<std::stringstream> out155;
std::unique_ptr<std::stringstream> out156;
std::unique_ptr<std::stringstream> out157;
std::unique_ptr<std::stringstream> out158;
std::unique_ptr<std::stringstream> out159;
std::unique_ptr<std::stringstream> out160;
std::unique_ptr<std::stringstream> out161;
std::unique_ptr<std::stringstream> out162;
std::unique_ptr<std::stringstream> out163;
std::unique_ptr<std::stringstream> out164;
std::unique_ptr<std::stringstream> out165;
std::unique_ptr<std::stringstream> out166;
std::unique_ptr<std::stringstream> out167;
std::unique_ptr<std::stringstream> out168;
std::unique_ptr<std::stringstream> out169;
std::unique_ptr<std::stringstream> out170;
std::unique_ptr<std::stringstream> out171;
std::unique_ptr<std::stringstream> out172;
std::unique_ptr<std::stringstream> out173;
std::unique_ptr<std::stringstream> out174;
std::unique_ptr<std::stringstream> out175;
std::unique_ptr<std::stringstream> out176;
std::unique_ptr<std::stringstream> out177;
std::unique_ptr<std::stringstream> out178;
std::unique_ptr<std::stringstream> out179;
std::unique_ptr<std::stringstream> out180;
std::unique_ptr<std::stringstream> out181;
std::unique_ptr<std::stringstream> out182;
std::unique_ptr<std::stringstream> out183;
std::unique_ptr<std::stringstream> out184;
std::unique_ptr<std::stringstream> out185;
std::unique_ptr<std::stringstream> out186;
std::unique_ptr<std::stringstream> out187;
std::unique_ptr<std::stringstream> out188;
std::unique_ptr<std::stringstream> out189;
std::unique_ptr<std::stringstream> out190;
std::unique_ptr<std::stringstream> out191;
std::unique_ptr<std::stringstream> out192;
std::unique_ptr<std::stringstream> out193;
std::unique_ptr<std::stringstream> out194