
#include <stdio.h>
#include <math.h>

int main() {
    // Read an integer n from the standard input
    int n;
    scanf("%d", &n);
    
    // Calculate the square root of n and store it in rt
    int rt = sqrt(n);
    
    // Initialize minf to 100, which will hold the minimum number of digits
    int minf = 100;
    
    // Iterate from 1 to rt + 1 to find divisors of n
    for (int i = 1; i < rt + 1; i++) {
        if (n % i == 0) {
            // If i is a divisor of n, calculate the quotient b
            int b = n / i;
            
            // Count the number of digits in b
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++;
            }
            
            // Update minf with the minimum number of digits found
            minf = fmin(minf, ndigit);
        }
    }
    
    // Print the minimum number of digits
    printf("%d\n", minf);
    
    return 0;
}

// Read a line from the standard input
char line[1000000];
fgets(line, sizeof(line), stdin);

// Split the input line into a string array
char *token = strtok(line, " ");

// Read an integer from the standard input
int nextInt() {
    int n;
    scanf("%d", &n);
    return n;
}

// Read an integer array from the standard input
int *nextIntArray() {
    char *token = strtok(NULL, " ");
    int n = 0;
    while (token!= NULL) {
        n++;
        token = strtok(NULL, " ");
    }
    int *a = (int *)malloc(n * sizeof(int));
    token = strtok(NULL, " ");
    for (int i = 0; i < n; i++) {
        a[i] = atoi(token);
        token = strtok(NULL, " ");
    }
    return a;
}

// Return the minimum of two integers
int min(int i, int j) {
    return i < j? i : j;
}

// Return the minimum of two doubles
double fmin(double i, double j) {
    return i < j? i : j;
}

// Return the maximum of two integers
int max(int i, int j) {
    return i > j? i : j;
}

// Return the maximum of two doubles
double fmax(double i, double j) {
    return i > j? i : j;
}

// Return the absolute value of an integer
int abs(int i) {
    return i < 0? -i : i;
}

// Return the absolute value of a double
double fabs(double i) {
    return i < 0? -i : i;
}

// Return the square root of a double
double sqrt(double i) {
    return sqrt(i);
}

// Return the cube root of a double
double cbrt(double i) {
    return cbrt(i);
}

// Return the remainder of the division of two integers
int mod(int i, int j) {
    return i % j;
}

// Return the remainder of the division of two doubles
double fmod(double i, double j) {
    return fmod(i, j);
}

// Return the sine of a double
double sin(double i) {
    return sin(i);
}

// Return the cosine of a double
double cos(double i) {
    return cos(i);
}

// Return the tangent of a double
double tan(double i) {
    return tan(i);
}

// Return the arcsine of a double
double asin(double i) {
    return asin(i);
}

// Return the arccosine of a double
double acos(double i) {
    return acos(i);
}

// Return the arctangent of a double
double atan(double i) {
    return atan(i);
}

// Return the hyperbolic sine of a double
double sinh(double i) {
    return sinh(i);
}

// Return the hyperbolic cosine of a double
double cosh(double i) {
    return cosh(i);
}

// Return the hyperbolic tangent of a double
double tanh(double i) {
    return tanh(i);
}

// Return the hyperbolic arcsine of a double
double asinh(double i) {
    return asinh(i);
}

// Return the hyperbolic arccosine of a double
double acosh(double i) {
    return acosh(i);
}

// Return the hyperbolic arctangent of a double
double atanh(double i) {
    return atanh(i);
}

// Return the exponential value of a double
double exp(double i) {
    return exp(i);
}

// Return the natural logarithm of a double
double log(double i) {
    return log(i);
}

// Return the base 10 logarithm of a double
double log10(double i) {
    return log10(i);
}

// Return the base 2 logarithm of a double
double log2(double i) {
    return log2(i);
}

// Return the power of a double to another double
double pow(double i, double j) {
    return pow(i, j);
}

// Return the square root of a double
double sqrt(double i) {
    return sqrt(i);
}

// Return the cube root of a double
double cbrt(double i) {
    return cbrt(i);
}

// Return the ceiling of a double
double ceil(double i) {
    return ceil(i);
}

// Return the floor of a double
double floor(double i) {
    return floor(i);
}

// Return the nearest integer to a double
int round(double i) {
    return round(i);
}

// Return the nearest integer to a double
int trunc(double i) {
    return trunc(i);
}

// Return the nearest integer to a double
int lround(double i) {
    return lround(i);
}

// Return the nearest integer to a double
int lrint(double i) {
    return lrint(i);
}

// Return the nearest integer to a double
int llround(double i) {
    return llround(i);
}

// Return the nearest integer to a double
int llrint(double i) {
    return llrint(i);
}

// Return the nearest integer to a double
int nearbyint(double i) {
    return nearbyint(i);
}

