

import java.util.*;
import java.io.*;

public class atcoder_ABC123_C{
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[5];
        for (int i = 0; i < 5; i++) {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
        System.out.println((int)Math.ceil(n / (double)a[0]) + 4);
    }
}

# Step 1: Import necessary modules for input/output operations and array manipulation.

# Step 2: Read an integer input N which represents some quantity or value.

# Step 3: Read five integer inputs and store them in an array A. This array will be used to determine the minimum value among these integers.

# Step 4: Calculate the result by dividing N by the smallest value in A and rounding up to the nearest integer, then add 4 to the result. Finally, print the result.


Translate the above Java code to C++ and end with comment "