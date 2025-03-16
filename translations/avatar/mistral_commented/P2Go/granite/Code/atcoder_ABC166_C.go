
###
# Code
###

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the first line of input containing the number of nodes 'n' and edges'm'
	data, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	data = strings.Replace(data, "\n", "", -1)
	n, m := 0, 0
	for _, v := range strings.Split(data, " ") {
		if n == 0 {
			n, _ = strconv.Atoi(v)
		} else {
			m, _ = strconv.Atoi(v)
		}
	}

	// Initialize a list 'p' of numbers from 1 to 'n'
	p := make([]int, n)
	for i := 0; i < n; i++ {
		p[i] = i + 1
	}

	// Read the second line of input containing the heights of the nodes
	data, _ = bufio.NewReader(os.Stdin).ReadString('\n')
	data = strings.Replace(data, "\n", "", -1)
	h := make([]int, n)
	for i, v := range strings.Split(data, " ") {
		h[i], _ = strconv.Atoi(v)
	}

	// Create a dictionary 'hp' using list comprehension to store node number as key and height as value
	hp := make(map[int]int)
	for i, v := range p {
		hp[v] = h[i]
	}

	// Initialize an empty dictionary 'path' to store the graph
	path := make(map[int][]int)

	// Read'm' lines of input containing edges and add them to the 'path' dictionary
	for i := 0; i < m; i++ {
		data, _ = bufio.NewReader(os.Stdin).ReadString('\n')
		data = strings.Replace(data, "\n", "", -1)
		a, b := 0, 0
		for _, v := range strings.Split(data, " ") {
			if a == 0 {
				a, _ = strconv.Atoi(v)
			} else {
				b, _ = strconv.Atoi(v)
			}
		}
		path[a] = append(path[a], b)
		path[b] = append(path[b], a)
	}

	// Initialize a counter 'c' to store the number of valid paths
	c := 0

	// Iterate through each node in the graph and check if it forms a valid path
	for i, v := range path {
		// Initialize a flag 'f' to check if the current node is a valid starting point
		f := 0
		// Iterate through each neighbor of the current node and check if it is a valid ending point
		for _, j := range v {
			// If the height of the current node is less than or equal to the height of its neighbor,
			// then it is not a valid path and we set the flag 'f' to 1 and break the loop
			if hp[i] <= hp[j] {
				f = 1
				break
			}
		}
		// If the flag 'f' is still 0 after checking all neighbors, then this node forms a valid path
		// and we increment the counter 'c'
		if f == 0 {
			c++
		}
	}

	// Print the final result, i.e., the number of valid paths
	fmt.Println(c)
}
