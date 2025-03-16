#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>

#define N_MAX (100)
#define P_MAX (100)
#define DP_ARRAY_SIZE (N_MAX * P_MAX / 32 + 1)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define ABSS(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

func strrstr(string, pattern string) string {
	offset := 0
	lastP := ""

	searchResult := ""
	for searchResult = strings.Index(string[offset:], pattern); searchResult != -1 && string[offset] != '\0'; {
		lastP = searchResult
		offset++
	}

	return lastP
}

func compare_f(a, b interface{}) int {
	return *a.(int) < *b.(int) ? -1 : 1
}

func comb(n, r int) int {
	result := 1

	for i := 0; i < r; i++ {
		result *= n - i
		result /= i + 1
	}

	return result
}

func gcd(m, n int) int {
	temp := 0

	for m%n != 0 {
		temp = n
		n = m % n
		m = temp
	}

	return n
}

func main() {
	patternBase := "keyence"
	top := make([]byte, 8)
	bottom := make([]byte, 8)
	S := make([]byte, 101)

	_, err := fmt.Scanf("%s", &S)
	if err != nil {
		panic(err)
	}

	len := len(S)
	found := false

	for offset := 0; offset < len(patternBase); offset++ {
		copy(top, patternBase[:offset])
		top[offset] = '\0'
		copy(bottom, patternBase[offset:])
		bottom[len(patternBase) - offset] = '\0'

		topSearch := strings.Index(string(S), string(top))
		if topSearch != -1 {
			bottomSearch := strrstr(string(S[topSearch:]), string(bottom))
			if bottomSearch != "" {
				sepCount := 0

				if topSearch != 0 {
					sepCount++
				}
				if bottomSearch != string(S[topSearch+offset:]) {
					sepCount++
				}
				if bottomSearch[len(bottom)] != '\0' {
					sepCount++
				}

				if sepCount <= 1 {
					found = true
					break
				}
			}
		}
	}

	fmt.Println((found ? "YES" : "NO"))

	return 0
}

