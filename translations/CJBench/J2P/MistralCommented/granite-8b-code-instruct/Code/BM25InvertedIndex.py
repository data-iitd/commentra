

import math

class Main:
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
            if term not in self.index:
                self.index[term] = {} # Add a new entry for the term if it doesn't exist
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
        results.sort(key=lambda x: x.getRelevanceScore(), reverse=True)
        
        return results
    
    # Compute the idf value for a term based on its document frequency
    def computeIDF(self, docFrequency):
        return math.log((self.totalDocuments - docFrequency + 0.5) / (docFrequency + 0.5) + 1)
    
    # Compute the BM25 score for a document based on its term frequency, document length, and idf value
    def computeBM25Score(self, termFrequency, docLength, idf):
        numerator = termFrequency * (1.5 + 1)
        denominator = termFrequency + 1.5 * (1 - 0.75 + 0.75 * (docLength / self.avgDocumentLength))
        return idf * (numerator / denominator)

if __name__ == "__main__":
    import sys
    
    movieCount = int(input()) # Read the number of movies from the input
    
    index = Main() # Create a new Main object to handle the indexing and searching
    
    for i in range(movieCount): # Iterate through the movies and add them to the index
        docId = int(input())
        name = input().strip()
        imdbRating = float(input())
        releaseYear = int(input())
        content = input().strip()
        index.addMovie(docId, name, imdbRating, releaseYear, content)
    
    queryCount = int(input()) # Read the number of queries from the input
    
    for i in range(queryCount): # Iterate through the queries and print the search results
        query = input().strip()
        results = index.search(query)
        print("Search results for:", query)
        for result in results:
            print("Doc ID:", result.getDocId(), "Score:", result.getRelevanceScore())

