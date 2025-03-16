
package main

import (
	"bufio"
	"container/list"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

// Define a custom input function
func input() string {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	return sc.Text()
}

// Define the main function
func main() {
	// Read input values for N and M
	N, M := readIntSlice(2)

	// Initialize an empty list for edge
	edge := make([][]int, N)
	for i := 0; i < N; i++ {
		edge[i] = make([]int, 0)
	}

	// Read edges and add them to the edge list
	for i := 0; i < M; i++ {
		X, Y, Z := readIntSlice(3)
		X--
		Y--
		edge[X] = append(edge[X], Y)
		edge[Y] = append(edge[Y], X)
	}

	// Initialize a list of boolean values for used nodes
	used := make([]bool, N)

	// Initialize a variable for answer
	ans := 0

	// Iterate through all nodes
	for i := 0; i < N; i++ {
		// If the current node is not used
		if!used[i] {
			// Increment the answer
			ans++
			// Initialize a stack for DFS traversal
			stack := list.New()
			// Add the current node to the stack
			stack.PushBack(i)
			// Traverse through the graph using DFS
			for stack.Len() > 0 {
				// Get the next node from the stack
				node := stack.Front()
				stack.Remove(node)
				// Mark the current node as used
				used[node.Value.(int)] = true
				// Traverse through the neighbors of the current node
				for _, nextnode := range edge[node.Value.(int)] {
					// If the neighbor is not used
					if!used[nextnode] {
						// Add the neighbor to the stack
						stack.PushBack(nextnode)
					}
				}
			}
		}
	}

	// Print the answer
	fmt.Println(ans)
}

// Define a custom function to read integer slice from input
func readIntSlice(n int) []int {
	s := input()
	s = strings.Replace(s, "\n", "", -1)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\t", "", -1)
	s = strings.Replace(s, "\r", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	s = strings.Replace(s, "(", "", -1)
	s = strings.Replace(s, ")", "", -1)
	s = strings.Replace(s, "{", "", -1)
	s = strings.Replace(s, "}", "", -1)
	s = strings.Replace(s, "[", "", -1)
	s = strings.Replace(s, "]", "", -1)
	s = strings.Replace(s, ";", "", -1)
	s = strings.Replace(s, ",", "", -1)
	s = strings.Replace(s, ":", "", -1)
	s = strings.Replace(s, "|", "", -1)
	s = strings.Replace(s, "?", "", -1)
	s = strings.Replace(s, "\"", "", -1)
	s = strings.Replace(s, "=", "", -1)
	s = strings.Replace(s, "+", "", -1)
	s = strings.Replace(s, "-", "", -1)
	s = strings.Replace(s, "*", "", -1)
	s = strings.Replace(s, "/", "", -1)
	s = strings.Replace(s, "&", "", -1)
	s = strings.Replace(s, "%", "", -1)
	s = strings.Replace(s, "<", "", -1)
	s = strings.Replace(s, ">", "", -1)
	s = strings.Replace(s, "^", "", -1)
	s = strings.Replace(s, "~", "", -1)
	s = strings.Replace(s, "`", "", -1)
	s = strings.Replace(s, "!", "", -1)
	s = strings.Replace(s, "@", "", -1)
	s = strings.Replace(s, "#", "", -1)
	s = strings.Replace(s, "$", "", -1)
	s = strings.Replace(s, "%", "", -1)
	s = strings.Replace(s, "^", "", -1)
	s = strings.Replace(s, "&", "", -1)
	s = strings.Replace(s, "*", "", -1)
	s = strings.Replace(s, "(", "", -1)
	s = strings.Replace(s, ")", "", -1)
	s = strings.Replace(s, "{", "", -1)
	s = strings.Replace(s, "}", "", -1)
	s = strings.Replace(s, "[", "", -1)
	s = strings.Replace(s, "]", "", -1)
	s = strings.Replace(s, ";", "", -1)
	s = strings.Replace(s, ",", "", -1)
	s = strings.Replace(s, ":", "", -1)
	s = strings.Replace(s, "|", "", -1)
	s = strings.Replace(s, "?", "", -1)
	s = strings.Replace(s, "\"", "", -1)
	s = strings.Replace(s, "=", "", -1)
	s = strings.Replace(s, "+", "", -1)
	s = strings.Replace(s, "-", "", -1)
	s = strings.Replace(s, "*", "", -1)
	s = strings.Replace(s, "/", "", -1)
	s = strings.Replace(s, "&", "", -1)
	s = strings.Replace(s, "%", "", -1)
	s = strings.Replace(s, "<", "", -1)
	s = strings.Replace(s, ">", "", -1)
	s = strings.Replace(s, "^", "", -1)
	s = strings.Replace(s, "~", "", -1)
	s = strings.Replace(s, "`", "", -1)
	s = strings.Replace(s, "!", "", -1)
	s = strings.Replace(s, "@", "", -1)
	s = strings.Replace(s, "#", "", -1)
	s = strings.Replace(s, "$", "", -1)
	s = strings.Replace(s, "%", "", -1)
	s = strings.Replace(s, "^", "", -1)
	s = strings.Replace(s, "&", "", -1)
	s = strings.Replace(s, "*", "", -1)
	s = strings.Replace(s, "(", "", -1)
	s = strings.Replace(s, ")", "", -1)
	s = strings.Replace(s, "{", "", -1)
	s = strings.Replace(s, "}", "", -1)
	s = strings.Replace(s, "[", "", -1)
	s = strings.Replace(s, "]", "", -1)
	s = strings.Replace(s, ";", "", -1)
	s = strings.Replace(s, ",", "", -1)
	s = strings.Replace(s, ":", "", -1)
	s = strings.Replace(s, "|", "", -1)
	s = strings.Replace(s, "?", "", -1)
	s = strings.Replace(s, "\"", "", -1)
	s = strings.Replace(s, "=", "", -1)
	s = strings.Replace(s, "+", "", -1)
	s = strings.Replace(s, "-", "", -1)
	s = strings.Replace(s, "*", "", -1)
	s = strings.Replace(s, "/", "", -1)
	s = strings.Replace(s, "&", "", -1)
	s = strings.Replace(s, "%", "", -1)
	s = strings.Replace(s, "<", "", -1)
	s = strings.Replace(s, ">", "", -1)
	s = strings.Replace(s, "^", "", -1)
	s = strings.Replace(s, "~", "", -1)
	s = strings.Replace(s, "`", "", -1)
	s = strings.Replace(s, "!", "", -1)
	s = strings.Replace(s, "@", "", -1)
	s = strings.Replace(s, "#", "", -1)
	s = strings.Replace(s, "$", "", -1)
	s = strings.Replace(s, "%", "", -1)
	s = strings.Replace(s, "^", "", -1)
	s = strings.Replace(s, "&", "", -1)
	s = strings.Replace(s, "*", "", -1)
	s = strings.Replace(s, "(", "", -1)
	s = strings.Replace(s, ")", "", -1)
	s = strings.Replace(s, "{", "", -1)
	s = strings.Replace(s, "}", "", -1)
	s = strings.Replace(s, "[", "", -1)
	s = strings.Replace(s, "]", "", -1)
	s = strings.Replace(s, ";", "", -1)
	s = strings.Replace(s, ",", "", -1)
	s = strings.Replace(s, ":", "", -1)
	s = strings.Replace(s, "|", "", -1)
	s = strings.Replace(s, "?", "", -1)
	s = strings.Replace(s, "\"", "", -1)
	s = strings.Replace(s, "=", "", -1)
	s = strings.Replace(s, "+", "", -1)
	s = strings.Replace(s, "-", "", -1)
	s = strings.Replace(s, "*", "", -1)
	s = strings.Replace(s, "/", "", -1)
	s = strings.Replace(s, "&", "", -1)
	s = strings.Replace(s, "%", "", -1)
	s = strings.Replace(s, "<", "", -1)
	s = strings.Replace(s, ">", "", -1)
	s = strings.Replace(s, "^", "", -1)
	s = strings.Replace(s, "~", "", -1)
	s = strings.Replace(s, "`", "", -1)
	s = strings.Replace(s, "!", "", -1)
	s = strings.Replace(s, "@", "", -1)
	s = strings.Replace(s, "#", "", -1)
	s = strings.Replace(s, "$", "", -1)
	s = strings.Replace(s, "%", "", -1)
	s = strings.Replace(s, "^", "", -1)
	s = strings.Replace(s, "&", "", -1)
	s = strings.Replace(s, "*", "", -1)
	s = strings.Replace(s, "(", "", -1)
	s = strings.Replace(s, ")", "", -1)
	s = strings.Replace(s, "{", "", -1)
	s = strings.Replace(s, "}", "", -1)
	s = strings.Replace(s, "[", "", -1)
	s = strings.Replace(s, "]", "", -1)
	s = strings.Replace(s, ";", "", -1)
	s = strings.Replace(s, ",", "", -1)
	s = strings.Replace(s, ":", "", -1)
	s = strings.Replace(s, "|", "", -1)
	s = strings.Replace(s, "?", "", -1)
	s = strings.Replace(s, "\"", "", -1)
	s = strings.Replace(s, "=", "", -1)
	s = strings.Replace(s, "+", "", -1)
	s = strings.Replace(s, "-", "", -1)
	s = strings.Replace(s, "*", "", -1)
	s = strings.Replace(s, "/", "", -1)
	s = strings.Replace(s, "&", "", -1)
	s = strings.Replace(s, "%", "", -1)
	s = strings.Replace(s, "<", "", -1)
	s = strings.Replace(s, ">", "", -1)
	s = strings.Replace(s, "^", "", -1)
	s = strings.Replace(s, "~", "", -1)
	s = strings.Replace(s, "`", "", -1)
	s = strings.Replace(s, "!", "", -1)
	s = strings.Replace(s, "@", "", -1)
	s = strings.Replace(s, "#", "", -1)
	s = strings.Replace(s, "$", "", -1)
	s = strings.Replace(s, "%", "", -1)
	s = strings.Replace(s, "^", "", -1)
	s = strings.Replace(s, "&", "", -1)
	s = strings.Replace(s, "*", "", -1)
	s = strings.Replace(s, "(", "", -1)
	s = strings.Replace(s, ")", "", -1)
	s = strings.Replace(s, "{", "", -1)
	s = strings.Replace(s, "}", "", -1)
	s = strings.Replace(s, "[", "", -1)
	s = strings.Replace(s, "]", "", -1)
	s = strings.Replace(s, ";", "", -1)
	s = strings.Replace(s, ",", "", -1)
	s = strings.Replace(s, ":", "", -1)
	s = strings.Replace(s, "|", "", -1)
	s = strings.Replace(s, "?", "", -1)
	s = strings.Replace(s, "\"", "", -1)
	s = strings.Replace(s, "=", "", -1)
	s = strings.Replace(s, "+", "", -1)
	s = strings.Replace(s, "-", "", -1)
	s = strings.Replace(s, "*", "", -1)
	s = strings.Replace(s, "/", "", -1)
	s = strings.Replace(s, "&", "", -1)
	s = strings.Replace(s, "%", "", -1)
	s = strings.Replace(s, "<", "", -1)
	s = strings.Replace(s, ">", "", -1)
	s = strings.Replace(s, "^", "", -1)
	s = strings.Replace(s, "~", "", -1)
	s = strings.Replace(s, "`", "", -1)
	s = strings.Replace(s, "!", "", -1)
	s = strings.Replace(s, "@", "", -1)
	s = strings.Replace(s, "#", "", -1)
	s = strings.Replace(s, "$", "", -1)
	s = strings.Replace(s, "%", "", -1)
	s = strings.Replace(s, "^", "", -1)
	s = strings.Replace(s, "&", "", -1)
	s = strings.Replace(s, "*", "", -1)
	s = strings.Replace(s, "(", "", -1)
	s = strings.Replace(s, ")", "", -1)
	s = strings.Replace(s, "{", "", -1)
	s = strings.Replace(s, "}", "", -1)
	s = strings.Replace(s, "[", "", -1)
	s = strings.Replace(s, "]", "", -1)
	s = strings.Replace(s, ";", "", -1)
	s = strings.Replace(s, ",", "", -1)
	s = strings.Replace(s, ":", "", -1)
	s = strings.Replace(s, "|", "", -1)
	s = strings.Replace(s, "?", "", -1)
	s = strings.Replace(s, "\"", "", -1)
	s = strings.Replace(s, "=", "", -1)
	s = strings.Replace(s, "+", "", -1)
	s = strings.Replace(s, "-", "", -1)
	s = strings.Replace(s, "*", "", -1)
	s = strings.Replace(s, "/", "", -1)
	s = strings.Replace(s, "&", "", -1)
	s = strings.Replace(s, "%", "", -1)
	s = strings.Replace(s, "<", "", -1)
	s = strings.Replace(s, ">", "", -1)
	s = strings.Replace(s, "^", "", -1)
	s = strings.Replace(s, "~", "", -1)
	s = strings.Replace(s, "`", "", -1)
	s = strings.Replace(s, "!", "", -1)
	s = strings.Replace(s, "@", "", -1)
	s = strings.Replace(s, "#", "", -1)
	s = strings.Replace(s, "$", "", -1)
