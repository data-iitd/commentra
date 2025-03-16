import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input and split into an array of integers
        String[] input = scanner.nextLine().split(" ");
        int[] cookies = new int[3];
        for (int i = 0; i < 3; i++) {
            cookies[i] = Integer.parseInt(input[i]);
        }
        
        int leftOver = cookies[0] - cookies[2];
        int takahashi = Math.max(0, leftOver);
        
        // Print the result
        if (takahashi > 0) {
            System.out.println(takahashi + " " + cookies[1]);
        } else {
            System.out.println(takahashi + " " + Math.max(0, cookies[1] - Math.abs(leftOver)));
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
