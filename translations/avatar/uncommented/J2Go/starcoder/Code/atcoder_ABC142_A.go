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
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, "\r", "", -1)
	inputFloat, _ := strconv.ParseFloat(input, 64)
	countOdd := int(inputFloat / 2)
	result := float64(countOdd) / inputFloat
	result = round(result, 10)
	fmt.Println(result)
}

func round(num float64, precision int) (new float64) {
	pow := math.Pow(10, float64(precision))
	digit := pow * float64(math.Floor(float64(num*pow+0.5)/pow))
	new = float64(math.Floor(digit)) / pow
	return
}

