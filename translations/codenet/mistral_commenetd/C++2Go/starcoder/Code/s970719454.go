
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Defining macros for for loops
#define reps(i,f,n) for i:=f;i<n;i++
#define rep(i,n) reps(i,0,n)

func main() {
	// Reading input
	for {
		var n, m int
		_, err := fmt.Scanf("%d %d", &n, &m)
		if err!= nil || n == 0 {
			break
		}

		// Initializing arrays
		here := make([]int, 100001)
		dp1 := make([]int, 100001)
		dp2 := make([]int, 100001)

		// Initializing all elements of the arrays to zero
		rep(i, 100001) {
			here[i] = 0
			dp1[i] = 0
			dp2[i] = 0
		}

		// Reading number of houses and queries
		dpflg := false

		// Reading queries
		for i := 0; i < m; i++ {
			var a int
			_, err := fmt.Scanf("%d", &a)
			if err!= nil {
				break
			}
			// Setting the corresponding element of 'here' array to 1
			here[a] = 1
			// If a query is to find the maximum length of a subsequence without any house, then setting 'dpflg' to true
			if a == 0 {
				dpflg = true
			}
		}

		// Calculating the maximum length of a subsequence without any house
		maxi1 := 0
		rep(i, 1, n+1) {
			if here[i] == 1 {
				dp1[i] = dp1[i-1] + 1
			}
			maxi1 = max(maxi1, dp1[i])
		}

		// Calculating the maximum length of a subsequence with at least one house
		maxi2 := 0
		rep(i, 1, n+1) {
			if here[i] == 1 {
				dp2[i] = dp2[i-1] + 1
			} else {
				dp2[i] = dp1[i-1] + 1
			}
			maxi2 = max(maxi2, dp2[i])
		}

		// Printing the result
		if!dpflg {
			fmt.Printf("%d\n", maxi1)
		} else {
			fmt.Printf("%d\n", maxi2)
		}
	}
}

