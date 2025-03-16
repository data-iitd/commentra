
public class Main {
    public static void main(String[] args) {
        int x, y, z;
        Scanner sc = new Scanner(System.in);
        x = sc.nextInt();
        y = sc.nextInt();
        if (x >= y)
            z = you(x, y);
        else
            z = you(y, x);
        System.out.println(z);
    }

    public static int you(int x, int y) {
        int z;
        while (true) {
            z = x % y;
            x = y;
            y = z;
            if (y <= 0)
                break;
        }
        return x;
    }
}

