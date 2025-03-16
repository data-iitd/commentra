class CodeforcesTask397BSolution:
    def __init__(self):
        # Initialize the result string, number of queries, and a list to hold the queries
        self.result = ''
        self.t = 0
        self.queries = []

    def read_input(self):
        # Read the number of queries from input
        self.t = int(input())
        # Read each query and store it as a list of integers in the queries list
        for _ in range(self.t):
            self.queries.append([int(x) for x in input().split(" ")])

    def process_task(self):
        # Initialize a list to hold the results for each query
        res = []
        # Process each query to determine if the condition is met
        for query in self.queries:
            # Calculate how many complete sets of query[1] fit into query[0]
            k = query[0] // query[1]
            # Check if k multiplied by query[2] is at least query[0]
            res.append("Yes" if k * query[2] >= query[0] else "No")
        # Join the results into a single string separated by newlines
        self.result = "\n".join(res)

    def get_result(self):
        # Return the final result string
        return self.result

if __name__ == "__main__":
    # Create an instance of the solution class
    Solution = CodeforcesTask397BSolution()
    # Read input data
    Solution.read_input()
    # Process the task based on the input data
    Solution.process_task()
    # Print the final results
    print(Solution.get_result())
