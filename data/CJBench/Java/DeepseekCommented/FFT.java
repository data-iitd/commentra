import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
public final class Main {
    private Main() {
    }

    // Represents a complex number with real and imaginary parts
    public static class Complex {
        private double real;
        private double img;

        // Default constructor initializes complex number to (0 + 0i)
        public Complex() {
            real = 0;
            img = 0;
        }

        // Parameterized constructor initializes complex number to (r + i*i)
        public Complex(double r, double i) {
            real = r;
            img = i;
        }

        // Adds two complex numbers
        public Complex add(Complex z) {
            return new Complex(this.real + z.real, this.img + z.img);
        }

        // Subtracts one complex number from another
        public Complex subtract(Complex z) {
            return new Complex(this.real - z.real, this.img - z.img);
        }

        // Multiplies two complex numbers
        public Complex multiply(Complex z) {
            return new Complex(this.real * z.real - this.img * z.img, this.real * z.img + this.img * z.real);
        }

        // Multiplies a complex number by a real number
        public Complex multiply(double n) {
            return new Complex(this.real * n, this.img * n);
        }

        // Divides a complex number by a real number
        public Complex divide(double n) {
            return new Complex(this.real / n, this.img / n);
        }

        // Returns a string representation of the complex number
        @Override
        public String toString() {
            return String.format("%.6f + %.6fi", real, img);
        }
    }

    // Computes the Fast Fourier Transform of a list of complex numbers
    public static ArrayList<Complex> fft(ArrayList<Complex> x, boolean inverse) {
        // Ensures the input size is a power of two by padding with zeros
        padToPowerOfTwo(x);
        int n = x.size();
        int log2n = (int) (Math.log(n) / Math.log(2));

        // Performs bit reversal on the input list
        bitReversal(x, log2n);
        int direction = inverse ? -1 : 1;

        // Main loop for the FFT algorithm
        for (int len = 2; len <= n; len *= 2) {
            double angle = -2 * Math.PI / len * direction;
            Complex wlen = new Complex(Math.cos(angle), Math.sin(angle));
            for (int i = 0; i < n; i += len) {
                Complex w = new Complex(1, 0);
                for (int j = 0; j < len / 2; j++) {
                    Complex u = x.get(i + j);
                    Complex v = w.multiply(x.get(i + j + len / 2));
                    x.set(i + j, u.add(v));
                    x.set(i + j + len / 2, u.subtract(v));
                    w = w.multiply(wlen);
                }
            }
        }

        // Adjusts the result for inverse FFT
        if (inverse) {
            for (int i = 0; i < n; i++) {
                x.set(i, x.get(i).divide(n));
            }
        }
        return x;
    }

    // Ensures the input list size is a power of two by padding with zeros
    private static void padToPowerOfTwo(ArrayList<Complex> x) {
        int n = 1;
        while (n < x.size()) {
            n *= 2;
        }
        while (x.size() < n) {
            x.add(new Complex());
        }
    }

    // Performs bit reversal on the input list
    private static void bitReversal(ArrayList<Complex> x, int log2n) {
        for (int i = 0; i < x.size(); i++) {
            int reverse = Integer.reverse(i) >>> (32 - log2n);
            if (i < reverse) {
                Collections.swap(x, i, reverse);
            }
        }
    }

    // Main method to read input, compute FFT, and print the result
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList<Complex> input = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            double real = scanner.nextDouble();
            double img = scanner.nextDouble();
            input.add(new Complex(real, img));
        }
        boolean inverse = scanner.nextBoolean();
        ArrayList<Complex> result = fft(input, inverse);
        System.out.println("Main Result:");
        for (Complex c : result) {
            System.out.println(c);
        }
    }
}
