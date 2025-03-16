
import java.io.BufferedReader; // BufferedReader to read input from System.in
import java.io.IOException; // Exception for I/O errors
import java.io.InputStreamReader; // InputStreamReader to read from System.in
import java.io.PrintWriter; // PrintWriter to write output to System.out
import java.util.StringTokenizer; // StringTokenizer to split input strings

public class Main {

 // Main method to start the program
 public static void main(String[] args) throws IOException {
 BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Create a BufferedReader object to read input
 PrintWriter pw = new PrintWriter(System.out); // Create a PrintWriter object to write output
 StringTokenizer st; // Create a StringTokenizer object to split input strings

 // Read the first line of input and parse the integers
 st = new StringTokenizer(br.readLine());
 int a = Integer.parseInt(st.nextToken()); // Parse the first integer (number of students)
 int tA = Integer.parseInt(st.nextToken()); // Parse the first integer (time taken by student A)

 // Read the second line of input and parse the integers
 st = new StringTokenizer(br.readLine());
 int b = Integer.parseInt(st.nextToken()); // Parse the second integer (number of students in bus B)
 int tB = Integer.parseInt(st.nextToken()); // Parse the second integer (time taken by bus B)

 // Read the third line of input and parse the string
 String timing = br.readLine(); // Read the string representing the bus timing
 int hrs = Integer.parseInt(timing.substring(0, 2)); // Parse the hours from the string
 int mins = Integer.parseInt(timing.substring(3)); // Parse the minutes from the string
 int simDeparture = hrs * 60 + mins; // Calculate the simulation time of bus departure
 int simArrival = simDeparture + tA; // Calculate the simulation time of bus arrival

 int counter = 0; // Initialize the counter to 0

 // Loop through the bus timings to find the number of buses that can accommodate students
 for (int i = 300; i < 1440; i += b) { // Loop through the bus timings from 300 to 1439 in increments of busB
 int busDeparture = i; // Store the bus departure time
 int busArrival = i + tB; // Calculate the bus arrival time

 if (busDeparture >= simArrival || simDeparture >= busArrival) { // Check if the bus departure or arrival time is after the simulation time
 continue; // If so, skip to the next iteration of the loop
 }
 counter++; // Increment the counter if the bus timing is valid
 }

 // Write the output to the console
 pw.println(counter); // Print the number of buses that can accommodate students
 pw.flush(); // Flush the PrintWriter buffer to write the output immediately
 pw.close(); // Close the PrintWriter object to free up system resources
 }
}

These comments should provide a clear understanding of what each part of the code does. Let me know if you have any questions or need further clarification.