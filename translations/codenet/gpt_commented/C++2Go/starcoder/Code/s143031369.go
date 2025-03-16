package main

import (
    "fmt"
    "math"
)

// Define a constant for PI using the arccosine function
const PI = math.Acos(-1.0)

// Function to determine the sign of a double value
func sig(d float64) int {
    if math.Abs(d) < 1e-8 {
        return 0
    } else if d < 0 {
        return -1
    } else {
        return 1
    }
}

// Structure to represent a point in 2D space
type Point struct {
    x, y float64 // Coordinates of the point
    k    float64 // Additional variable (not used in this code)
}

// Default constructor
func (p *Point) init() {}

// Constructor to initialize point with coordinates
func (p *Point) set(x, y float64) {
    p.x = x
    p.y = y
}

// Method to calculate the modulus (length) of the point vector
func (p *Point) mod() float64 {
    return math.Sqrt(p.x*p.x + p.y*p.y)
}

// Method to calculate the square of the modulus (length squared)
func (p *Point) mod_pow() float64 {
    return p.x*p.x + p.y*p.y
}

// Method to output the coordinates of the point
func (p *Point) output() {
    fmt.Printf("x = %f, y = %f\n", p.x, p.y)
}

// Overloaded operator to compare two points
func (p *Point) less(p2 *Point) bool {
    if sig(p.x-p2.x)!= 0 {
        return p.x < p2.x
    } else {
        return sig(p.y-p2.y) < 0
    }
}

// Function to calculate the dot product of two vectors defined by points
func dot(o Point, a, b Point) float64 {
    return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y)
}

// Overloaded function to calculate the dot product of two points
func dot(a, b Point) float64 {
    return a.x*b.x + a.y*b.y
}

// Function to calculate the cross product of two vectors defined by points
func cross(o Point, a, b Point) float64 {
    return (a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y)
}

// Function to determine if point x is between points a and b
func btw(x, a, b Point) int {
    return sig(dot(x, a, b))
}

// Function to calculate the distance between two points
func dis(a, b Point) float64 {
    return math.Sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))
}

// Function to calculate the cosine of the angle between two vectors
func cos(o, a, b Point) float64 {
    return dot(o, a, b) / dis(o, a) / dis(o, b)
}

// Function to compute the convex hull using the Jarvis march algorithm
func jarvis(p []Point, n int) []int {
    ch := make([]int, n)
    var d, i, o, s, l, t int
    // Find the leftmost point to start the hull
    for d = i = 0; i < n; i++ {
        if p[i].less(&p[d]) {
            d = i
        }
    }
    l = s = ch[0] = d
    d = 1
    // Loop to find all points in the convex hull
    for {
        o = l
        for i = 0; i < n; i++ {
            // Check if point i is more counter-clockwise than the current point l
            if sig(cross(p[o], p[l], p[i])) > 0 || (sig(cross(p[o], p[l], p[i])) == 0 && btw(p[l], p[o], p[i]) <= 0) {
                l = i
            }
        }
        ch[d] = l
        d++
        if l == s {
            break
        }
    }
    return ch[:d]
}

// Main function
func main() {
    var n, xx, yy int
    fmt.Scanf("%d", &n)
    p := make([]Point, n)
    // Read the coordinates of the points
    for i := 0; i < n; i++ {
        fmt.Scanf("%d%d", &xx, &yy)
        p[i].set(float64(xx), float64(yy))
    }
    // Special case for two points
    if n == 2 {
        fmt.Println("0.5") // Each point contributes equally to the area
        fmt.Println("0.5")
    } else {
        ch := jarvis(p, n)
        var m int
        if len(ch) == 2 {
            p[ch[0]].k = 0.5 // Assign equal area to both points
            p[ch[1]].k = 0.5
        } else {
            // Calculate angles for each point in the convex hull
            for i := 0; i < len(ch); i++ {
                p[ch[i]].k = PI - math.Acos(cos(p[ch[i]], p[ch[(i-1+len(ch))%len(ch)]], p[ch[(i+1)%len(ch)]]))
            }
            // Calculate the area contribution for each point
            for i := 0; i < n; i++ {
                p[i].k /= 2. / PI
            }
        }
        // Output the area contributions for each point
        for i := 0; i < n; i++ {
            fmt.Printf("%.20f\n", p[i].k)
        }
    }
}

