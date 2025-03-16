import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read two integers from input: S (the strength) and W (the weight)
        Scanner sc = new Scanner(System.in);
        int S = sc.nextInt();
        int W = sc.nextInt();

        // Check if the strength S is less than or equal to the weight W
        // If it is, print "unsafe"; otherwise, print "safe"
        if (S <= W) {
            System.out.println("unsafe");
        } else {
            System.out.println("safe");
        }
    }
}

