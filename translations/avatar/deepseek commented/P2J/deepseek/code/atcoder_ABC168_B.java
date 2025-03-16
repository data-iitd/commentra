import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the value of K from the user
        int K = scanner.nextInt();
        // Read the string S from the user
        String S = scanner.next();
        // Check if the length of S is less than or equal to K
        if (S.length() <= K) {
            // If the length of S is less than or equal to K, return S as it is
            System.out.println(S);
        } else {
            // If the length of S is greater than K, return the first K characters of S followed by '...'
            System.out.println(S.substring(0, K) + "...");
        }
    }
}

