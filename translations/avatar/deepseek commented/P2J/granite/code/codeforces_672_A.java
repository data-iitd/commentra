

import java.util.Scanner;

public class codeforces_672_A{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] li = new int[370];
        int ind = 0;
        // Initialize an array li of size 370 and a variable ind to keep track of the index

        for (int i = 1; i < 371; i++) {
            int[] temp = new int[3];
            int p = i, q = i, count = 0;
            // Initialize a temporary array temp of size 3 and set p and q to the current value of i
            // Initialize a counter count to count the number of digits in i

            while (p!= 0) {
                p /= 10;
                count++;
            }
            // Count the number of digits in i by repeatedly dividing p by 10

            if (count == 1) {
                li[ind] = i;
                ind++;
            }
            // If i has 1 digit, append it to the array li

            if (count == 2) {
                temp = new int[3];
                while (q!= 0) {
                    int x = q % 10;
                    q /= 10;
                    temp[count - 1] = x;
                }
                for (int j = 0; j < count; j++) {
                    li[ind] = temp[j];
                    ind++;
                }
            }
            // If i has 2 digits, extract the digits and append them to li

            if (count == 3) {
                temp = new int[3];
                while (q!= 0) {
                    int x = q % 10;
                    q /= 10;
                    temp[count - 1] = x;
                }
                for (int j = 0; j < count; j++) {
                    li[ind] = temp[j];
                    ind++;
                }
            }
            // If i has 3 digits, extract the digits and append them to li
        }

        li[ind - 1] = 0;
        li[ind - 2] = 0;
        // Remove the last two elements from li

        System.out.println(li[n - 1]);
        // Print the nth element of li based on the user's input
    }
}

Translate the above Java code to C++ and end with comment "