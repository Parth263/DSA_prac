#include <iostream>
using namespace std;
class Set
{
    int set[20], n;

public:
    Set() { n = 0; }
    void add();
    void display();
    void remove(int x);
    int search(int x);
    void set_union(Set &s1, Set &s2);
    void set_intersection(Set &s1, Set &s2);
    void set_difference(Set &s1, Set &s2);
    void set_subset(Set &s1, Set &s2);
};
void Set::set_subset(Set &s1, Set &s2)
{
    n = 0;
    int cnt = 0, cnt1 = 0;
    for (int i = 0; i < s1.n; i++)
    {
        for (int j = 0; j < s2.n; j++)
        {
            if (s1.set[i] == s2.set[j])
            {
                set[n++] = s1.set[i];
                break;
            }
        }
    }
    if (n == s1.n)
    {
        cout << "\n A is subset of B :-";
        display();
    }
    else if (n == s2.n)
    {
        cout << "\n B is subset of A :-";
        display();
    }
    else
    {
        cout << "\n There is subset not found. ";
    }
}
void Set::set_difference(Set &s1, Set &s2)
{
    n = 0;
    for (int i = 0; i < s1.n; i++)
    {
        int flag = 0;
        for (int j = 0; j < s2.n; j++)
        {
            if (s1.set[i] == s2.set[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            set[n++] = s1.set[i];
        }
    }
    cout << "\nDifference of two sets: ";
    display();
}
void Set::set_intersection(Set &s1, Set &s2)
{
    n = 0;
    for (int i = 0; i < s1.n; i++)
    {
        for (int j = 0; j < s2.n; j++)
        {
            if (s1.set[i] == s2.set[j])
            {
                set[n++] = s1.set[i];
                break;
            }
        }
    }
    cout << "\nIntersection of two sets: ";
    display();
}
void Set::set_union(Set &s1, Set &s2)
{
    n = 0;
    for (int i = 0; i < s1.n; i++)
    {
        set[i] = s1.set[i];
        n++;
    }
    for (int i = 0; i < s2.n; i++)
    {
        if (search(s2.set[i]) == -1)
        {
            set[n++] = s2.set[i];
        }
    }
    cout << "\nUnion of two sets: ";
    display();
}
void Set::remove(int x)
{
    int ele = search(x);
    if (ele != -1)
    {
        for (int j = ele; j < n - 1; j++)
        {
            set[j] = set[j + 1];
        }
        n--;
        cout << "\nElement " << x << " removed successfully.";
    }
    else
    {
        cout << "\nElement not found in the set.";
    }
}
void Set::add()
{
    cout << "\n Enter the " << n << " element:-";
    cin >> set[n];
    n++;
}
void Set::display()
{
    if (n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "\t" << set[i];
        }
        cout << "\n";
    }
    else
        cout << "\n Set is empty";
}
int Set::search(int x)
{
    for (int i = 0; i < n; i++)
    {
        if (x == set[i])
            return i;
    }
    return -1;
}
int main()
{
    Set s1, s2, s3;
    int ch, element;
    do
    {
        cout << "\n1: Enter an element";
        cout << "\n2: Display elements";
        cout << "\n3: Remove an element";
        cout << "\n4: Search for an element";
        cout << "\n5: Union of set ";
        cout << "\n6: Intersection of set ";
        cout << "\n7: Difference of set ";
        cout << "\n8: Subset of set ";
        cout << "\n9: Exit";
        cout << "\nEnter your choice:- ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int ch1;
            cout << "\n 1:Add element in set A";
            cout << "\n 2:Add element in set B";
            cout << "\nEnter your choice:- ";
            cin >> ch1;
            switch (ch1)
            {
            case 1:
                s1.add();
                break;
            case 2:
                s2.add();
                break;
            default:
                cout << "\nInvalid choice";
            }
            break;
        case 2:
            int ch2;
            cout << "\n 1:Display element in set A";
            cout << "\n 2:Display element in set B";
            cout << "\nEnter your choice:- ";
            cin >> ch2;
            switch (ch2)
            {
            case 1:
                s1.display();
                break;
            case 2:
                s2.display();
                break;
            default:
                cout << "\nInvalid choice";
            }
            break;
        case 3:
            int ch3;
            cout << "\n 1:Remove element in set A";
            cout << "\n 2:Remove element in set B";
            cout << "\nEnter your choice:- ";
            cin >> ch3;
            switch (ch3)
            {
            case 1:
                cout << "\nEnter the element to remove: ";
                cin >> element;
                s1.remove(element);
                break;
            case 2:
                cout << "\nEnter the element to remove: ";
                cin >> element;
                s2.remove(element);
                break;
            default:
                cout << "\nInvalid choice";
            }
            break;
        case 4:
            int ch4, pos;
            cout << "\n 1:Search element in set A";
            cout << "\n 2:Search element in set B";
            cout << "\nEnter your choice:- ";
            cin >> ch4;
            switch (ch4)
            {
            case 1:
                cout << "\nEnter the element to search: ";
                cin >> element;
                pos = s1.search(element);
                if (pos != -1)
                {
                    cout << "\nElement " << element << " found in the set at "<< pos;
                }
                else
                {
                    cout << "\nElement " << element << " not found in the set ";
                }
                break;
            case 2:
                cout << "\nEnter the element to search: ";
                cin >> element;
                pos = s2.search(element);
                if (pos != -1)
                {
                    cout << "\nElement " << element << " found in the set at " << pos;
                }
                else
                {
                    cout << "\nElement " << element << " not found in the set ";
                }
                break;
            default:
                cout << "\nInvalid choice";
            }
            break;
        case 5:
            s3.set_union(s1, s2);
            break;
        case 6:
            s3.set_intersection(s1, s2);
            break;
        case 7:
            int ch5;
            cout << "\n 1:Difference between set A & B";
            cout << "\n 2:Difference between set B & A ";
            cout << "\nEnter your choice:- ";
            cin >> ch5;
            switch (ch5)
            {
            case 1:
                s3.set_difference(s1, s2);
                break;
            case 2:
                s3.set_difference(s2, s1);
                break;
            default:
                cout << "\nInvalid choice";
            }
            break;
        case 8:
            s3.set_subset(s1, s2);
            break;
        case 9:
            break;
        default:
            cout << "\nInvalid choice";
        }
    } while (ch != 9);
    return 0;
}
//OUTPUT

