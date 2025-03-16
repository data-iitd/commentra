
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type node struct {
	key  int
	next *node
	prev *node
}

var head *node

func main() {
	var i, n, a int
	var op string
	var x *node

	// Initialize the head node
	head = &node{key: 0}
	head.next = head
	head.prev = head

	// Read the number of operations
	fmt.Scan(&n)
	for i = 0; i < n; i++ {
		// Read the operation type
		fmt.Scan(&op)
		if op == "insert" {
			// Read the value to insert
			fmt.Scan(&a)
			insert(a)
		} else if op == "delete" {
			// Read the value to delete
			fmt.Scan(&a)
			delete(a)
		} else if op == "deleteFirst" {
			deleteFirst()
		} else if op == "deleteLast" {
			deleteLast()
		}
	}

	// Print the list
	x = head
	for x.next!= head {
		fmt.Printf("%d", x.next.key)
		x = x.next
		if x.next!= head {
			fmt.Printf(" ")
		}
	}
	fmt.Println()
}

// Function to create a new node with the given key
func makenode(a int) *node {
	x := new(node) // Allocate memory for the new node
	x.key = a       // Set the key of the new node
	x.next = nil   // Initialize next pointer to nil
	x.prev = nil   // Initialize prev pointer to nil
	return x         // Return the pointer to the new node
}

// Function to insert a new node with the given key after the head node
func insert(a int) {
	x := makenode(a) // Create a new node
	x.next = head.next
	head.next.prev = x
	head.next = x
	x.prev = head
}

// Function to delete the node with the given key
func delete(a int) {
	x := head
	for x.next!= head {
		x = x.next
		if x.key == a {
			x.prev.next = x.next
			x.next.prev = x.prev
			free(x)
			break
		}
	}
}

// Function to delete the first node after the head node
func deleteFirst() {
	x := head.next
	head.next = x.next
	x.next.prev = head
	free(x)
}

// Function to delete the last node before the head node
func deleteLast() {
	x := head.prev
	head.prev = x.prev
	x.prev.next = head
	free(x)
}

// Function to free the memory of a node
func free(x *node) {
	// Implement the free function to deallocate the memory of a node
}

// Function to read a string from the standard input
func readString() string {
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
	return strings.TrimSpace(str)
}

// Function to read an integer from the standard input
func readInt() int {
	str := readString()
	result, _ := strconv.Atoi(str)
	return result
}

// Function to read a float64 from the standard input
func readFloat64() float64 {
	str := readString()
	result, _ := strconv.ParseFloat(str, 64)
	return result
}

// Function to read a string array from the standard input
func readStringArray() []string {
	str := readString()
	return strings.Split(str, " ")
}

// Function to read an integer array from the standard input
func readIntArray() []int {
	strArray := readStringArray()
	result := make([]int, len(strArray))
	for i, str := range strArray {
		result[i], _ = strconv.Atoi(str)
	}
	return result
}

// Function to read a float64 array from the standard input
func readFloat64Array() []float64 {
	strArray := readStringArray()
	result := make([]float64, len(strArray))
	for i, str := range strArray {
		result[i], _ = strconv.ParseFloat(str, 64)
	}
	return result
}

// Function to print the given string to the standard output
func println(str string) {
	fmt.Println(str)
}

// Function to print the given integer to the standard output
func print(a int) {
	fmt.Print(a)
}

// Function to print the given float64 to the standard output
func printf(format string, a float64) {
	fmt.Printf(format, a)
}

// Function to print the given string array to the standard output
func printArray(a []string) {
	fmt.Println(strings.Join(a, " "))
}

// Function to print the given integer array to the standard output
func printIntArray(a []int) {
	fmt.Println(strings.Join(convert.IntSliceToStringSlice(a), " "))
}

// Function to print the given float64 array to the standard output
func printFloat64Array(a []float64) {
	fmt.Println(strings.Join(convert.Float64SliceToStringSlice(a), " "))
}

