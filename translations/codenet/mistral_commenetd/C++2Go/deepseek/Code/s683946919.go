package main

import (
	"fmt"
	"math"
	"sort"
)

// Function to convert date, hour and minute to total minutes
func time2min(month, day, hour, min int) int {
	const totalDayOfMonth = []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} // Total days in each month
	total := 0
	for i := 1; i < month; i++ { // Calculate total minutes for each month before the current one
		total += totalDayOfMonth[i-1] * 24 * 60
	}
	for i := 1; i < day; i++ { // Calculate total minutes for each day before the current one
		total += 24 * 60
	}
	total += hour*60 + min // Calculate total minutes for the current hour and minute
	return total
}

func main() {
	var N int
	for {
		fmt.Scan(&N) // Read the number of logs from the standard input
		if N == 0 {
			break // If the number of logs is zero, break the loop
		}

		log := make(map[int][]int) // Create a map to store logs for each id
		for i := 0; i < N; i++ {   // Iterate through each log
			var month, day, hour, min, id int
			var action string // Read the action (add or remove) from the standard input

			fmt.Scanf("%d/%d %d:%d %s %d", &month, &day, &hour, &min, &action, &id) // Read the month, day, hour, minute, action and id from the standard input

			t := time2min(month, day, hour, min) // Calculate the total minutes for the log
			log[id] = append(log[id], t)         // Add the total minutes to the vector of logs for the id
		}

		total := make([]int, 1000) // Create an array to store the total time spent for each id
		for i := 0; i+1 < len(log[0]); i += 2 { // Iterate through each pair of logs for the id 0
			godStart := log[0][i] // Get the start time of the first log
			godEnd := log[0][i+1] // Get the end time of the first log

			for id, schedule := range log { // Iterate through each id and its logs
				if id == 0 {
					continue // If the id is 0, skip the iteration
				}
				for j := 0; j < len(schedule); j += 2 { // Iterate through each pair of logs for the current id
					pplStart := schedule[j] // Get the start time of the first log
					pplEnd := schedule[j+1] // Get the end time of the first log
					start := max(godStart, pplStart) // Get the maximum start time between the logs of god and people
					end := min(godEnd, pplEnd)       // Get the minimum end time between the logs of god and people
					total[id] += max(0, end-start)  // Calculate and add the total time spent for the current id
				}
			}
		}

		maxV := 0 // Initialize the maximum total time spent to zero
		for id := 0; id < 1000; id++ { // Iterate through each id and find the maximum total time spent
			if total[id] > maxV {
				maxV = total[id]
			}
		}
		fmt.Println(maxV) // Print the maximum total time spent
	}
}

