
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import (
	"fmt"
	"strings"
)
<<<<<<< HEAD

func main() {
	// read string a from standard input
	var a string
	fmt.Scanf("%s", &a)
	n := len(a) // get the length of string a

	// read string b from standard input
	var b string
	fmt.Scanf("%s", &b)
	m := len(b) // get the length of string b

	// iterate through all possible substrings of string a that have the same length as string b
	for i := 1; i+m-1 <= n; i++ {
		// initialize sum to 0, it will be used to count the number of differences between the i-th substring of string a and string b
		sum := 0

		// iterate through each character in the substring of string a and compare it with the corresponding character in string b
		for j := 1; j <= m; j++ {
			// if the characters are different, increment sum by 1
			if a[i+j-1]!= b[j] {
				sum++
			}
		}

		// update the minimum number of differences if a smaller number is found
		if sum < ans {
			ans = sum
		}
	}

	// print the minimum number of differences to standard output
	fmt.Printf("%d\n", ans)
}

=======
const M=1010
func main() {
	var a,b string
	fmt.Scanf("%s", &a)
	n:=len(a)
	fmt.Scanf("%s", &b)
	m:=len(b)
	for i:=1;i+m-1<=n;i++ {
		sum:=0
		for j:=1;j<=m;j++ {
			if a[i+j-1]!=b[j] {
				sum++
			}
		}
		ans:=min(ans,sum)
	}
	fmt.Printf("%d\n", ans)
}

func min(a,b int) int {
	if a<b {
		return a
	}
	return b
}

>>>>>>> 98c87cb78a (data updated)
