import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        System.out.println(a.contains("1")? 0 : prod(Arrays.stream(a.split("1")).map(s -> s.length() - s.replace("0", "").length() + 1).toArray(Integer[]::new)));
    }

    private static int prod(int[] a) {
        int p = 1;
        for (int i : a) p *= i;
        return p;
    }
}

