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

// This C++ code defines a simple console-based student information management system using a file-based data storage approach. It allows the user to create, display, search for, and delete student records stored in a binary file named "stud.dat". Here's a detailed line-by-line explanation:

// ### Structure and Class Definition

// 1. `#include<iostream>`: Includes the Standard I/O stream library.
// 2. `#include<fstream>`: Includes the File stream library for file handling.
// 3. `#include<string.h>`: Includes the C string manipulation library.
// 4. `using namespace std;`: Avoids the need to prefix `std::` to standard library objects and functions.

// 5. `struct stud`: Defines a structure named `stud` to hold individual student records. 
//    - `int roll;`: Student's roll number.
//    - `char name[10];`: Student's name, limited to 10 characters.
//    - `char div;`: Student's division (class section).
//    - `char add[10];`: Student's address, limited to 10 characters.

// 6. `class student`: Defines a class to handle student data operations.
//    - Contains methods for creating records, displaying them, searching for a specific record, and deleting a record.

// ### Class Methods

// #### `create()` method:
// - Opens a file "stud.dat" in binary output mode.
// - Repeatedly prompts the user to enter details for a student.
// - Writes these details to the file and flushes the output buffer using `flush`.
// - Continues until the user decides to stop adding records.

// #### `display()` method:
// - Opens the file "stud.dat" in binary input mode.
// - Reads and displays all student records, unless the roll number is `-1` (indicating a deleted or invalid record).

// #### `search()` method:
// - Searches for a student record by roll number.
// - Displays the record if found.
// - Returns the position of the record in the file (or `0` if not found).

// #### `Delete()` method:
// - Calls `search()` to get the position of the record to delete.
// - If found, it marks the record as deleted by setting the roll number to `-1` and updating other fields to indicate deletion.
// - This deletion is logical rather than physical, as the record space is not removed from the file.

// ### Main Function

// - Displays a menu for the user to choose from various operations (create, display, delete, search, or exit).
// - Executes the chosen operation.
// - Loops back to the menu until the user decides to exit.

// ### Issues and Improvements Needed

// 1. **Buffer Overflow Risk**: The fixed size of character arrays for `name` and `add` can lead to buffer overflow if the user inputs exceed the expected length.
// 2. **Security Risk**: The use of `cin >>` for strings without length checks is unsafe.
// 3. **Better Data Handling**: Using `-1` as a marker for deleted records is inefficient for large data sets. Implementing a more robust way to handle deletions would be beneficial.
// 4. **Use of Modern C++ Features**: This code uses old C-style strings and could be updated to use `std::string` for better memory management and safety. Also, `std::fstream` could be used with modern techniques like RAII for better resource management.
// 5. **Error Checking**: There is minimal error checking, particularly for file operations and user inputs, which could lead to runtime errors if the file isn't found or the inputs are invalid.

// This system, while functional for basic tasks, lacks robustness and efficiency needed for a more serious application. Upgrading to modern C++ practices and improving data handling would significantly enhance its usability and security.