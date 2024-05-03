#include<iostream>
using namespace std;

class HashTable
{
    public:
        int index;
        long int mobile;
};

class Hashing
{
    HashTable h[10];
    public:
        Hashing()
        {
            for(int i=0;i<10;i++)
            {
                h[i].index=i;
                h[i].mobile=-1;
            }
        }

        void display();
        void insert(int);
        void search();
        int LinearProbing(int);
        int QuadraticProbing(long int);

};

int Hashing::QuadraticProbing(long int key)
{
    int a;

    for(int j=0;j<10;j++)
    {
        a=  (key + (j*j))%10;
        if(h[a].mobile==-1)
        {
            return a;
        }
    }

    return -1; // Ensure a value is returned in all control paths
}

int Hashing::LinearProbing(int collision_position)
{
    for(int i=collision_position;i<10;i++)
    {
        if(h[i].mobile==-1)
            return i;

        if(i==9)
            return -1; // Ensure a value is returned in all control paths
    }

    return -1; // Ensure a value is returned in all control paths
}

void Hashing::display()
{
    for(int i=0;i<10;i++)
    {
        cout<<h[i].index;
        cout<<"  "<<h[i].mobile;
        cout<<endl;
    }
}

void Hashing::insert(int probchoice)
{   
    long int key;
    int position;
    cout<<"\nEnter mobile number to insert in to hash table : ";
    cin>>key;
    position = key % 10;

    cout<<"\nPosition = "<<position;

    if(h[position].mobile==-1)
    {
        h[position].mobile=key;
    }
    else if(probchoice ==1)// Linear Probing collision.
    {
        int temp_position;
        temp_position = LinearProbing(position);
        h[temp_position].mobile=key;
    }
    else if(probchoice ==2)// Quadratic Probing for collision.
    {
        int temp_position;
        temp_position = QuadraticProbing(key);
        h[temp_position].mobile=key;
    }

}

void Hashing::search()
{   
    long int key;
    int position,i;
    cout<<"\nEnter mobile number to search in the hash table : ";
    cin>>key;
    position = key % 10;
    
    if(h[position].mobile==key)
    {
        cout<<"\nGiven mobile number is found in the hash table ";
    }
    else
    {
        for(i = 0; i<10;i++)
        {
            if(h[i].mobile==key)
            {
                cout<<"\nGiven mobile number is found in the hash table  ";
                break;
            }
        }
        if(i == 10)
        {
            cout<<"\nGiven mobile number is not found in the hash table ";
        }
    }
}

int main()
{
    Hashing H;
    int ch;

    do
    {
        cout<<"\n Menu";
        cout<<"\n 1.insert";
        cout<<"\n 2.display";
        cout<<"\n 3.search";
        cout<<"\n 5. exit";
        cout<<"\n Enter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1 : //insert
                int probchoice;
                cout<<"\nEnter \n1 for LinearProbing and \n2 for Quadratic probing";
                cin>>probchoice;
                H.insert(probchoice);
            break;
            case 2 : //display
                H.display();
            break;
        
            case 3 : //display
                H.search();
            break;
        
            default:
                cout<<"\nWrong choice :";
            break;
        }
        
    }while(ch != 5);
    H.display();
}












// **What is Hashing?**

// - **Core Idea:** Hashing is a technique used to map data of varying sizes to fixed-size values. These fixed-size values are called "hash values," "hash codes," or simply "hashes."
// - **Key Components:**
//     1. **Key:** This is the data item you want to store or look up (e.g., a client's name in your telephone book example).
//     2. **Hash Function:** A mathematical function that takes the key as input and computes the hash value (the index where the data might be stored).
//     3. **Hash Table:** An array-like data structure where the computed hash values serve as indices for storing or retrieving data.

// **Why Do We Use Hashing?**

// - **Speed:** Hashing aims to provide near-constant time complexity (O(1) on average) for data lookup, insertion, and deletion. This makes it extremely efficient, especially when dealing with large datasets.
// - **Data Organization:** Hashing helps organize data in a way that makes finding specific items very fast. Think of it like a super-efficient index system in a library.

// **How It Works (Simplified Example)**

// 1. **Hash Function:** Let's say our hash function is "modulus 10" (for simplicity). If the key is "John Smith," we might treat the letters as numbers and add them up, then take the remainder after dividing by 10. This remainder becomes the hash value.
// 2. **Hash Table:** Our hash table has 10 slots (indices 0-9). The hash value we calculated determines where we might store or find the data associated with the key "John Smith."

// **Real-World Applications**

// - **Databases:** Hashing is used extensively for indexing in databases to speed up searches.
// - **Password Storage:** Passwords are not stored directly; instead, their hashes are stored for security reasons.
// - **Caching:** Caches use hashing techniques for quick data retrieval.
// - **Data Integrity:** Hashing is used to generate checksums to detect file corruption or tampering.

// **Let me know if you would like a more elaborate example, or discuss the importance of good hash functions!**

// Let's dive into the details of Linear Probing, Quadratic Probing, and Double Hashing, specifically for collision handling in hash tables, and analyze their strengths and weaknesses:

// **Linear Probing**

