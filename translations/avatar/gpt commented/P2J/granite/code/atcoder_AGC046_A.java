
// Import the gcd function from the Math class to calculate the greatest common divisor
import static java.lang.Math.gcd;

// Take an integer input from the user
import java.util.Scanner;
Scanner scanner = new Scanner(System.in);
int x = scanner.nextInt();

// Calculate and print the number of equal parts in a full circle (360 degrees) 
// that can be formed with the given angle x using the gcd
System.out.println(360 / gcd(360, x));

