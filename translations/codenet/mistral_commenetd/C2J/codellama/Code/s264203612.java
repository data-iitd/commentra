
public class Main {
    public static void main(String[] args) {
        double r; // Declare a variable 'r' of type double
        double s, l; // Declare two variables 's' and 'l' of type double
        double p = 3.141592653589; // Initialize a constant variable 'p' with the value of pi

        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the standard input
        r = sc.nextDouble(); // Read a value of type double from the standard input and store it in variable 'r'

        s = r*r*p; // Calculate the area of a circle with radius 'r' and store it in variable 's'
        l = 2*p*r; // Calculate the circumference of a circle with radius 'r' and store it in variable 'l'

        System.out.printf("%f %f\n",s,l); // Print the values of 's' and 'l' to the standard output
    }
}

