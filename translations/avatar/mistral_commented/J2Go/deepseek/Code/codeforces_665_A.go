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
 writer := bufio.NewWriter(os.Stdout)
 defer writer.Flush()

 // Read the first line of input and parse the integers
 line, _ := reader.ReadString('\n')
 line = strings.TrimSpace(line)
 parts := strings.Split(line, " ")
 a, _ := strconv.Atoi(parts[0])
 tA, _ := strconv.Atoi(parts[1])

 // Read the second line of input and parse the integers
 line, _ = reader.ReadString('\n')
 line = strings.TrimSpace(line)
 parts = strings.Split(line, " ")
 b, _ := strconv.Atoi(parts[0])
 tB, _ := strconv.Atoi(parts[1])

 // Read the third line of input and parse the string
 line, _ = reader.ReadString('\n')
 line = strings.TrimSpace(line)
 parts = strings.Split(line, ":")
 hrs, _ := strconv.Atoi(parts[0])
 mins, _ := strconv.Atoi(parts[1])
 simDeparture := hrs*60 + mins
 simArrival := simDeparture + tA

 counter := 0

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
 fmt.Fprintln(writer, counter)
}

