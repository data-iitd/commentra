
import math

class Main:
    # A map to store terms and their occurrences in documents
    index = {}
    # A map to store document IDs and their corresponding Movie objects
    movies = {}
    # Counter for the total number of documents
    total_documents = 0
    # Variable to store the average document length
    avg_document_length = 0.0

    # Constructor to initialize the index, movies, and counters
    def __init__(self):
        self.index = {}
        self.movies = {}
        self.total_documents = 0
        self.avg_document_length = 0.0

    # Method to add a movie to the index
    def add_movie(self, doc_id, name, imdb_rating, release_year, content):
        # Create a new Movie object and add it to the movies map
        movie = Movie(doc_id, name, imdb_rating, release_year, content)
        self.movies[doc_id] = movie
        self.total_documents += 1

        # Update the average document length
        terms = movie.get_words()
        doc_length = len(terms)
        self.avg_document_length = ((self.avg_document_length * (self.total_documents - 1)) + doc_length) / self.total_documents

        # Update the index with the terms in the movie's content
        for term in terms:
            self.index.setdefault(term, {})
            doc_list = self.index[term]
            doc_list[doc_id] = doc_list.get(doc_id, 0) + 1

    # Method to search for movies based on a term
    def search(self, term):
        # Convert the search term to lowercase
        term = term.lower()

        # Return an empty list if the term is not in the index
        if term not in self.index:
            return []

        # Get the documents containing the term and compute the IDF
        term_docs = self.index[term]
        results = []
        idf = self.compute_idf(len(term_docs))

        # Compute the BM25 score for each document and add to the results list
        for doc_id, term_frequency in term_docs.items():
            movie = self.movies[doc_id]
            doc_length = len(movie.get_words())
            score = self.compute_bm25_score(term_frequency, doc_length, idf)
            results.append(SearchResult(doc_id, score))

        # Sort the results by relevance score in descending order
        results.sort(key=lambda r: r.relevance_score, reverse=True)
        return results

    # Method to compute the BM25 score for a term in a document
    def compute_bm25_score(self, term_frequency, doc_length, idf):
        numerator = term_frequency * (K + 1)
        denominator = term_frequency + K * (1 - B + B * (doc_length / self.avg_document_length))
        return idf * (numerator / denominator)

    # Method to compute the inverse document frequency (IDF)
    def compute_idf(self, doc_frequency):
        return math.log((self.total_documents - doc_frequency + 0.5) / (doc_frequency + 0.5) + 1)

    # Class to represent a movie
class Movie:
    def __init__(self, doc_id, name, imdb_rating, release_year, content):
        self.doc_id = doc_id
        self.name = name
        self.imdb_rating = imdb_rating
        self.release_year = release_year
        self.content = content

    # Method to split the movie's name and content into words
    def get_words(self):
        return (self.name + " " + self.content).lower().split()

    # Class to represent the result of a search
class SearchResult:
    def __init__(self, doc_id, relevance_score):
        self.doc_id = doc_id
        self.relevance_score = relevance_score

    # Getter method for the document ID
    def get_doc_id(self):
        return self.doc_id

    # Getter method for the relevance score
    def get_relevance_score(self):
        return self.relevance_score

# Constants for BM25 formula
K = 1.5
B = 0.75

# Main method to read input, add movies, and process search queries
def main():
    movie_count = int(input().strip())
    index = Main()
    for i in range(movie_count):
        doc_id = int(input().strip())
        name = input().strip()
        imdb_rating = float(input().strip())
        release_year = int(input().strip())
        content = input().strip()
        index.add_movie(doc_id, name, imdb_rating, release_year, content)
    query_count = int(input().strip())
    for i in range(query_count):
        query = input().strip()
        results = index.search(query)
        print("Search results for: " + query)
        for result in results:
            print("Doc ID: " + str(result.get_doc_id()) + ", Score: " + str(result.get_relevance_score()))

if __name__ == "__main__":
    main()

