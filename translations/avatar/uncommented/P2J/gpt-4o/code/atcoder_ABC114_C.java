import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    static int N;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = Integer.parseInt(scanner.nextLine());
        System.out.println(aaa("0"));
    }

    public static int aaa(String n) {
        if (Integer.parseInt(n) > N) {
            return 0;
        }
        Set<Character> digits = new HashSet<>();
        for (char c : n.toCharArray()) {
            digits.add(c);
        }
        int ans = digits.equals(Set.of('7', '5', '3')) ? 1 : 0;
        for (char i : "753".toCharArray()) {
            ans += aaa(n + i);
        }
        return ans;
    }
}

// <END-OF-CODE>
