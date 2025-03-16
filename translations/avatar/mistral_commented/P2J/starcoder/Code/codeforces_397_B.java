#######
// Class definition for CodeforcesTask397BSolution
#######

class CodeforcesTask397BSolution {

    // Constructor method with initializations
    public CodeforcesTask397BSolution () {
        this.result = "";                  // Initialize an empty string to store the result
        this.t = 0;                        // Initialize the number of queries to 0
        this.queries = new ArrayList<List<Integer>>(); // Initialize an empty list to store the queries
    }

    // Method to read input
    public void read_input () {
        this.t = Integer.parseInt(input()); // Read the number of queries from the input
        this.queries = new ArrayList<List<Integer>>(); // Initialize an empty list to store the queries
        for (int i = 0; i < this.t; i++) { // Iterate through the number of queries
            this.queries.add(Arrays.asList(Integer.parseInt(x) for x in input().split(" "))); // Read the queries and store them in a list of lists
        }
    }

    // Method to process the task
    public void process_task () {
        List<String> res = new ArrayList<String>(); // Initialize an empty list to store the results of each query
        for (List<Integer> query : this.queries) { // Iterate through each query in the queries list
            int k = query.get(0) / query.get(1); // Calculate the value of k for the current query
            res.add("Yes" if k * query.get(2) >= query.get(0) else "No"); // Append the result (Yes or No) for the current query to the results list
        }
        this.result = String.join("\n", res); // Join the results list with newline character and store it in the result string
    }

    // Method to get the result
    public String get_result () {
        return this.result; // Return the result string
    }

}

// Main method to run the code
public static void main ( String[] args ) {
    CodeforcesTask397BSolution Solution = new CodeforcesTask397BSolution(); // Create an instance of the CodeforcesTask397BSolution class
    Solution.read_input(); // Read the input
    Solution.process_task(); // Process the task
    System.out.println(Solution.get_result()); // Print the result
}

