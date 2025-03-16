

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Create scanner to read input from System.in
    scanner := bufio.NewScanner(os.Stdin)
    
    // Read the first train's details
    scanner.Scan()
    line := scanner.Text()
    tokens := strings.Split(line, " ")
    a, _ := strconv.Atoi(tokens[0])
    tA, _ := strconv.Atoi(tokens[1])
    
    // Read the second train's details
    scanner.Scan()
    line = scanner.Text()
    tokens = strings.Split(line, " ")
    b, _ := strconv.Atoi(tokens[0])
    tB, _ := strconv.Atoi(tokens[1])
    
    // Read the current timing
    scanner.Scan()
    timing := scanner.Text()
    hrs, _ := strconv.Atoi(timing[:2])
    mins, _ := strconv.Atoi(timing[3:])
    
    // Calculate the simulated departure and arrival times for train a
    simDeparture := hrs*60 + mins
    simArrival := simDeparture + tA
    
    // Initialize counter to keep track of conflicts
    counter := 0
    
    // Iterate through the bus schedule, checking for conflicts
    for i := 300; i < 1440; i += b {
        busDeparture := i
        busArrival := i + tB
        
        // Check if there's a conflict (bus and train schedules overlap)
        if busDeparture >= simArrival || simDeparture >= busArrival {
            continue
        }
        
        // Increment counter if a conflict is found
        counter++
    }
    
    // Print the number of conflicts found
    fmt.Println(counter)
}

