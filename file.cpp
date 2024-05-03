/*-----------------------------------------------------------
Pr. No : 11
Title : Department maintains a student information. The file contains roll number, name, division and address. Allow user to add, delete information of student. Display information of particular employee. If record of student does not exist an appropriate message is displayed. If it is, then the system displays the student details. Use sequential file to main the data.

------------------------------------------------------------*/

#include<iostream> 
#include<fstream> 
#include<string.h> 
using namespace std; 

struct stud 
{ 
    int roll; 
    char name[10]; 
    char div; 
    char add[10]; 
}rec; 


class student 
{ 
    public:      
    void create(); 
    void display(); 
    int search(); 
    void Delete(); 
}; 

void student::create() 
 { 
    char ans; 
    ofstream fout; 
    fout.open("stud.dat",ios::out|ios::binary); 
    do 
    { 
        cout<<"\n\tEnter Roll No of Student : "; 
        cin>>rec.roll; 
        cout<<"\n\tEnter a Name of Student : "; 
        cin>>rec.name; 
        cout<<"\n\tEnter a Division of Student : "; 
        cin>>rec.div; 
        cout<<"\n\tEnter a Address of Student : "; 
        cin>>rec.add; 
        fout.write((char *)&rec,sizeof(stud))<<flush; 
        cout<<"\n\tDo You Want to Add More Records: "; 
        cin>>ans; 
    }while(ans=='y'||ans=='Y'); 
    fout.close(); 
} 

void student::display() 
{ 
    ifstream fin;
    fin.open("stud.dat",ios::in|ios::binary); 
    fin.seekg(0,ios::beg); 
    cout<<"\n\tThe Content of File are:\n"; 
    cout<<"\n\tRoll\tName\tDiv\tAddress"; 
    while(fin.read((char *)&rec,sizeof(stud))) 
    { 
        if(rec.roll!=-1) 
        cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;  
        
    } 
        fin.close(); 
} 

int student::search() 
{ 
    int r,i=0; 
    ifstream fin; 
    fin.open("stud.dat",ios::in|ios::binary); 
    fin.seekg(0,ios::beg); 
    cout<<"\n\tEnter a Roll No: "; 
    cin>>r; 
    
    while(fin.read((char *)&rec,sizeof(stud))) 
    { 
        if(rec.roll==r) 
        { 
            cout<<"\n\tRecord Found...\n"; 
            cout<<"\n\tRoll\tName\tDiv\tAddress"; 
            cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add; 
            return i; 
        } 
        i++; 
    } 
    fin.close(); 
    return 0; 
} 

void student::Delete() 
{ 
    int pos; 
    pos=search(); 
    fstream f; 
    f.open("stud.dat",ios::in|ios::out|ios::binary); 
    f.seekg(0,ios::beg); 
    if(pos==0) 
    { 
        cout<<"\n\tRecord Not Found"; 
        return; 
    } 
    int offset=pos*sizeof(stud); 
    f.seekp(offset); 
    rec.roll=-1; 
    strcpy(rec.name,"NULL"); 
    rec.div='N'; 
    strcpy(rec.add,"NULL");
    f.write((char *)&rec,sizeof(stud)); 
    f.seekg(0); 
    f.close(); 
    cout<<"\n\tRecord Deleted"; 
 } 
 
int main() 
{ 
       student obj; 
       int ch,key; 
       char ans; 
       do 
       { 
              cout<<"\n\t***** Student Information *****"; 
              cout<<"\n\t1. Create\n\t2. Display\n\t3. Delete\n\t4.  Search\n\t5. Exit"; 
              cout<<"\n\t..... Enter Your Choice: "; 
              cin>>ch; 
              switch(ch) 
              { 
              case 1: obj.create(); 
              break; 
              case 2: obj.display(); 
              break; 
              case 3: obj.Delete(); 
              break; 
              case 4: key=obj.search(); 
              break; 
              case 5: 
              break; 
              } 
              cout<<"\n\t..... Do You Want to Continue in Main Menu: "; cin>>ans; 
       }while(ans=='y'||ans=='Y'); 
 
return 1; 
 } 









// Let's break down the C++ code you provided, explaining the algorithms and logic behind its operations on a sequential file for student records.

// **Overview**

// The code implements a rudimentary student information management system using a sequential file ("stud.dat") to store the data. Here's the core functionality:

// * **Create Records:**  Adds new student records to the file.
// * **Display Records:**  Reads and displays all records from the file.
// * **Search Records:**  Searches for a student based on their roll number.
// * **Delete Records:** Marks a student record as deleted (without physically removing it from the file).

// **Data Structures**

// * **`stud` structure:** 
//    * `roll`:  Students roll number (numeric)
//    * `name`: Student's name (string)
//    * `div`:  Student's division (character)
//    * `add`:  Student's address (string)

// **Classes**

// * **`student` class:**  Encapsulates all the operations on the student file:
//    * `create()`: Handles adding new records.
//    * `display()`: Handles displaying records.
//    * `search()`: Handles searching for records.
//    * `Delete()`: Handles deleting records.

// **Code Breakdown**

// **`create()`**

// 1. Opens the "stud.dat" file in output and binary mode (`ios::out|ios::binary`).
// 2. In a loop:
//    * Prompts the user for student details (roll number, name, division, address).
//    * Writes the `rec` structure to the file using `fout.write()`.
//    * Asks if the user wants to add more records.
// 3. Closes the file (`fout.close()`).

// **`display()`**

// 1. Opens the "stud.dat" file in input and binary mode (`ios::in|ios::binary`).
// 2. Prints a header.
// 3. Loops while reading records from the file using `fin.read()`:
//    * If `rec.roll` is not -1 (indicates a valid record), it prints the student details.
// 4. Closes the file (`fin.close()`).    

