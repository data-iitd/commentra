#include <bits/stdc++.h>
using namespace std;

#define I(x) scanf("%d", &x)  // Macro to read an integer input
#define II(x, y) scanf("%d %d", &x, &y)  // Macro to read two integer inputs
#define III(x, y, z) scanf("%d %d %d", &x, &y, &z)  // Macro to read three integer inputs
#define L(x) scanf("%lld", &x)  // Macro to read a long long input
#define LL(x, y) scanf("%lld %lld", &x, &y)  // Macro to read two long long inputs
#define LLL(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)  // Macro to read three long long inputs
#define D(x) scanf("%lf", &x)  // Macro to read a double input
#define DD(x, y) scanf("%lf %lf", &x, &y)  // Macro to read two double inputs
#define DDD(x, y, z) scanf("%lf %lf %lf", &x, &y, &z)  // Macro to read three double inputs
#define S(x) scanf("%s", x)  // Macro to read a string input
#define SS(x, y) scanf("%s %s", x, y)  // Macro to read two string inputs
#define SSS(x, y, z) scanf("%s %s %s", x, y, z)  // Macro to read three string inputs
#define PI(x) printf("%d\n", x)  // Macro to print an integer input
#define PII(x, y) printf("%d %d\n", x, y)  // Macro to print two integer inputs
#define PIII(x, y, z) printf("%d %d %d\n", x, y, z)  // Macro to print three integer inputs
#define PL(x) printf("%lld\n", x)  // Macro to print a long long input
#define PLL(x, y) printf("%lld %lld\n", x, y)  // Macro to print two long long inputs
#define PLLL(x, y, z) printf("%lld %lld %lld\n", x, y, z)  // Macro to print three long long inputs
#define PD(x) printf("%.10lf\n", x)  // Macro to print a double input
#define PDD(x, y) printf("%.10lf %.10lf\n", x, y)  // Macro to print two double inputs
#define PDDD(x, y, z) printf("%.10lf %.10lf %.10lf\n", x, y, z)  // Macro to print three double inputs
#define PS(x) printf("%s\n", x)  // Macro to print a string input
#define PSS(x, y) printf("%s %s\n", x, y)  // Macro to print two string inputs
#define PSSS(x, y, z) printf("%s %s %s\n", x, y, z)  // Macro to print three string inputs
#define PB(x) printf("%d\n", x)  // Macro to print a boolean input
#define PBB(x, y) printf("%d %d\n", x, y)  // Macro to print two boolean inputs
#define PBBB(x, y, z) printf("%d %d %d\n", x, y, z)  // Macro to print three boolean inputs
#define PI2(x) printf("%d %d\n", x, x)  // Macro to print an integer input twice
#define PII2(x, y) printf("%d %d %d %d\n", x, y, x, y)  // Macro to print two integer inputs twice
#define PIII2(x, y, z) printf("%d %d %d %d %d %d\n", x, y, z, x, y, z)  // Macro to print three integer inputs twice
#define PLL2(x) printf("%lld %lld\n", x, x)  // Macro to print a long long input twice
#define PLLL2(x, y) printf("%lld %lld %lld %lld\n", x, y, x, y)  // Macro to print two long long inputs twice
#define PLLLL2(x, y, z) printf("%lld %lld %lld %lld %lld %lld\n", x, y, z, x, y, z)  // Macro to print three long long inputs twice
#define PD2(x) printf("%.10lf %.10lf\n", x, x)  // Macro to print a double input twice
#define PDD2(x, y) printf("%.10lf %.10lf %.10lf %.10lf\n", x, y, x, y)  // Macro to print two double inputs twice
#define PDDD2(x, y, z) printf("%.10lf %.10lf %.10lf %.10lf %.10lf %.10lf\n", x, y, z, x, y, z)  // Macro to print three double inputs twice
#define PS2(x) printf("%s %s\n", x, x)  // Macro to print a string input twice
#define PSS2(x, y) printf("%s %s %s %s\n", x, y, x, y)  // Macro to print two string inputs twice
#define PSSS2(x, y, z) printf("%s %s %s %s %s %s\n", x, y, z, x, y, z)  // Macro to print three string inputs twice
#define PB2(x) printf("%d %d\n", x, x)  // Macro to print a boolean input twice
#define PBB2(x, y) printf("%d %d %d %d\n", x, y, x, y)  // Macro to print two boolean inputs twice
#define PBBB2(x, y, z) printf("%d %d %d %d %d %d\n", x, y, z, x, y, z)  // Macro to print three boolean inputs twice
#define PI3(x) printf("%d %d %d\n", x, x, x)  // Macro to print an integer input three times
#define PII3(x, y) printf("%d %d %d %d %d %d\n", x, y, x, y, x, y)  // Macro to print two integer inputs three times
#define PIII3(x, y, z) printf("%d %d %d %d %d %d %d %d %d\n", x, y, z, x, y, z, x, y, z)  // Macro to print three integer inputs three times
#define PLL3(x) printf("%lld %lld %lld\n", x, x, x)  // Macro to print a long long input three times
#define PLLL3(x, y) printf("%lld %lld %lld %lld %lld %lld\n", x, y, x, y, x, y)  // Macro to print two long long inputs three times
#define PLLLL3(x, y, z) printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld\n", x, y, z, x, y, z, x, y, z)  // Macro to print three long long inputs three times
#define PD3(x) printf("%.10lf %.10lf %.10lf\n", x, x, x)  // Macro to print a double input three times
#define PDD3(x, y) printf("%.10lf %.10lf %.10lf %.10lf %.10lf %.10lf\n", x, y, x, y, x, y)  // Macro to print two double inputs three times
#define PDDD3(x, y, z) printf("%.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf\n", x, y, z, x, y, z, x, y, z)  // Macro to print three double inputs three times
#define PS3(x) printf("%s %s %s\n", x, x, x)  // Macro to print a string input three times
#define PSS3(x, y) printf("%s %s %s %s %s %s\n", x, y, x, y, x, y)  // Macro to print two string inputs three times
#define PSSS3(x, y, z) printf("%s %s %s %s %s %s %s %s %s\n", x, y, z, x, y, z, x, y, z)  // Macro to print three string inputs three times
#define PB3(x) printf("%d %d %d\n", x, x, x)  // Macro to print a boolean input three times
#define PBB3(x, y) printf("%d %d %d %d %d %d\n", x, y, x, y, x, y)  // Macro to print two boolean inputs three times
#define PBBB3(x, y, z) printf("%d %d %d %d %d %d %d %d %d\n", x, y, z, x, y, z, x, y, z)  // Macro to print three boolean inputs three times
#define PI4(x) printf("%d %d %d %d\n", x, x, x, x)  // Macro to print an integer input four times
#define PII4(x, y) printf("%d %d %d %d %d %d %d %d\n", x, y, x, y, x, y, x, y)  // Macro to print two integer inputs four times
#define PIII4(x, y, z) printf("%d %d %d %d %d %d %d %d %d %d %d %d\n", x, y, z, x, y, z, x, y, z, x, y, z)  // Macro to print three integer inputs four times
#define PLL4(x) printf("%lld %lld %lld %lld\n", x, x, x, x)  // Macro to print a long long input four times
#define PLLL4(x, y) printf("%lld %lld %lld %lld %lld %lld %lld %lld\n", x, y, x, y, x, y, x, y)  // Macro to print two long long inputs four times
#define PLLLL4(x, y, z) printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld\n", x, y, z, x, y, z, x, y, z, x, y, z)  // Macro to print three long long inputs four times
#define PD4(x) printf("%.10lf %.10lf %.10lf %.10lf\n", x, x, x, x)  // Macro to print a double input four times
#define PDD4(x, y) printf("%.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf\n", x, y, x, y, x, y, x, y)  // Macro to print two double inputs four times
#define PDDD4(x, y, z) printf("%.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf\n", x, y, z, x, y, z, x, y, z, x, y, z)  // Macro to print three double inputs four times
#define PS4(x) printf("%s %s %s %s\n", x, x, x, x)  // Macro to print a string input four times
#define PSS4(x, y) printf("%s %s %s %s %s %s %s %s\n", x, y, x, y, x, y, x, y)  // Macro to print two string inputs four times
#define PSSS4(x, y, z) printf("%s %s %s %s %s %s %s %s %s %s %s %s\n", x, y, z, x, y, z, x, y, z, x, y, z)  // Macro to print three string inputs four times
#define PB4(x) printf("%d %d %d %d\n", x, x, x, x)  // Macro to print a boolean input four times
#define PBB4(x, y) printf("%d %d %d %d %d %d %d %d\n", x, y, x, y, x, y, x, y)  // Macro to print two boolean inputs four times
#define PBBB4(x, y, z) printf("%d %d %d %d %d %d %d %d %d %d %d %d\n", x, y, z, x, y, z, x, y, z, x, y, z)  // Macro to print three boolean inputs four times
#define PI5(x) printf("%d %d %d %d %d\n", x, x, x, x, x)  // Macro to print an integer input five times
#define PII5(x, y) printf("%d %d %d %d %d %d %d %d %d %d\n", x, y, x, y, x, y, x, y, x, y)  // Macro to print two integer inputs five times
#define PIII5(x, y, z) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", x, y, z, x, y, z, x, y, z, x, y, z, x, y, z)  // Macro to print three integer inputs five times
#define PLL5(x) printf("%lld %lld %lld %lld %lld\n", x, x, x, x, x)  // Macro to print a long long input five times
#define PLLL5(x, y) printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld\n", x, y, x, y, x, y, x, y, x, y)  // Macro to print two long long inputs five times
#define PLLLL5(x, y, z) printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld\n", x, y, z, x, y, z, x, y, z, x, y, z, x, y, z)  // Macro to print three long long inputs five times
#define PD5(x) printf("%.10lf %.10lf %.10lf %.10lf %.10lf\n", x, x, x, x, x)  // Macro to print a double input five times
#define PDD5(x, y) printf("%.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf\n", x, y, x, y, x, y, x, y, x, y)  // Macro to print two double inputs five times
#define PDDD5(x, y, z) printf("%.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf\n", x, y, z, x, y, z, x, y, z, x, y, z, x, y, z)  // Macro to print three double inputs five times
#define PS5(x) printf("%s %s %s %s %s\n", x, x, x, x, x)  // Macro to print a string input five times
#define PSS5(x, y) printf("%s %s %s %s %s %s %s %s %s %s\n", x, y, x, y, x, y, x, y, x, y)  // Macro to print two string inputs five times
#define PSSS5(x, y, z) printf("%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", x, y, z, x, y, z, x, y, z, x, y, z, x, y, z, x, y, z)  // Macro to print three string inputs five times
#define PB5(x) printf("%d %d %d %d %d\n", x, x, x, x, x)  // Macro to print a boolean input five times
#define PBB5(x, y) printf("%d %d %d %d %d %d %d %d %d %d\n", x, y, x, y, x, y, x, y, x, y)  // Macro to print two boolean inputs five times
#define PBBB5(x, y, z) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", x, y, z, x, y, z, x, y, z, x, y, z, x, y, z, x, y, z)  // Macro to print three boolean inputs five times
#def