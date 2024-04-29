/*Implement the Shell sort algorithm implemented in Java demonstrating shell data structure 
with modularity of programming language*/

import java.util.Scanner;
/// Java implementation of ShellSort
class ShellSort
{
/* An utility function to print array of size n*/
static void printArray(int arr[])
{
int n = arr.length;
for (int i=0; i<n; ++i)
System.out.print(arr[i] + " ");
System.out.println();
}

/* function to sort arr using shellSort */
int sort(int arr[])
{
int n = arr.length;

// Start with a big gap, then reduce the gap
for (int gap = n/2; gap > 0; gap /= 2)
{
// Do a gapped insertion sort for this gap size.
// The first gap elements a[0..gap-1] are already
// in gapped order keep adding one more element
// until the entire array is gap sorted
for (int i = gap; i < n; i += 1)
{
// add a[i] to the elements that have been gap
// sorted save a[i] in temp and make a hole at
// position i
int temp = arr[i];

// shift earlier gap-sorted elements up until
// the correct location for a[i] is found
int j;
for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
arr[j] = arr[j - gap];

// put temp (the original a[i]) in its correct
// location
arr[j] = temp;
}
}
return 0;
}

// Driver method
public static void main(String args[])
{
   int n;  
        Scanner sc=new Scanner(System.in);  
        System.out.print("Enter the number of elements you want to store: ");  
        //reading the number of elements from the that we want to enter  
        n=sc.nextInt();  
        //creates an array in the memory of length 10  
        int[] arr = new int[n];  
        System.out.println("Enter the elements of the array: ");  
        for(int i=0; i<n; i++)  
        {  
        //reading array elements from the user  
            arr[i]=sc.nextInt();  
}    
   System.out.println("Enter Array before sorting");

//int arr[] = {12, 34, 54, 2, 3};
System.out.println("Array before sorting");
printArray(arr);

ShellSort ob = new ShellSort();
ob.sort(arr);

System.out.println("Array after sorting");
printArray(arr);
}
} 






// The provided Java code implements the Shell sort algorithm, a variant of the insertion sort that allows the exchange of items that are far apart. The idea is to arrange the list of elements so that, starting with any element, every kth element (where k is a gap size) produces a sorted list. These gaps are then progressively reduced, finishing up with a conventional insertion sort, but by this time, the array is guaranteed to be almost sorted, which improves efficiency. Here’s a detailed breakdown of each part of the code:

// ### Code Breakdown

// 1. **Utility Function to Print Array**
//    ```java
//    static void printArray(int arr[]) {
//        int n = arr.length;
//        for (int i = 0; i < n; ++i)
//            System.out.print(arr[i] + " ");
//        System.out.println();
//    }
//    ```
//    This function prints the elements of an array passed as an argument. It iterates over the array and prints each element followed by a space.

// 2. **Shell Sort Function**
//    ```java
//    int sort(int arr[]) {
//        int n = arr.length;
//        for (int gap = n / 2; gap > 0; gap /= 2) {
//            for (int i = gap; i < n; i += 1) {
//                int temp = arr[i];
//                int j;
//                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
//                    arr[j] = arr[j - gap];
//                arr[j] = temp;
//            }
//        }
//        return 0;
//    }
//    ```
//    - The sort function begins with a gap size equal to half the length of the array.
//    - It then performs a gapped insertion sort: Each pass, starting at `gap` and continuing through the array, the current element is compared with elements back down the array at distances of `gap`, swapping where necessary to place the element in the correct gapped position.
//    - The gap size is halved each iteration of the outer loop until it is 1, at which point a regular insertion sort finalizes the order.

// 3. **Main Function**
//    ```java
//    public static void main(String args[]) {
//        Scanner sc = new Scanner(System.in);
//        System.out.print("Enter the number of elements you want to store: ");
//        int n = sc.nextInt();
//        int[] arr = new int[n];
//        System.out.println("Enter the elements of the array: ");
//        for (int i = 0; i < n; i++) {
//            arr[i] = sc.nextInt();
//        }
//        System.out.println("Array before sorting");
//        printArray(arr);
//        ShellSort ob = new ShellSort();
//        ob.sort(arr);
//        System.out.println("Array after sorting");
//        printArray(arr);
//    }
//    ```
//    - Initializes a Scanner to read user input.
//    - Prompts the user to input the number of elements and the elements themselves, storing them in an array.
//    - Prints the array before sorting, calls the `sort` method to sort the array using the Shell sort algorithm, and then prints the sorted array.