// **`search()`**

// 1. Opens the "stud.dat" file in input and binary mode.
// 2. Prompts the user to enter the roll number to search for.
// 3. Loops while reading records from the file using `fin.read()`:
//    *  If `rec.roll` matches the search key:
//      *  Prints "Record Found..." and the student details.
//      *  Returns the record's position in the file (`i`).
// 4. Closes the file. Returns 0 if the record is not found.

// **`Delete()`**

// 1. Calls the `search()` function to locate the record to be deleted. If not found, prints "Record Not Found" and exits.
// 2. Opens the "stud.dat" in input/output and binary mode (`ios::in|ios::out|ios::binary`).
// 3. Calculates the offset of the record within the file using the position returned by `search()`.
// 4. Uses `seekp()` to move to the record's location in the file.
// 5. Creates a `rec` structure with all fields set to indicate deletion (`roll = -1`, `name = "NULL"`, etc.).
// 6. Overwrites the existing record with the deletion marker using `f.write()`.
// 7. Prints "Record Deleted". 
// 8. Closes the file.

// **Main Function (`main()`)**

// 1. Creates a `student` object (`obj`).
// 2. Provides a menu-driven interface in a loop:
//    *  Displays options (Create, Display, Delete, Search, Exit)
//    *  Takes user input.
//    *  Uses a `switch` statement to call the corresponding functions on the `obj` object.

// **Key Points**

// * **Sequential File:** Data is stored and accessed in order, one record after another.
// * **Deletion:** Records are not physically removed but marked as deleted.  This can lead to file space issues over time.

// **Improvements**

// * **Error Handling:**  More robust input validation and error handling.
// * **Efficient Search:**  A binary search could be used if the file is sorted by roll number.
// * **True Deletion:** Implement actual record removal with file reorganization.

// **Let me know if you'd like to focus on the algorithm of a specific function in more detail!** 





// The `fstream` library in C++ is used for file handling operations. It provides classes and functions for reading from and writing to files. Here's a brief overview of the main classes in the `fstream` library:

// 1. **`ofstream` (output file stream)**: This class is used to create and write to files. Objects of this class are used to write data to files as output streams.

// 2. **`ifstream` (input file stream)**: This class is used to read from files. Objects of this class are used to read data from files as input streams.

// 3. **`fstream` (file stream)**: This class combines the functionality of both `ofstream` and `ifstream`, allowing you to both read from and write to files.

// **Basic File Handling Operations:**

// - **Opening a File**: To open a file for reading or writing, you use the `open` method. For example, `ofstream myfile; myfile.open("example.txt");` opens a file named "example.txt" for writing.

// - **Writing to a File**: To write to a file, you use the `<<` operator with an `ofstream` object. For example, `myfile << "Hello, World!\n";` writes the string "Hello, World!" to the file followed by a newline.

// - **Reading from a File**: To read from a file, you use the `>>` operator with an `ifstream` object. For example, `int x; myfile >> x;` reads an integer from the file into the variable `x`.

// - **Closing a File**: After you are done with a file, you should close it using the `close` method. For example, `myfile.close();` closes the file associated with the `myfile` object.

// Here's a simple example that demonstrates writing to and reading from a file using `ofstream` and `ifstream`:

// ```cpp
// #include <iostream>
// #include <fstream>
// using namespace std;

// int main() {
//     ofstream outfile;
//     outfile.open("example.txt"); // Open file for writing

//     outfile << "Hello, World!" << endl; // Write to file

//     outfile.close(); // Close file

//     ifstream infile;
//     infile.open("example.txt"); // Open file for reading

//     string line;
//     getline(infile, line); // Read from file
//     cout << "Read from file: " << line << endl;

//     infile.close(); // Close file

//     return 0;
// }
// ```

// In this example, the program writes "Hello, World!" to a file named "example.txt" and then reads it back to output to the console.



// In C++, `seekg` and `seekp` are member functions of the `std::istream` and `std::ostream` classes, respectively, which are used for positioning the get and put pointers (file position indicators) in input and output streams. These functions are primarily used for file handling to move the file pointer to a specific position within a file.

// - `seekg` stands for "seek get" and is used to set the position of the get pointer (read pointer) in an input stream (`std::istream`).
// - `seekp` stands for "seek put" and is used to set the position of the put pointer (write pointer) in an output stream (`std::ostream`).

// Both `seekg` and `seekp` take an offset and a direction as arguments:

// - `offset` specifies the number of bytes to move the file pointer.
// - `direction` specifies the direction of movement relative to the current position of the file pointer. It can take one of the following values defined in the `ios` class:
//   - `ios::beg` (beginning): Move relative to the beginning of the stream.
//   - `ios::cur` (current): Move relative to the current position of the stream.
//   - `ios::end` (end): Move relative to the end of the stream.

// **Syntax**:

// ```cpp
// // seekg for input streams
// istream& seekg (streamoff offset, ios_base::seekdir way);
// // seekp for output streams
// ostream& seekp (streamoff offset, ios_base::seekdir way);
// ```

// **Example**:

// ```cpp
// #include <iostream>
// #include <fstream>
// using namespace std;

// int main() {
//     ifstream infile("example.txt"); // Open file for reading
//     if (!infile.is_open()) {
//         cerr << "Error opening file." << endl;
//         return 1;
//     }

//     // Move the get pointer to the 5th byte from the beginning of the file
//     infile.seekg(4, ios::beg);

//     string line;
//     getline(infile, line); // Read from file starting from the 5th byte
//     cout << "Read from file: " << line << endl;

//     infile.close(); // Close file

//     return 0;
// }
// ```

// In this example, `seekg` is used to move the get pointer to the 5th byte from the beginning of the file. Subsequent reads from the file will start from this position.