
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define types for convenience
type ll int
type P [2]int
type PP [2]P

// Function to convert date and time into total minutes from the start of the year
func time2min(month, day, hour, min int) int {
	// Array containing the total days in each month
	total_day_of_month := [13]int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	total := 0

	// Calculate total minutes for the months before the given month
	for i := 1; i < month; i++ {
		total += total_day_of_month[i] * 24 * 60
	}

	// Add total minutes for the days before the given day
	for i := 1; i < day; i++ {
		total += 24 * 60
	}

	// Add minutes for the given hour and minute
	total += hour*60 + min

	return total // Return total minutes
}

func main() {
	var N int
	// Read the number of logs until a zero is encountered
	for {
		fmt.Scan(&N)
		if N == 0 {
			break // Exit if N is zero
		}

		// Map to store the log entries for each ID
		log := make(map[int][]int)
		for i := 0; i < N; i++ {
			var month, day, hour, min, id int
			var action string
			// Read the log entry details
			fmt.Scan(&month, &day, &hour, &min, &action, &id)

			// Convert the date and time to total minutes and store in the log
			t := time2min(month, day, hour, min)
			log[id] = append(log[id], t)
		}

		// Array to keep track of total overlap time for each ID
		total := make([]int, 1000)
		for i := range total {
			total[i] = 0
		} // Initialize total array to zero

		// Calculate overlap time for the "god" (ID 0) and other IDs
		for i := 0; i+1 < len(log[0]); i += 2 {
			god_start := log[0][i]   // Start time for god
			god_end := log[0][i+1]   // End time for god
			for id, schedule := range log { // Iterate through each log entry
				if id == 0 {
					continue // Skip the god's own log
				}

				// Calculate overlap time for each pair of start and end times
				for j := 0; j < len(schedule); j += 2 {
					ppl_start := schedule[j]   // Start time for the person
					ppl_end := schedule[j+1]   // End time for the person
					start := max(god_start, ppl_start)   // Calculate the maximum start time
					end := min(god_end, ppl_end)         // Calculate the minimum end time
					total[id] += max(0, end-start)        // Add the overlap time to the total
				}
			}
		}

		// Find the maximum overlap time among all IDs
		max_v := 0
		for id := 0; id < 1000; id++ {
			max_v = max(total[id], max_v) // Update max_v if current total is greater
		}

		// Output the maximum overlap time
		fmt.Println(max_v)
	}
}

// Function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Function to return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Function to read a line of input from stdin and return a slice of its words.
func readLine(file *os.File) []string {
	reader := bufio.NewReader(file)
	var line string
	line, _ = reader.ReadString('\n')

	// For some reason there are empty lines in the input file
	if line == "\n" {
		return readLine(file)
	}

	return strings.Split(strings.TrimRight(line, "\r\n"), " ")
}

// Function to convert a string to an integer
func toInt(s string) int {
	x, _ := strconv.Atoi(s)
	return x
}

// Function to convert a string to a slice of integers
func toInts(s []string) []int {
	out := make([]int, len(s))
	for i, v := range s {
		out[i] = toInt(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings2(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings3(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings4(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings5(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings6(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings7(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings8(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings9(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings10(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings11(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings12(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings13(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings14(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings15(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings16(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings17(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings18(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings19(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings20(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings21(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings22(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings23(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings24(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings25(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings26(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings27(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings28(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings29(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings30(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings31(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings32(s []int) []string {
	out := make([]string, len(s))
	for i, v := range s {
		out[i] = strconv.Itoa(v)
	}
	return out
}

// Function to convert a slice of integers to a slice of strings
func toStrings33(s []int) []string {
	out := make([]string, len(s))
	for 