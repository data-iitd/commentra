import math

class Movie:
    def __init__(self, doc_id, name, imdb_rating, release_year, content):
        self.doc_id = doc_id
        self.name = name
        self.imdb_rating = imdb_rating
        self.release_year = release_year
        self.content = content

    def get_words(self):
        return (self.name + " " + self.content).lower().split()


class SearchResult:
    def __init__(self, doc_id, relevance_score):
        self.doc_id = doc_id
        self.relevance_score = relevance_score


class Main:
    def __init__(self):
        self.index = {}
        self.movies = {}
        self.total_documents = 0
        self.avg_document_length = 0.0

    def add_movie(self, doc_id, name, imdb_rating, release_year, content):
        movie = Movie(doc_id, name, imdb_rating, release_year, content)
        self.movies[doc_id] = movie
        self.total_documents += 1

        # Get words (terms) from the movie's name and content
        terms = movie.get_words()
        doc_length = len(terms)
        # Update the average document length
        self.avg_document_length = ((self.avg_document_length * (self.total_documents - 1)) + doc_length) / self.total_documents

        # Update the inverted index
        for term in terms:
            # Create a new entry if the term is not yet in the index
            self.index.setdefault(term, {})
            doc_list = self.index[term]
            doc_list[doc_id] = doc_list.get(doc_id, 0) + 1

    def search(self, term):
        term = term.lower()
        if term not in self.index:
            return []

        term_docs = self.index[term]
        results = []
        # Compute IDF for the search term
        idf = self.compute_idf(len(term_docs))

        # Calculate relevance scores for all documents containing the term
        for doc_id, term_frequency in term_docs.items():
            movie = self.movies[doc_id]
            doc_length = len(movie.get_words())
            # Compute BM25 relevance score
            score = self.compute_bm25_score(term_frequency, doc_length, idf)
            results.append(SearchResult(doc_id, score))

        # Sort the results by relevance score in descending order
        results.sort(key=lambda r: r.relevance_score, reverse=True)
        return results

    def compute_bm25_score(self, term_frequency, doc_length, idf):
        numerator = term_frequency * (K + 1)
        denominator = term_frequency + K * (1 - B + B * (doc_length / self.avg_document_length))
        return idf * (numerator / denominator)

    def compute_idf(self, doc_frequency):
        # Total number of documents in the index
        return math.log((self.total_documents - doc_frequency + 0.5) / (doc_frequency + 0.5) + 1)


if __name__ == "__main__":
    # Input: Number of movies
    movie_count = int(input().strip())

    index = Main()

    # Input: Movie details
    for _ in range(movie_count):
        doc_id = int(input().strip())
        name = input().strip()
        imdb_rating = float(input().strip())
        release_year = int(input().strip())
        content = input().strip()

        index.add_movie(doc_id, name, imdb_rating, release_year, content)

    # Input: Number of queries
    query_count = int(input().strip())

    # Process queries
    for _ in range(query_count):
        query = input().strip()
        results = index.search(query)

        # Output results for the query
        print("Search results for:", query)
        for result in results:
            print("Doc ID:", result.doc_id, ", Score:", result.relevance_score)


