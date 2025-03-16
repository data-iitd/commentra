import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] a = Arrays.stream(scanner.next().split(" ")).mapToInt(Integer::parseInt).toArray();
        int total = Arrays.stream(a).reduce(0, (acc, ai) -> acc ^ ai);
        String result = Arrays.stream(a).mapToObj(ai -> String.valueOf(ai ^ total)).collect(Collectors.joining(" "));
        System.out.println(result);
    }
}