// Return the nearest integer to a double
int rint(double i) {
    return rint(i);
}

// Return the nearest integer to a double
long lrint(double i) {
    return lrint(i);
}

// Return the nearest integer to a double
long long llrint(double i) {
    return llrint(i);
}

// Return the nearest integer to a double
double frexp(double i, int *j) {
    return frexp(i, j);
}

// Return the nearest integer to a double
double ldexp(double i, int j) {
    return ldexp(i, j);
}

// Return the nearest integer to a double
double modf(double i, double *j) {
    return modf(i, j);
}

// Return the nearest integer to a double
double scalbn(double i, int j) {
    return scalbn(i, j);
}

// Return the nearest integer to a double
double scalbln(double i, long j) {
    return scalbln(i, j);
}

// Return the nearest integer to a double
doubleilogb(double i) {
    return ilogb(i);
}

// Return the nearest integer to a double
double logb(double i) {
    return logb(i);
}

// Return the nearest integer to a double
double nextafter(double i, double j) {
    return nextafter(i, j);
}

// Return the nearest integer to a double
double nexttoward(double i, long double j) {
    return nexttoward(i, j);
}

// Return the nearest integer to a double
double copysign(double i, double j) {
    return copysign(i, j);
}

// Return the nearest integer to a double
double nan(const char *j) {
    return nan(j);
}

// Return the nearest integer to a double
double nanf(const char *j) {
    return nanf(j);
}

// Return the nearest integer to a double
double nanl(const char *j) {
    return nanl(j);
}

// Return the nearest integer to a double
double j0(double i) {
    return j0(i);
}

// Return the nearest integer to a double
double j1(double i) {
    return j1(i);
}

// Return the nearest integer to a double
double jn(int i, double j) {
    return jn(i, j);
}

// Return the nearest integer to a double
double y0(double i) {
    return y0(i);
}

// Return the nearest integer to a double
double y1(double i) {
    return y1(i);
}

// Return the nearest integer to a double
double yn(int i, double j) {
    return yn(i, j);
}

// Return the nearest integer to a double
double erf(double i) {
    return erf(i);
}

// Return the nearest integer to a double
double erfc(double i) {
    return erfc(i);
}

// Return the nearest integer to a double
double lgamma(double i) {
    return lgamma(i);
}

// Return the nearest integer to a double
double tgamma(double i) {
    return tgamma(i);
}

// Return the nearest integer to a double
double gamma(double i) {
    return gamma(i);
}

// Return the nearest integer to a double
double hypot(double i, double j) {
    return hypot(i, j);
}

// Return the nearest integer to a double
double remainder(double i, double j) {
    return remainder(i, j);
}

// Return the nearest integer to a double
double remquo(double i, double j, int *k) {
    return remquo(i, j, k);
}

// Return the nearest integer to a double
double fdim(double i, double j) {
    return fdim(i, j);
}

// Return the nearest integer to a double
double fma(double i, double j, double k) {
    return fma(i, j, k);
}

// Return the nearest integer to a double
double fmax(double i, double j) {
    return fmax(i, j);
}

// Return the nearest integer to a double
double fmin(double i, double j) {
    return fmin(i, j);
}

// Return the nearest integer to a double
double scalbn(double i, int j) {
    return scalbn(i, j);
}

// Return the nearest integer to a double
double scalbln(double i, long j) {
    return scalbln(i, j);
}

// Return the nearest integer to a double
double cbrt(double i) {
    return cbrt(i);
}

// Return the nearest integer to a double
double hypot(double i, double j) {
    return hypot(i, j);
}

// Return the nearest integer to a double
double remainder(double i, double j) {
    return remainder(i, j);
}

// Return the nearest integer to a double
double remquo(double i, double j, int *k) {
    return remquo(i, j, k);
}

// Return the nearest integer to a double
double fdim(double i, double j) {
    return fdim(i, j);
}

// Return the nearest integer to a double
double fma(double i, double j, double k) {
    return fma(i, j, k);
}

// Return the nearest integer to a double
double fmax(double i, double j) {
    return fmax(i, j);
}

// Return the nearest integer to a double
double fmin(double i, double j) {
    return fmin(i, j);
}

// Return the nearest integer to a double
double scalbn(double i, int j) {
    return scalbn(i, j);
}

// Return the nearest integer to a double
double scalbln(double i, long j) {
    return scalbln(i, j);
}

// Return the nearest integer to a double
double cbrt(double i) {
    return cbrt(i);
}

// Return the nearest integer to a double
double hypot(double i, double j) {
    return hypot(i, j);
}

// Return the nearest integer to a double
double remainder(double i, double j) {
    return remainder(i, j);
}

// Return the nearest integer to a double
double remquo(double i, double j, 