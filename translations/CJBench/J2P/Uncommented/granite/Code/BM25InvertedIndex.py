
import math
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
        terms = movie.getWords()
        docLength = len(terms)
        self.avgDocumentLength = ((self.avgDocumentLength * (self.totalDocuments - 1)) + docLength) / self.totalDocuments
        for term in terms:
            if term not in self.index:
                self.index[term] = {}
            termDocs = self.index[term]
            termDocs[docId] = termDocs.get(docId, 0) + 1

    def search(self, term):
        term = term.lower()
        if term not in self.index:
            return []
        termDocs = self.index[term]
        results = []
        idf = self.computeIDF(len(termDocs))
        for docId, termFrequency in termDocs.items():
            movie = self.movies[docId]
            docLength = len(movie.getWords())
            score = self.computeBM25Score(termFrequency, docLength, idf)
            results.append(SearchResult(docId, score))
        results.sort(key=lambda r: r.getRelevanceScore(), reverse=True)
        return results

    def computeBM25Score(self, termFrequency, docLength, idf):
        numerator = termFrequency * (1.5 + 1)
        denominator = termFrequency + 1.5 * (1 - 0.75 + 0.75 * (docLength / self.avgDocumentLength))
        return idf * (numerator / denominator)

    def computeIDF(self, docFrequency):
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
    import sys
    movieCount = int(input().strip())
    index = Main()
    for i in range(movieCount):
        docId = int(input().strip())
        name = input().strip()
        imdbRating = float(input().strip())
        releaseYear = int(input().strip())
        content = input().strip()
        index.addMovie(docId, name, imdbRating, releaseYear, content)
    queryCount = int(input().strip())
    for i in range(queryCount):
        query = input().strip()
        results = index.search(query)
        print("Search results for: " + query)
        for result in results:
            print("Doc ID: " + str(result.getDocId()) + ", Score: " + str(result.getRelevanceScore()))
