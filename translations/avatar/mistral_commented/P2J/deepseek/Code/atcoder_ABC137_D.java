import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking input of number of days and number of employees
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initializing empty priority queues for storing days and salaries
        PriorityQueue<Employee> x = new PriorityQueue<>((a, b) -> {
            if (a.day == b.day) {
                return b.salary - a.salary;
            }
            return b.day - a.day;
        });
        
        PriorityQueue<Integer> y = new PriorityQueue<>();
        
        // Iterating through each employee and adding their details to the priority queue 'x'
        for (int i = 0; i < n; i++) {
            int day = scanner.nextInt();
            int salary = scanner.nextInt();
            // Adding employee details as an object to the priority queue 'x'
            x.add(new Employee(day, salary));
        }
        
        // Simulation loop to check if an employee can be added to the list 'y'
        while (!x.isEmpty()) {
            // Popping the employee with minimum negative day from the priority queue 'x'
            Employee e = x.poll();
            // Calculating the remaining capacity in the list 'y'
            int r = m - y.size();
            // Checking if the remaining capacity is enough to add the current employee
            if (r >= e.day) {
                // If yes, adding the salary of the employee to the list 'y'
                y.add(e.salary);
            } else {
                // If no, removing an employee with minimum salary from the list 'y' and adding the current employee
                if (!y.isEmpty() && y.peek() < e.salary) {
                    y.poll();
                    y.add(e.salary);
                }
            }
        }
        
        // Printing the sum of salaries of employees in the list 'y'
        int sum = 0;
        for (int salary : y) {
            sum += salary;
        }
        System.out.println(sum);
    }
    
    // Employee class to store day and salary
    static class Employee {
        int day;
        int salary;
        
        Employee(int day, int salary) {
            this.day = day;
            this.salary = salary;
        }
    }
}
