import java.util.Scanner;

public class Main {
    private static Scanner sc = new Scanner(System.in);

    // NextLine reads a line text from stdin, and then returns its string.
    public static String nextLine() {
        return sc.nextLine();
    }

    // NextIntsLine reads a line text, that consists of ONLY INTEGERS DELIMITED BY SPACES, from stdin.
    // And then returns integers array.
    public static int[] nextIntsLine() {
        String[] parts = nextLine().split(" ");
        int[] integers = new int[parts.length];
        for (int i = 0; i < parts.length; i++) {
            integers[i] = Integer.parseInt(parts[i]);
        }
        return integers;
    }

    public static void main(String[] args) {
        int[] tmp = nextIntsLine();
        int x = tmp[0];
        int i = 1;
        int sum = 0;
        while (true) {
            sum += i;
            if (sum >= x) {
                break;
            }
            i++;
        }
        System.out.println(i);
    }
}

// <END-OF-CODE>
