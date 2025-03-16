
<<<<<<< HEAD
import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
=======
package main
import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
>>>>>>> 98c87cb78a (data updated)
)

// Function to read input from stdin
func readInput(reader *bufio.Reader) (X, Y, Z, K int) {
<<<<<<< HEAD
    fmt.Fscanln(reader, &X)
    fmt.Fscanln(reader, &Y)
    fmt.Fscanln(reader, &Z)
    fmt.Fscanln(reader, &K)
    return
}

// Function to print output to stdout
func printOutput(writer *bufio.Writer, result []int) {
    for _, val := range result {
        fmt.Fprintln(writer, val)
    }
}

// Function to sort a given array in descending order
func sortArray(arr []int) {
    sort.Slice(arr, func(i, j int) bool {
        return arr[i] > arr[j]
    })
}

// Function to add each element of A to each element of B
func addElements(A []int, B []int) []int {
    var AB []int
    for _, a := range A {
        for _, b := range B {
            AB = append(AB, a+b)
        }
    }
    return AB
}

// Function to add each element of AB to each element of C
func addElements2(AB []int, C []int) []int {
    var ABC []int
    for _, ab := range AB {
        for _, c := range C {
            ABC = append(ABC, ab+c)
        }
    }
    return ABC
=======
	// Read X, Y, Z, and K from standard input
	fmt.Fscanln(reader, &X)
	fmt.Fscanln(reader, &Y)
	fmt.Fscanln(reader, &Z)
	fmt.Fscanln(reader, &K)
	return
}

// Function to print output to stdout
func printOutput(writer *bufio.Writer, ABC []int) {
	// Print K smallest elements of vector ABC
	for _, a := range ABC[:K] {
		fmt.Fprintln(writer, a)
	}
>>>>>>> 98c87cb78a (data updated)
}

// Main function starts here
func main() {
<<<<<<< HEAD
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    X, Y, Z, K := readInput(reader)
    A := make([]int, X)
    B := make([]int, Y)
    C := make([]int, Z)
    for i := 0; i < X; i++ {
        fmt.Fscanln(reader, &A[i])
    }
    for i := 0; i < Y; i++ {
        fmt.Fscanln(reader, &B[i])
    }
    for i := 0; i < Z; i++ {
        fmt.Fscanln(reader, &C[i])
    }
    sort.Slice(A, func(i, j int) bool {
        return A[i] > A[j]
    })
    sort.Slice(B, func(i, j int) bool {
        return B[i] > B[j]
    })
    sort.Slice(C, func(i, j int) bool {
        return C[i] > C[j]
    })
    AB := addElements(A, B)
    sortArray(AB)
    ABC := addElements2(AB, C)
    sortArray(ABC)
    printOutput(writer, ABC[:K])
    writer.Flush()
=======
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	X, Y, Z, K := readInput(reader)

	// Initialize vectors A, B, and C
	A := make([]int, X) // A vector of size X, initialized with zeroes
	B := make([]int, Y) // B vector of size Y, initialized with zeroes
	C := make([]int, Z) // C vector of size Z, initialized with zeroes

	// Read input values for vectors A, B, and C from standard input
	for i := 0; i < X; i++ {
		fmt.Fscanln(reader, &A[i])
	}
	for i := 0; i < Y; i++ {
		fmt.Fscanln(reader, &B[i])
	}
	for i := 0; i < Z; i++ {
		fmt.Fscanln(reader, &C[i])
	}

	// Sort vectors A, B, and C in descending order
	sort.Slice(A, func(i, j int) bool { return A[i] > A[j] })
	sort.Slice(B, func(i, j int) bool { return B[i] > B[j] })
	sort.Slice(C, func(i, j int) bool { return C[i] > C[j] })

	// Create a new vector AB by adding each element of A to each element of B
	AB := make([]int, 0)
	for i := 0; i < X; i++ {
		for j := 0; j < Y; j++ {
			AB = append(AB, A[i]+B[j]) // Add A[i] and B[j] and push the sum into vector AB
		}
	}

	// Sort vector AB in descending order
	sort.Slice(AB, func(i, j int) bool { return AB[i] > AB[j] })

	// Create a new vector ABC by adding each element of AB to each element of C
	ABC := make([]int, 0)
	for i := 0; i < min(K, len(AB)); i++ {
		for j := 0; j < Z; j++ {
			ABC = append(ABC, AB[i]+C[j]) // Add AB[i] and C[j] and push the sum into vector ABC
		}
	}

	// Sort vector ABC in descending order
	sort.Slice(ABC, func(i, j int) bool { return ABC[i] > ABC[j] })

	// Print K smallest elements of vector ABC
	printOutput(bufio.NewWriter(os.Stdout), ABC)
>>>>>>> 98c87cb78a (data updated)
}

