import java.util.*;
import java.util.stream.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        int[] a = Arrays.stream(scanner.nextLine().split(" "))
                        .mapToInt(Integer::parseInt)
                        .toArray();
        
        int total = 0;
        for (int num : a) {
            total ^= num;
        }
        
        String result = Arrays.stream(a)
                              .mapToObj(num -> String.valueOf(num ^ total))
                              .collect(Collectors.joining(" "));
        
        System.out.println(result);
    }
}
// <END-OF-CODE>
