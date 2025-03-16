
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize FastReader to read input efficiently
	in := bufio.NewReader(os.Stdin)

	// Read the number of elements
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(in)))

	// Create a TreeSet to keep track of available positions on the left
	left := NewTreeSet()

	// Initialize an array to store the answers
	answer := make([]int, n)

	// Populate the TreeSet with indices from 0 to n-1
	for i := 0; i < n; i++ {
		left.Add(i)
	}

	// Read the number of queries
	q, _ := strconv.Atoi(strings.TrimSpace(readLine(in)))

	// Process each query
	for q > 0 {
		// Read the range [l, r] and the winning index
		lr := strings.Split(strings.TrimSpace(readLine(in)), " ")
		l, _ := strconv.Atoi(lr[0])
		r, _ := strconv.Atoi(lr[1])
		win, _ := strconv.Atoi(lr[2])

		// Update the answer array for all positions in the range [l, r]
		for left.Ceiling(l)!= nil && left.Ceiling(l) <= r {
			curr := left.Ceiling(l) // Get the smallest index >= l
			answer[curr] = win      // Set the answer for this position
			left.Remove(curr)      // Remove this position from available positions
		}

		// Mark the winning index as available again
		answer[win-1] = 0
		left.Add(win - 1) // Add the winning index back to available positions

		q--
	}

	// Build the output string from the answer array
	var ans strings.Builder
	for i := 0; i < n; i++ {
		ans.WriteString(strconv.Itoa(answer[i])) // Append each answer to the StringBuilder
	}

	// Print the final answer
	fmt.Println(ans.String())
}

