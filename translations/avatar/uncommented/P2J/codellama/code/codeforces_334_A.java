
public class Main {
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int i = 1, j = n * n;
        while (i < j) {
            System.out.println(i + " " + j);
            i++;
            j--;
        }
    }
}

