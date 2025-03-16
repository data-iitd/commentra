package main

import (
	"fmt"
	"sort"
)

const INF = 0x3f3f3f3f

// Function to convert date and time into total minutes from the start of the year
func time2min(month, day, hour, min int) int {
	// Array containing the total days in each month
	totalDayOfMonth := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	total := 0

	// Calculate total minutes for the months before the given month
	for i := 1; i < month; i++ {
		total += totalDayOfMonth[i-1] * 24 * 60
	}

	// Add total minutes for the days before the given day
	for i := 1; i < day; i++ {
		total += 24 * 60
	}

	// Add minutes for the given hour and minute
	total += hour * 60 + min

	return total // Return total minutes
}

func main() {
	var N int
	// Read the number of logs until a zero is encountered
	for {
		if _, err := fmt.Scan(&N); err != nil || N == 0 {
			break // Exit if N is zero or an error occurs
		}

		// Map to store the log entries for each ID
		log := make(map[int][]int)
		for i := 0; i < N; i++ {
			var month, day, hour, min, id int
			var action string
			// Read the log entry details
			fmt.Scanf("%d/%d %d:%d %s %d", &month, &day, &hour, &min, &action, &id)

			// Convert the date and time to total minutes and store in the log
			t := time2min(month, day, hour, min)
			log[id] = append(log[id], t)
		}

		// Array to keep track of total overlap time for each ID
		total := make([]int, 1000) // Initialize total array to zero

		// Calculate overlap time for the "god" (ID 0) and other IDs
		for i := 0; i+1 < len(log[0]); i += 2 {
			godStart := log[0][i]   // Start time for god
			godEnd := log[0][i+1]   // End time for god

			// Iterate through each log entry
			for id, schedule := range log {
				if id == 0 {
					continue // Skip the god's own log
				}

				// Calculate overlap time for each pair of start and end times
				for j := 0; j < len(schedule); j += 2 {
					pplStart := schedule[j]     // Start time for the person
					pplEnd := schedule[j+1]     // End time for the person
					start := max(godStart, pplStart) // Calculate the maximum start time
					end := min(godEnd, pplEnd)       // Calculate the minimum end time
					total[id] += max(0, end-start)   // Add the overlap time to the total
				}
			}
		}

		// Find the maximum overlap time among all IDs
		maxV := 0
		for id := 0; id < 1000; id++ {
			maxV = max(total[id], maxV) // Update maxV if current total is greater
		}

		// Output the maximum overlap time
		fmt.Println(maxV)
	}
}

// Helper function to get the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Helper function to get the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
