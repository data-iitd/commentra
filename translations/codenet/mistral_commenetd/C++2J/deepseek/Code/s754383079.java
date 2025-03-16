import java.util.Scanner;

public class Main {
    static final int M = 1010; // maximum size of strings a and b
    static char[] a = new char[M]; // strings a and b
    static char[] b = new char[M]; // strings a and b
    static int n, m, ans = M + 10; // n is the length of string a, m is the length of string b, ans is the minimum number of differences between strings a and b

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // read string a from standard input
        String input = scanner.nextLine();
        a = (" " + input).toCharArray(); // get the length of string a
        n = a.length - 1;

        // read string b from standard input
        input = scanner.nextLine();
        b = (" " + input).toCharArray(); // get the length of string b
        m = b.length - 1;

        // iterate through all possible substrings of string a that have the same length as string b
        for (int i = 1; i + m - 1 <= n; i++) {
            // initialize sum to 0, it will be used to count the number of differences between the i-th substring of string a and string b
            int sum = 0;

            // iterate through each character in the substring of string a and compare it with the corresponding character in string b
            for (int j = 1; j <= m; j++)
                // if the characters are different, increment sum by 1
                if (a[i + j - 1] != b[j])
                    sum++;

            // update the minimum number of differences if a smaller number is found
            ans = Math.min(ans, sum);
        }

        // print the minimum number of differences to standard output
        System.out.println(ans);

        // terminate the program with exit code 0
        scanner.close();
    }
}