// ### Running the Code

// To run this Java code, you need to have Java installed on your machine. Follow these steps:

// 1. **Save the Code**: Copy the code into a text file and save it as `ShellSort.java`. This name is important because Java requires that the public class name matches the filename.

// 2. **Compile the Code**:
//    Open a terminal or command prompt and navigate to the directory containing your `ShellSort.java` file. Compile the code by running:
//    ```bash
//    javac ShellSort.java
//    ```
//    This command will compile the `ShellSort.java` file and generate a `ShellSort.class` file in the same directory.

// 3. **Run the Program**:
//    Execute the compiled class file using the Java interpreter:
//    ```bash
//    java ShellSort
//    ```
//    Follow the on-screen prompts to enter the number of elements and each element's value. The program will display the sorted array once completed.

// Make sure that your Java Development Kit (JDK) is properly installed and that `javac` and `java` commands are available in your system's PATH to follow these steps successfully.

// Shell sort, also known as Shell's method, is an in-place comparison-based sorting algorithm that was invented by Donald Shell in 1959. It is mainly a variation of insertion sort that allows the exchange of items that are far apart. The idea is to improve the efficiency of insertion sort by breaking the original list into a number of smaller sublists, each of which is sorted using an insertion sort. The unique feature of Shell sort compared to other sorting algorithms is that it reduces the amount of shifting (movement of elements across positions) necessary.

// ### How Shell Sort Works

// 1. **Gap Selection**:
//    Shell sort starts by sorting pairs of elements far apart from each other, then progressively reducing the gap between elements to be compared. The gaps between the elements are typically determined by a sequence known as the gap sequence. Common gap sequences include:
//    - The original sequence suggested by Shell: \(N/2, N/4, ..., 1\)
//    - Hibbard’s sequence: \(1, 3, 7, ..., 2^k - 1\)
//    - Knuth’s sequence: \(1, 4, 13, ..., (3^k - 1)/2\)
//    - Sedgewick’s sequence, and others.

// 2. **Initial Gapped Sorts**:
//    Starting with a large gap, the algorithm compares elements that are distance `gap` apart. If they are in the wrong order, they are swapped. This initial step using a large gap allows elements to move long distances in the original array, helping to move items closer to their final position early on.

// 3. **Reducing the Gap**:
//    After each pass, the gap is reduced according to the sequence until it becomes 1. A gap of 1 means that a standard insertion sort is performed, but by this time, the array has been partially sorted by the earlier steps, which makes the final pass very efficient.

// 4. **Final Insertion Sort**:
//    With the gap reduced to 1, the array is sorted with a regular insertion sort, but the array is already "almost sorted," making the process faster than a standard insertion sort applied to an unsorted array.

// ### Properties and Use Cases

// - **Efficiency**: Shell sort is more efficient than traditional insertion sort because it minimizes the number of movements required when using smaller gaps.
// - **Complexity**: The time complexity of Shell sort varies depending on the gap sequence used, typically ranging from \(O(n\log n)\) to \(O(n^{3/2})\) for the best-known sequences.
// - **In-place and Unstable**: Shell sort requires only a constant amount of additional memory space, making it an in-place sorting algorithm. It is generally considered unstable because it can change the relative order of equal elements.
// - **Adaptive**: If the list is already partially sorted (as it increasingly becomes during the execution of the algorithm), Shell sort runs faster.

// Shell sort is particularly useful in scenarios where auxiliary memory is limited. It is a good choice when the records to be sorted are already somewhat ordered, due to its adaptive nature. However, for large datasets, more advanced algorithms like quicksort, mergesort, or heapsort are generally more efficient.