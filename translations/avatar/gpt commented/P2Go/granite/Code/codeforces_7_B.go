
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of operations (t) and the size of the array (m)
	t, m := readTwoInt()
	// Initialize an array to keep track of allocated memory blocks, initially all set to 0
	alocuente := make([]int, m)
	// Initialize an index to keep track of the next allocation identifier
	ind := 1

	// Process each operation
	for i := 0; i < t; i++ {
		// Read the operation and its parameters
		op := readLine()
		// Handle the 'alloc' operation
		if op[0] == "alloc" {
			pos := 0 // Position counter to find free blocks
			for j := 0; j < m; j++ {
				// Check if the current block is free (0)
				if alocuente[j] == 0 {
					pos++ // Increment the position counter
					// If we have found enough consecutive free blocks
					if pos == int64(op[1]) {
						// Allocate the blocks and set them to the current identifier
						for k := j - int64(op[1])+1; k <= j; k++ {
							alocuente[k] = int(ind)
						}
						fmt.Println(ind) // Output the identifier of the allocated blocks
						ind++ // Increment the identifier for the next allocation
						break
					}
				} else {
					pos = 0 // Reset position counter if a block is occupied
				}
			}
			if pos < int64(op[1]) {
				// If no sufficient space was found, output NULL
				fmt.Println("NULL")
			}
		}
		// Handle the 'erase' operation
		if op[0] == "erase" {
			pos := 0 // Position counter for finding the block to erase
			// Check if the identifier to erase is valid
			if int64(op[1]) <= 0 || int64(op[1]) > int64(ind) {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT") // Output error for illegal erase
			} else {
				// Iterate through the array to find and erase the specified block
				for j := 0; j < m; j++ {
					if int64(op[1]) == int64(alocuente[j]) {
						alocuente[j] = 0 // Set the block to 0 to indicate it is free
					}
				}
			}
		}
		// Handle the 'defragment' operation
		if op[0] == "defragment" {
			cnt := 0 // Counter for the number of free blocks
			cnt = count(alocuente, 0) // Count how many blocks are free
			// Create a new list with only the allocated blocks (non-zero)
			alocuente = make([]int, 0)
			for j := 0; j < m; j++ {
				if alocuente[j]!= 0 {
					alocuente = append(alocuente, alocuente[j])
				}
			}
			// Append the free blocks (0) back to the end of the list
			for j := 0; j < cnt; j++ {
				alocuente = append(alocuente, 0)
			}
		}
	}
}

func readLine() []string {
	_line := readLineSlice()
	line := make([]string, len(_line))
	for i, v := range _line {
		line[i] = string(v)
	}
	return line
}

func readLineSlice() []rune {
	buf := bufio.NewReader(os.Stdin)
	line, _, err := buf.ReadLine()
	if err!= nil {
		panic(err)
	}
	return line
}

func readInt() int {
	line := readLineSlice()
	i, err := strconv.Atoi(string(line[0]))
	if err!= nil {
		panic(err)
	}
	return i
}

func readTwoInt() (int, int) {
	line := readLineSlice()
	i, err := strconv.Atoi(string(line[0]))
	if err!= nil {
		panic(err)
	}
	j, err := strconv.Atoi(string(line[1]))
	if err!= nil {
		panic(err)
	}
	return i, j
}

func readThreeInt() (int, int, int) {
	line := readLineSlice()
	i, err := strconv.Atoi(string(line[0]))
	if err!= nil {
		panic(err)
	}
	j, err := strconv.Atoi(string(line[1]))
	if err!= nil {
		panic(err)
	}
	k, err := strconv.Atoi(string(line[2]))
	if err!= nil {
		panic(err)
	}
	return i, j, k
}

func readInt64() int64 {
	line := readLineSlice()
	i, err := strconv.ParseInt(string(line[0]), 10, 64)
	if err!= nil {
		panic(err)
	}
	return i
}

func readTwoInt64() (int64, int64) {
	line := readLineSlice()
	i, err := strconv.ParseInt(string(line[0]), 10, 64)
	if err!= nil {
		panic(err)
	}
	j, err := strconv.ParseInt(string(line[1]), 10, 64)
	if err!= nil {
		panic(err)
	}
	return i, j
}

func readThreeInt64() (int64, int64, int64) {
	line := readLineSlice()
	i, err := strconv.ParseInt(string(line[0]), 10, 64)
	if err!= nil {
		panic(err)
	}
	j, err := strconv.ParseInt(string(line[1]), 10, 64)
	if err!= nil {
		panic(err)
	}
	k, err := strconv.ParseInt(string(line[2]), 10, 64)
	if err!= nil {
		panic(err)
	}
	return i, j, k
}

func readFloat() float64 {
	line := readLineSlice()
	f, err := strconv.ParseFloat(string(line[0]), 64)
	if err!= nil {
		panic(err)
	}
	return f
}

func readTwoFloat() (float64, float64) {
	line := readLineSlice()
	f1, err := strconv.ParseFloat(string(line[0]), 64)
	if err!= nil {
		panic(err)
	}
	f2, err := strconv.ParseFloat(string(line[1]), 64)
	if err!= nil {
		panic(err)
	}
	return f1, f2
}

func readThreeFloat() (float64, float64, float64) {
	line := readLineSlice()
	f1, err := strconv.ParseFloat(string(line[0]), 64)
	if err!= nil {
		panic(err)
	}
	f2, err := strconv.ParseFloat(string(line[1]), 64)
	if err!= nil {
		panic(err)
	}
	f3, err := strconv.ParseFloat(string(line[2]), 64)
	if err!= nil {
		panic(err)
	}
	return f1, f2, f3
}

func readLineStr() string {
	line := readLineSlice()
	return string(line[0])
}

