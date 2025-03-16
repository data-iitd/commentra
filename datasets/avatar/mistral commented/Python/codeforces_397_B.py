#######
# Class definition for CodeforcesTask397BSolution
#######

class CodeforcesTask397BSolution :

    # Constructor method with initializations
    def __init__ ( self ) :
        self.result = ''                   # Initialize an empty string to store the result
        self.t = 0                         # Initialize the number of queries to 0
        self.queries = []                  # Initialize an empty list to store the queries

    # Method to read input
    def read_input ( self ) :
        self.t = int(input())             # Read the number of queries from the input
        self.queries = [ [ int(x) for x in input().split(" ")] for _ in range(self.t) ] # Read the queries and store them in a list of lists

    # Method to process the task
    def process_task ( self ) :
        res = []                          # Initialize an empty list to store the results of each query
        for query in self.queries :         # Iterate through each query in the queries list
            k = query[0] // query[1]         # Calculate the value of k for the current query
            res.append( "Yes" if k * query[2] >= query[0] else "No" ) # Append the result (Yes or No) for the current query to the results list
        self.result = "\n".join(res)       # Join the results list with newline character and store it in the result string

    # Method to get the result
    def get_result ( self ) :
        return self.result               # Return the result string

# Main method to run the code
if __name__ == "__main__" :
    Solution = CodeforcesTask397BSolution() # Create an instance of the CodeforcesTask397BSolution class
    Solution.read_input()                   # Read the input
    Solution.process_task()                 # Process the task
    print(Solution.get_result())            # Print the result
