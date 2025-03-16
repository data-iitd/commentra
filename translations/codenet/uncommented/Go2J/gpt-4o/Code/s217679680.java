import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int[] arr = scanArrayInt();
        int a = arr[0], b = arr[1];
        int tap = 0;
        int consent = 1;
        
        while (consent < b) {
            consent = consent + a - 1;
            tap++;
        }
        
        System.out.println(tap);
    }

    private static int[] scanArrayInt() {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String[] parts = input.split(" ");
        int[] ret = new int[parts.length];
        
        for (int i = 0; i < parts.length; i++) {
            ret[i] = Integer.parseInt(parts[i]);
        }
        
        return ret;
    }
}

// <END-OF-CODE>
