import java.util.Scanner;

public class CookieDistribution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking input from the user and converting it into an array of integers
        String[] input = scanner.nextLine().split(" ");
        int[] cookies = new int[3];
        for (int i = 0; i < 3; i++) {
            cookies[i] = Integer.parseInt(input[i]);
        }
        
        // Calculating the difference between the first and third elements of the array
        int leftOver = cookies[0] - cookies[2];
        
        // Calculating the number of cookies Takahashi gets, ensuring it's not negative
        int takahashi = Math.max(0, leftOver);
        
        // Printing the result, including the number of cookies Takahashi gets and the number of cookies left for Aoki
        if (takahashi > 0) {
            System.out.println(takahashi + " " + cookies[1]);
        } else {
            System.out.println(takahashi + " " + Math.max(0, cookies[1] - Math.abs(leftOver)));
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
