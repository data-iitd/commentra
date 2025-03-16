<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Function to convert date and time into total minutes from the start of the year
func time2min(month, day, hour, min int) int {
    // Array containing the total days in each month
    total_day_of_month := [...]int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    total := 0

    // Calculate total minutes for the months before the given month
    for i := 1; i < month; i++ {
        total += total_day_of_month[i] * 24 * 60
    }
<<<<<<< HEAD
    
=======

>>>>>>> 98c87cb78a (data updated)
    // Add total minutes for the days before the given day
    for i := 1; i < day; i++ {
        total += 24 * 60
    }
<<<<<<< HEAD
    
=======

>>>>>>> 98c87cb78a (data updated)
    // Add minutes for the given hour and minute
    total += hour * 60 + min

    return total // Return total minutes
}

func main() {
    // Read the number of logs until a zero is encountered
    for {
        var N int
        if _, err := fmt.Scanf("%d", &N); err!= nil {
            break
        }
        if N == 0 {
            break
        }

        // Map to store the log entries for each ID
        log := make(map[int][]int)
        for i := 0; i < N; i++ {
            var month, day, hour, min, id int
            var action string
            fmt.Scanf("%d/%d %d:%d %s %d", &month, &day, &hour, &min, &action, &id)
<<<<<<< HEAD
            
=======

>>>>>>> 98c87cb78a (data updated)
            // Convert the date and time to total minutes and store in the log
            t := time2min(month, day, hour, min)
            log[id] = append(log[id], t)
        }

        // Array to keep track of total overlap time for each ID
        total := make([]int, 1000)
        for i := 0; i < 1000; i++ {
            total[i] = 0
        }

        // Calculate overlap time for the "god" (ID 0) and other IDs
<<<<<<< HEAD
        for i := 0; i + 1 < len(log[0]); i += 2 {
            god_start := log[0][i] // Start time for god
            god_end := log[0][i + 1] // End time for god
=======
        for i := 0; i+1 < len(log[0]); i += 2 {
            god_start := log[0][i] // Start time for god
            god_end := log[0][i+1] // End time for god
>>>>>>> 98c87cb78a (data updated)

            // Iterate through each log entry
            for id, schedule := range log {
                if id == 0 {
                    continue
                }

                // Calculate overlap time for each pair of start and end times
                for j := 0; j < len(schedule); j += 2 {
                    ppl_start := schedule[j] // Start time for the person
<<<<<<< HEAD
                    ppl_end := schedule[j + 1] // End time for the person
                    start := max(god_start, ppl_start) // Calculate the maximum start time
                    end := min(god_end, ppl_end) // Calculate the minimum end time
                    total[id] += max(0, end - start) // Add the overlap time to the total
=======
                    ppl_end := schedule[j+1] // End time for the person
                    start := max(god_start, ppl_start) // Calculate the maximum start time
                    end := min(god_end, ppl_end) // Calculate the minimum end time
                    total[id] += max(0, end-start) // Add the overlap time to the total
>>>>>>> 98c87cb78a (data updated)
                }
            }
        }

        // Find the maximum overlap time among all IDs
        max_v := 0
        for id, v := range total {
            max_v = max(max_v, v) // Update max_v if current total is greater
        }
<<<<<<< HEAD
        
=======

>>>>>>> 98c87cb78a (data updated)
        // Output the maximum overlap time
        fmt.Printf("%d\n", max_v)
    }
}

