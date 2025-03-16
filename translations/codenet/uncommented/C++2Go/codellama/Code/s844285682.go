package main

import "fmt"

func main() {
	var a int
	fmt.Scan(&a)
	fmt.Println(a/(60*60), a%(60*60)/60, a%(60*60)%60)
}

