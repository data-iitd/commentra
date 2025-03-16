
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // Initialize an empty map to store the index of each term in the documents
    private Map<String, Map<Integer, Integer>> index;
    
    // Initialize an empty map to store the movies with their details
    private Map<Integer, Movie> movies;
    
    // Initialize the total number of documents and average document length
    private int totalDocuments;
    private double avgDocumentLength;
    
    // Define constants for BM25 algorithm
    private static final double K = 1.5;
    private static final double B = 0.75;
    
    public Main() {
        index = new HashMap<>(); // Initialize an empty index map
        movies = new HashMap<>(); // Initialize an empty movies map
        totalDocuments = 0; // Initialize totalDocuments to 0
        avgDocumentLength = 0.0; // Initialize avgDocumentLength to 0.0
    }
    
    public void addMovie(int docId, String name, double imdbRating, int releaseYear, String content) {
        // Create a new movie object with the given details
        Movie movie = new Movie(docId, name, imdbRating, releaseYear, content);
        
        // Add the movie to the movies map
        movies.put(docId, movie);
        
        // Increment totalDocuments
        totalDocuments++;
        
        // Get the words from the movie content
        String[] terms = movie.getWords();
        
        // Update the document length and add the terms to the index map
        int docLength = terms.length;
        avgDocumentLength = ((avgDocumentLength * (totalDocuments - 1)) + docLength) / totalDocuments;
        for (String term : terms) {
            index.putIfAbsent(term, new HashMap<>()); // Add a new entry for the term if it doesn't exist
            Map<Integer, Integer> docList = index.get(term); // Get the document list for the term
            docList.put(docId, docList.getOrDefault(docId, 0) + 1); // Increment the term frequency for the document
        }
    }
    
    public List<SearchResult> search(String term) {
        term = term.toLowerCase(); // Convert the term to lowercase
        
        // Check if the term exists in the index map
        if (!index.containsKey(term)) {
            return new ArrayList<>(); // Return an empty list if the term is not found
        }
        
        Map<Integer, Integer> termDocs = index.get(term); // Get the document list for the term
        List<SearchResult> results = new ArrayList<>(); // Initialize an empty list to store the search results
        
        // Compute the idf value for the term
        double idf = computeIDF(termDocs.size());
        
        // Iterate through the document list and compute the BM25 score for each document
        for (Map.Entry<Integer, Integer> entry : termDocs.entrySet()) {
            int docId = entry.getKey();
            int termFrequency = entry.getValue();
            Movie movie = movies.get(docId);
            double docLength = movie.getWords().length;
            double score = computeBM25Score(termFrequency, docLength, idf);
            results.add(new SearchResult(docId, score)); // Add the search result to the list
        }
        
        // Sort the results based on the relevance score
        results.sort((r1, r2) -> Double.compare(r2.getRelevanceScore(), r1.getRelevanceScore()));
        
        return results;
    }
    
    // Compute the idf value for a term based on its document frequency
    private double computeIDF(int docFrequency) {
        return Math.log((totalDocuments - docFrequency + 0.5) / (docFrequency + 0.5) + 1);
    }
    
    // Compute the BM25 score for a document based on its term frequency, document length, and idf value
    private double computeBM25Score(int termFrequency, double docLength, double idf) {
        double numerator = termFrequency * (K + 1);
        double denominator = termFrequency + K * (1 - B + B * (docLength / avgDocumentLength));
        return idf * (numerator / denominator);
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a scanner to read input from the console
        
        int movieCount = Integer.parseInt(scanner.nextLine().trim()); // Read the number of movies from the input
        
        Main index = new Main(); // Create a new Main object to handle the indexing and searching
        
        for (int i = 0; i < movieCount; i++) { // Iterate through the movies and add them to the index
            int docId = Integer.parseInt(scanner.nextLine().trim());
            String name = scanner.nextLine().trim();
            double imdbRating = Double.parseDouble(scanner.nextLine().trim());
            int releaseYear = Integer.parseInt(scanner.nextLine().trim());
            String content = scanner.nextLine().trim();
            index.addMovie(docId, name, imdbRating, releaseYear, content);
        }
        
        int queryCount = Integer.parseInt(scanner.nextLine().trim()); // Read the number of queries from the input
        
        for (int i = 0; i < queryCount; i++) { // Iterate through the queries and print the search results
            String query = scanner.nextLine().trim();
            List<SearchResult> results = index.search(query);
            System.out.println("Search results for: " + query);
            for (SearchResult result : results) {
                System.out.println("Doc ID: " + result.getDocId() + ", Score: " + result.getRelevanceScore());
            }
        }
        
        scanner.close(); // Close the scanner after processing all the input
    }
}

class Movie {
    int docId;
    String name;
    double imdbRating;
    int releaseYear;
    String content;
    
    public Movie(int docId, String name, double imdbRating, int releaseYear, String content) {
        this.docId = docId;
        this.name = name;
        this.imdbRating = imdbRating;
        this.releaseYear = releaseYear;
        this.content = content;
    }
    
    public String[] getWords() {
        return (name + " " + content).toLowerCase().split("\\W+");
    }
}

class SearchResult {
    private final int docId;
    private final double relevanceScore;
    
    public SearchResult(int docId, double relevanceScore) {
        this.docId = docId;
        this.relevanceScore = relevanceScore;
    }
    
    public int getDocId() {
        return docId;
    }
    
    public double getRelevanceScore() {
        return relevanceScore;
    }
}