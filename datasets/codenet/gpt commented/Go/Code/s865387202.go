package main

import (
	"fmt"
	"sort"
	"strings"
)

// Define a struct to represent a city with its prefecture, year, and position
type city struct {
	prefecture int // Prefecture number
	position   int // Position in the input
	year       int // Year associated with the city
}

// Define a slice of city pointers for sorting
type cities []*city

// Define a map where the key is an integer (prefecture) and the value is a slice of cities
type cMap map[int]cities

func main() {
	var (
		n, m int // n: number of prefectures, m: number of cities
	)
	// Read the number of prefectures and cities from input
	fmt.Scanf("%d %d\n", &n, &m)
	
	// Initialize a map to hold cities grouped by their prefecture
	h := make(cMap)
	
	// Read city data from input
	for i := 0; i < m; i++ {
		var x, y int // x: prefecture number, y: year
		fmt.Scanf("%d %d\n", &x, &y)
		
		// Check if the prefecture already exists in the map
		_, exists := h[x]
		if !exists {
			// If it doesn't exist, create a new entry with the city
			h[x] = cities{{prefecture: x, year: y, position: i}}
		} else {
			// If it exists, append the new city to the existing slice
			h[x] = append(h[x], &city{prefecture: x, year: y, position: i})
		}
	}

	// Prepare a results slice to hold formatted output for each city
	results := make([]string, m)

	// Iterate over each group of cities in the map
	for _, v := range h {
		// Sort the cities by year using the Less method defined below
		sort.Sort(v)
		// Format the output for each city based on its position and year
		for idx, ci := range v {
			results[ci.position] = fmt.Sprintf("%06d%06d", ci.prefecture, idx+1)
		}
	}
	
	// Print the results, joining them with newline characters
	fmt.Println(strings.Join(results, "\n"))
}

// Implement the Len method for sorting cities
func (c cities) Len() int {
	return len(c)
}

// Implement the Swap method for sorting cities
func (c cities) Swap(i, j int) {
	c[i], c[j] = c[j], c[i]
}

// Implement the Less method for sorting cities by year
func (c cities) Less(i, j int) bool {
	return c[i].year < c[j].year
}
