
import math

class Main:
    # Index to store term frequencies for each document
    index = {}
    # Map to store movies by their document ID
    movies = {}
    # Total number of documents (movies) added
    total_documents = 0
    # Average document length (number of terms)
    avg_document_length = 0.0

    # Constructor to initialize the index and movies map
    def __init__(self):
        self.index = {}
        self.movies = {}
        self.total_documents = 0
        self.avg_document_length = 0.0

    # Method to add a movie to the index
    def add_movie(self, doc_id, name, imdb_rating, release_year, content):
        # Create a new Movie object
        movie = Movie(doc_id, name, imdb_rating, release_year, content)
        # Store the movie in the movies map
        self.movies[doc_id] = movie
        # Increment the total document count
        self.total_documents += 1
        # Get the terms from the movie content
        terms = movie.get_words()
        doc_length = len(terms)
        # Update the average document length
        self.avg_document_length = ((self.avg_document_length * (self.total_documents - 1)) + doc_length) / self.total_documents

        # Update the index with term frequencies
        for term in terms:
            self.index.setdefault(term, {})
            doc_list = self.index[term]
            # Increment the term frequency for the document
            doc_list[doc_id] = doc_list.get(doc_id, 0) + 1

    # Method to search for a term and return relevant results
    def search(self, term):
        # Normalize the search term to lowercase
        term = term.lower()
        # If the term is not in the index, return an empty list
        if term not in self.index:
            return []

        # Retrieve the documents containing the term
        term_docs = self.index[term]
        results = []
        # Compute the IDF (Inverse Document Frequency) for the term
        idf = self.compute_idf(len(term_docs))

        # Calculate the BM25 score for each document containing the term
        for doc_id, term_frequency in term_docs.items():
            movie = self.movies[doc_id]
            doc_length = len(movie.get_words())
            # Compute the BM25 score
            score = self.compute_bm25_score(term_frequency, doc_length, idf)
            # Add the result to the list
            results.append(SearchResult(doc_id, score))

        # Sort the results by relevance score in descending order
        results.sort(key=lambda r: r.relevance_score, reverse=True)
        return results

    # Method to compute the BM25 score for a document
    def compute_bm25_score(self, term_frequency, doc_length, idf):
        numerator = term_frequency * (K + 1)
        denominator = term_frequency + K * (1 - B + B * (doc_length / self.avg_document_length))
        return idf * (numerator / denominator)

    # Method to compute the IDF (Inverse Document Frequency)
    def compute_idf(self, doc_frequency):
        return math.log((self.total_documents - doc_frequency + 0.5) / (doc_frequency + 0.5) + 1)


# Class representing a Movie
class Movie:
    def __init__(self, doc_id, name, imdb_rating, release_year, content):
        self.doc_id = doc_id
        self.name = name
        self.imdb_rating = imdb_rating
        self.release_year = release_year
        self.content = content

    # Method to get the words from the movie's name and content
    def get_words(self):
        return (self.name + " " + self.content).lower().split()


# Class representing a search result
class SearchResult:
    def __init__(self, doc_id, relevance_score):
        self.doc_id = doc_id
        self.relevance_score = relevance_score


# BM25 parameters
K = 1.5
B = 0.75


# Main method to run the application
def main():
    # Read the number of movies to be added
    movie_count = int(input().strip())
    index = Main()

    # Loop to read movie details and add them to the index
    for i in range(movie_count):
        doc_id = int(input().strip())
        name = input().strip()
        imdb_rating = float(input().strip())
        release_year = int(input().strip())
        content = input().strip()
        index.add_movie(doc_id, name, imdb_rating, release_year, content)

    # Read the number of search queries
    query_count = int(input().strip())
    # Loop to process each search query
    for i in range(query_count):
        query = input().strip()
        results = index.search(query)
        # Output the search results
        print("Search results for:", query)
        for result in results:
            print("Doc ID:", result.doc_id, ", Score:", result.relevance_score)


if __name__ == "__main__":
    main()


