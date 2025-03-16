package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare arrays to hold the arrival times for train and bus
    var train [2]int
    var bus [2]int

    // Input the arrival times for the train
    fmt.Scanf("%d %d", &train[0], &train[1])
    // Input the arrival times for the bus
    fmt.Scanf("%d %d", &bus[0], &bus[1])

    // Calculate the minimum arrival time between the two times for train and bus,
    // and output the total minimum arrival time
    fmt.Println((train[0] < train[1]? train[0] : train[1]) + (bus[0] < bus[1]? bus[0] : bus[1]))

    // 