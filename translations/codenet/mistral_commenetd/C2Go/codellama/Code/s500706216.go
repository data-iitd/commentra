#include <stdbool.h>
#include <stdio.h>

func main() {
	// Read input n and k
	var n, k int
	fmt.Scanf("%d%d", &n, &k)

	// Read input array a
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}

	// Initialize light array based on initial a array
	light := make([]int, n+1)
	for i := 0; i < n; i++ {
		r := i - a[i]
		l := i + a[i]
		light[(r < 0 ? 0 : r)]++
		light[(l + 1 > n ? n + 1 : l + 1)]--
	}

	// Perform k iterations
	for i := 0; i < k; i++ {
		// Initialize temporary array tmpa
		sum := 0
		tmpa := make([]int, n)
		for j := 0; j < n; j++ {
			tmpa[j] = a[j]
			sum += light[j]
			a[j] = sum
		}

		// Update light array based on new a array
		for j := 0; j < n; j++ {
			r := j - a[j]
			l := j + a[j]
			light[(r < 0 ? 0 : r)]--
			light[(l + 1 > n ? n + 1 : l + 1)]++
			r = j - a[j]
			l = j + a[j]
			light[(r < 0 ? 0 : r)]++
			light[(l + 1 > n ? n + 1 : l + 1)]--
		}

		// Check if a array is the same for all elements except the first one, and if the first element is equal to the size of the array
		isSame := true
		for j := 0; j < n-1; j++ {
			if a[j] != a[j+1] {
				isSame = false
				break
			}
		}
		if isSame && a[0] == n {
			break
		}
	}

	// Print out updated a array
	for j := 0; j < n; j++ {
		fmt.Printf("%d", a[j])
		fmt.Printf(j == n-1 ? "\n" : " ")
	}
}

