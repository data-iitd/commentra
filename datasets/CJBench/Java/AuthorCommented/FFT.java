import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 * Class for calculating the Fast Fourier Transform (FFT) of a discrete signal
 * using the Cooley-Tukey algorithm.
 *
 * @author Ioannis Karavitsis
 * @version 1.0
 */
public final class FFT {
    private FFT() {
    }

    /**
     * This class represents a complex number and has methods for basic
     * operations.
     *
     * <p>
     * More info:
     * https://introcs.cs.princeton.edu/java/32class/Complex.java.html
     */
    public static class Complex {
        private double real;
        private double img;

        public Complex() {
            real = 0;
            img = 0;
        }

        /**
         * Constructor. Creates a complex number.
         *
         * @param r The real part of the number.
         * @param i The imaginary part of the number.
         */
        public Complex(double r, double i) {
            real = r;
            img = i;
        }

        /**
         * Adds this complex number to another.
         *
         * @param z The number to be added.
         * @return The sum.
         */
        public Complex add(Complex z) {
            return new Complex(this.real + z.real, this.img + z.img);
        }

        /**
         * Subtracts a number from this complex number.
         *
         * @param z The number to be subtracted.
         * @return The difference.
         */
        public Complex subtract(Complex z) {
            return new Complex(this.real - z.real, this.img - z.img);
        }

        /**
         * Multiplies this complex number by another.
         *
         * @param z The number to be multiplied.
         * @return The product.
         */
        public Complex multiply(Complex z) {
            return new Complex(this.real * z.real - this.img * z.img, this.real * z.img + this.img * z.real);
        }

        /**
         * Multiplies this complex number by a scalar.
         *
         * @param n The real number to be multiplied.
         * @return The product.
         */
        public Complex multiply(double n) {
            return new Complex(this.real * n, this.img * n);
        }

        public Complex divide(double n) {
            return new Complex(this.real / n, this.img / n);
        }

        @Override
        public String toString() {
            return String.format("%.6f + %.6fi", real, img);
        }
    }

    /**
     * Iterative In-Place Radix-2 Cooley-Tukey Fast Fourier Transform Algorithm
     * with Bit-Reversal. The size of the input signal must be a power of 2. If
     * it isn't then it is padded with zeros and the output FFT will be bigger
     * than the input signal.
     *
     * <p>
     * More info:
     * https://www.algorithm-archive.org/contents/cooley_tukey/cooley_tukey.html
     * https://www.geeksforgeeks.org/iterative-fast-fourier-transformation-polynomial-multiplication/
     * https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm
     * https://cp-algorithms.com/algebra/fft.html
     *  @param x The discrete signal which is then converted to the FFT or the
     * IFFT of signal x.
     * @param inverse True if you want to find the inverse FFT.
     * @return
     */
    public static ArrayList<Complex> fft(ArrayList<Complex> x, boolean inverse) {
        /* Pad the signal with zeros if necessary */
        padToPowerOfTwo(x);
        int n = x.size();
        int log2n = (int) (Math.log(n) / Math.log(2));
        bitReversal(x, log2n);

        int direction = inverse ? -1 : 1;

        /* Main loop of the algorithm */
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

        if (inverse) {
            for (int i = 0; i < n; i++) {
                x.set(i, x.get(i).divide(n));
            }
        }

        return x;
    }

    /**
     * This method pads an ArrayList with zeros in order to have a size equal to
     * the next power of two of the previous size.
     *
     * @param x The ArrayList to be padded.
     */
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
        for (int i = 0; i < x.size(); i++) {
            int reverse = Integer.reverse(i) >>> (32 - log2n);
            if (i < reverse) {
                Collections.swap(x, i, reverse);
            }
        }
    }

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
        System.out.println("FFT Result:");
        for (Complex c : result) {
            System.out.println(c);
        }
    }
}
