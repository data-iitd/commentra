
// Importing PriorityQueue class from java.util package
import java.util.PriorityQueue;

// Taking input of number of days and number of employees
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int m = sc.nextInt();

// Initializing PriorityQueue for storing days and salaries
PriorityQueue<int[]> x = new PriorityQueue<>((a, b) -> a[0] - b[0]);

// Iterating through each employee and adding their details to the PriorityQueue 'x'
for (int i = 0; i < n; i++) {
    int day = sc.nextInt();
    int salary = sc.nextInt();
    // Adding employee details as an array to the PriorityQueue 'x' with negative day and salary values
    x.add(new int[]{-day, -salary});
}

// Simulation loop to check if an employee can be added to the PriorityQueue 'y'
PriorityQueue<Integer> y = new PriorityQueue<>((a, b) -> b - a);
while (!x.isEmpty()) {
    // Popping the employee with minimum negative day from the PriorityQueue 'x'
    int[] emp = x.poll();
    int day = emp[0];
    int salary = emp[1];
    // Calculating the remaining capacity in the PriorityQueue 'y'
    int r = m - y.size();
    // Checking if the remaining capacity is enough to add the current employee
    if (r >= day) {
        // If yes, adding the salary of the employee to the PriorityQueue 'y'
        y.add(-salary);
    } else {
        // If no, removing an employee with minimum salary from the PriorityQueue 'y' and adding the current employee
        y.poll();
        y.add(-salary);
    }
}

// Printing the sum of salaries of employees in the PriorityQueue 'y'
int sum = 0;
for (int salary : y) {
    sum += salary;
}
System.out.println(sum);