// - **Mechanics:** When a collision occurs, you sequentially examine the next slot, then the next, and so on until you find an empty slot to insert the element. If you reach the end of the table, you often wrap around to the beginning.
// - **Clustering:** The biggest issue is **primary clustering**. Consecutive occupied slots get longer and longer, making collisions more likely in those regions. This leads to longer search times, as you might need to traverse many filled slots to find your target.
// - **Example:** Let's say your ideal hash value (index) is 5:
//     - Collision at 5!
//     - Check 6... occupied.
//     - Check 7... occupied.
//     - Check 8... empty! You insert the element here.

// **Pros of Linear Probing:**

// - **Simplicity:** Very easy to understand and implement.
// - **Cache Performance:** Good for cache memory due to locality of reference (accessing data in neighboring locations).

// **Cons of Linear Probing:**

// - **Clustering:** High susceptibility to primary clustering degrades search performance.

// **Quadratic Probing**

// - **Mechanics:** Instead of a linear search, you use a quadratic function to determine the probe sequence. You jump further away with each probe (e.g., initially +1, then +4, +9, +16, etc.).
// - **Reduced Clustering:** Quadratic probing is less prone to primary clustering compared to linear probing, as it spreads out the probes.
// - **Example:** Again, assume ideal hash value (index) is 5:
//     - Collision at 5!
//     - Check 6 (5 + 1)... occupied.
//     - Check 9 (5 + 4)... occupied.
//     - Check 14 (5 + 9)... empty! You insert the element here.

// **Pros of Quadratic Probing:**

// - **Reduces Primary Clustering:** Better distribution than linear probing.

// **Cons of Quadratic Probing:**

// - **Secondary Clustering:** Quadratic probing can still lead to mild clustering of another kind, though less severe than linear probing.
// - **Calculation:** Slightly more compute overhead due to the quadratic calculation.

// **Double Hashing**

// - **Mechanics:** You use a second hash function to calculate the probe offset when a collision occurs. This offset depends on the key itself.
// - **Distribution:** Double hashing aims for the most even distribution of elements, significantly reducing clustering issues.
// - **Example:** Ideal hash value is 5:
//     - Collision at 5!
//     - Second hash function gives offset of 3. Check 8...occupied.
//     - Second hash function gives offset of 5. Check 10... empty! Insert here.

// **Pros of Double Hashing**

// - **Minimizes Clustering:** Best for avoiding both primary and secondary clustering.
// - **Flexibility:** Gives control over the probe sequence.

// **Cons of Double Hashing:**

// - **Complexity:** Slightly more complex to implement due to the second hash function.
// - **Hash Function Choice:** Performance depends heavily on selecting good hash functions.

// **In Summary**

// - **Clustering Avoidance:** Double Hashing > Quadratic Probing > Linear Probing
// - **Simplicity:** Linear Probing > Quadratic Probing > Double Hashing

// The best choice depends on your dataset and priorities. If minimizing clustering is paramount, double hashing is usually preferred.

// Let me know if you'd like more illustrations or have any questions!

// Absolutely! Let's break down your C++ hash table implementation step by step.

// **Structure**

// - **HashTable class:** A simple structure to hold the index (position in the hash table) and mobile number. This represents a single entry in the table.
// - **Hashing class:** This is the core of the implementation. It stores your data, and contains functions for insertion, display, and searching, as well as handling collisions with linear and quadratic probing.

// **Hashing Class Breakdown**

// 1. **Constructor:**
//     - You have an array `h` of 10 `HashTable` objects.
//     - The constructor initializes each entry:
//         - `index` is set to its position in the array for quick reference.
//         - `mobile` is set to -1, indicating an empty slot.
// 2. **display()**
//     - Iterates over the hash table and prints the `index` and `mobile` number for each entry.
// 3. **insert(int probchoice)**
//     - **Input:** Asks the user for the mobile number to insert.
//     - **Hash Calculation:** `position = key % 10`. The mobile number is used as the key, and a simple modulo 10 is your hash function.
//     - **Check for Empty Slots:** If `h[position].mobile == -1`, the slot is empty, and the number is inserted directly.
//     - **Collision Handling:** If there's a collision, you either call `LinearProbing` or `QuadraticProbing` based on the user's choice (`probchoice`).
// 4. **LinearProbing(int collision_position)**
//     - Begins searching for an empty slot sequentially from the point of collision (`collision_position`).
//     - If an empty slot is found, the index is returned.
//     - Returns -1 if the end of the table is reached without finding an empty slot.
// 5. **QuadraticProbing(long int key)**
//     - Implements the quadratic probing formula: `(key + (j*j)) % 10` to determine the offset from the collision point.
//     - Searches for an empty slot using this offset.
//     - Returns -1 if the table is full and no empty slot is found.
// 6. **search()**
//     - **Input:** Asks the user for the mobile number to search for.
//     - **Hash Calculation:** `position = key % 10` calculates the initial hash position.
//     - **Direct Check:** If the number is found at the initial position, it's reported as found.
//     - **Iterative Search:** If not, it iterates over the table to check other potential locations determined by the probing strategy.

// **Main Function**

// - Creates a `Hashing` object.
// - Provides a menu-driven interface for the user to interact with the hash table (insert, display, search, exit).

// **Notes**

// - **Hash Function:** Your hash function (`key % 10`) is quite simple. For larger datasets or more complex keys, you'd likely want a better function to distribute values more evenly.
// - **Load Factor:** Your table has a fixed size of 10. As it fills up, collision resolution efficiency becomes very important.
// - **Error Handling:** You might consider more robust error handling for when the table becomes full.

// Let me know if you want to focus on optimizing a specific part of the code or explore alternative collision handling techniques!