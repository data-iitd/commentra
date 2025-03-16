package main
import "fmt"
import "strings"

func main() {
	l := input()
	l = strings.Split(l, ".")
	s := []rune(l[0])
	p := []rune(l[1])
	i := int(p[0])
	if s[len(s)-1] == '9' {
		fmt.Println("GOTO Vasilisa.")
	} else if s[len(s)-1]!= '9' && i < 5 {
		s = string(s)
		fmt.Println(s)
	} else {
		s = string(s)
		s = fmt.Sprintf("%d", int(s)+1)
		fmt.Println(s)
	}
}

