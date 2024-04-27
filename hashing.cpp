#include <iostream>
using namespace std;

class Hashtable {
	public :
	  int key;
	  int mob_number;
};

class Hashing {
	Hashtable t[10];
	public : 
		Hashing() {
			for( int i = 0; i < 10; i++ ) {
           t[i].key = i;
		   t[i].mob_number = -1;
		};

	};

	void insert();
	void Display();

};

int main() {
   Hashing h;
   int choice;
   do {
	cout << "\n1. Insert" << endl;
	cout << "\n2. Insert" << endl;
	cout << "\n. Choose the option" << endl;
	cin >> choice;

	switch(choice) {
		case 1 :
		 h.insert();
		 break;
		case 2 : 
		 h.Display();
		 break;
		 default :
		 cout << "\nInvalid choice" << endl;
    }

	} while (choice == 1 || choice == 2);
 return 0;
   } 





// Absolutely, we'll start by building the program step by step. Let's begin with the foundational structure.

// ### Step 1: Setting Up the Basic Structure

// We'll start by setting up the basic structure of your C++ program. This includes including necessary headers, declaring the main function, and defining the basic classes we'll use for the hash table. Here’s how to begin:

// #### 1.1 Include Headers
// First, include the necessary header for input and output operations.

// ```cpp
// #include <iostream>
// ```

// #### 1.2 Use Namespace
// To avoid prefixing `std::` before every standard library object or function, we use the entire standard namespace.

// ```cpp
// using namespace std;
// ```

// #### 1.3 Define the `Hashtable` Class
// Define a class `Hashtable` that will store individual entries of the hash table. Each entry has a key and a mobile number.

// ```cpp
// class Hashtable {
// public:
//     int key;  // This will store the index in the hash table
//     long int mob_number;  // This will store the mobile number
// };
// ```

// #### 1.4 Define the `Hashing` Class
// Create a class `Hashing` that contains an array of `Hashtable` objects. This class will manage the hash table operations such as insertion and display.

// ```cpp
// class Hashing {
//     Hashtable t[10];  // Array of Hashtable objects, fixed size of 10
// public:
//     Hashing() {
//         for (int i = 0; i < 10; i++) {
//             t[i].key = i;  // Initialize keys as indices
//             t[i].mob_number = -1;  // -1 indicates an empty slot
//         }
//     }
//     void insert();  // Function to insert a new mobile number
//     void display();  // Function to display the hash table
// };
// ```

// #### 1.5 Start the `main` Function
// Setup the `main` function that provides the basic user interface for interaction.

// ```cpp
// int main() {
//     Hashing h;  // Create an object of Hashing
//     int choice;  // To store the user's menu choice
//     do {
//         cout << "\n1. Insert";
//         cout << "\n2. Display";
//         cout << "\n Enter a choice: ";
//         cin >> choice;  // Get user's choice

//         switch (choice) {
//             case 1:
//                 h.insert();
//                 break;
//             case 2:
//                 h.display();
//                 break;
//             default:
//                 cout << "\nInvalid choice";
//         }
//     } while (choice == 1 || choice == 2);

//     return 0;
// }
// ```

// This sets up the fundamental structure of your program. The `main` function initializes a `Hashing` object and provides a menu to insert a mobile number or display the hash table. The `do-while` loop continues to show the menu until the user enters a choice other than 1 or 2, effectively quitting the program.

// Let's pause here. Review the structure and let me know how it looks or if you have any modifications before we proceed to implement the `insert` and `display` methods.

// Great! Now that we have the basic structure set up, let's proceed to implement the `insert` and `display` methods of the `Hashing` class.

// ### Step 2: Implementing the `insert` Method

// The `insert` method will be responsible for adding a new mobile number to the hash table. We will also handle collisions using linear probing.

// #### 2.1 Implementing the `insert` Function

// Here's how you can write the `insert` function:

// ```cpp
// void Hashing::insert() {
//     long int temp_num;
//     cout << "\nEnter your mobile number: ";
//     cin >> temp_num;  // User inputs the mobile number

//     int position = temp_num % 10;  // Calculate hash position

//     if (t[position].mob_number == -1) {
//         // If no collision, place the number at the computed position
//         t[position].mob_number = temp_num;
//     } else {
//         // Collision handling using linear probing
//         cout << "Collision occurred at position " << position << ". Trying to resolve...\n";
//         int original_position = position;
//         position = (position + 1) % 10;  // Move to the next slot

//         while (position != original_position && t[position].mob_number != -1) {
//             // Keep moving until we find an empty slot or return to the start
//             position = (position + 1) % 10;
//         }

//         if (position == original_position) {
//             cout << "\nHash table is full";
//         } else {
//             t[position].mob_number = temp_num;
//             cout << "Placed at position " << position << "\n";
//         }
//     }
// }
// ```

// #### Explanation
// - **Hash Function**: The hash function here is `temp_num % 10`, which computes the index based on the last digit of the mobile number.
// - **Collision Detection**: If the `mob_number` at the computed index is not `-1` (i.e., the slot is not empty), it means a collision has occurred.
// - **Linear Probing**: The code then uses linear probing to find the next available slot. It moves to the next index and wraps around using modulo operation. If it circles back to the original position, it indicates that the hash table is full.
// - **Collision Resolution Output**: Messages are printed to show where collisions occur and where the number is eventually placed.

// ### Step 3: Implementing the `display` Method

// The `display` method will show the current content of the hash table.

// #### 3.1 Implementing the `display` Function

// Here's the implementation:

// ```cpp
// void Hashing::display() {
//     cout << "Key\tMobile Number\n";
//     for (int i = 0; i < 10; i++) {
//         cout << i << "\t" << (t[i].mob_number == -1 ? "Empty" : to_string(t[i].mob_number)) << "\n";
//     }
// }
// ```

// #### Explanation
// - **Output Format**: This method lists each index (key) with the corresponding mobile number or "Empty" if the slot is not filled (`mob_number` is `-1`).
// - **Use of Ternary Operator**: The ternary operator is used to check if `mob_number` is `-1`, indicating an empty slot, otherwise, it prints the mobile number.

// These methods complete the functionality for inserting and displaying data in the hash table. Let me know if this makes sense and if you're ready to discuss how to compile and test the program, or if there's anything else you'd like to add or modify!