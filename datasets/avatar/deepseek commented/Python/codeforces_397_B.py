
class CodeforcesTask397BSolution :
    def __init__ ( self ) :
        self.result = ''
        self.t = 0
        self.queries = [ ]
    
    # Reads the number of test cases and the queries from input
    def read_input ( self ) :
        self.t = int ( input ( ) )  # Read the number of test cases
        for _ in range ( self.t ) :
            self.queries.append ( [ int ( x ) for x in input ( ).split ( " " ) ] )  # Read each query and store it in the list
    
    # Processes each query to determine if the condition is met
    def process_task ( self ) :
        res = [ ]
        for query in self.queries :
            k = query [ 0 ] // query [ 1 ]  # Calculate k as the integer division of query[0] by query[1]
            res.append ( "Yes" if k * query [ 2 ] >= query [ 0 ] else "No" )  # Append "Yes" or "No" based on the condition
        self.result = "\n".join ( res )  # Join the results into a single string with newline characters
    
    # Returns the final result
    def get_result ( self ) :
        return self.result

if __name__ == "__main__" :
    Solution = CodeforcesTask397BSolution ( )
    Solution.read_input ( )
    Solution.process_task ( )
    print ( Solution.get_result ( ) )  # Print the final result

