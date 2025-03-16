import java.util.Scanner;

public class Main {
    static int d; // number of test cases
    static String[] map = new String[105]; // 2D array to store the grid
    static int n; // size of the grid
    static int[] dx = {0, 1, 0, -1}; // directions to move in 4 directions
    static int[] dy = {-1, 0, 1, 0}; // directions to move in 4 directions
    static int sum, flg = 0; // variables used in visit function
    static int x = 2, y; // initial position of the function
    static char temp; // temporary variable to store the character in the grid

    static void visit() {
        // function to find the path of 'O' in the grid
        int[] ab = {2, 2, 2, 2}; // array to store the number of 'O's in 4 directions

        while (true) {
            sum = 0; // initialize sum to 0
            flg = 0; // initialize flag to 0

            while (true) {
                if (map[y + dy[flg] * 2].charAt(x + dx[flg] * 2) != '#' && 
                    map[y + dy[flg]].charAt(x + dx[flg]) != ' ') {
                    // check if the next cell is not a wall or empty
                    flg++; // increment flag

                    // mark the cell as visited
                    map[y + dy[flg]] = map[y + dy[flg]].substring(0, x + dx[flg]) + ' ' + 
                                      map[y + dy[flg]].substring(x + dx[flg] + 1);

                    // move to the next cell
                    y = y + dy[flg];
                    x = x + dx[flg];

                    sum++; // increment sum

                    break;
                }
                if (flg == 4) break; // break if all directions are checked
            }

            if (flg == 4) { // if all 4 directions are visited
                flg = 0; // reset flag

                if (sum == 0) break; // if no 'O' is found, break the loop

                ab[0] = ab[1]; // copy the value of ab[1] to ab[0]
                ab[1] = ab[2]; // copy the value of ab[2] to ab[1]
                ab[2] = sum; // store the number of 'O's in the current direction

                if (ab[0] == 1 && ab[2] == 1 && ab[1] == 1) { // check if all 3 directions have 'O's
                    break; // if yes, break the loop
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        d = scanner.nextInt(); // read the number of test cases

        for (int l = 0; l < d; l++) { // iterate through each test case
            n = scanner.nextInt(); // read the size of the grid

            if (n == 1) { // if the size of the grid is 1
                System.out.println("#"); // print '#'
                if (l != d - 1) System.out.println(); // print newline if it's not the last test case
                continue; // move to the next test case
            }

            for (int i = 0; i <= n + 1; i++) { // initialize the map with '#' and '.'
                StringBuilder row = new StringBuilder();
                for (int j = 0; j <= n + 1; j++) {
                    if (i == 0 || j == 0 || i == n + 1 || j == n + 1) {
                        row.append('.');
                    } else {
                        row.append('#');
                    }
                }
                map[i] = row.toString();
            }

            visit(); // call the visit function

            for (int i = 1; i <= n; i++) { // print the grid
                System.out.println(map[i].substring(1, map[i].length() - 1));
            }

            if (l != d - 1) System.out.println(); // print newline if it's not the last test case
        }

        scanner.close();
    }
}

// <END-OF-CODE>
