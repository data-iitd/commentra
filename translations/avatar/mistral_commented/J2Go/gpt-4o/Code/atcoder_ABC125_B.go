package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scanln(&n) // Reading the first line of input which is an integer representing the number of elements in the arrays

	var vStr string
	fmt.Scanln(&vStr) // Reading the second line of input which is a string representing the values array
	vList := str2List(vStr) // Converting the string representation of the values array to a map

	var cStr string
	fmt.Scanln(&cStr) // Reading the third line of input which is a string representing the costs array
	cList := str2List(cStr) // Converting the string representation of the costs array to a map

	max := 0 // Initializing the variable max to 0

	for i := 0; i < n; i++ { // Iterating through each element in the arrays using a for loop
		profit := vList[i] - cList[i] // Calculating the profit for the current element by subtracting the cost from the value
		if profit > 0 { // Checking if the profit is positive
			max += profit // If the profit is positive, adding it to the max variable
		}
	}

	fmt.Println(max) // Printing the maximum profit to the standard output stream
}

func str2List(str string) map[int]int { // Defining the str2List function that converts a string representation of an array to a map
	vArrStr := strings.Split(str, " ") // Splitting the string into an array of strings using the space character as a delimiter
	ret := make(map[int]int) // Creating an empty map to store the key-value pairs

	for key, val := range vArrStr { // Iterating through each string in the array using a range loop
		intVal, _ := strconv.Atoi(val) // Converting the string to an integer
		ret[key] = intVal // Adding each string to the map as a key-value pair
	}

	return ret // Returning the map
}

// <END-OF-CODE>
