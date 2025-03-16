public class Main {
    public static void main(String[] args) {
        // Step 3: Input a string
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String N = scanner.nextLine();

        // Step 4: Calculate the sum of digits
        int S = 0;
        for (int i = 0; i < N.length(); i++) {
            S += N.charAt(i) - '0';
        }

        // Step 5: Check if the number is divisible by the sum of its digits
        int number = Integer.parseInt(N);
        if (number % S == 0) 
            System.out.println("Yes");
        else 
            System.out.println("No");

        // Step 6: Return 0
    }
}
