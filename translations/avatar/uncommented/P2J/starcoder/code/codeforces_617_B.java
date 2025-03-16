import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        System.out.println(0 == a.replaceAll("1", "").length()? 0 : prod(Arrays.stream(a.split("1")).map(s -> s.replaceAll("0", "").length() + 1).toArray(Integer[]::new)));
    }

    private static int prod(Integer[] arr) {
        int res = 1;
        for (int i : arr) res *= i;
        return res;
    }
}
