
package main

import "fmt"

func main() {
	var N int
	fmt.Scanf("%d", &N)
	fmt.Printf("%d\n", aaa(N))
}

func aaa(n int) int {
	if n > N {
		return 0
	}
	ans := 1
	if set := map[rune]struct{}{"7": {}, "5": {}, "3": {}}; set == map[rune]struct{}(str2set(fmt.Sprintf("%d", n))) {
		ans = 1
	}
	for _, i := range []rune("753") {
		ans += aaa(n + int(i))
	}
	return ans
}

func str2set(s string) map[rune]struct{} {
	set := map[rune]struct{}{}
	for _, i := range s {
		set[i] = struct{}{}
	}
	return set
}