// Function to convert an integer array to a string array
func convert.IntSliceToStringSlice(a []int) []string {
	result := make([]string, len(a))
	for i, v := range a {
		result[i] = strconv.Itoa(v)
	}
	return result
}

// Function to convert a float64 array to a string array
func convert.Float64SliceToStringSlice(a []float64) []string {
	result := make([]string, len(a))
	for i, v := range a {
		result[i] = strconv.FormatFloat(v, 'f', 6, 64)
	}
	return result
}

// Function to convert a string array to an integer array
func convert.StringSliceToIntSlice(a []string) []int {
	result := make([]int, len(a))
	for i, v := range a {
		result[i], _ = strconv.Atoi(v)
	}
	return result
}

// Function to convert a string array to a float64 array
func convert.StringSliceToFloat64Slice(a []string) []float64 {
	result := make([]float64, len(a))
	for i, v := range a {
		result[i], _ = strconv.ParseFloat(v, 64)
	}
	return result
}

// Function to read a line from the standard input
func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
	return strings.TrimSpace(str)
}

// Function to read a byte array from the standard input
func readByteArray() []byte {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return b[:len(b)-1]
}

// Function to read a byte slice from the standard input
func readByteSlice() []byte {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return b[:len(b)-1]
}

// Function to read a rune array from the standard input
func readRuneArray() []rune {
	reader := bufio.NewReader(os.Stdin)
	r, _, _ := reader.ReadRune()
	return []rune(string(r))
}

// Function to read a rune slice from the standard input
func readruneSlice() []rune {
	reader := bufio.NewReader(os.Stdin)
	r, _, _ := reader.ReadRune()
	return []rune(string(r))
}

// Function to read a character array from the standard input
func readCharArray() []byte {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return b[:len(b)-1]
}

// Function to read a character slice from the standard input
func readCharSlice() []byte {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return b[:len(b)-1]
}

// Function to read a boolean array from the standard input
func readBoolArray() []bool {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return []bool{b[0] == '1'}
}

// Function to read a boolean slice from the standard input
func readBoolSlice() []bool {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return []bool{b[0] == '1'}
}

// Function to read a complex64 array from the standard input
func readComplex64Array() []complex64 {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return []complex64{complex(0, 0)}
}

// Function to read a complex64 slice from the standard input
func readComplex64Slice() []complex64 {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return []complex64{complex(0, 0)}
}

// Function to read a complex128 array from the standard input
func readComplex128Array() []complex128 {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return []complex128{complex(0, 0)}
}

// Function to read a complex128 slice from the standard input
func readComplex128Slice() []complex128 {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return []complex128{complex(0, 0)}
}

// Function to read a time.Time array from the standard input
func readTimeTimeArray() []time.Time {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return []time.Time{time.Now()}
}

// Function to read a time.Time slice from the standard input
func readTimeTimeSlice() []time.Time {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return []time.Time{time.Now()}
}

// Function to read a type A from the standard input
func readTypeA() A {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return A{}
}

// Function to read a type B from the standard input
func readTypeB() B {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return B{}
}

// Function to read a type C from the standard input
func readTypeC() C {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return C{}
}

// Function to read a type D from the standard input
func readTypeD() D {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return D{}
}

// Function to read a type E from the standard input
func readTypeE() E {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return E{}
}

// Function to read a type F from the standard input
func readTypeF() F {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return F{}
}

// Function to read a type G from the standard input
func readTypeG() G {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return G{}
}

// Function to read a type H from the standard input
func readTypeH() H {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return H{}
}

// Function to read a type I from the standard input
func readTypeI() I {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return I{}
}

// Function to read a type J from the standard input
func readTypeJ() J {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return J{}
}

// Function to read a type K from the standard input
func readTypeK() K {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return K{}
}

// Function to read a type L from the standard input
func readTypeL() L {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return L{}
}

// Function to read a type M from the standard input
func readTypeM() M {
	reader := bufio.NewReader(os.Stdin)
	b, _ := reader.ReadBytes('\n')
	return M{}
}

// Function to read a type N from the standard input
func readTypeN() N {
	reader := bufio.NewReader(