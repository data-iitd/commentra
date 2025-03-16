import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int[] num_inp = () -> {
            String input = scanner.nextLine();
            return Integer.parseInt(input);
        };

        int[] arr_inp = () -> {
            String input = scanner.nextLine();
            String[] parts = input.split(" ");
            int[] arr = new int[parts.length];
            for (int i = 0; i < parts.length; i++) {
                arr[i] = Integer.parseInt(parts[i]);
            }
            Arrays.sort(arr);
            return arr;
        };

        int[] sp_inp = () -> {
            String input = scanner.nextLine();
            String[] parts = input.split(" ");
            int[] arr = new int[parts.length];
            for (int i = 0; i < parts.length; i++) {
                arr[i] = Integer.parseInt(parts[i]);
            }
            return arr;
        };

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] inputLines = reader.lines().toArray(String[]::new);
        int[] a = Arrays.stream(inputLines[1].split(" ")).mapToInt(Integer::parseInt).sorted().toArray();

        System.out.println(Arrays.stream(a).anyMatch(x -> x % a[0] == 0) ? a[0] : -1);
    }
}
