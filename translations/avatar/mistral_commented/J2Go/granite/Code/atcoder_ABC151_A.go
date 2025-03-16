

package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

func main() {
    r := bufio.NewReaderSize(os.Stdin, 1)
    s, _ := r.ReadString('\n')
    s = strings.TrimSpace(s)
    fmt.Printf("%c", s[0]+1)
}

class RemRing {
    long module;

    public RemRing(long module) {
        this.module = module;
    }

    public long sum(long a, long b) {
        return (a + b + module) % module;
    }

    public long sub(long a, long b) {
        return (a - b + module) % module;
    }

    public long prod(long a, long b) {
        return (a * b) % module;
    }

    public long div(long a, long b) {
        long quotient = a * inv(b);
        return quotient % module;
    }

    public long inv(long a) {
        long b = module;
        long u = 1;
        long v = 0;

        while (b > 0) {
            long t = a / b;
            long z = a;
            a = b;
            b = z % module;
            long temp = u;
            u = v;
            v = temp - t * v;
        }

        if (u < 0) u += module;

        return u;
    }
}

