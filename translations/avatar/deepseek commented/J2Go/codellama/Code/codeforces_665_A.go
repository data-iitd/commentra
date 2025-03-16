
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Create BufferedReader to read input from System.in
    br := bufio.NewReader(os.Stdin)
    // Create PrintWriter to write output to System.out
    pw := bufio.NewWriter(os.Stdout)

    // Read the first train's details
    st := strings.Split(br.ReadString('\n'), " ")
    a, _ := strconv.Atoi(st[0]) // Train number a
    tA, _ := strconv.Atoi(st[1]) // Travel time for train a

    // Read the second train's details
    st = strings.Split(br.ReadString('\n'), " ")
    b, _ := strconv.Atoi(st[0]) // Train number b
    tB, _ := strconv.Atoi(st[1]) // Travel time for train b

    // Read the current timing
    timing := br.ReadString('\n')
    hrs, _ := strconv.Atoi(timing[0:2]) // Extract hour from timing
    mins, _ := strconv.Atoi(timing[3:]) // Extract minute from timing

    // Calculate the simulated departure and arrival times for train a
    simDeparture := hrs*60 + mins
    simArrival := simDeparture + tA

    // Initialize counter to keep track of conflicts
    counter := 0

    // Iterate through the bus schedule, checking for conflicts
    for i := 300; i < 1440; i += b {
        busDeparture := i // Bus departure time
        busArrival := i + tB // Bus arrival time

        // Check if there's a conflict (bus and train schedules overlap)
        if busDeparture >= simArrival || simDeparture >= busArrival {
            continue
        }

        // Increment counter if a conflict is found
        counter++
    }

    // Print the number of conflicts found
    fmt.Fprintln(pw, counter)
    pw.Flush()
    pw.Close()
}

