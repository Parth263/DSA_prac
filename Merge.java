/* Assume we have two input and two output tapes to perform the sorting. The internal memory can hold and sort m records at a time. Write a program in Java for external sorting. Find out time complexity. */
import java.util.Scanner;
class MergeSort 
{

  // Merge two subarrays L and M into arr
  void merge(int arr[], int p, int q, int r) 
   {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[] = new int[n1];
    int M[] = new int[n2];

    for (int i = 0; i < n1; i++)
      L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
      M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) 
    {
      if (L[i] <= M[j]) 
      {
        arr[k] = L[i];
        i++;
      } else 
      {
        arr[k] = M[j];
        j++;
      }
      k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) 
    {
      arr[k] = L[i];
      i++;
      k++;
    }

    while (j < n2) 
    {
      arr[k] = M[j];
      j++;
      k++;
    }
  }

  // Divide the array into two subarrays, sort them and merge them
  void mergeSort(int arr[], int l, int r) 
   {
     if (l < r)
     {

      // m is the point where the array is divided into two subarrays
      int m = (l + r) / 2;

      mergeSort(arr, l, m);
      mergeSort(arr, m + 1, r);

      // Merge the sorted subarrays
      merge(arr, l, m, r);
    }
  }

  // Print the array
  static void printArray(int arr[])
  {
    int n = arr.length;
    for (int i = 0; i < n; ++i)
      System.out.print(arr[i] + " ");
    System.out.println();
  }
    // Driver program
  public static void main(String args[]) {
 
int n;  
        Scanner sc=new Scanner(System.in);  
        System.out.print("Enter the number of elements you want to store: ");  
        //reading the number of elements from the that we want to enter  
        n=sc.nextInt();  
        
        int[] arr = new int[n];  
        System.out.println("Enter the elements of the array: ");  
        for(int i=0; i<n; i++)  
        {  
        //reading array elements from the user  
            arr[i]=sc.nextInt();  
}    
   System.out.println("Enter Array before sorting");


System.out.println("Array before sorting");
printArray(arr);
    MergeSort ob = new MergeSort();
    ob.mergeSort(arr, 0, arr.length - 1);

    System.out.println("Sorted array:");
    printArray(arr);
  }
}



// This `merge` function is a crucial part of the Merge Sort algorithm. It takes in an array `arr`, and three indices `p`, `q`, and `r`, where `p` is the start index of the first subarray, `q` is the end index of the first subarray, and `r` is the end index of the second subarray. The function merges the two subarrays `arr[p..q]` and `arr[q+1..r]` into a single sorted subarray `arr[p..r]`.

// Here's a step-by-step explanation of the `merge` function:

// 1. Calculate the sizes of the two subarrays `n1` and `n2`.
// 2. Create two temporary arrays `L[]` and `M[]` to hold the elements of the two subarrays.
// 3. Copy the elements from the original array `arr` to the temporary arrays `L[]` and `M[]`.
// 4. Initialize three indices `i`, `j`, and `k` to track the current position in `L[]`, `M[]`, and the merged array `arr` respectively.
// 5. Compare elements from `L[]` and `M[]` and copy the smaller element to the original array `arr`. Increment the corresponding indices (`i`, `j`, `k`).
// 6. Repeat step 5 until all elements from either `L[]` or `M[]` have been copied to `arr`.
// 7. If there are any remaining elements in `L[]` or `M[]`, copy them to `arr`.

// After the `merge` function is executed, the subarray `arr[p..r]` will be sorted in ascending order.



// // Merge Sort is a powerful sorting algorithm based on the divide-and-conquer approach. Here's a breakdown of how it works and its key characteristics:

// The Core Idea

// Divide: The unsorted array is recursively divided into halves until subarrays of size 1 are reached (a single element is inherently sorted).
// Conquer (Merge): Pairs of these subarrays are merged in sorted order, gradually building up larger sorted portions of the array.
// Repeat: The merging process continues at each level, combining increasingly larger sorted subarrays until the entire array is sorted.
// Visual Example

// Imagine an unsorted array: [8, 3, 1, 7, 0, 10, 2]

// Divide:

