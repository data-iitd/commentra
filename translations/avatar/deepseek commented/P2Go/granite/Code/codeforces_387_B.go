
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the number of elements in round_complexity and george_complexity
    reader := bufio.NewReader(os.Stdin)
    n, m := readTwoInt64s(reader)
    
    // Read the complexities of the rounds
    round_complexity := readNInt64s(reader, n)
    
    // Read the complexities of George's challenges
    george_complexity := readNInt64s(reader, m)
    
    // Initialize counters for both lists
    i, j := int64(0), int64(0)
    
    // Loop through both lists to compare complexities
    for i < n && j < m {
        // Increment i if the current round complexity is less than or equal to George's complexity
        i += 1 * (round_complexity[i] <= george_complexity[j])
        
        // Increment j to move to the next element in george_complexity
        j += 1
    }
    
    // Print the number of rounds George can solve
    fmt.Println(n - i)
}

func readInt(bytes []byte, from int, val *int) int {
    // Implement the readInt function as described in the code snippet
}

func readNum(reader *bufio.Reader) (a int) {
    // Implement the readNum function as described in the code snippet
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
    // Implement the readTwoNums function as described in the code snippet
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
    // Implement the readThreeNums function as described in the code snippet
}

func readNNums(reader *bufio.Reader, n int) []int {
    // Implement the readNNums function as described in the code snippet
}

func readTwoInt64s(reader *bufio.Reader) (a int64, b int64) {
    // Implement the readTwoInt64s function as described in the code snippet
}

func readNInt64s(reader *bufio.Reader, n int) []int64 {
    // Implement the readNInt64s function as described in the code snippet
}

func readUint64(bytes []byte, from int, val *uint64) int {
    // Implement the readUint64 function as described in the code snippet
}

func readInt64(bytes []byte, from int, val *int64) int {
    // Implement the readInt64 function as described in the code snippet
}

func readUint64s(bytes []byte, from int, val *[]uint64) int {
    // Implement the readUint64s function as described in the code snippet
}

func readInt64s(bytes []byte, from int, val *[]int64) int {
    // Implement the readInt64s function as described in the code snippet
}

func main() {
    // Read the number of elements in round_complexity and george_complexity
    reader := bufio.NewReader(os.Stdin)
    n, m := readTwoInt64s(reader)
    
    // Read the complexities of the rounds
    round_complexity := readNInt64s(reader, n)
    
    // Read the complexities of George's challenges
    george_complexity := readNInt64s(reader, m)
    
    // Initialize counters for both lists
    i, j := int64(0), int64(0)
    
    // Loop through both lists to compare complexities
    for i < n && j < m {
        // Increment i if the current round complexity is less than or equal to George's complexity
        i += 1 * (round_complexity[i] <= george_complexity[j])
        
        // Increment j to move to the next element in george_complexity
        j += 1
    }
    
    // Print the number of rounds George can solve
    fmt.Println(n - i)
}

func readInt(bytes []byte, from int, val *int) int {
    // Implement the readInt function as described in the code snippet
}

func readNum(reader *bufio.Reader) (a int) {
    // Implement the readNum function as described in the code snippet
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
    // Implement the readTwoNums function as described in the code snippet
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
    // Implement the readThreeNums function as described in the code snippet
}

func readNNums(reader *bufio.Reader, n int) []int {
    // Implement the readNNums function as described in the code snippet
}

func readTwoInt64s(reader *bufio.Reader) (a int64, b int64) {
    // Implement the readTwoInt64s function as described in the code snippet
}

func readNInt64s(reader *bufio.Reader, n int) []int64 {
    // Implement the readNInt64s function as described in the code snippet
}

func readUint64(bytes []byte, from int, val *uint64) int {
    // Implement the readUint64 function as described in the code snippet
}

func readInt64(bytes []byte, from int, val *int64) int {
    // Implement the readInt64 function as described in the code snippet
}

func readUint64s(bytes []byte, from int, val *[]uint64) int {
    // Implement the readUint64s function as described in the code snippet
}

func readInt64s(bytes []byte, from int, val *[]int64) int {
    // Implement the readInt64s function as described in the code snippet
}

