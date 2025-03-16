package main
import "fmt"
func main() {
	var pya int
	fmt.Scanf("%d", &pya)
	arre := make([]string, pya)
	for i := 0; i < pya; i++ {
		fmt.Scanf("%s", &arre[i])
	}
	oString := make([]byte, 1000000)
	fmt.Scanf("%s", &oString)
	lowString := string(oString)
	letter1 := string(oString[0])
	letter2 := 'a'
	if letter1!= 'a' {
		letter2 = 'b'
	}
	valid := make([]int, len(oString))
	setcito := make(map[int]bool)
	for _, x := range arre {
		for i := 0; i < len(lowString); i++ {
			if lowString[i:i+len(x)] == x {
				for j := i; j < i+len(x); j++ {
					setcito[j] = true
				}
			}
		}
	}
	for i, x := range oString {
		if setcito[i] {
			letter := letter1
			if x >= 'A' && x <= 'Z' {
				letter = letter2
			}
			oString[i] = byte(letter)
		}
	}
	fmt.Println(string(oString))
}