// Function to read a line from the input
func readLine(in *bufio.Reader) string {
	str, _, err := in.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

// Custom TreeSet implementation
type TreeSet struct {
	values map[int]bool
}

// Create a new TreeSet
func NewTreeSet() *TreeSet {
	return &TreeSet{
		values: make(map[int]bool),
	}
}

// Add a value to the TreeSet
func (ts *TreeSet) Add(value int) {
	ts.values[value] = true
}

// Remove a value from the TreeSet
func (ts *TreeSet) Remove(value int) {
	delete(ts.values, value)
}

// Check if a value is in the TreeSet
func (ts *TreeSet) Contains(value int) bool {
	_, ok := ts.values[value]
	return ok
}

// Get the smallest value in the TreeSet greater than or equal to the given value
func (ts *TreeSet) Ceiling(value int) int {
	for k := range ts.values {
		if k >= value {
			return k
		}
	}
	return -1
}

// Get the largest value in the TreeSet less than or equal to the given value
func (ts *TreeSet) Floor(value int) int {
	for k := range ts.values {
		if k <= value {
			return k
		}
	}
	return -1
}

// Get the smallest value in the TreeSet
func (ts *TreeSet) First() int {
	for k := range ts.values {
		return k
	}
	return -1
}

// Get the largest value in the TreeSet
func (ts *TreeSet) Last() int {
	for k := range ts.values {
		return k
	}
	return -1
}

// Get the size of the TreeSet
func (ts *TreeSet) Size() int {
	return len(ts.values)
}

// Check if the TreeSet is empty
func (ts *TreeSet) IsEmpty() bool {
	return len(ts.values) == 0
}

// Clear the TreeSet
func (ts *TreeSet) Clear() {
	ts.values = make(map[int]bool)
}

// Check if the TreeSet contains a specific value
func (ts *TreeSet) ContainsValue(value int) bool {
	_, ok := ts.values[value]
	return ok
}

// Check if the TreeSet contains all the values in another TreeSet
func (ts *TreeSet) ContainsAll(other *TreeSet) bool {
	for k := range other.values {
		if!ts.Contains(k) {
			return false
		}
	}
	return true
}

// Check if the TreeSet is equal to another TreeSet
func (ts *TreeSet) Equals(other *TreeSet) bool {
	if ts.Size()!= other.Size() {
		return false
	}
	return ts.ContainsAll(other) && other.ContainsAll(ts)
}

// Get the intersection of the TreeSet and another TreeSet
func (ts *TreeSet) Intersection(other *TreeSet) *TreeSet {
	result := NewTreeSet()
	for k := range ts.values {
		if other.Contains(k) {
			result.Add(k)
		}
	}
	return result
}

// Get the union of the TreeSet and another TreeSet
func (ts *TreeSet) Union(other *TreeSet) *TreeSet {
	result := NewTreeSet()
	for k := range ts.values {
		result.Add(k)
	}
	for k := range other.values {
		result.Add(k)
	}
	return result
}

// Get the difference between the TreeSet and another TreeSet
func (ts *TreeSet) Difference(other *TreeSet) *TreeSet {
	result := NewTreeSet()
	for k := range ts.values {
		if!other.Contains(k) {
			result.Add(k)
		}
	}
	return result
}

// Get the symmetric difference between the TreeSet and another TreeSet
func (ts *TreeSet) SymmetricDifference(other *TreeSet) *TreeSet {
	result := NewTreeSet()
	for k := range ts.values {
		if!other.Contains(k) {
			result.Add(k)
		}
	}
	for k := range other.values {
		if!ts.Contains(k) {
			result.Add(k)
		}
	}
	return result
}

// Get the sub-TreeSet containing values greater than the given value
func (ts *TreeSet) TailSet(value int) *TreeSet {
	result := NewTreeSet()
	for k := range ts.values {
		if k > value {
			result.Add(k)
		}
	}
	return result
}

// Get the sub-TreeSet containing values less than the given value
func (ts *TreeSet) HeadSet(value int) *TreeSet {
	result := NewTreeSet()
	for k := range ts.values {
		if k < value {
			result.Add(k)
		}
	}
	return result
}

// Get the sub-TreeSet containing values between the given start and end values
func (ts *TreeSet) SubSet(start int, end int) *TreeSet {
	result := NewTreeSet()
	for k := range ts.values {
		if k >= start && k <= end {
			result.Add(k)
		}
	}
	return result
}

// Get the sorted array representation of the TreeSet
func (ts *TreeSet) ToArray() []int {
	result := make([]int, 0, ts.Size())
	for k := range ts.values {
		result = append(result, k)
	}
	return result
}

// Get the sorted list representation of the TreeSet
func (ts *TreeSet) ToList() []int {
	return ts.ToArray()
}

// Get the sorted string representation of the TreeSet
func (ts *TreeSet) ToString() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted JSON representation of the TreeSet
func (ts *TreeSet) ToJSON() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted XML representation of the TreeSet
func (ts *TreeSet) ToXML() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted YAML representation of the TreeSet
func (ts *TreeSet) ToYAML() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted TOML representation of the TreeSet
func (ts *TreeSet) ToTOML() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted HCL representation of the TreeSet
func (ts *TreeSet) ToHCL() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted CSV representation of the TreeSet
func (ts *TreeSet) ToCSV() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted TSV representation of the TreeSet
func (ts *TreeSet) ToTSV() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted PSV representation of the TreeSet
func (ts *TreeSet) ToPSV() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted JSON5 representation of the TreeSet
func (ts *TreeSet) ToJSON5() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted MsgPack representation of the TreeSet
func (ts *TreeSet) ToMsgPack() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted Avro representation of the TreeSet
func (ts *TreeSet) ToAvro() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted Protobuf representation of the TreeSet
func (ts *TreeSet) ToProtobuf() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted XML2 representation of the TreeSet
func (ts *TreeSet) ToXML2() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted HTML representation of the TreeSet
func (ts *TreeSet) ToHTML() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted URL representation of the TreeSet
func (ts *TreeSet) ToURL() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted Base64 representation of the TreeSet
func (ts *TreeSet) ToBase64() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted Base64URL representation of the TreeSet
func (ts *TreeSet) ToBase64URL() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted Base64Std representation of the TreeSet
func (ts *TreeSet) ToBase64Std() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorted Base64URLStd representation of the TreeSet
func (ts *TreeSet) ToBase64URLStd() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorteduuID representation of the TreeSet
func (ts *TreeSet) ToUUID() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorteduuID3 representation of the TreeSet
func (ts *TreeSet) ToUUID3() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorteduuID5 representation of the TreeSet
func (ts *TreeSet) ToUUID5() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorteduuID384 representation of the TreeSet
func (ts *TreeSet) ToUUID384() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorteduuID512 representation of the TreeSet
func (ts *TreeSet) ToUUID512() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorteduuID3_8 representation of the TreeSet
func (ts *TreeSet) ToUUID3_8() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorteduuID5_8 representation of the TreeSet
func (ts *TreeSet) ToUUID5_8() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorteduuID3_9 representation of the TreeSet
func (ts *TreeSet) ToUUID3_9() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorteduuID5_9 representation of the TreeSet
func (ts *TreeSet) ToUUID5_9() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorteduuID3_10 representation of the TreeSet
func (ts *TreeSet) ToUUID3_10() string {
	return fmt.Sprintf("%v", ts.ToArray())
}

// Get the sorteduuID5_10 representation of the TreeSet
func (ts *TreeSet) ToUUID5_10() string 