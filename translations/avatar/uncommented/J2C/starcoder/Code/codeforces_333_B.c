#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>

#define MAX 1000000000
#define MOD 1000000007
#define MIN -1000000000

typedef struct {
    int row;
    int col;
} Point;

typedef struct {
    int row;
    int col;
    int val;
} Cell;

typedef struct {
    int row;
    int col;
    int val;
} Pair;

typedef struct {
    int row;
    int col;
    int val;
} Triplet;

typedef struct {
    int row;
    int col;
    int val;
} Quadruplet;

typedef struct {
    int row;
    int col;
    int val;
} Quintuplet;

typedef struct {
    int row;
    int col;
    int val;
} Sextuplet;

typedef struct {
    int row;
    int col;
    int val;
} Septuplet;

typedef struct {
    int row;
    int col;
    int val;
} Octuplet;

typedef struct {
    int row;
    int col;
    int val;
} Nonuplet;

typedef struct {
    int row;
    int col;
    int val;
} Decuplet;

typedef struct {
    int row;
    int col;
    int val;
} Undecuplet;

typedef struct {
    int row;
    int col;
    int val;
} Duodecuplet;

typedef struct {
    int row;
    int col;
    int val;
} Tredecuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quattuordecuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quindecuplet;

typedef struct {
    int row;
    int col;
    int val;
} Sexdecuplet;

typedef struct {
    int row;
    int col;
    int val;
} Septendecuplet;

typedef struct {
    int row;
    int col;
    int val;
} Octodecuplet;

typedef struct {
    int row;
    int col;
    int val;
} Novemdecuplet;

typedef struct {
    int row;
    int col;
    int val;
} Viginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Unviginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Duoviginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Treviginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quattuorviginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quinviginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Sexviginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Septenviginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Octoviginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Novemviginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Trigintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Untrigintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Duotrigintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Tretrigintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quattuortrigintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quintotrigintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Sextotrigintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Septentrigintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Octotrigintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Novemtrigintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quadragintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Unquadragintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Duoquadragintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Trequadragintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quattuorquadragintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quinquadragintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Sexquadragintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Septenquadragintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Octoquadragintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Novemquadragintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quinquagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Unquinquagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Duoquinquagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Trequinquagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quattuorquinquagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quinquinquagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Sexquinquagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Septenquinquagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Octoquinquagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Novemquinquagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Sexagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Unsexagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Duosexagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Tresexagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quattuorsexagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quinsexagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Sexsexagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Septensexagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Octosexagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Novemsexagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Septuagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Unseptuagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Duoseptuagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Treseptuagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quattuorseptuagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quinseptuagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Sexseptuagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Septenseptuagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Octoseptuagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Novemseptuagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Octogintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Unoctogintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Duooctogintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Trequoctogintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quattuoroctogintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quinoctogintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Sexoctogintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Septenoctogintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Octooctogintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Novemoctogintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Nonagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Unnonagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Duononagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Trenonagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quattuornonagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quinnonagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Sexnonagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Septennonagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Octononagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Novemnonagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Decagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Undecagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Duodecagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Tredecagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quattuordecagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quindecagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Sexdecagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Septendecagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Octodecagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Novemdecagintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Viginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Unviginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Duoviginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Treviginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quattuorviginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Quinviginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Sexviginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Septenviginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Octoviginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Novemviginticuplet;

typedef struct {
    int row;
    int col;
    int val;
} Trigintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Untrigintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Duotrigintacuplet;

typedef struct {
    int row;
    int col;
    int val;
} Tretrigintacuplet;

typedef struct {
    