
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

using namespace std;

// ReadLongLines function reads long lines from standard input
vector<string> ReadLongLines(int times) {
	// Initialize result vector with the given size
	vector<string> result(times);
	// Initialize a new buffered reader
	cin.sync_with_stdio(false);
	cin.tie(0);
	// Initialize a new string variable to store the current line
	string line;
	// For each iteration, read a line from the standard input
	for (int i = 0; i < times; i++) {
		// Read a line from the standard input
		getline(cin, line);
		// Store the content of the line in the result vector
		result[i] = line;
	}
	// Return the result
	return result;
}

// Console type is used to manage the standard output
struct Console {
	// Declare a pointer to a FILE object
	FILE *writer;
	// Declare a pointer to a FILE object
	FILE *reader;
	// Declare a pointer to a FILE object
	FILE *error;
	// Declare a pointer to a FILE object
	FILE *input;
	// Declare a pointer to a FILE object
	FILE *output;
	// Declare a pointer to a FILE object
	FILE *standard;
	// Declare a pointer to a FILE object
	FILE *debug;
	// Declare a pointer to a FILE object
	FILE *trace;
	// Declare a pointer to a FILE object
	FILE *null;
	// Declare a pointer to a FILE object
	FILE *stderr;
	// Declare a pointer to a FILE object
	FILE *stdout;
	// Declare a pointer to a FILE object
	FILE *stdin;
	// Declare a pointer to a FILE object
	FILE *log;
	// Declare a pointer to a FILE object
	FILE *log2;
	// Declare a pointer to a FILE object
	FILE *log3;
	// Declare a pointer to a FILE object
	FILE *log4;
	// Declare a pointer to a FILE object
	FILE *log5;
	// Declare a pointer to a FILE object
	FILE *log6;
	// Declare a pointer to a FILE object
	FILE *log7;
	// Declare a pointer to a FILE object
	FILE *log8;
	// Declare a pointer to a FILE object
	FILE *log9;
	// Declare a pointer to a FILE object
	FILE *log10;
	// Declare a pointer to a FILE object
	FILE *log11;
	// Declare a pointer to a FILE object
	FILE *log12;
	// Declare a pointer to a FILE object
	FILE *log13;
	// Declare a pointer to a FILE object
	FILE *log14;
	// Declare a pointer to a FILE object
	FILE *log15;
	// Declare a pointer to a FILE object
	FILE *log16;
	// Declare a pointer to a FILE object
	FILE *log17;
	// Declare a pointer to a FILE object
	FILE *log18;
	// Declare a pointer to a FILE object
	FILE *log19;
	// Declare a pointer to a FILE object
	FILE *log20;
	// Declare a pointer to a FILE object
	FILE *log21;
	// Declare a pointer to a FILE object
	FILE *log22;
	// Declare a pointer to a FILE object
	FILE *log23;
	// Declare a pointer to a FILE object
	FILE *log24;
	// Declare a pointer to a FILE object
	FILE *log25;
	// Declare a pointer to a FILE object
	FILE *log26;
	// Declare a pointer to a FILE object
	FILE *log27;
	// Declare a pointer to a FILE object
	FILE *log28;
	// Declare a pointer to a FILE object
	FILE *log29;
	// Declare a pointer to a FILE object
	FILE *log30;
	// Declare a pointer to a FILE object
	FILE *log31;
	// Declare a pointer to a FILE object
	FILE *log32;
	// Declare a pointer to a FILE object
	FILE *log33;
	// Declare a pointer to a FILE object
	FILE *log34;
	// Declare a pointer to a FILE object
	FILE *log35;
	// Declare a pointer to a FILE object
	FILE *log36;
	// Declare a pointer to a FILE object
	FILE *log37;
	// Declare a pointer to a FILE object
	FILE *log38;
	// Declare a pointer to a FILE object
	FILE *log39;
	// Declare a pointer to a FILE object
	FILE *log40;
	// Declare a pointer to a FILE object
	FILE *log41;
	// Declare a pointer to a FILE object
	FILE *log42;
	// Declare a pointer to a FILE object
	FILE *log43;
	// Declare a pointer to a FILE object
	FILE *log44;
	// Declare a pointer to a FILE object
	FILE *log45;
	// Declare a pointer to a FILE object
	FILE *log46;
	// Declare a pointer to a FILE object
	FILE *log47;
	// Declare a pointer to a FILE object
	FILE *log48;
	// Declare a pointer to a FILE object
	FILE *log49;
	// Declare a pointer to a FILE object
	FILE *log50;
	// Declare a pointer to a FILE object
	FILE *log51;
	// Declare a pointer to a FILE object
	FILE *log52;
	// Declare a pointer to a FILE object
	FILE *log53;
	// Declare a pointer to a FILE object
	FILE *log54;
	// Declare a pointer to a FILE object
	FILE *log55;
	// Declare a pointer to a FILE object
	FILE *log56;
	// Declare a pointer to a FILE object
	FILE *log57;
	// Declare a pointer to a FILE object
	FILE *log58;
	// Declare a pointer to a FILE object
	FILE *log59;
	// Declare a pointer to a FILE object
	FILE *log60;
	// Declare a pointer to a FILE object
	FILE *log61;
	// Declare a pointer to a FILE object
	FILE *log62;
	// Declare a pointer to a FILE object
	FILE *log63;
	// Declare a pointer to a FILE object
	FILE *log64;
	// Declare a pointer to a FILE object
	FILE *log65;
	// Declare a pointer to a FILE object
	FILE *log66;
	// Declare a pointer to a FILE object
	FILE *log67;
	// Declare a pointer to a FILE object
	FILE *log68;
	// Declare a pointer to a FILE object
	FILE *log69;
	// Declare a pointer to a FILE object
	FILE *log70;
	// Declare a pointer to a FILE object
	FILE *log71;
	// Declare a pointer to a FILE object
	FILE *log72;
	// Declare a pointer to a FILE object
	FILE *log73;
	// Declare a pointer to a FILE object
	FILE *log74;
	// Declare a pointer to a FILE object
	FILE *log75;
	// Declare a pointer to a FILE object
	FILE *log76;
	// Declare a pointer to a FILE object
	FILE *log77;
	// Declare a pointer to a FILE object
	FILE *log78;
	// Declare a pointer to a FILE object
	FILE *log79;
	// Declare a pointer to a FILE object
	FILE *log80;
	// Declare a pointer to a FILE object
	FILE *log81;
	// Declare a pointer to a FILE object
	FILE *log82;
	// Declare a pointer to a FILE object
	FILE *log83;
	// Declare a pointer to a FILE object
	FILE *log84;
	// Declare a pointer to a FILE object
	FILE *log85;
	// Declare a pointer to a FILE object
	FILE *log86;
	// Declare a pointer to a FILE object
	FILE *log87;
	// Declare a pointer to a FILE object
	FILE *log88;
	// Declare a pointer to a FILE object
	FILE *log89;
	// Declare a pointer to a FILE object
	FILE *log90;
	// Declare a pointer to a FILE object
	FILE *log91;
	// Declare a pointer to a FILE object
	FILE *log92;
	// Declare a pointer to a FILE object
	FILE *log93;
	// Declare a pointer to a FILE object
	FILE *log94;
	// Declare a pointer to a FILE object
	FILE *log95;
	// Declare a pointer to a FILE object
	FILE *log96;
	// Declare a pointer to a FILE object
	FILE *log97;
	// Declare a pointer to a FILE object
	FILE *log98;
	// Declare a pointer to a FILE object
	FILE *log99;
	// Declare a pointer to a FILE object
	FILE *log100;
	// Declare a pointer to a FILE object
	FILE *log101;
	// Declare a pointer to a FILE object
	FILE *log102;
	// Declare a pointer to a FILE object
	FILE *log103;
	// Declare a pointer to a FILE object
	FILE *log104;
	// Declare a pointer to a FILE object
	FILE *log105;
	// Declare a pointer to a FILE object
	FILE *log106;
	// Declare a pointer to a FILE object
	FILE *log107;
	// Declare a pointer to a FILE object
	FILE *log108;
	// Declare a pointer to a FILE object
	FILE *log109;
	// Declare a pointer to a FILE object
	FILE *log110;
	// Declare a pointer to a FILE object
	FILE *log111;
	// Declare a pointer to a FILE object
	FILE *log112;
	// Declare a pointer to a FILE object
	FILE *log113;
	// Declare a pointer to a FILE object
	FILE *log114;
	// Declare a pointer to a FILE object
	FILE *log115;
	// Declare a pointer to a FILE object
	FILE *log116;
	// Declare a pointer to a FILE object
	FILE *log117;
	// Declare a pointer to a FILE object
	FILE *log118;
	// Declare a pointer to a FILE object
	FILE *log119;
	// Declare a pointer to a FILE object
	FILE *log120;
	// Declare a pointer to a FILE object
	FILE *log121;
	// Declare a pointer to a FILE object
	FILE *log122;
	// Declare a pointer to a FILE object
	FILE *log123;
	// Declare a pointer to a FILE object
	FILE *log124;
	// Declare a pointer to a FILE object
	FILE *log125;
	// Declare a pointer to a FILE object
	FILE *log126;
	// Declare a pointer to a FILE object
	FILE *log127;
	// Declare a pointer to a FILE object
	FILE *log128;
	// Declare a pointer to a FILE object
	FILE *log129;
	// Declare a pointer to a FILE object
	FILE *log130;
	// Declare a pointer to a FILE object
	FILE *log131;
	// Declare a pointer to a FILE object
	FILE *log132;
	// Declare a pointer to a FILE object
	FILE *log133;
	// Declare a pointer to a FILE object
	FILE *log134;
	// Declare a pointer to a FILE object
	FILE *log135;
	// Declare a pointer to a FILE object
	FILE *log136;
	// Declare a pointer to a FILE object
	FILE *log137;
	// Declare a pointer to a FILE object
	FILE *log138;
	// Declare a pointer to a FILE object
	FILE *log139;
	// Declare a pointer to a FILE object
	FILE *log140;
	// Declare a pointer to a FILE object
	FILE *log141;
	// Declare a pointer to a FILE object
	FILE *log142;
	// Declare a pointer to a FILE object
	FILE *log143;
	// Declare a pointer to a FILE object
	FILE *log144;
	// Declare a pointer to a FILE object
	FILE *log145;
	// Declare a pointer to a FILE object
	FILE *log146;
	// Declare a pointer to a FILE object
	FILE *log147;
	// Declare a pointer to a FILE object
	FILE *log148;
	// Declare a pointer to a FILE object
	FILE *log149;
	// Declare a pointer to a FILE object
	FILE *log150;
	// Declare a pointer to a FILE object
	FILE *log151;
	// Declare a pointer to a FILE object
	FILE *log152;
	// Declare a pointer to a FILE object
	FILE *log153;
	// Declare a pointer to a FILE object
	FILE *log154;
	// Declare a pointer to a FILE object
	FILE *log155;
	// Declare a pointer to a FILE object
	FILE *log156;
	// Declare a pointer to a FILE object
	FILE *log157;
	// Declare a pointer to a FILE object
	FILE *log158;
	// Declare a pointer to a FILE object