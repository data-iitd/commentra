
import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;

public class atcoder_ABC171_E{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] a = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int total = Arrays.stream(a).reduce(0, (ai, total1) -> ai ^ total1);
        System.out.println(Arrays.stream(a).mapToObj(ai -> String.valueOf(ai ^ total)).collect(Collectors.joining(" ")));
    }
}