/*1: Enter an element
2: Display elements
3: Remove an element
4: Search for an element
5: Union of set
6: Intersection of set
7: Difference of set
8: Subset of set
9: Exit
Enter your choice:- 1

 1:Add element in set A
 2:Add element in set B
Enter your choice:- 1

 Enter the 0 element:-6

1: Enter an element
2: Display elements
3: Remove an element
4: Search for an element
5: Union of set 
6: Intersection of set
7: Difference of set
8: Subset of set
9: Exit
Enter your choice:- 2

 1:Display element in set A
 2:Display element in set B
Enter your choice:- 1
        6

1: Enter an element
2: Display elements
3: Remove an element
4: Search for an element
5: Union of set
6: Intersection of set
7: Difference of set
8: Subset of set
9: Exit
Enter your choice:- 4

 1:Search element in set A
 2:Search element in set B
Enter your choice:- 1

Enter the element to search: 6

Element 6 found in the set at 0
1: Enter an element
2: Display elements
3: Remove an element
4: Search for an element
5: Union of set
6: Intersection of set
7: Difference of set
8: Subset of set
9: Exit
Enter your choice:-*/



// This C++ code implements a basic set data structure using arrays. It allows users to perform various set operations such as adding elements, removing elements, checking for subsets, finding the union, intersection, and difference of sets, and searching for elements within sets. Let's break down the code into its key components and operations:

// 1. **Class Set**:
//    - `int set[20]`: Array to store the elements of the set. The maximum size of the set is 20.
//    - `int n`: Variable to keep track of the number of elements in the set.
//    - Constructor `Set()`: Initializes the number of elements `n` to 0.
//    - Functions:
//      - `void add()`: Adds an element to the set.
//      - `void display()`: Displays the elements of the set.
//      - `void remove(int x)`: Removes an element from the set.
//      - `int search(int x)`: Searches for an element in the set.
//      - `void set_union(Set &s1, Set &s2)`: Computes the union of two sets.
//      - `void set_intersection(Set &s1, Set &s2)`: Computes the intersection of two sets.
//      - `void set_difference(Set &s1, Set &s2)`: Computes the difference of two sets.
//      - `void set_subset(Set &s1, Set &s2)`: Checks if a set is a subset of another set.

// 2. **add() Function**:
//    - Prompts the user to enter an element and adds it to the set.

