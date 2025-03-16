import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

class Main:
    # Index to store term frequencies for each document
    index = {}
    # Map to store movies by their document ID
    movies = {}
    # Total number of documents (movies) added
    totalDocuments = 0
    # Average document length (number of terms)
    avgDocumentLength = 0.0
    # BM25 parameters
    K = 1.5
    B = 0.75

    # Constructor to initialize the index and movies map
    def __init__(self):
        self.index = {}
        self.movies = {}
        self.totalDocuments = 0
        self.avgDocumentLength = 0.0

    # Method to add a movie to the index
    def addMovie(self, docId, name, imdbRating, releaseYear, content):
        # Create a new Movie object
        movie = Movie(docId, name, imdbRating, releaseYear, content)
        # Store the movie in the movies map
        self.movies[docId] = movie
        # Increment the total document count
        self.totalDocuments += 1
        # Get the terms from the movie content
        terms = movie.getWords()
        docLength = len(terms)
        # Update the average document length
        self.avgDocumentLength = ((self.avgDocumentLength * (self.totalDocuments - 1)) + docLength) / self.totalDocuments

        # Update the index with term frequencies
        for term in terms:
            self.index.setdefault(term, {})
            docList = self.index.get(term)
            # Increment the term frequency for the document
            docList[docId] = docList.get(docId, 0) + 1

    # Method to search for a term and return relevant results
    def search(self, term):
        # Normalize the search term to lowercase
        term = term.lower()
        # If the term is not in the index, return an empty list
        if term not in self.index:
            return []

        # Retrieve the documents containing the term
        termDocs = self.index.get(term)
        results = []
        # Compute the IDF (Inverse Document Frequency) for the term
        idf = self.computeIDF(len(termDocs))

        # Calculate the BM25 score for each document containing the term
        for docId, termFrequency in termDocs.items():
            movie = self.movies.get(docId)
            docLength = len(movie.getWords())
            # Compute the BM25 score
            score = self.computeBM25Score(termFrequency, docLength, idf)
            # Add the result to the list
            results.append(SearchResult(docId, score))

        # Sort the results by relevance score in descending order
        results.sort(key=lambda r: r.getRelevanceScore(), reverse=True)
        return results

    # Method to compute the BM25 score for a document
    def computeBM25Score(self, termFrequency, docLength, idf):
        numerator = termFrequency * (self.K + 1)
        denominator = termFrequency + self.K * (1 - self.B + self.B * (docLength / self.avgDocumentLength))
        return idf * (numerator / denominator)

    # Method to compute the IDF (Inverse Document Frequency)
    def computeIDF(self, docFrequency):
        return math.log((self.totalDocuments - docFrequency + 0.5) / (docFrequency + 0.5) + 1)

    # Main method to run the application
    @staticmethod
    def main(args):
        scanner = Scanner(System.in)
        # Read the number of movies to be added
        movieCount = int(scanner.nextLine().strip())
        index = Main()

        # Loop to read movie details and add them to the index
        for i in range(movieCount):
            docId = int(scanner.nextLine().strip())
            name = scanner.nextLine().strip()
            imdbRating = float(scanner.nextLine().strip())
            releaseYear = int(scanner.nextLine().strip())
            content = scanner.nextLine().strip()
            index.addMovie(docId, name, imdbRating, releaseYear, content)

        # Read the number of search queries
        queryCount = int(scanner.nextLine().strip())
        # Loop to process each search query
        for i in range(queryCount):
            query = scanner.nextLine().strip()
            results = index.search(query)
            # Output the search results
            print("Search results for: " + query)
            for result in results:
                print("Doc ID: " + str(result.getDocId()) + ", Score: " + str(result.getRelevanceScore()))
        # Close the scanner
        scanner.close()

# Class representing a Movie
class Movie:
    docId = 0
    name = ""
    imdbRating = 0.0
    releaseYear = 0
    content = ""

    # Constructor to initialize movie details
    def __init__(self, docId, name, imdbRating, releaseYear, content):
        self.docId = docId
        self.name = name
        self.imdbRating = imdbRating
        self.releaseYear = releaseYear
        self.content = content

    # Method to get the words from the movie's name and content
    def getWords(self):
        return (self.name + " " + self.content).lower().split("\\W+")

# Class representing a search result
class SearchResult:
    docId = 0
    relevanceScore = 0.0

    # Constructor to initialize search result details
    def __init__(self, docId, relevanceScore):
        self.docId = docId
        self.relevanceScore = relevanceScore

    # Getter for document ID
    def getDocId(self):
        return self.docId

    # Getter for relevance score
    def getRelevanceScore(self):
        return self.relevanceScore

