// Ask the user for the size of the permutation list
n := int(input())

// Import the itertools module for generating permutations
import "itertools"

// Create a list of all possible permutations of numbers from 1 to n
orig := make([][]int, 0)
for _, p := range itertools.Permutations(make([]int, n), n) {
    orig = append(orig, p)
}

// Ask the user for two permutations as tuples
p := make([]int, n)
q := make([]int, n)
for i := 0; i < n; i++ {
    p[i], q[i] = int(input()), int(input())
}

// Find the indices of p and q in the orig list
pn := -1
for i, o := range orig {
    if reflect.DeepEqual(o, p) {
        pn = i
    }
}

// Find the indices of p and q in the orig list
qn := -1
for i, o := range orig {
    if reflect.DeepEqual(o, q) {
        qn = i
    }
}

// Print the absolute difference between the indices of p and q
fmt.Println(abs(pn - qn))

