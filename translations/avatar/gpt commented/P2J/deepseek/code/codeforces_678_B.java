import java.util.Scanner;

public class LeapYearFinder {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String d = "f";
        String ans;

        if (isLeapYear(n)) {
            ans = "ly";
        } else {
            ans = "nly";
        }

        while (true) {
            if (isLeapYear(n)) {
                switch (d) {
                    case "m":
                        d = "w";
                        n++;
                        break;
                    case "t":
                        d = "th";
                        n++;
                        break;
                    case "w":
                        d = "f";
                        n++;
                        break;
                    case "th":
                        d = "sa";
                        n++;
                        break;
                    case "f":
                        d = "s";
                        n++;
                        break;
                    case "sa":
                        d = "m";
                        n++;
                        break;
                    case "s":
                        d = "t";
                        n++;
                        break;
                }
            } else {
                switch (d) {
                    case "m":
                        d = "t";
                        n++;
                        break;
                    case "t":
                        d = "w";
                        n++;
                        break;
                    case "w":
                        d = "th";
                        n++;
                        break;
                    case "th":
                        d = "f";
                        n++;
                        break;
                    case "f":
                        d = "sa";
                        n++;
                        break;
                    case "sa":
                        d = "s";
                        n++;
                        break;
                    case "s":
                        d = "m";
                        n++;
                        break;
                }
            }

            if (d.equals("f") && ans.equals("ly") && isLeapYear(n)) {
                break;
            } else if (d.equals("f") && ans.equals("nly") && !isLeapYear(n)) {
                break;
            }
        }

        System.out.println(n);
    }

    public static boolean isLeapYear(int year) {
        return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
    }
}
