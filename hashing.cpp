#include <iostream>
using namespace std;
class Hashtable
{
public:
	int key;
	long int mob_number;
};
class Hashing
{
	Hashtable t[10];
	int i;

public:
	Hashing()
	{

		for (i = 0; i < 10; i++)
		{
			t[i].key = i;
			t[i].mob_number = -1;
		}
	}
	void insert();
	void display();
	void search();
};
void Hashing::display()
{
	cout << "Key"
		 << "\t"
		 << "number\n";

	for (int i = 0; i < 10; i++)
	{
		cout << t[i].key << " \t " << t[i].mob_number << "\n";
	}
}
void Hashing::insert()
{
	long int temp_num;
	int position;
	cout << "\n Enter your mobile number ";
	cin >> temp_num;

	position = temp_num % 10;

	if (t[position].mob_number == -1)
	{
		t[position].mob_number = temp_num;
	}
	else
	{
		cout << "collision occur";
		int original_position = temp_num % 10;
		int position = (original_position + 1) % 10;
		while (position != original_position && t[position].mob_number != -1)
		{
			position = (position + 1) % 10;
		}
		if (position == original_position)
		{
			cout << "\nHashTable is Full";
		}
		t[position].mob_number = temp_num;
	}
}
int main()
{
	Hashing h;
	int ch;
	do
	{
		cout << "\n 1.Insert";
		cout << "\n 2.display";

		cout << "\n Enter a choice";
		cin >> ch;

		switch (ch)
		{
		case 1:
			h.insert();
			break;

		case 2:
			h.display();
			break;

		default:
			cout << "\n Invalid choice";
		}
	} while (ch <= 2);

	return 0;
}
//OUTPUT
/*1.Insert
 2.display
 Enter a choice1

 Enter your mobile number 12345

 1.Insert
 2.display
 Enter a choice1

 Enter your mobile number 23546

 1.Insert
 2.display
 Enter a choice1

 Enter your mobile number 12865
collision occur
 1.Insert
 2.display
 Enter a choice2
Key     number
0        -1
1        -1
2        -1
3        -1
4        -1
5        12345
6        23546
7        12865
8        -1
9        -1

 1.Insert
 2.display
 Enter a choice*/