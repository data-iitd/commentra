
public class Main {
    public static void main(String[] args) {
        int a, b, c, i, count;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        count = 0;
        for (i = a; i <= b; i++) {
            if (c % i == 0)
                count++;
        }
        System.out.println(count);
    }
}

