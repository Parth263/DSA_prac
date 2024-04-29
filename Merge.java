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





// Merge sort is a highly efficient, comparison-based sorting algorithm. It is a classic example of the "divide and conquer" strategy in computer science, where a problem is broken down into smaller, more manageable parts (divide), each part is solved independently (conquer), and the solutions are combined to solve the original problem (combine). Merge sort operates by dividing the array into two halves, sorting each half recursively, and then merging the two sorted halves back together.

// ### How Merge Sort Works

// 1. **Divide**: Split the array into two halves (or nearly two, if the number of elements is odd).
// 2. **Conquer**: Recursively sort both halves of the array.
// 3. **Combine**: Merge the two sorted halves to produce a sorted array.

// This method achieves sorting with a time complexity of \(O(n \log n)\) in all cases (best, average, and worst), making it much more efficient for large data sets compared to simple sorting algorithms like insertion sort or bubble sort, which have \(O(n^2)\) complexity.

// ### Java Implementation Explanation

// In the provided Java code, the `MergeSort` class implements the merge sort algorithm:

// - **merge(int[] arr, int p, int q, int r)**: Merges two consecutive sorted subarrays of `arr`. The first subarray is from index `p` to `q`, and the second subarray is from `q+1` to `r`. Here’s the step-by-step breakdown:
//   - **Temporary Arrays**: Two temporary arrays `L` and `M` are created to hold the values of the two subarrays.
//   - **Merging Process**: The two arrays are merged back into the original array `arr` in a sorted manner. If one of the temporary arrays is exhausted first, the remaining elements from the other array are copied over.

// - **mergeSort(int[] arr, int l, int r)**: Recursively sorts the array by dividing it into two halves, sorting each half, and merging them back together using the `merge` method.

// - **printArray(int[] arr)**: Utility function to print the elements of an array.

// - **main(String[] args)**: This is the entry point of the program where the following steps occur:
//   - **Input Gathering**: The program prompts the user to enter the number of elements and then the elements themselves.
//   - **Sorting Process**: An instance of `MergeSort` is created, and the array is sorted using the `mergeSort` method.
//   - **Output**: Displays the array before and after sorting.

// ### How to Run the Code

// 1. **Compile the Program**: Save the code in a file named `MergeSort.java`. Compile it using a Java compiler:
//    ```
//    javac MergeSort.java
//    ```
// 2. **Run the Compiled Program**: Execute the compiled program:
//    ```
//    java MergeSort
//    ```
//    Follow the prompts to input the number of elements and each element's value.

// ### Time Complexity

// Merge sort consistently runs in \(O(n \log n)\) time complexity. This efficiency is due to the way it divides the array into halves, ensuring that each element is involved in log₂(n) merge steps, and each step involves all n elements.

// - **Dividing**: The array is split in half log₂(n) times until individual elements are reached.
// - **Merging**: Each merge operation for an array of size n takes linear time, i.e., \(O(n)\).

// ### Conclusion

// Merge sort is a powerful sorting technique especially useful for large arrays because its performance doesn't degrade with large data sets as dramatically as \(O(n^2)\) sorting algorithms. It is also stable, which means that the relative order of equal elements is preserved, an important property for certain applications like sorting records based on multiple fields.

// Sure! Let's take a closer look at the Java program implementing the Merge Sort algorithm. This code sorts an array of integers entered by the user. Here is a detailed step-by-step explanation of each component and how they work together:

// ### Step 1: Defining the MergeSort Class

// The program is encapsulated within a class called `MergeSort`. This class contains all the methods required to perform merge sort and to manage array input/output.

// ```java
// class MergeSort {
//     // Contains methods for sorting and merging
// }
// ```

// ### Step 2: The `merge` Method

// This method is responsible for merging two sorted subarrays into a single sorted array. It's the "combine" part of the divide-and-conquer strategy.

// ```java
// void merge(int arr[], int p, int q, int r) {
//     int n1 = q - p + 1;  // Number of elements in the first subarray
//     int n2 = r - q;      // Number of elements in the second subarray
//     int L[] = new int[n1];  // Temporary array for the first subarray
//     int M[] = new int[n2];  // Temporary array for the second subarray

//     // Copying data to temporary arrays
//     for (int i = 0; i < n1; i++)
//         L[i] = arr[p + i];
//     for (int j = 0; j < n2; j++)
//         M[j] = arr[q + 1 + j];

//     // Merge the temp arrays back into arr[p..r]
//     int i = 0, j = 0, k = p;  // Initial index of subarrays and merged subarray

//     // Actual merging process
//     while (i < n1 && j < n2) {
//         if (L[i] <= M[j]) {
//             arr[k] = L[i];
//             i++;
//         } else {
//             arr[k] = M[j];
//             j++;
//         }
//         k++;
//     }

//     // Copy remaining elements of L[], if any
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     // Copy remaining elements of M[], if any
//     while (j < n2) {
//         arr[k] = M[j];
//         j++;
//         k++;
//     }
// }
// ```

// - **Subarray Sizes**: Computes the sizes of the two subarrays to be merged.
// - **Temporary Arrays**: Creates temporary arrays `L` and `M` for the left and right subarrays, respectively.
// - **Copying Data**: Copies data from the original array to the temporary arrays.
// - **Merging Process**: Compares elements from the temporary arrays and merges them in sorted order back into the original array. Once one of the temporary arrays is exhausted, it copies the remaining elements from the other temporary array.

// ### Step 3: The `mergeSort` Method

// This recursive method sorts an array by dividing it into two halves, sorting each half, and then merging them together.

// ```java
// void mergeSort(int arr[], int l, int r) {
//     if (l < r) {
//         // Find the middle point
//         int m = (l + r) / 2;

//         // Sort first and second halves
//         mergeSort(arr, l, m);
//         mergeSort(arr, m + 1, r);

//         // Merge the sorted halves
//         merge(arr, l, m, r);
//     }
// }
// ```

// - **Recursive Division**: Continuously splits the array into two halves until each subarray has one element.
// - **Recursive Sorting**: Recursively sorts both halves of the array.
// - **Merging Sorted Halves**: Uses the `merge` method to combine the two sorted halves into a single sorted section of the array.

// ### Step 4: Utility Function `printArray`

// This method prints the elements of an array. It's used to show the array before and after sorting.

// ```java
// static void printArray(int arr[]) {
//     int n = arr.length;
//     for (int i = 0; i < n; ++i)
//         System.out.print(arr[i] + " ");
//     System.out.println();
// }
// ```

// ### Step 5: The `main` Method

// This is the entry point of the program. It manages user interaction and invokes the sorting process.

// ```java
// public static void main(String args[]) {
//     Scanner sc = new Scanner(System.in);
//     System.out.print("Enter the number of elements you want to store: ");
//     int n = sc.nextInt();
//     int[] arr = new int[n];
//     System.out.println("Enter the elements of the array: ");
//     for (int i = 0; i < n; i++) {
//         arr[i] = sc.nextInt();
//     }
//     System.out.println("Array before sorting");
//     printArray(arr);
//     MergeSort ob = new MergeSort();
   