func main() {
    // Read the number of elements in round_complexity and george_complexity
    reader := bufio.NewReader(os.Stdin)
    n, m := readTwoInt64s(reader)
    
    // Read the complexities of the rounds
    round_complexity := readNInt64s(reader, n)
    
    // Read the complexities of George's challenges
    george_complexity := readNInt64s(reader, m)
    
    // Initialize counters for both lists
    i, j := int64(0), int64(0)
    
    // Loop through both lists to compare complexities
    for i < n && j < m {
        // Increment i if the current round complexity is less than or equal to George's complexity
        i += 1 * (round_complexity[i] <= george_complexity[j])
        
        // Increment j to move to the next element in george_complexity
        j += 1
    }
    
    // Print the number of rounds George can solve
    fmt.Println(n - i)
}

func readInt(bytes []byte, from int, val *int) int {
    // Implement the readInt function as described in the code snippet
}

func readNum(reader *bufio.Reader) (a int) {
    // Implement the readNum function as described in the code snippet
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
    // Implement the readTwoNums function as described in the code snippet
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
    // Implement the readThreeNums function as described in the code snippet
}

func readNNums(reader *bufio.Reader, n int) []int {
    // Implement the readNNums function as described in the code snippet
}

func readTwoInt64s(reader *bufio.Reader) (a int64, b int64) {
    // Implement the readTwoInt64s function as described in the code snippet
}

func readNInt64s(reader *bufio.Reader, n int) []int64 {
    // Implement the readNInt64s function as described in the code snippet
}

func readUint64(bytes []byte, from int, val *uint64) int {
    // Implement the readUint64 function as described in the code snippet
}

func readInt64(bytes []byte, from int, val *int64) int {
    // Implement the readInt64 function as described in the code snippet
}

func readUint64s(bytes []byte, from int, val *[]uint64) int {
    // Implement the readUint64s function as described in the code snippet
}

func readInt64s(bytes []byte, from int, val *[]int64) int {
    // Implement the readInt64s function as described in the code snippet
}

func main() {
    // Read the number of elements in round_complexity and george_complexity
    reader := bufio.NewReader(os.Stdin)
    n, m := readTwoInt64s(reader)
    
    // Read the complexities of the rounds
    round_complexity := readNInt64s(reader, n)
    
    // Read the complexities of George's challenges
    george_complexity := readNInt64s(reader, m)
    
    // Initialize counters for both lists
    i, j := int64(0), int64(0)
    
    // Loop through both lists to compare complexities
    for i < n && j < m {
        // Increment i if the current round complexity is less than or equal to George's complexity
        i += 1 * (round_complexity[i] <= george_complexity[j])
        
        // Increment j to move to the next element in george_complexity
        j += 1
    }
    
    // Print the number of rounds George can solve
    fmt.Println(n - i)
}

func readInt(bytes []byte, from int, val *int) int {
    // Implement the readInt function as described in the code snippet
}

func readNum(reader *bufio.Reader) (a int) {
    // Implement the readNum function as described in the code snippet
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
    // Implement the readTwoNums function as described in the code snippet
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
    // Implement the readThreeNums function as described in the code snippet
}

func readNNums(reader *bufio.Reader, n int) []int {
    // Implement the readNNums function as described in the code snippet
}

func readTwoInt64s(reader *bufio.Reader) (a int64, b int64) {
    // Implement the readTwoInt64s function as described in the code snippet
}

func readNInt64s(reader *bufio.Reader, n int) []int64 {
    // Implement the readNInt64s function as described in the code snippet
}

func readUint64(bytes []byte, from int, val *uint64) int {
    // Implement the readUint64 function as described in the code snippet
}

func readInt64(bytes []byte, from int, val *int64) int {
    // Implement the readInt64 function as described in the code snippet
}

func readUint64s(bytes []byte, from int, val *[]uint64) int {
    // Implement the readUint64s function as described in the code snippet
}

func readInt64s(bytes []byte, from int, val *[]int64) int {
    // Implement the readInt64s function as described in the code snippet
}

func main() {
    // Read the number of elements in round_complexity and george_complexity
    reader := bufio.NewReader(os.Stdin)
    n, m := readTwoInt64s(reader)
    
    // Read the complexities of the rounds
    round_complexity := readNInt64s(reader, n)
    
    // Read the complexities of George's challenges
    george_complexity := readNInt64s(reader, m)
    
    // Initialize counters for both lists
    i, j := int64(0), int64(0)
    
    // Loop through both lists to compare complexities
    for i < 