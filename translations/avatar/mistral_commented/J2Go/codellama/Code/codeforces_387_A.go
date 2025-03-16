
package main

import (
  "fmt"
  "time"
)

func main() {
  // Create a new Scanner object to read input from the console
  sc := new(Scanner)

  // Read the first time string from the console and split it into hour and minute parts
  s := sc.next().split(":")

  // Read the second time string from the console and split it into hour and minute parts
  t := sc.next().split(":")

  // Create LocalTime objects `x` and `y` from the hour and minute parts of the first and second time strings, respectively
  x := time.LocalTime.of(s[0], s[1])
  y := time.LocalTime.of(t[0], t[1])

  // Print the result of subtracting the second time from the first time, which is the difference between the two times in hours and minutes
  fmt.Println(x.minusHours(y.getHour()).minusMinutes(y.getMinute()))
}

