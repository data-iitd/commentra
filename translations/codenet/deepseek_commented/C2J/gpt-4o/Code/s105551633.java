import java.util.Scanner;

// Define a class for the main functionality
public class Main {
    
    // Function to count the number of digits in a number
    public static int digit(long n) {
        int res = 0;
        while (n > 0) {
            res++;
            n /= 10;
        }
        return res;
    }

    // Main logic of the program
    public static void run() {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        int min = digit(n);
        
        for (int i = 1; (long) i * i <= n; i++) {
            if (n % i != 0) continue;
            long a = i;
            long b = n / i;
            min = Math.min(min, Math.max(digit(a), digit(b)));
        }
        
        System.out.println(min);
        scanner.close();
    }

    // Main function
    public static void main(String[] args) {
        run();
    }
}

// <END-OF-CODE>
