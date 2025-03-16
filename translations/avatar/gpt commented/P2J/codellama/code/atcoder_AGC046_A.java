// Import the Math class to access the gcd method
import java.lang.Math;

// Take an integer input from the user
Scanner sc = new Scanner(System.in);
int x = sc.nextInt();

// Calculate and print the number of equal parts in a full circle (360 degrees) 
// that can be formed with the given angle x using the gcd
System.out.println(360 / Math.gcd(360, x));

