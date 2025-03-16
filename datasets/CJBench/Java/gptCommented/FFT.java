import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the Main class
    private Main() {
    }

    // Class to represent a complex number
    public static class Complex {
        private double real; // Real part of the complex number
        private double img;  // Imaginary part of the complex number

        // Default constructor initializes complex number to 0 + 0i
        public Complex() {
            real = 0;
            img = 0;
        }

        // Constructor to initialize complex number with given real and imaginary parts
        public Complex(double r, double i) {
            real = r;
            img = i;
        }

        // Method to add two complex numbers
        public Complex add(Complex z) {
            return new Complex(this.real + z.real, this.img + z.img);
        }

        // Method to subtract one complex number from another
        public Complex subtract(Complex z) {
            return new Complex(this.real - z.real, this.img - z.img);
        }

        // Method to multiply two complex numbers
        public Complex multiply(Complex z) {
            return new Complex(this.real * z.real - this.img * z.img, this.real * z.img + this.img * z.real);
        }

        // Method to multiply a complex number by a real number
        public Complex multiply(double n) {
            return new Complex(this.real * n, this.img * n);
        }

        // Method to divide a complex number by a real number
        public Complex divide(double n) {
            return new Complex(this.real / n, this.img / n);
        }

        // Override toString method to format complex number as a string
        @Override
        public String toString() {
            return String.format("%.6f + %.6fi", real, img);
        }
    }

    // Method to perform Fast Fourier Transform (FFT) or Inverse FFT
    public static ArrayList<Complex> fft(ArrayList<Complex> x, boolean inverse) {
        // Pad the input list to the next power of two
        padToPowerOfTwo(x);
        int n = x.size(); // Size of the input array
        int log2n = (int) (Math.log(n) / Math.log(2)); // Calculate log base 2 of n
        bitReversal(x, log2n); // Perform bit-reversal permutation

        // Determine the direction of the FFT (forward or inverse)
        int direction = inverse ? -1 : 1;

        // Main FFT computation loop
        for (int len = 2; len <= n; len *= 2) {
            double angle = -2 * Math.PI / len * direction; // Calculate angle for the current length
            Complex wlen = new Complex(Math.cos(angle), Math.sin(angle)); // Calculate the complex root of unity

            // Perform the FFT computation
            for (int i = 0; i < n; i += len) {
                Complex w = new Complex(1, 0); // Initialize w to 1
                for (int j = 0; j < len / 2; j++) {
                    Complex u = x.get(i + j); // First half of the data
                    Complex v = w.multiply(x.get(i + j + len / 2)); // Second half of the data
                    x.set(i + j, u.add(v)); // Combine results
                    x.set(i + j + len / 2, u.subtract(v)); // Store results
                    w = w.multiply(wlen); // Update w for the next iteration
                }
            }
        }

        // If performing inverse FFT, normalize the results
        if (inverse) {
            for (int i = 0; i < n; i++) {
                x.set(i, x.get(i).divide(n)); // Divide each element by n
            }
        }
        return x; // Return the transformed array
    }

    // Method to pad the input array to the next power of two
    private static void padToPowerOfTwo(ArrayList<Complex> x) {
        int n = 1;
        // Find the next power of two greater than or equal to the size of x
        while (n < x.size()) {
            n *= 2;
        }
        // Add zero-initialized complex numbers until the size is a power of two
        while (x.size() < n) {
            x.add(new Complex());
        }
    }

    // Method to perform bit-reversal permutation on the input array
    private static void bitReversal(ArrayList<Complex> x, int log2n) {
        for (int i = 0; i < x.size(); i++) {
            int reverse = Integer.reverse(i) >>> (32 - log2n); // Calculate the bit-reversed index
            // Swap elements if necessary
            if (i < reverse) {
                Collections.swap(x, i, reverse);
            }
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        int n = scanner.nextInt(); // Read the number of complex numbers
        ArrayList<Complex> input = new ArrayList<>(); // Initialize the input list

        // Read complex numbers from input
        for (int i = 0; i < n; i++) {
            double real = scanner.nextDouble(); // Read real part
            double img = scanner.nextDouble(); // Read imaginary part
            input.add(new Complex(real, img)); // Add complex number to the list
        }

        boolean inverse = scanner.nextBoolean(); // Read whether to perform inverse FFT
        ArrayList<Complex> result = fft(input, inverse); // Perform FFT or inverse FFT

        // Output the results
        System.out.println("Main Result:");
        for (Complex c : result) {
            System.out.println(c); // Print each complex number in the result
        }
    }
}
