import java.io.*;
import java.util.*;

public class ExternalSorting {
    public static void main(String[] args) throws IOException {
        int m = 100; // Number of records that can be sorted in internal memory

        // Step 1: Split the input into sorted chunks
        splitInputIntoSortedChunks(m);

        // Step 2: Merge the sorted chunks using a k-way merge algorithm
        mergeSortedChunks(m);
    }

    private static void splitInputIntoSortedChunks(int m) throws IOException {
        // Open the input file
        BufferedReader inputFile = new BufferedReader(new FileReader("input.txt"));

        // Create temporary files for storing the sorted chunks
        List<File> sortedChunks = new ArrayList<>();

        // Read m records at a time, sort them, and write them to temporary files
        List<Integer> records = new ArrayList<>();
        String line;
        while ((line = inputFile.readLine()) != null) {
            int record = Integer.parseInt(line);
            records.add(record);

            if (records.size() == m) {
                Collections.sort(records);
                File sortedChunk = writeSortedChunk(records);
                sortedChunks.add(sortedChunk);
                records.clear();
            }
        }

        // Sort and write the remaining records to a temporary file
        if (!records.isEmpty()) {
            Collections.sort(records);
            File sortedChunk = writeSortedChunk(records);
            sortedChunks.add(sortedChunk);
        }

        // Close the input file
        inputFile.close();
    }

    private static File writeSortedChunk(List<Integer> records) throws IOException {
        File sortedChunk = File.createTempFile("sorted_chunk_", ".txt");
        BufferedWriter outputFile = new BufferedWriter(new FileWriter(sortedChunk));

        for (int record : records) {
            outputFile.write(Integer.toString(record));
            outputFile.newLine();
        }

        outputFile.close();
        return sortedChunk;
    }

    private static void mergeSortedChunks(int m) throws IOException {
        // Open the output file
        BufferedWriter outputFile = new BufferedWriter(new FileWriter("output.txt"));

        // Open the sorted chunks
        List<BufferedReader> sortedChunkReaders = new ArrayList<>();
        List<File> sortedChunks = new ArrayList<>(); // Declare and initialize sortedChunks
        for (File sortedChunk : sortedChunks) {
            BufferedReader sortedChunkReader = new BufferedReader(new FileReader(sortedChunk));
            sortedChunkReaders.add(sortedChunkReader);
        }

        // Perform a k-way merge using a priority queue
        PriorityQueue<Record> minHeap = new PriorityQueue<>();
        for (int i = 0; i < sortedChunkReaders.size(); i++) {
            BufferedReader sortedChunkReader = sortedChunkReaders.get(i);
            String line = sortedChunkReader.readLine();
            if (line != null) {
                int record = Integer.parseInt(line);
                minHeap.add(new Record(record, i));
            }
        }

        while (!minHeap.isEmpty()) {
            Record minRecord = minHeap.poll();
            outputFile.write(Integer.toString(minRecord.value));
            outputFile.newLine();

            BufferedReader sortedChunkReader = sortedChunkReaders.get(minRecord.chunkIndex);
            String line = sortedChunkReader.readLine();
            if (line != null) {
                int record = Integer.parseInt(line);
                minHeap.add(new Record(record, minRecord.chunkIndex));
            }
        }

        // Close the output file
        outputFile.close();

        // Close the sorted chunk readers
        for (BufferedReader sortedChunkReader : sortedChunkReaders) {
            sortedChunkReader.close();
        }
    }

    private static class Record implements Comparable<Record> {
        int value;
        int chunkIndex;

        public Record(int value, int chunkIndex) {
            this.value = value;
            this.chunkIndex = chunkIndex;
        }

        @Override
        public int compareTo(Record other) {
            return Integer.compare(this.value, other.value);
        }
    }
}




// This Java program demonstrates external sorting, a technique used for sorting large amounts of data that cannot fit entirely into memory. The program assumes the data is read from a file, sorted, and then written back to two output files, using the merge sort algorithm. Here's a detailed explanation of the code:

// 1. **ExternalSort Class**:
//    - The `ExternalSort` class contains the main logic for external sorting.
//    - It defines a constant `M` to represent the size of the internal memory.
//    - The `externalSort` method is the main method for sorting external data. It takes the input file path (`inputFile`), and two output file paths (`outputFile1` and `outputFile2`) as arguments.
//    - Inside the `externalSort` method, a `BufferedReader` is used to read data from the input file, and two `BufferedWriters` are used to write data to the output files.

// 2. **Sorting Process**:
//    - The sorting process is done in chunks that fit into the internal memory (`M` records at a time).
//    - The program reads a chunk of data from the input file, sorts it internally using `Arrays.sort`, and then writes the sorted chunk to one of the output files.
//    - It alternates between writing to `outputFile1` and `outputFile2` to achieve the final sorted output.

// 3. **readChunk Method**:
//    - The `readChunk` method reads a chunk of data from the input file into the buffer array.
//    - It returns the number of records read (which may be less than `M` if the end of the file is reached).

// 4. **writeChunk Method**:
//    - The `writeChunk` method writes a chunk of data from the buffer array to an output file.
//    - It takes the `BufferedWriter` and the number of records to write as arguments.

// 5. **Main Method**:
//    - The `main` method is the entry point of the program.
//    - It defines the paths to the input and output files and calls the `externalSort` method to perform the sorting.

// 6. **File Handling**:
//    - The program uses try-with-resources to handle file I/O, ensuring that the files are properly closed after use.

// 7. **Error Handling**:
//    - The program does not include extensive error handling for simplicity. It assumes that the input file exists and can be read, and the output files can be written.

// 8. **Complexity**:
//    - The time complexity of the external sorting algorithm depends on the number of chunks and the internal sorting complexity.
//    - In this implementation, the sorting complexity is O(M log M) for each chunk and O(n log k) for merging, where n is the total number of records and k is the number of chunks. Overall, the time complexity is approximately O(n log n) when M is a constant factor of n.

// This program provides a basic example of how external sorting can be implemented in Java using the merge sort algorithm.