// 3. **display() Function**:
//    - Displays all the elements of the set.

// 4. **remove(int x) Function**:
//    - Removes the element `x` from the set if it exists.

// 5. **search(int x) Function**:
//    - Searches for the element `x` in the set and returns its index if found, otherwise returns -1.

// 6. **set_union(Set &s1, Set &s2) Function**:
//    - Computes the union of two sets `s1` and `s2` and stores the result in the current set.

// 7. **set_intersection(Set &s1, Set &s2) Function**:
//    - Computes the intersection of two sets `s1` and `s2` and stores the result in the current set.

// 8. **set_difference(Set &s1, Set &s2) Function**:
//    - Computes the difference between two sets `s1` and `s2` (i.e., elements present in `s1` but not in `s2`) and stores the result in the current set.

// 9. **set_subset(Set &s1, Set &s2) Function**:
//    - Checks if set `s1` is a subset of set `s2` or vice versa, and if so, displays the subset.

// 10. **main() Function**:
//     - Creates instances of `Set` class for two sets (`s1` and `s2`) and a result set (`s3`).
//     - Displays a menu for the user to choose various set operations.
//     - Uses a `do-while` loop to repeatedly display the menu and perform operations until the user chooses to exit (`ch = 9`).

// Overall, this code provides a basic implementation of set operations using arrays. However, it has limitations such as fixed size (maximum 20 elements) and may not be efficient for large sets.

// Certainly! Here's a detailed explanation of each operation:

// 1. **Enter an Element**:
//    - This operation allows the user to add an element to one of the sets (`s1` or `s2`).
//    - The user is prompted to choose the set (A or B) and then enter the element to be added.
//    - The `add()` method of the `Set` class is called to add the element to the selected set.

// 2. **Display Elements**:
//    - This operation allows the user to display the elements of one of the sets (`s1` or `s2`).
//    - The user is prompted to choose the set (A or B) whose elements should be displayed.
//    - The `display()` method of the `Set` class is called to display the elements of the selected set.

// 3. **Remove an Element**:
//    - This operation allows the user to remove an element from one of the sets (`s1` or `s2`).
//    - The user is prompted to choose the set (A or B) from which the element should be removed, and then enter the element to be removed.
//    - The `remove(int x)` method of the `Set` class is called to remove the element from the selected set.

// 4. **Search for an Element**:
//    - This operation allows the user to search for an element in one of the sets (`s1` or `s2`).
//    - The user is prompted to choose the set (A or B) in which to search for the element, and then enter the element to be searched.
//    - The `search(int x)` method of the `Set` class is called to search for the element in the selected set. If the element is found, its index is displayed; otherwise, a message indicating that the element was not found is displayed.

// 5. **Union of Set**:
//    - This operation computes the union of the two sets (`s1` and `s2`) and stores the result in the third set `s3`.
//    - The `set_union(Set &s1, Set &s2)` method of the `Set` class is called to compute the union of `s1` and `s2`, and the result is stored in `s3`.
//    - The union of two sets contains all the distinct elements from both sets.

// 6. **Intersection of Set**:
//    - This operation computes the intersection of the two sets (`s1` and `s2`) and stores the result in the third set `s3`.
//    - The `set_intersection(Set &s1, Set &s2)` method of the `Set` class is called to compute the intersection of `s1` and `s2`, and the result is stored in `s3`.
//    - The intersection of two sets contains only the elements that are common to both sets.

// 7. **Difference of Set**:
//    - This operation computes the difference between the two sets (`s1` and `s2`) and stores the result in the third set `s3`.
//    - The `set_difference(Set &s1, Set &s2)` method of the `Set` class is called to compute the difference between `s1` and `s2`, and the result is stored in `s3`.
//    - The difference of two sets contains the elements that are present in `s1` but not in `s2` (or vice versa).

// 8. **Subset of Set**:
//    - This operation checks if one set (`s1`) is a subset of another set (`s2`) and displays the result.
//    - The `set_subset(Set &s1, Set &s2)` method of the `Set` class is called to check if `s1` is a subset of `s2`.
//    - If `s1` is a subset of `s2`, the method displays the subset; otherwise, it displays a message indicating that no subset was found.

// 9. **Exit**:
//    - This operation allows the user to exit the program. Once selected, the program terminates.

// These operations provide a basic set of functionalities for managing sets, including adding, removing, displaying elements, and performing set operations such as union, intersection, difference, and subset checking.