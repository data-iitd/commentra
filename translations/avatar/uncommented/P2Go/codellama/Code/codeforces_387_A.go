
package main

import "fmt"

func main() {
	var h1, m1, h2, m2 int
	fmt.Scan(&h1, &m1)
	m1 += h1 * 60
	fmt.Scan(&h2, &m2)
	m2 += h2 * 60
	m2 = m1 - m2
	m2 %= 1440
	fmt.Printf("%02d:%02d", m2/60, m2%60)
}

