
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] li = new int[370];
        int ind = 0;
        // Initialize an empty list and a variable to keep track of the index

        for (int i = 1; i <= 370; i++) {
            int[] temp = new int[370];
            int p = i, q = i, count = 0;
            // Initialize an empty temporary list and set p and q to the current value of i
            // Initialize a counter to count the number of digits in i

            while (p != 0) {
                p /= 10;
                count++;
            }
            // Count the number of digits in i by repeatedly dividing p by 10

            if (count == 1) {
                li[ind] = i;
                ind++;
            }
            // If i has 1 digit, append it to the list li

            if (count == 2) {
                temp = new int[370];
                while (q != 0) {
                    int x = q % 10;
                    q /= 10;
                    temp[ind] = x;
                    ind++;
                }
                for (int j = 0; j < temp.length; j++) {
                    li[j] = temp[temp.length - j - 1];
                }
            }
            // If i has 2 digits, extract the digits and reverse them, then append to li

            if (count == 3) {
                temp = new int[370];
                while (q != 0) {
                    int x = q % 10;
                    q /= 10;
                    temp[ind] = x;
                    ind++;
                }
                for (int j = 0; j < temp.length; j++) {
                    li[j] = temp[temp.length - j - 1];
                }
            }
            // If i has 3 digits, extract the digits and reverse them, then append to li

        }
        li = new int[ind];
        for (int i = 0; i < li.length; i++) {
            li[i] = li[i];
        }
        li = Arrays.copyOfRange(li, 0, li.length - 2);
        // Remove the last two elements from li

        System.out.println(li[n - 1]);
        // Print the nth element of li based on the user's input

    }
}

