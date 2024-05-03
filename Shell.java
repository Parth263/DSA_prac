import java.util.Scanner;

class ShellSort {
    static void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    int sort(int arr[]) {
        int n = arr.length;

        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i += 1) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];
                arr[j] = temp;
            }
        }
        return 0;
    }

    public static void main(String args[]) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements you want to store: ");
        n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        System.out.println("Array before sorting");
        printArray(arr);
        ShellSort ob = new ShellSort();
        ob.sort(arr);
        System.out.println("Array after sorting");
        printArray(arr);
    }
}



// Let's break down the Java implementation of Shell sort step by step, explaining both the algorithm and the code.

// **Core Theory (Recap)**

// 1. Shell sort uses the concept of "gaps" to compare elements that are not directly adjacent.
// 2. It starts with larger gaps and gradually reduces them in each iteration.
// 3. For each gap value, Shell sort performs a modified insertion sort on sub-arrays of elements spaced `gap` positions apart.

// **Code Breakdown**

// **`ShellSort` Class**

// - **`printArray(int arr[])`**
//     - A utility function to print the contents of an integer array.
// - **`sort(int arr[])`**
//     - **The Heart of Shell Sort:** This function implements the core Shell sort algorithm:
//         1. **Outer Loop: Gap Initialization and Reduction:**
//             - `for (int gap = n/2; gap > 0; gap /= 2)`
//                 - Sets the initial gap to half the array size (`n/2`).
//                 - Iterates as long as the gap is greater than 0.
//                 - In each iteration, the gap is halved.
//         2. **Inner Loop: Gapped Insertion Sort:**
//             - `for (int i = gap; i < n; i += 1)`
//             - Iterates over elements starting from the `gap` position to the end of the array.
//             - Each element 'i' is treated as the starting point of the insertion sort within its subarray.
//             1. **Insertion Sort Logic:**
//             - `int temp = arr[i];`
//                 - Temporarily stores the value to be inserted.
//             - `for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)`
//                 - Compares `temp` with elements `gap` position backwards and shifts elements greater than `temp` one position to the right.
//             - `arr[j] = temp;`
//                 - Places `temp` in its correct position within the sub-array.

// **`main()` Function**

// - **Input Handling**
//     - Uses a `Scanner` to take input from the user:
//         - Gets the number of elements.
//         - Creates an array `arr` of the given size.
//         - Reads the array elements from the user.
// - **Sorting and Output**
//     - `System.out.println("Array before sorting");`
//     - `printArray(arr);` – Prints the unsorted array.
//     - `ShellSort ob = new ShellSort();` – Creates an object of the `ShellSort` class.
//     - `ob.sort(arr);` – Calls the `sort()` function to perform Shell sort on the array.
//     - `System.out.println("Array after sorting");`
//     - `printArray(arr);` – Prints the sorted array.

// **Key Points**

// - **Modularity:** The sorting logic is encapsulated within the `ShellSort` class. The `printArray()` serves as a helper function for readability.
// - **No Specific Data Structure:** Shell sort itself doesn't introduce any complex data structure; it effectively operates on the input array.

// **Let's Enhance!**

// - **Gap Sequence:** We could experiment with different gap sequences instead of simply halving.
// - **Generics:** Using Java Generics, we could make the `sort()` function work with arrays of any comparable data type.

// **Let me know if you want to dive into a specific section more deeply or explore modifications to the code!**

// Here's a breakdown of Shell sort with a standard example, combining the best aspects of previous explanations and addressing potential issues:

// **Shell Sort Explained Simply**

// Imagine you have a messy array of numbers that you want to sort in ascending order. Shell sort works in stages, focusing on larger gaps between elements first, and gradually reducing the gaps for finer sorting.

// **1. Grouping with Gaps:**

// - Unlike insertion sort, which compares neighboring elements, Shell sort introduces a concept called a "gap." Initially, the gap is a chosen value (often half the array size).
// - The array is conceptually divided into sub-arrays based on this gap. Elements within each sub-array are `gap` positions apart.

// **2. Sub-array Insertion Sort:**

// - Shell sort performs a modified insertion sort on each sub-array. This insertion sort considers elements `gap` positions apart and swaps them if they're in the wrong order.
// - This process ensures that elements within each sub-array are (partially) sorted based on the chosen gap.

// **3. Reducing the Gap and Repeating:**

// - After processing all sub-arrays for the current gap, the gap value is reduced (often by dividing by 2).
// - The grouping and sub-array insertion sort steps are repeated with the new, smaller gap.
// - This process continues until the gap becomes 1, at which point a standard insertion sort is effectively performed on the entire array.

// **Standard Example:**

// Let's sort the array: `[8, 3, 1, 4, 2, 7, 6, 5]`

// **Pass 1: Gap of 4 (Half the array size)**

// 1. **Grouping:** We have sub-arrays: `[8]`, `[3, 7]`, `[1, 5]`, `[4, 6]` (consider elements within square brackets as a sub-array).
// 2. **Sub-array Sorting:** Sort each sub-array using insertion sort based on the gap (4). Here, only `[3, 7]` needs sorting, becoming `[3, 7]`.
// 3. **Array After Pass 1:** `[8, 3, 7, 1, 5, 4, 6, 2]` (notice some elements have moved significantly).

// **Pass 2: Gap of 2**

// 1. **Grouping:** Sub-arrays become: `[8, 6]`, `[3, 5]`, `[7, 4]`, `[1, 2]`.
// 2. **Sub-array Sorting:** Sort each sub-array based on the gap (2). Here, `[8, 6]`, `[7, 4]` need sorting, becoming `[6, 8]` and `[4, 7]`.
// 3. **Array After Pass 2:** `[6, 8, 3, 5, 7, 4, 1, 2]` (elements are getting closer to their sorted positions).

// **Pass 3: Gap of 1 (Standard Insertion Sort):**

// At this point, the gap is 1, effectively performing a standard insertion sort on the almost-sorted array, resulting in the final sorted array: `[1, 2, 3, 4, 5, 6, 7, 8]`.

// **Key Points:**

// - Shell sort leverages gaps for efficient sorting, especially when elements are initially far apart.
// - The choice of gap sequence can impact performance (common choices include Knuth's sequence or variants).
// - Shell sort generally has a time complexity between O(n log n) and O(n^2), depending on the gap sequence and input data.
// - Shell sort offers better performance than insertion sort for larger arrays due to its ability to make larger jumps during initial passes.

// **I hope this explanation clarifies Shell sort! Feel free to ask if you have any further questions.**