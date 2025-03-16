import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // Index to store term frequencies for each document
    private Map<String, Map<Integer, Integer>> index;
    // Map to store movies by their document ID
    private Map<Integer, Movie> movies;
    // Total number of documents (movies) added
    private int totalDocuments;
    // Average document length (number of terms)
    private double avgDocumentLength;
    // BM25 parameters
    private static final double K = 1.5;
    private static final double B = 0.75;

    // Constructor to initialize the index and movies map
    public Main() {
        index = new HashMap<>();
        movies = new HashMap<>();
        totalDocuments = 0;
        avgDocumentLength = 0.0;
    }

    // Method to add a movie to the index
    public void addMovie(int docId, String name, double imdbRating, int releaseYear, String content) {
        // Create a new Movie object
        Movie movie = new Movie(docId, name, imdbRating, releaseYear, content);
        // Store the movie in the movies map
        movies.put(docId, movie);
        // Increment the total document count
        totalDocuments++;
        // Get the terms from the movie content
        String[] terms = movie.getWords();
        int docLength = terms.length;
        // Update the average document length
        avgDocumentLength = ((avgDocumentLength * (totalDocuments - 1)) + docLength) / totalDocuments;

        // Update the index with term frequencies
        for (String term : terms) {
            index.putIfAbsent(term, new HashMap<>());
            Map<Integer, Integer> docList = index.get(term);
            // Increment the term frequency for the document
            docList.put(docId, docList.getOrDefault(docId, 0) + 1);
        }
    }

    // Method to search for a term and return relevant results
    public List<SearchResult> search(String term) {
        // Normalize the search term to lowercase
        term = term.toLowerCase();
        // If the term is not in the index, return an empty list
        if (!index.containsKey(term)) {
            return new ArrayList<>();
        }

        // Retrieve the documents containing the term
        Map<Integer, Integer> termDocs = index.get(term);
        List<SearchResult> results = new ArrayList<>();
        // Compute the IDF (Inverse Document Frequency) for the term
        double idf = computeIDF(termDocs.size());

        // Calculate the BM25 score for each document containing the term
        for (Map.Entry<Integer, Integer> entry : termDocs.entrySet()) {
            int docId = entry.getKey();
            int termFrequency = entry.getValue();
            Movie movie = movies.get(docId);
            double docLength = movie.getWords().length;
            // Compute the BM25 score
            double score = computeBM25Score(termFrequency, docLength, idf);
            // Add the result to the list
            results.add(new SearchResult(docId, score));
        }

        // Sort the results by relevance score in descending order
        results.sort((r1, r2) -> Double.compare(r2.getRelevanceScore(), r1.getRelevanceScore()));
        return results;
    }

    // Method to compute the BM25 score for a document
    private double computeBM25Score(int termFrequency, double docLength, double idf) {
        double numerator = termFrequency * (K + 1);
        double denominator = termFrequency + K * (1 - B + B * (docLength / avgDocumentLength));
        return idf * (numerator / denominator);
    }

    // Method to compute the IDF (Inverse Document Frequency)
    private double computeIDF(int docFrequency) {
        return Math.log((totalDocuments - docFrequency + 0.5) / (docFrequency + 0.5) + 1);
    }

    // Main method to run the application
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of movies to be added
        int movieCount = Integer.parseInt(scanner.nextLine().trim());
        Main index = new Main();

        // Loop to read movie details and add them to the index
        for (int i = 0; i < movieCount; i++) {
            int docId = Integer.parseInt(scanner.nextLine().trim());
            String name = scanner.nextLine().trim();
            double imdbRating = Double.parseDouble(scanner.nextLine().trim());
            int releaseYear = Integer.parseInt(scanner.nextLine().trim());
            String content = scanner.nextLine().trim();
            index.addMovie(docId, name, imdbRating, releaseYear, content);
        }

        // Read the number of search queries
        int queryCount = Integer.parseInt(scanner.nextLine().trim());
        // Loop to process each search query
        for (int i = 0; i < queryCount; i++) {
            String query = scanner.nextLine().trim();
            List<SearchResult> results = index.search(query);
            // Output the search results
            System.out.println("Search results for: " + query);
            for (SearchResult result : results) {
                System.out.println("Doc ID: " + result.getDocId() + ", Score: " + result.getRelevanceScore());
            }
        }
        // Close the scanner
        scanner.close();
    }
}

// Class representing a Movie
class Movie {
    int docId;
    String name;
    double imdbRating;
    int releaseYear;
    String content;

    // Constructor to initialize movie details
    public Movie(int docId, String name, double imdbRating, int releaseYear, String content) {
        this.docId = docId;
        this.name = name;
        this.imdbRating = imdbRating;
        this.releaseYear = releaseYear;
        this.content = content;
    }

    // Method to get the words from the movie's name and content
    public String[] getWords() {
        return (name + " " + content).toLowerCase().split("\\W+");
    }
}

// Class representing a search result
class SearchResult {
    private final int docId;
    private final double relevanceScore;

    // Constructor to initialize search result details
    public SearchResult(int docId, double relevanceScore) {
        this.docId = docId;
        this.relevanceScore = relevanceScore;
    }

    // Getter for document ID
    public int getDocId() {
        return docId;
    }

    // Getter for relevance score
    public double getRelevanceScore() {
        return relevanceScore;
    }
}
