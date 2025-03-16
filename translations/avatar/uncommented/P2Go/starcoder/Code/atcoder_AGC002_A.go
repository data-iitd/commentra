package main
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var a, b int
	fmt.Scanf("%d %d", &a, &b)
	if a > 0 {
		fmt.Println("Positive")
	} else if a <= 0 && b >= 0 {
		fmt.Println("Zero")
	} else {
		if (a+b)%2 == 0 {
			fmt.Println("Negative")
		} else {
			fmt.Println("Positive")
		}
	}
}

