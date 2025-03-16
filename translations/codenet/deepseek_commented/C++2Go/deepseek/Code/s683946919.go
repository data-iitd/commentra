package main

import (
	"fmt"
	"math"
	"sort"
)

// Function to convert date and time into total minutes from the start of the year
func time2min(month, day, hour, min int) int {
	// Array containing the total days in each month
	total_day_of_month := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	total := 0

	// Calculate total minutes for the months before the given month
	for i := 1; i < month; i++ {
		total += total_day_of_month[i-1] * 24 * 60
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
			fmt.Scanf("%d/%d %d:%d %s %d", &month, &day, &hour, &min, &action, &id)

			// Convert the date and time to total minutes and store in the log
			t := time2min(month, day, hour, min)
			log[id] = append(log[id], t)
		}

		// Array to keep track of total overlap time for each ID
		total := make([]int, 1000)

		// Calculate overlap time for the "god" (ID 0) and other IDs
		for i := 0; i+1 < len(log[0]); i += 2 {
			god_start := log[0][i] // Start time for god
			god_end := log[0][i+1] // End time for god

			// Iterate through each log entry
			for id, schedule := range log {
				if id == 0 {
					continue // Skip the god's own log
				}

				// Calculate overlap time for each pair of start and end times
				for j := 0; j < len(schedule); j += 2 {
					ppl_start := schedule[j] // Start time for the person
					ppl_end := schedule[j+1] // End time for the person
					start := int(math.Max(float64(god_start), float64(ppl_start)))
					end := int(math.Min(float64(god_end), float64(ppl_end)))
					total[id] += int(math.Max(0, float64(end-start)))
				}
			}
		}

		// Find the maximum overlap time among all IDs
		max_v := 0
		for id := 0; id < 1000; id++ {
			if total[id] > max_v {
				max_v = total[id] // Update max_v if current total is greater
			}
		}

		// Output the maximum overlap time
		fmt.Println(max_v)
	}
}