// [8, 3, 1, 7] [0, 10, 2]
// [8, 3] [1, 7] [0, 10] [2]
// [8] [3] [1] [7] [0] [10] [2] (Subarrays of size 1)
// Conquer (Merge):

// [3, 8] [1, 7] [0, 10] [2]
// [1, 3, 7, 8] [0, 2, 10]
// [0, 1, 2, 3, 7, 8, 10] (Sorted array)
// Algorithmic Steps

// Recursive Splitting:

// If the array has more than one element:
// Find the middle index to divide the array.
// Recursively call merge sort on the left half.
// Recursively call merge sort on the right half.
// Merging:

// Create temporary subarrays for left and right halves.
// Compare elements from the subarrays:
// Pick the smaller element and place it in the original array.
// Handle remaining elements in either subarray (if one is finished).
// Key Characteristics

// Divide-and-Conquer: Classic example of this algorithmic strategy.
// Time Complexity:
// Average and Best-case: O(n log n). This makes it efficient for most real-world datasets.
// Worst-case: O(n log n). Merge Sort offers consistent performance.
// Space Complexity: O(n) auxiliary space is needed for the merge process.
// Stability: Merge Sort is stable, meaning elements with equal values maintain their relative order from the input.
// Advantages

// Efficiency: Good time complexity for larger datasets.
// Consistency: Performance doesn't degrade as much with nearly sorted data.
// Good for Linked Lists: Merge Sort can be adapted efficiently for linked lists (unlike some other sorting algorithms).
// Disadvantages

// Space: The extra space requirement might be a factor with limited memory.
// Not always the fastest: For smaller arrays, simpler algorithms like insertion sort can outperform it.
// When to Use Merge Sort

// You need a stable sorting algorithm.
// You're sorting linked lists.
// You prioritize consistent performance and have sufficient memory.
// Let me know if you would like a code example (Java, Python, etc.) or a more detailed explanation of the merging process!




// Your code implements the classic recursive Merge Sort algorithm:

// merge(int arr[], int p, int q, int r)

// This function is responsible for merging two already sorted subarrays of arr.
// p is the start index of the left subarray, q is the middle index, and r is the end index of the right subarray.
// It compares elements from the two subarrays and places them in the main array arr in sorted order.
// mergeSort(int arr[], int l, int r)

// The core recursive sorting function:
// Base Case: If the array has only one element (l<r), it's already sorted.
// Divide: Finds the middle index (m) to split the array.
// Recurse: Recursively calls mergeSort on the left and right halves.
// Merge: Calls the merge() function to combine the sorted halves.
// printArray(int arr[])

// A simple helper function to print the array.
// main() function

// Handles user input, creates an array, calls mergeSort, and prints the result.
// Key Points: Merge Sort

// In-Memory: This implementation assumes the entire array to be sorted fits into available RAM.
// Time Complexity: Merge Sort has an average and best-case time complexity of O(n log n).
// Divide-and-Conquer: It's a classic example of the divide-and-conquer algorithm design strategy.
// External Sorting: The Challenge

// External sorting deals with datasets too large to fit into main memory. It uses techniques like:

// Splitting: Breaking the large file into smaller "runs" that can fit into memory.
// In-Memory Sorting: Sorting each run individually using a suitable in-memory algorithm (like your Merge Sort implementation).
// Merging Runs: Repeatedly merging pairs of sorted runs into larger sorted runs, writing intermediate results back to external storage (like your tapes).
// Final Merge: Merging the final sorted runs into the output file.
// Adapting Merge Sort for External Sorting

// Initial Runs: Divide the input file into chunks that fit into memory. Sort each chunk using Merge Sort and store sorted runs on the output tapes.
// K-way Merge: Design a merge routine for 'K' sorted runs at a time (your merge function merges two). This depends on the number of tapes you have.
// Repeat Merging: Continue merging runs, doubling the size of sorted runs in every pass until you have a single sorted file.
// Time Complexity: External Sorting

// The time complexity of external sorting mainly depends on disk I/O operations. A typical analysis includes:

// Number of passes over the data.
// Number of disk reads and writes per pass.
// Let's Discuss Implementation

// Would you like to flesh out a Java implementation of external merge sort considering the I/O operations with tapes?

