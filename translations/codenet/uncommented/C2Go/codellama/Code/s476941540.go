#include <stdio.h>
#include <ctype.h>

func main(){
    var i int
    var alpha [26]int
    var ch byte

    for i = 0; i < 26; i++ {
        alpha[i] = 0
    }

    for {
        ch = getchar()
        if ch == EOF {
            break
        }

        if isalpha(ch) {
            if isupper(ch) {
                alpha[ch - 65]++
            } else {
                alpha[ch - 97]++
            }
        }
    }

    ch = 'a'
    for i = 0; i < 26; i++ {
        fmt.Printf("%c : %d\n", ch, alpha[i])
        ch++
    }
}

