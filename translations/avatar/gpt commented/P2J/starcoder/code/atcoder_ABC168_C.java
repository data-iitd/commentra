// Read input values for hours (h), minutes (m), and lengths (a, b)
Scanner scanner = new Scanner(System.in);
int a = scanner.nextInt();
int b = scanner.nextInt();
int h = scanner.nextInt();
int m = scanner.nextInt();

// Import the math module for mathematical functions
import java.lang.Math;

// Calculate the angle C between the hour and minute hands of the clock
// The formula calculates the absolute difference in degrees
int C = Math.abs(360 / 60 * m - 360 / 12 * h - 360 / 12 / 60 * m);

// If the angle is greater than 180 degrees, find the smaller angle
if (C > 180) {
    C = 360 - C;
}

// Calculate the cosine of angle C in radians
double cosC = Math.cos(Math.toRadians(C));

// Use the Law of Cosines to calculate the length of the third side of the triangle
// formed by the lengths a, b, and the angle C
System.out.println(Math.sqrt(a * a + b * b - 2 * a * b * cosC));

