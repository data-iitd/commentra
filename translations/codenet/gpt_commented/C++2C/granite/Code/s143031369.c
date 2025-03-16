
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

// Define a constant for PI using the arccosine function
#define PI acos(-1.0)

// Function to determine the sign of a double value
int sig(double d) {
    return fabs(d) < 1e-8? 0 : d < 0? -1 : 1; // Returns 0 if d is close to 0, -1 if d is negative, 1 if d is positive
}

// Structure to represent a point in 2D space
typedef struct Point {
    double x, y; // Coordinates of the point
    double k; // Additional variable (not used in this code)
} Point;

// Function to calculate the dot product of two vectors defined by points
double dot(Point o, Point a, Point b) {
    return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y);
}

// Overloaded function to calculate the dot product of two points
double dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y; // Standard dot product
}

// Function to calculate the cross product of two vectors defined by points
double cross(Point o, Point a, Point b) {
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

// Function to determine if point x is between points a and b
int btw(Point x, Point a, Point b) {
    return sig(dot(x, a, b)); // Returns the sign of the dot product
}

// Function to calculate the distance between two points
double dis(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); // Euclidean distance
}

// Function to calculate the cosine of the angle between two vectors
double cos(Point o, Point a, Point b) {
    return dot(o, a, b) / dis(o, a) / dis(o, b); // Cosine formula using dot product and distances
}

// Function to compute the convex hull using the Jarvis march algorithm
int jarvis(Point *p, int n, int *ch) {
    static int d, i, o, s, l, t;
    // Find the leftmost point to start the hull
    for(d = i = 0; i < n; i++)
        if(p[i] < p[d])
            d = i;
    
    l = s = *ch = d; // Initialize the starting point
    d = 1; // Index for the convex hull array

    // Loop to find all points in the convex hull
    do {
        o = l; // Current point
        for(i = 0; i < n; i++)
            // Check if point i is more counter-clockwise than the current point l
            if((t = sig(cross(p[o], p[l], p[i]))) > 0 || (t == 0 && btw(p[l], p[o], p[i]) <= 0))
                l = i; // Update the point in the hull
        ch[d++] = l; // Add the point to the convex hull
    } while(l!= s); // Continue until we return to the starting point

    return d - 1; // Return the number of points in the convex hull
}

// Main function
int main() {
    // Initialize angle and answer arrays to zero
    double ang[110], ans[110];
    memset(ang, 0, sizeof(ang));
    memset(ans, 0, sizeof(ans));

    int n, xx, yy; // Number of points and coordinates
    scanf("%d", &n); // Read number of points

    // Read the coordinates of the points
    Point P[110];
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &xx, &yy);
        P[i].x = xx; // Set the x-coordinate for each point
        P[i].y = yy; // Set the y-coordinate for each point
    }

    // Special case for two points
    if(n == 2) {
        puts("0.5"); // Each point contributes equally to the area
        puts("0.5");
    } else {
        // Compute the convex hull
        int m = jarvis(P, n, ch);
        double sum = 0;

        // Special case for two points in the convex hull
        if(m == 2) {
            ans[ch[0]] = 0.5; // Assign equal area to both points
            ans[ch[1]] = 0.5;
        } else {
            // Calculate angles for each point in the convex hull
            for(int i = 0; i < m; i++) {
                ang[ch[i]] = PI - acos(cos(P[ch[i]], P[ch[(i - 1 + m) % m]], P[ch[(i + 1) % m]]));
            }
            // Calculate the area contribution for each point
            for(int i = 0; i < n; i++) {
                ans[i] = ang[i] / 2. / PI; // Normalize the angle to get area contribution
            }
        }

        // Output the area contributions for each point
        for(int i = 0; i < n; i++) {
            printf("%.20f\n", ans[i]); // Print results with high precision
        }
    }
    return 0; // Return success
}

