#######
# Import necessary libraries
#######

import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

#######
# Function to read integers from the standard input
#######

public static int[] readInts() {
    Scanner sc = new Scanner(System.in);
    String[] str = sc.nextLine().split(" ");
    int[] A = new int[str.length];
    for (int i = 0; i < str.length; i++) {
        A[i] = Integer.parseInt(str[i]);
    }
    return A;
}

#######
# Main function
#######

public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] A = readInts();
    Arrays.sort(A);
    int ans = 0;
    for (int i = A.length - 2; i >= A.length - 2 * n - 1; i -= 2) {
        ans += A[i];
    }
    System.out.println(ans);
}

#######
# Run the main function if the script is run as the main module
#######

if __name__ == '__main__':
    main()

