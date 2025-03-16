
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] ns = new int[4];
        System.out.println("Reading input");
        for (int i = 0; i < 4; i++) {
            ns[i] = scanner.nextInt();
        }
        System.out.println("Sorting the numbers in ns slice");
        sort(ns);
        System.out.println("Checking the condition");
        if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
            System.out.println("The condition is true, print YES");
            System.out.println("Output: YES");
            System.out.println();
            System.out.println("End of the program");
        } else {
            System.out.println("The condition is false, print NO");
            System.out.println("Output: NO");
            System.out.println();
            System.out.println("End of the program");
        }
    }

    public static void sort(int[] ns) {
        for (int i = 0; i < ns.length - 1; i++) {
            for (int j = i + 1; j < ns.length; j++) {
                if (ns[i] > ns[j]) {
                    int temp = ns[i];
                    ns[i] = ns[j];
                    ns[j] = temp;
                }
            }
        }
    }
}

