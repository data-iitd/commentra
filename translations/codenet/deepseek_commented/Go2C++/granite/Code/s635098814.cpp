
#include <bits/stdc++.h>
using namespace std;

// Package and Imports
// The code starts with the package declaration and includes necessary libraries.
// This is a common setup for competitive programming in C++.

/*********** I/O ***********/

// ReadString returns a WORD string.
string ReadString() {
    string s;
    cin >> s;
    return s;
}

// Initialization
// The `init` function sets up the input reader and the output writer.
// This is a good practice for competitive programming to ensure efficient input and output handling.

// Input Functions
// The code includes various functions to read different types of inputs: integers, float numbers, strings, and slices of these types.
// This is useful for competitive programming where inputs can be large and need to be read efficiently.

// ReadInt returns an integer.
int ReadInt() {
    int i;
    cin >> i;
    return i;
}

// ReadIntSlice returns an integer slice that has n integers.
vector<int> ReadIntSlice(int n) {
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    return b;
}

// ReadFloat64 returns an float64.
double ReadFloat64() {
    double f;
    cin >> f;
    return f;
}

// ReadFloat64Slice returns an float64 slice that has n float64.
vector<double> ReadFloat64Slice(int n) {
    vector<double> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    return b;
}

// ReadruneSlice returns a rune slice.
string ReadruneSlice() {
    string s;
    cin >> s;
    return s;
}

// Debugging Functions
// The code includes functions for zero-padding and for checking and updating minimum and maximum values, which can be useful for debugging and competitive programming.

// ZeroPaddingRuneSlice returns binary expressions of integer n with zero padding.
// For debugging use.
string ZeroPaddingRuneSlice(int n, int digitsNum) {
    bitset<64> bs(n);
    string s = bs.to_string();
    s = string(digitsNum - s.length(), '0') + s;
    return s;
}

// DP sub-functions
// Functions related to dynamic programming can be included here.

// ChMin accepts a pointer of integer and a target value.
// If target value is SMALLER than the first argument,
//	then the first argument will be updated by the second argument.
bool ChMin(int* updatedValue, int target) {
    if (*updatedValue > target) {
        *updatedValue = target;
        return true;
    }
    return false;
}

// ChMax accepts a pointer of integer and a target value.
// If target value is LARGER than the first argument,
//	then the first argument will be updated by the second argument.
bool ChMax(int* updatedValue, int target) {
    if (*updatedValue < target) {
        *updatedValue = target;
        return true;
    }
    return false;
}

// NthBit returns nth bit value of an argument.
// n starts from 0.
int NthBit(int num, int nth) {
    return (num >> nth) & 1;
}

// OnBit returns the integer that has nth ON bit.
// If an argument has nth ON bit, OnBit returns the argument.
int OnBit(int num, int nth) {
    return num | (1 << nth);
}

// OffBit returns the integer that has nth OFF bit.
// If an argument has nth OFF bit, OffBit returns the argument.
int OffBit(int num, int nth) {
    return num & ~(1 << nth);
}

// PopCount returns the number of ON bit of an argument.
int PopCount(int num) {
    int res = 0;
    for (int i = 0; i < 70; i++) {
        if ((num >> i) & 1) {
            res++;
        }
    }
    return res;
}

// Arithmetic Functions
// The code includes functions for arithmetic operations such as maximum and minimum values, digit sums, powers, absolute values, and more.
// These are useful for competitive programming where quick calculations are necessary.

// Max returns the max integer among input set.
// This function needs at least 1 argument (no argument causes panic).
int Max(int a, int b) {
    return a > b? a : b;
}

// Min returns the min integer among input set.
// This function needs at least 1 argument (no argument causes panic).
int Min(int a, int b) {
    return a < b? a : b;
}

// DigitSum returns digit sum of a decimal number.
// DigitSum only accept a positive integer.
int DigitSum(int n) {
    if (n < 0) {
        return -1;
    }

    int res = 0;

    for (n; n > 0; n /= 10) {
        res += n % 10;
    }

    return res;
}

// DigitNumOfDecimal returns digits number of n.
// n is non negative number.
int DigitNumOfDecimal(int n) {
    int res = 0;

    for (n; n > 0; n /= 10) {
        res++;
    }

    return res;
}

// Sum returns multiple integers sum.
int Sum(int a, int b) {
    return a + b;
}

// Kiriage returns Ceil(a/b)
// a >= 0, b > 0
int Kiriage(int a, int b) {
    return (a + b - 1) / b;
}

// PowInt is integer version of math.Pow
// PowInt calculate a power by Binary Power (二分累乗法(O(log e))).
func PowInt(a, e int) int {
    if a < 0 || e < 0 {
        panic(errors.New("[argument error]: PowInt does not accept negative integers"))
    }

    if e == 0 {
        return 1
    }

    if e%2 == 0 {
        halfE := e / 2
        half := PowInt(a, halfE)
        return half * half
    }

    return a * PowInt(a, e-1)
}

// AbsInt is integer version of math.Abs
func AbsInt(a int) int {
    if a < 0 {
        panic(errors.New("[argument error]: AbsInt does not accept negative integers"))
    }

    return a
}

// Gcd returns the Greatest Common Divisor of two natural numbers.
// Gcd only accepts two natural numbers (a, b int) int {
    if a < 0 || b < 0 {
        panic(errors.New("[argument error]: Gcd only accepts two natural numbers"))
    }

    if a == 0 {
        return 1
    }

    if a%2 == 0 {
        halfA := a / 2
        halfB := b / 2
        return Gcd(halfA, halfB)
    }

    return a * b
}

// Lcm returns the Least Common Multiple of two natural numbers.
// Lcm only accepts two natural numbers (a, b int) int {
    if a < 0 || b < 0 {
        panic(errors.New("[argument error]: Lcm only accepts two natural numbers"))
    }

    if a < 0 {
        return a * Lcm(a, b-1)
}

// Strtoi is a wrapper of strconv.Atoi().
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts integer string.
// If strconv.Atoi() returns an error, Strtoi only accepts 