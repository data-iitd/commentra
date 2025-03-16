import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from input: S (the strength) and W (the weight)
        int S = scanner.nextInt();
        int W = scanner.nextInt();
        
        // Check if the strength S is less than or equal to the weight W
        // If it is, print "unsafe"; otherwise, print "safe"
        if (S <= W) {
            System.out.println("unsafe");
        } else {
            System.out.println("safe");
        }
    }
}
