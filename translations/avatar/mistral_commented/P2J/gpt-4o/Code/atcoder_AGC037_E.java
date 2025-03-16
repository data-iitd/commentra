import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Define input variables
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        String S = scanner.next();

        // Initialize a flag variable
        boolean aaaa = false;

        // Check if K is greater than or equal to 15
        if (K >= 15) {
            // If so, set the flag variable to True
            aaaa = true;
        } 
        // Else, check if 2^K is greater than or equal to N
        else if (Math.pow(2, K) >= N) {
            // If so, set the flag variable to True
            aaaa = true;
        }

        // If the flag variable is True, print the result and exit the function
        if (aaaa) {
            StringBuilder result = new StringBuilder();
            for (int i = 0; i < N; i++) {
                result.append(Character.min(S.charAt(0), S.charAt(0)));
            }
            System.out.println(result.toString());
            return;
        }

        // Get the last dictionary of the string S
        S = getLastDict(S, N);

        // If K is equal to 1, print the string S
        if (K == 1) {
            System.out.println(S);
        } else {
            int count = 0;
            for (char c : S.toCharArray()) {
                // If the current character is the same as the first character, increment the count
                if (c == S.charAt(0)) {
                    count++;
                } else {
                    break;
                }
            }
            // If the count is greater than or equal to N/2^(K-1), print the string consisting of the first character repeated N times
            if (count * (int) Math.pow(2, K - 1) >= N) {
                StringBuilder result = new StringBuilder();
                for (int i = 0; i < N; i++) {
                    result.append(S.charAt(0));
                }
                System.out.println(result.toString());
            } else {
                StringBuilder result = new StringBuilder();
                for (int i = 0; i < count * (int) Math.pow(2, K - 1) - 1; i++) {
                    result.append(S.charAt(0));
                }
                result.append(S);
                System.out.println(result.substring(0, N));
            }
        }
    }

    // Define a function to get the last dictionary of the string S
    private static String getLastDict(String sStr, int N) {
        // Create a new string U by concatenating S with its reverse
        String U = sStr + new StringBuilder(sStr).reverse().toString();
        // Find the minimum character in S
        char c = Character.MIN_VALUE;
        for (char ch : sStr.toCharArray()) {
            if (c == Character.MIN_VALUE || ch < c) {
                c = ch;
            }
        }
        // Find the index of the first occurrence of the minimum character in U
        int p = U.indexOf(c);
        // Initialize a variable minindex to store the index of the first occurrence of the minimum character in S
        int minindex = p;
        // Move the pointer p to the next character in U
        p++;
        // Check if the substring starting from the current pointer and of length N is a normal dictionary
        while (p <= N) {
            // If the character at the current pointer in U is the same as the minimum character,
            // and if the substring starting from the current pointer and of length N is a normal dictionary,
            // update the index minindex
            if (U.charAt(p) == c && checkNormalDict(U, minindex, p, N)) {
                minindex = p;
            }
            // Move the pointer p to the next character in U
            p++;
        }
        // Return the substring starting from minindex and of length N
        return U.substring(minindex, minindex + N);
    }

    // Define a function to check if a substring is a normal dictionary
    private static boolean checkNormalDict(String u, int pointer1, int pointer2, int N) {
        // Iterate through each character in the substring of length N
        for (int i = 0; i < N; i++) {
            // If the character at pointer1+i in U is greater than the character at pointer2+i,
            // return True (indicating that the substring is a normal dictionary)
            if (u.charAt(pointer1 + i) > u.charAt(pointer2 + i)) {
                return true;
            } 
            // Else, if the character at pointer1+i is less than the character at pointer2+i,
            // return False (indicating that the substring is not a normal dictionary)
            else if (u.charAt(pointer1 + i) < u.charAt(pointer2 + i)) {
                return false;
            }
        }
        // If none of the above conditions are met, return False
        return false;
    }
}
// <END-OF-CODE>
