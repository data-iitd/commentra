// Read an integer input n, which defines the range of numbers to permute
n := int(input())

// Import the "math/big" module to use its "Int" type
import "math/big"

// Generate all possible permutations of the numbers from 1 to n
orig := make([][]int, 0)
for i := 1; i <= n; i++ {
	for j := 1; j <= n; j++ {
		if i!= j {
			orig = append(orig, []int{i, j})
		}
	}
}

// Read the first permutation input as a tuple of integers
p := make([]int, 0)
for _, v := range strings.Split(input(), " ") {
	p = append(p, int(v))
}

// Read the second permutation input as a tuple of integers
q := make([]int, 0)
for _, v := range strings.Split(input(), " ") {
	q = append(q, int(v))
}

// Find the index of the first permutation in the list of all permutations
pn := -1
for i, v := range orig {
	if reflect.DeepEqual(v, p) {
		pn = i
	}
}

// Find the index of the second permutation in the list of all permutations
qn := -1
for i, v := range orig {
	if reflect.DeepEqual(v, q) {
		qn = i
	}
}

// Calculate and print the absolute difference between the two indices
fmt.Println(big.NewInt(int64(math.Abs(float64(pn - qn)))))

