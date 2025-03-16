#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_POINTS 110
<<<<<<< HEAD
=======
#define EPSILON 1e-8
>>>>>>> 98c87cb78a (data updated)

// Define a constant for PI using the arccosine function
const double PI = acos(-1.0);

// Function to determine the sign of a double value
int sig(double d) {
<<<<<<< HEAD
    return fabs(d) < 1e-8 ? 0 : d < 0 ? -1 : 1; // Returns 0 if d is close to 0, -1 if d is negative, 1 if d is positive
=======
    return fabs(d) < EPSILON ? 0 : d < 0 ? -1 : 1; // Returns 0 if d is close to 0, -1 if d is negative, 1 if d is positive
>>>>>>> 98c87cb78a (data updated)
}

// Structure to represent a point in 2D space
typedef struct {
    double x, y; // Coordinates of the point
} Point;

<<<<<<< HEAD
Point P[MAX_POINTS]; // Array to hold up to 110 points
int ch[MAX_POINTS]; // Array to hold the indices of the convex hull points
double ang[MAX_POINTS], ans[MAX_POINTS]; // Arrays to hold angles and results

=======
>>>>>>> 98c87cb78a (data updated)
// Function to calculate the dot product of two vectors defined by points
double dot(Point *o, Point *a, Point *b) {
    return (a->x - o->x) * (b->x - o->x) + (a->y - o->y) * (b->y - o->y);
}

// Function to calculate the cross product of two vectors defined by points
double cross(Point o, Point a, Point b) {
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

// Function to determine if point x is between points a and b
int btw(Point *x, Point *a, Point *b) {
    return sig(dot(x, a, b)); // Returns the sign of the dot product
}

// Function to calculate the distance between two points
double dis(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); // Euclidean distance
}

// Function to calculate the cosine of the angle between two vectors
double cos(Point o, Point a, Point b) {
    return dot(&o, &a, &b) / dis(o, a) / dis(o, b); // Cosine formula using dot product and distances
}

// Function to compute the convex hull using the Jarvis march algorithm
int jarvis(Point *p, int n, int *ch) {
    int d, i, o, s, l, t;
    // Find the leftmost point to start the hull
<<<<<<< HEAD
    for(d = i = 0; i < n; i++)
        if(p[i].x < p[d].x || (p[i].x == p[d].x && p[i].y < p[d].y))
            d = i;
    
=======
    for (d = i = 0; i < n; i++)
        if (p[i].x < p[d].x || (p[i].x == p[d].x && p[i].y < p[d].y))
            d = i;

>>>>>>> 98c87cb78a (data updated)
    l = s = ch[0] = d; // Initialize the starting point
    d = 1; // Index for the convex hull array

    // Loop to find all points in the convex hull
    do {
        o = l; // Current point
<<<<<<< HEAD
        for(i = 0; i < n; i++)
            // Check if point i is more counter-clockwise than the current point l
            if((t = sig(cross(p[o], p[l], p[i]))) > 0 || (t == 0 && btw(&p[l], &p[o], &p[i]) <= 0))
                l = i; // Update the point in the hull
        ch[d++] = l; // Add the point to the convex hull
    } while(l != s); // Continue until we return to the starting point
=======
        for (i = 0; i < n; i++)
            // Check if point i is more counter-clockwise than the current point l
            if ((t = sig(cross(p[o], p[l], p[i]))) > 0 || (t == 0 && btw(&p[l], &p[o], &p[i]) <= 0))
                l = i; // Update the point in the hull
        ch[d++] = l; // Add the point to the convex hull
    } while (l != s); // Continue until we return to the starting point
>>>>>>> 98c87cb78a (data updated)

    return d - 1; // Return the number of points in the convex hull
}

// Main function
int main() {
<<<<<<< HEAD
    // Initialize angle and answer arrays to zero
    memset(ang, 0, sizeof(ang));
    memset(ans, 0, sizeof(ans));
=======
    double ang[MAX_POINTS] = {0}; // Array to hold angles
    double ans[MAX_POINTS] = {0}; // Array to hold results
    Point P[MAX_POINTS]; // Array to hold points
    int ch[MAX_POINTS]; // Array to hold the indices of the convex hull points
>>>>>>> 98c87cb78a (data updated)

    int n, xx, yy; // Number of points and coordinates
    scanf("%d", &n); // Read number of points

    // Read the coordinates of the points
<<<<<<< HEAD
    for(int i = 0; i < n; i++) {
=======
    for (int i = 0; i < n; i++) {
>>>>>>> 98c87cb78a (data updated)
        scanf("%d%d", &xx, &yy);
        P[i].x = xx; // Set the x coordinate for each point
        P[i].y = yy; // Set the y coordinate for each point
    }

    // Special case for two points
<<<<<<< HEAD
    if(n == 2) {
=======
    if (n == 2) {
>>>>>>> 98c87cb78a (data updated)
        puts("0.5"); // Each point contributes equally to the area
        puts("0.5");
    } else {
        // Compute the convex hull
        int m = jarvis(P, n, ch);
        double sum = 0;

        // Special case for two points in the convex hull
<<<<<<< HEAD
        if(m == 2) {
=======
        if (m == 2) {
>>>>>>> 98c87cb78a (data updated)
            ans[ch[0]] = 0.5; // Assign equal area to both points
            ans[ch[1]] = 0.5;
        } else {
            // Calculate angles for each point in the convex hull
<<<<<<< HEAD
            for(int i = 0; i < m; i++) {
                ang[ch[i]] = PI - acos(cos(P[ch[i]], P[ch[(i - 1 + m) % m]], P[ch[(i + 1) % m]]));
            }
            // Calculate the area contribution for each point
            for(int i = 0; i < n; i++) {
                ans[i] = ang[i] / 2. / PI; // Normalize the angle to get area contribution
=======
            for (int i = 0; i < m; i++) {
                ang[ch[i]] = PI - acos(cos(P[ch[i]], P[ch[(i - 1 + m) % m]], P[ch[(i + 1) % m]]));
            }
            // Calculate the area contribution for each point
            for (int i = 0; i < n; i++) {
                ans[i] = ang[i] / 2.0 / PI; // Normalize the angle to get area contribution
>>>>>>> 98c87cb78a (data updated)
            }
        }

        // Output the area contributions for each point
<<<<<<< HEAD
        for(int i = 0; i < n; i++) {
=======
        for (int i = 0; i < n; i++) {
>>>>>>> 98c87cb78a (data updated)
            printf("%.20f\n", ans[i]); // Print results with high precision
        }
    }
    return 0; // Return success
}

// <END-OF-CODE>
