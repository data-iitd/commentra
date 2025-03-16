
package main

import (
 "bufio"
 "fmt"
 "os"
 "strconv"
 "strings"
)

func main() {
 var a, tA, b, tB, hrs, mins, simDeparture, simArrival, counter int

 // Read the first line of input and parse the integers
 fmt.Scan(&a, &tA)

 // Read the second line of input and parse the integers
 fmt.Scan(&b, &tB)

 // Read the third line of input and parse the string
 var timing string
 fmt.Scan(&timing)
 hrs, _ = strconv.Atoi(timing[0:2])
 mins, _ = strconv.Atoi(timing[3:])
 simDeparture = hrs*60 + mins
 simArrival = simDeparture + tA

 // Loop through the bus timings to find the number of buses that can accommodate students
 for i := 300; i < 1440; i += b {
 busDeparture := i
 busArrival := i + tB

 if busDeparture >= simArrival || simDeparture >= busArrival {
 continue
 }
 counter++
 }

 // Write the output to the console
 fmt.Println(counter)
}

