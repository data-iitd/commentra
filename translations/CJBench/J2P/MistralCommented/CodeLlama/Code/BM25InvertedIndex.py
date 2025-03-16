
import math

class Main:
    # Initialize an empty map to store the index of each term in the documents
    index = {}
    
    # Initialize an empty map to store the movies with their details
    movies = {}
    
    # Initialize the total number of documents and average document length
    totalDocuments = 0
    avgDocumentLength = 0.0
    
    # Define constants for BM25 algorithm
    K = 1.5
    B = 0.75
    
    def __init__(self):
        self.index = {} # Initialize an empty index map
        self.movies = {} # Initialize an empty movies map
        self.totalDocuments = 0 # Initialize totalDocuments to 0
        self.avgDocumentLength = 0.0 # Initialize avgDocumentLength to 0.0
    
    def addMovie(self, docId, name, imdbRating, releaseYear, content):
        # Create a new movie object with the given details
        movie = Movie(docId, name, imdbRating, releaseYear, content)
        
        # Add the movie to the movies map
        self.movies[docId] = movie
        
        # Increment totalDocuments
        self.totalDocuments += 1
        
        # Get the words from the movie content
        terms = movie.getWords()
        
        # Update the document length and add the terms to the index map
        docLength = len(terms)
        self.avgDocumentLength = ((self.avgDocumentLength * (self.totalDocuments - 1)) + docLength) / self.totalDocuments
        for term in terms:
            self.index.setdefault(term, {}) # Add a new entry for the term if it doesn't exist
            docList = self.index[term] # Get the document list for the term
            docList[docId] = docList.get(docId, 0) + 1 # Increment the term frequency for the document
    
    def search(self, term):
        term = term.lower() # Convert the term to lowercase
        
        # Check if the term exists in the index map
        if term not in self.index:
            return [] # Return an empty list if the term is not found
        
        termDocs = self.index[term] # Get the document list for the term
        results = [] # Initialize an empty list to store the search results
        
        # Compute the idf value for the term
        idf = self.computeIDF(len(termDocs))
        
        # Iterate through the document list and compute the BM25 score for each document
        for docId, termFrequency in termDocs.items():
            movie = self.movies[docId]
            docLength = len(movie.getWords())
            score = self.computeBM25Score(termFrequency, docLength, idf)
            results.append(SearchResult(docId, score)) # Add the search result to the list
        
        # Sort the results based on the relevance score
        results.sort(key=lambda r: r.relevanceScore, reverse=True)
        
        return results
    
    # Compute the idf value for a term based on its document frequency
    def computeIDF(self, docFrequency):
        return math.log((self.totalDocuments - docFrequency + 0.5) / (docFrequency + 0.5) + 1)
    
    # Compute the BM25 score for a document based on its term frequency, document length, and idf value
    def computeBM25Score(self, termFrequency, docLength, idf):
        numerator = termFrequency * (self.K + 1)
        denominator = termFrequency + self.K * (1 - self.B + self.B * (docLength / self.avgDocumentLength))
        return idf * (numerator / denominator)

class Movie:
    def __init__(self, docId, name, imdbRating, releaseYear, content):
        self.docId = docId
        self.name = name
        self.imdbRating = imdbRating
        self.releaseYear = releaseYear
        self.content = content
    
    def getWords(self):
        return (self.name + " " + self.content).lower().split()

class SearchResult:
    def __init__(self, docId, relevanceScore):
        self.docId = docId
        self.relevanceScore = relevanceScore

if __name__ == "__main__":
    import sys
    import math
    
    # Read the number of movies from the input
    movieCount = int(sys.stdin.readline().strip())
    
    index = Main() # Create a new Main object to handle the indexing and searching
    
    for i in range(movieCount): # Iterate through the movies and add them to the index
        docId = int(sys.stdin.readline().strip())
        name = sys.stdin.readline().strip()
        imdbRating = float(sys.stdin.readline().strip())
        releaseYear = int(sys.stdin.readline().strip())
        content = sys.stdin.readline().strip()
        index.addMovie(docId, name, imdbRating, releaseYear, content)
    
    # Read the number of queries from the input
    queryCount = int(sys.stdin.readline().strip())
    
    for i in range(queryCount): # Iterate through the queries and print the search results
        query = sys.stdin.readline().strip()
        results = index.search(query)
        print("Search results for: " + query)
        for result in results:
            print("Doc ID: " + str(result.docId) + ", Score: " + str(result.relevanceScore))
    
    # End of code
    print("