func readTwoLineStr() (string, string) {
	line := readLineSlice()
	return string(line[0]), string(line[1])
}

func readThreeLineStr() (string, string, string) {
	line := readLineSlice()
	return string(line[0]), string(line[1]), string(line[2])
}

func readLineStrSlice() []string {
	line := readLineSlice()
	strSlice := make([]string, len(line))
	for i, v := range line {
		strSlice[i] = string(v)
	}
	return strSlice
}

func readLineIntSlice() []int {
	line := readLineSlice()
	intSlice := make([]int, len(line))
	for i, v := range line {
		intSlice[i], _ = strconv.Atoi(string(v))
	}
	return intSlice
}

func readLineInt64Slice() []int64 {
	line := readLineSlice()
	int64Slice := make([]int64, len(line))
	for i, v := range line {
		int64Slice[i], _ = strconv.ParseInt(string(v), 10, 64)
	}
	return int64Slice
}

func readLineFloatSlice() []float64 {
	line := readLineSlice()
	floatSlice := make([]float64, len(line))
	for i, v := range line {
		floatSlice[i], _ = strconv.ParseFloat(string(v), 64)
	}
	return floatSlice
}

func count(s []int, e int) int {
	c := 0
	for _, v := range s {
		if v == e {
			c++
		}
	}
	return c
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func pow(x, n int) int {
	if n == 0 {
		return 1
	}
	tmp := pow(x, n/2)
	if n%2 == 0 {
		return tmp * tmp
	} else {
		return tmp * tmp * x
	}
}

func powMod(x, n, mod int) int {
	if n == 0 {
		return 1
	}
	tmp := powMod(x, n/2, mod)
	tmp %= mod
	if n%2 == 0 {
		return (tmp * tmp) % mod
	} else {
		return (tmp * tmp * x) % mod
	}
}

func formatInt(num int) string {
	return strconv.Itoa(num)
}

func formatInt64(num int64) string {
	return strconv.FormatInt(num, 10)
}

func formatFloat(num float64, digit int) string {
	return strconv.FormatFloat(num, 'f', digit, 64)
}

func formatUInt64(num uint64) string {
	return strconv.FormatUint(num, 10)
}

func formatBool(b bool) string {
	if b {
		return "TRUE"
	} else {
		return "FALSE"
	}
}

func formatStr(s string) string {
	return s
}

func formatStrSlice(s []string) string {
	return strings.Join(s, " ")
}

func formatIntSlice(s []int) string {
	a := make([]string, len(s))
	for i, v := range s {
		a[i] = strconv.Itoa(v)
	}
	return strings.Join(a, " ")
}

func formatInt64Slice(s []int64) string {
	a := make([]string, len(s))
	for i, v := range s {
		a[i] = strconv.FormatInt(v, 10)
	}
	return strings.Join(a, " ")
}

func formatFloatSlice(s []float64, digit int) string {
	a := make([]string, len(s))
	for i, v := range s {
		a[i] = strconv.FormatFloat(v, 'f', digit, 64)
	}
	return strings.Join(a, " ")
}

func formatBoolSlice(s []bool) string {
	a := make([]string, len(s))
	for i, v := range s {
		if v {
			a[i] = "TRUE"
		} else {
			a[i] = "FALSE"
		}
	}
	return strings.Join(a, " ")
}

func formatStrSlice(s []string) string {
	return strings.Join(s, " ")
}

func formatAnswer(a...interface{}) string {
	return strings.Join(formatArgs(a...), "\n")
}

func formatArgs(a...interface{}) []string {
	ret := make([]string, len(a))
	for i, v := range a {
		switch v.(type) {
		case int:
			ret[i] = formatInt(v.(int))
		case int64:
			ret[i] = formatInt64(v.(int64))
		case float64:
			ret[i] = formatFloat(v.(float64), 6)
		case uint64:
			ret[i] = formatUInt64(v.(uint64))
		case bool:
			ret[i] = formatBool(v.(bool))
		case string:
			ret[i] = formatStr(v.(string))
		case []string:
			ret[i] = formatStrSlice(v.([]string))
		case []int:
			ret[i] = formatIntSlice(v.([]int))
		case []int64:
			ret[i] = formatInt64Slice(v.([]int64))
		case []float64:
			ret[i] = formatFloatSlice(v.([]float64), 6)
		case []bool:
			ret[i] = formatBoolSlice(v.([]bool))
		}
	}
	return ret
}

func main() {
	// Read the number of operations (t) and the size of the array (m)
	t, m := readTwoInt()
	// Initialize an array to keep track of allocated memory blocks, initially all set to 0
	alocuente := make([]int, m)
	// Initialize an index to keep track of the next allocation identifier
	ind := 1

	// Process each operation
	for i := 0; i < t; i++ {
		// Read the operation and its parameters
		op := readLine()
		// Handle the 'alloc' operation
		if op[0] == "alloc" {
			pos := 0 // Position counter to find free blocks
			for j := 0; j < m; j++ {
				// Check if the current block is free (0)
				if alocuente[j] == 0 {
					pos++ // Increment the position counter
					// If we have found enough consecutive free blocks
					if pos == int64(op[1]) {
						// Allocate the blocks and set them to the current identifier
						for k := j - int64(op[1])+1; k <= j; k++ {
							alocuente[k] = int(ind)
						}
						fmt.Println(ind) // Output the identifier of the allocated blocks
						ind++ // Increment the identifier for the next allocation
						break
					}
				} else {
					pos = 0 // Reset position counter if a block is occupied
				}
			}
			if pos < int64(op[1]) {
				// If no sufficient space was found, output NULL
				fmt.Println("NULL")
			}
		}
		// Handle the 'e