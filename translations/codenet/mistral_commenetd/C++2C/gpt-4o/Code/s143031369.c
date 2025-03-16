// Include necessary libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Define a constant value
const double PI = acos(-1.0);

// Define a function to determine the sign of a double value
int sig(double d) {
    return fabs(d) < 1e-8 ? 0 : d < 0 ? -1 : 1;
}

// Define a Point structure
struct Point {
    double x, y;
};

// Define an array of Points P
struct Point P[110];

// Define an array ch to store the indices of the points in the convex hull
int ch[110];

// Define arrays ang and ans to store the angles and answers respectively
double ang[110], ans[110];

// Calculate the dot product of three Points
double dot(struct Point *o, struct Point *a, struct Point *b) {
    return (a->x - o->x) * (b->x - o->x) + (a->y - o->y) * (b->y - o->y);
}

// Calculate the cross product of a Point and two other Points
double cross(struct Point o, struct Point a, struct Point b) {
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

// Check if a Point is between two other Points on the counterclockwise arc
int btw(struct Point *x, struct Point *a, struct Point *b) {
    return sig(dot(x, a, b));
}

// Calculate the distance between two Points
double dis(struct Point a, struct Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Calculate the cosine of the angle between a line passing through two Points and a given Point
double cos_angle(struct Point *o, struct Point *a, struct Point *b) {
    return dot(o, a, b) / dis(*o, *a) / dis(*o, *b);
}

// Find the convex hull of a set of Points using Jarvis March algorithm
int jarvis(struct Point *p, int n, int *ch) {
    int d, i, o, s, l, t;
    for (d = i = 0; i < n; i++)
        if (p[i].x < p[d].x || (p[i].x == p[d].x && p[i].y < p[d].y))
            d = i;
    l = s = *ch = d;
    d = 1;
    do {
        o = l;
        for (i = 0; i < n; i++) {
            t = sig(cross(p[o], p[l], p[i]));
            if (t > 0 || (t == 0 && btw(&p[l], &p[o], &p[i]) <= 0))
                l = i;
        }
        ch[d++] = l;
    } while (l != s);
    return d - 1;
}

// Main function to read input and calculate the answers
int main() {
    memset(ang, 0, sizeof(ang));
    memset(ans, 0, sizeof(ans));
    
    // Read the number of Points
    int n;
    scanf("%d", &n);
    
    // Initialize the Points
    for (int i = 0; i < n; i++) {
        double xx, yy;
        scanf("%lf%lf", &xx, &yy);
        P[i].x = xx;
        P[i].y = yy;
    }
    
    // Special case for 2 Points
    if (n == 2) {
        // Output the answers
        puts("0.5");
        puts("0.5");
    } else {
        // Find the convex hull of the Points
        int m = jarvis(P, n, ch);
        
        // Calculate the angles for the Points in the convex hull
        if (m == 2) {
            // Set the answers for the first and second Points
            ans[ch[0]] = 0.5;
            ans[ch[1]] = 0.5;
        } else {
            // Calculate the angles for all the Points in the convex hull
            for (int i = 0; i < m; i++) {
                ang[ch[i]] = PI - acos(cos_angle(&P[ch[i]], &P[ch[(i - 1 + m) % m]], &P[ch[(i + 1) % m]]));
            }
            // Calculate the answers for all the Points
            for (int i = 0; i < n; i++) {
                ans[i] = ang[i] / 2.0 / PI;
            }
        }
        // Output the answers for all the Points
        for (int i = 0; i < n; i++) {
            printf("%.20f\n", ans[i]);
        }
    }
    // Return 0 to indicate successful execution
    return 0;
}

// <END-OF-CODE>
