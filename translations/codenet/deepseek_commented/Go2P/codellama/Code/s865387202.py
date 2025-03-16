
# Go:
package main

import (
	"fmt"
	"sort"
	"strings"
)

type city struct {
	prefecture int // Represents the prefecture number of the city
	position   int // Represents the position of the city in its prefecture
	year       int // Represents the year the city was established
}

type cities []*city // A slice of city pointers

type cMap map[int]cities // A map from prefecture numbers to slices of city pointers

func main() {
	var (
		n, m int // Declares variables to hold the number of prefectures and cities
	)
	fmt.Scanf("%d %d\n", &n, &m) // Reads the number of prefectures and cities from input
	h := make(cMap) // Initializes the map to store cities by their prefecture

	# Loop to read city entries
	for i in range(m):
		x, y = map(int, input().split()) # Reads the prefecture number and year from input
		_, exists = h[x] # Checks if the prefecture already exists in the map
		if not exists:
			h[x] = cities([{prefecture: x, year: y, position: i}]) # Creates a new entry if prefecture doesn't exist
		else:
			h[x] = h[x] + [city(prefecture=x, year=y, position=i)] # Appends the city to the existing slice

	results = [None] * m # Initializes a slice to hold the formatted city strings

	# Loop to sort and format cities
	for _, v in h.items():
		sort.sort(v) # Sorts the cities within the prefecture
		for idx, ci in enumerate(v):
			results[ci.position] = f"{ci.prefecture:06d}{idx+1:06d}" # Formats the city string
	print("\n".join(results)) # Joins the formatted city strings and prints them

