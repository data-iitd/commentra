import java.util.*;

public class EmployeeSalaries {
    public static void main(String[] args) {
        // Creating a scanner for input
        Scanner scanner = new Scanner(System.in);
        
        // Taking input of number of days and number of employees
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initializing priority queues for storing days and salaries
        PriorityQueue<int[]> x = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) {
                return Integer.compare(b[0], a[0]); // Max heap for days
            }
            return Integer.compare(b[1], a[1]); // Max heap for salaries
        });
        
        // Iterating through each employee and adding their details to the heap 'x'
        for (int i = 0; i < n; i++) {
            int day = scanner.nextInt();
            int salary = scanner.nextInt();
            // Adding employee details as an array to the heap 'x' with negative day and salary values
            x.offer(new int[]{day, salary});
        }
        
        // List to store salaries of selected employees
        PriorityQueue<Integer> y = new PriorityQueue<>();
        
        // Simulation loop to check if an employee can be added to the list 'y'
        while (!x.isEmpty()) {
            int[] employee = x.poll();
            int d = employee[0];
            int s = employee[1];
            // Calculating the remaining capacity in the list 'y'
            int r = m - y.size();
            // Checking if the remaining capacity is enough to add the current employee
            if (r >= d) {
                // If yes, adding the salary of the employee to the list 'y'
                y.offer(s);
            } else {
                // If no, removing an employee with minimum salary from the list 'y' and adding the current employee
                y.offer(s);
                y.poll();
            }
        }
        
        // Calculating the sum of salaries of employees in the list 'y'
        int sum = 0;
        while (!y.isEmpty()) {
            sum += y.poll();
        }
        
        // Printing the sum of salaries of employees in the list 'y'
        System.out.println(sum);
        
        // Closing the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
