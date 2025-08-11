#include <iostream>
using namespace std;

class Publication 
{
public:
    string title;
    float price;

    Publication(string title, float price) 
	{
        this->title = title;
        this->price = price;
    }
};

class Book : public Publication 
{
public:
    int page_count;

    Book(string title, float price, int page_count) : Publication(title, price) 
	{
        this->page_count = page_count;
    }

    void print_data() 
	{
        cout << string(20, '-') << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Page Count: " << page_count << endl;
        cout << string(20, '-') << endl;
    }
};

class Tape : public Publication 
{
public:
    float playing_time;

    Tape(string title, float price, float playing_time) : Publication(title, price) 
	{
        this->playing_time = playing_time;
    }

    void print_data() 
	{
        cout << string(20, '-') << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Playing Time: " << playing_time << " minutes" << endl;
        cout << string(20, '-') << endl;
    }
};

int main() 
{
    string title;
    float price;
    int page_count;
    float playing_time;

    // Input for the Book
    cout << "Enter Book Title: ";
    getline(cin, title);  // Using getline to allow spaces in the title
    cout << "Enter Book Price: ";
    cin >> price;
    cout << "Enter Page Count: ";
    cin >> page_count;

    Book b1(title, price, page_count);
    cout << "\nBook Information: \n";
    b1.print_data();

    // Clear the input buffer before reading the tape data
    cin.ignore();

    // Input for the Tape
    cout << "Enter Tape Title: ";
    getline(cin, title);
    cout << "Enter Tape Price: ";
    cin >> price;
    cout << "Enter Playing Time (in minutes): ";
    cin >> playing_time;

    Tape t1(title, price, playing_time);
    cout << "\nTape Information: \n";
    t1.print_data();

    return 0;
}

