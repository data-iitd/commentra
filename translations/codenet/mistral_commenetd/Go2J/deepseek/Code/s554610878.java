import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
        String s = scanner.nextLine();
        int index = -1;
        for (int i = 0; i < week.length; i++) {
            if (week[i].equals(s)) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            throw new IllegalArgumentException("Invalid day of the week");
        }
        System.out.println(7 - index);
    }
}
