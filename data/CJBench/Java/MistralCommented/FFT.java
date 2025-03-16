
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class from outside
    }

    public static class Complex {
        // Define a complex number class with private real and img fields, constructors, methods for addition, subtraction, multiplication, division, and a toString method to print complex numbers in a readable format
        // ...
    }

    public static ArrayList<Complex> fft(ArrayList<Complex> x, boolean inverse) {
        // Fast Fourier Transform method that takes an ArrayList of Complex numbers 'x' and a boolean flag 'inverse' indicating whether to perform inverse FFT or not

        // Pad the input ArrayList to a power of 2 size using empty Complex numbers
        padToPowerOfTwo(x);

        // Calculate the number of bits required to represent the size of the input ArrayList
        int n = x.size();
        int log2n = (int) (Math.log(n) / Math.log(2));

        // Perform bit reversal on the input ArrayList to reorder the elements
        bitReversal(x, log2n);

        // Iterate through the input ArrayList and perform Cooley-Tukey FFT algorithm
        int direction = inverse ? -1 : 1;
        for (int len = 2; len <= n; len *= 2) {
            // Calculate the angle for the current length of the DIT (Decimation in Time) FFT
            double angle = -2 * Math.PI / len * direction;

            // Create a Complex number 'wlen' representing the length 'len' of the current DIT
            Complex wlen = new Complex(Math.cos(angle), Math.sin(angle));

            // Iterate through the input ArrayList in chunks of length 'len' and perform butterfly operations
            for (int i = 0; i < n; i += len) {
                Complex w = new Complex(1, 0); // Initialize a Complex number 'w' for the current stage of the butterfly

                // Iterate through the first half of the current chunk and perform butterfly operations
                for (int j = 0; j < len / 2; j++) {
                    Complex u = x.get(i + j); // Get the Complex number 'u' from the current chunk
                    Complex v = w.multiply(x.get(i + j + len / 2)); // Multiply 'w' with the Complex number 'v' from the next chunk
                    x.set(i + j, u.add(v)); // Add the results and store them in the current chunk
                    x.set(i + j + len / 2, u.subtract(v)); // Subtract the results and store them in the next chunk
                    w = w.multiply(wlen); // Multiply 'w' with 'wlen' for the next stage of the butterfly
                }
            }
        }

        // If inverse FFT is requested, divide each complex number by the size of the input ArrayList to get the inverse FFT result
        if (inverse) {
            for (int i = 0; i < n; i++) {
                x.set(i, x.get(i).divide(n));
            }
        }

        // Return the ArrayList of Complex numbers representing the FFT or inverse FFT result
        return x;
    }

    // Helper methods for padding the input ArrayList to a power of 2 size and performing bit reversal on the input ArrayList
    private static void padToPowerOfTwo(ArrayList<Complex> x) {
        int n = 1;
        while (n < x.size()) {
            n *= 2;
        }
        while (x.size() < n) {
            x.add(new Complex());
        }
    }

    private static void bitReversal(ArrayList<Complex> x, int log2n) {
        // Perform bit reversal on the input ArrayList to reorder the elements
        for (int i = 0; i < x.size(); i++) {
            int reverse = Integer.reverse(i) >>> (32 - log2n); // Calculate the reverse bit index of the current index 'i'
            if (i < reverse) { // If the current index 'i' is smaller than the reverse index, swap the elements in the input ArrayList
                Collections.swap(x, i, reverse);
            }
        }
    }

    public static void main(String[] args) {
        // Main method to read input from the user, perform FFT or inverse FFT, and print the results

        Scanner scanner = new Scanner(System.in); // Initialize a Scanner object to read input from the user

        int n = scanner.nextInt(); // Read the number of complex numbers 'n' from the user
        ArrayList<Complex> input = new ArrayList<>(); // Create an empty ArrayList to store the input complex numbers

        for (int i = 0; i < n; i++) {
            double real = scanner.nextDouble(); // Read the real part of the complex number 'i' from the user
            double img = scanner.nextDouble(); // Read the imaginary part of the complex number 'i' from the user
            input.add(new Complex(real, img)); // Add the complex number 'i' to the input ArrayList
        }

        boolean inverse = scanner.nextBoolean(); // Read the boolean flag 'inverse' indicating whether to perform inverse FFT or not

        ArrayList<Complex> result = fft(input, inverse); // Perform FFT or inverse FFT on the input ArrayList and store the result in a new ArrayList

        System.out.println("Main Result:"); // Print the header for the main result
        for (Complex c : result) { // Iterate through the ArrayList of Complex numbers and print each complex number in a readable format
            System.out.println(c);
        }
    }
}