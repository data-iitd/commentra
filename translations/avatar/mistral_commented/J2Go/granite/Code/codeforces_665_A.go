

package main

import (
 "bufio"
 "fmt"
 "os"
 "strconv"
 "strings"
)

func main() {
 reader := bufio.NewReader(os.Stdin)
 var a, tA, b, tB int
 var timing string
 var simDeparture, simArrival, busDeparture, busArrival, counter int

 // Read the first line of input and parse the integers
 input, _ := reader.ReadString('\n')
 tokens := strings.Split(input, " ")
 a, _ = strconv.Atoi(tokens[0])
 tA, _ = strconv.Atoi(tokens[1])

 // Read the second line of input and parse the integers
 input, _ = reader.ReadString('\n')
 tokens = strings.Split(input, " ")
 b, _ = strconv.Atoi(tokens[0])
 tB, _ = strconv.Atoi(tokens[1])

 // Read the third line of input and parse the string
 timing, _ = reader.ReadString('\n')
 timing = strings.TrimSpace(timing)
 hrs, _ := strconv.Atoi(timing[:2])
 mins, _ := strconv.Atoi(timing[3:])
 simDeparture = hrs*60 + mins
 simArrival = simDeparture + tA

 counter = 0

 // Loop through the bus timings to find the number of buses that can accommodate students
 for i := 300; i < 1440; i += b {
 busDeparture = i
 busArrival = i + tB

 if busDeparture >= simArrival || simDeparture >= busArrival {
 continue
 }
 counter++
 }

 // Write the output to the console
 fmt.Println(counter)

 // 