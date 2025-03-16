import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

class Main:
    def __init__(self):
        self.index = {}
        self.movies = {}
        self.totalDocuments = 0
        self.avgDocumentLength = 0.0

    def addMovie(self, docId, name, imdbRating, releaseYear, content):
        movie = Movie(docId, name, imdbRating, releaseYear, content)
        self.movies[docId] = movie
        self.totalDocuments += 1

        # Get words (terms) from the movie's name and content
        terms = movie.getWords()
        docLength = len(terms)
        # Update the average document length
        self.avgDocumentLength = ((self.avgDocumentLength * (self.totalDocuments - 1)) + docLength) / self.totalDocuments

        # Update the inverted index
        for term in terms:
            # Create a new entry if the term is not yet in the index
            self.index.setdefault(term, {})
            docList = self.index[term]
            docList[docId] = docList.get(docId, 0) + 1

    def search(self, term):
        term = term.lower()
        if term not in self.index:
            return []

        termDocs = self.index[term]
        results = []
        # Compute IDF for the search term
        idf = self.computeIDF(len(termDocs))

        # Calculate relevance scores for all documents containing the term
        for docId, termFrequency in termDocs.items():
            movie = self.movies[docId]
            docLength = len(movie.getWords())
            # Compute BM25 relevance score
            score = self.computeBM25Score(termFrequency, docLength, idf)
            results.append(SearchResult(docId, score))

        # Sort the results by relevance score in descending order
        results.sort(key=lambda r: r.relevanceScore, reverse=True)
        return results

    def computeBM25Score(self, termFrequency, docLength, idf):
        numerator = termFrequency * (1.5 + 1)
        denominator = termFrequency + 1.5 * (1 - 0.75 + 0.75 * (docLength / self.avgDocumentLength))
        return idf * (numerator / denominator)

    def computeIDF(self, docFrequency):
        # Total number of documents in the index
        return math.log((self.totalDocuments - docFrequency + 0.5) / (docFrequency + 0.5) + 1)

class Movie:
    def __init__(self, docId, name, imdbRating, releaseYear, content):
        self.docId = docId
        self.name = name
        self.imdbRating = imdbRating
        self.releaseYear = releaseYear
        self.content = content

    def getWords(self):
        return (self.name + " " + self.content).lower().split("\\W+")

class SearchResult:
    def __init__(self, docId, relevanceScore):
        self.docId = docId
        self.relevanceScore = relevanceScore

    def getDocId(self):
        return self.docId

    def getRelevanceScore(self):
        return self.relevanceScore

if __name__ == "__main__":
    scanner = Scanner(System.in)

    # Input: Number of movies

    movieCount = Integer.parseInt(scanner.nextLine().trim())

    index = Main()

    # Input: Movie details

    for i in range(movieCount):
        docId = Integer.parseInt(scanner.nextLine().trim())
        name = scanner.nextLine().trim()
        imdbRating = Double.parseDouble(scanner.nextLine().trim())
        releaseYear = Integer.parseInt(scanner.nextLine().trim())
        content = scanner.nextLine().trim()

        index.addMovie(docId, name, imdbRating, releaseYear, content)

    # Input: Number of queries

    queryCount = Integer.parseInt(scanner.nextLine().trim())

    # Process queries

    for i in range(queryCount):
        query = scanner.nextLine().trim()
        results = index.search(query)

        # Output results for the query
        print("Search results for: " + query)
        for result in results:
            print("Doc ID: " + result.getDocId() + ", Score: " + result.getRelevanceScore())

    scanner.close()

