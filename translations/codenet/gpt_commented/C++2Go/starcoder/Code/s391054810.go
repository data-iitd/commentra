package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables to hold the height and width of the rectangle,
	// as well as the height and width of the cut-out section.
	var h, w, hh, ww int

	// Read the height and width of the rectangle, and the height and width of the cut-out section from user input.
	fmt.Scanf("%d %d %d %d", &h, &w, &hh, &ww)

	// Calculate the area of the remaining rectangle after the cut-out section
	// by subtracting the cut-out dimensions from the original dimensions.
	// The area is calculated as (remaining height) * (remaining width).
	fmt.Println((h - hh) * (w - ww))
}

