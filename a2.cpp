#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    string studentClass;
    char division;
    string dob;
    string bloodGroup;
    string address;
    long long phoneNumber;
    string drivingLicense;

    static int studentCount; // Static member to keep track of students

public:
    // Default Constructor
    Student()
        : rollNo(0), division('A'), phoneNumber(0) {
        studentCount++;
    }

    // Parameterized Constructor
    Student(string name, int rollNo, string studentClass, char division, string dob,
            string bloodGroup, string address, long long phoneNumber, string drivingLicense)
        : name(name), rollNo(rollNo), studentClass(studentClass), division(division),
          dob(dob), bloodGroup(bloodGroup), address(address), phoneNumber(phoneNumber),
          drivingLicense(drivingLicense) {
        studentCount++;
    }

    // Destructor
    ~Student() {
        studentCount--;
    }

    // Static Function to get student count
    static int getStudentCount() {
        return studentCount;
    }

    // Function to set data dynamically
    void setDataDynamically() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Class: ";
        cin >> studentClass;
        cout << "Enter Division: ";
        cin >> division;
        cout << "Enter Date of Birth (DD/MM/YYYY): ";
        cin >> dob;
        cout << "Enter Blood Group: ";
        cin >> bloodGroup;
        cout << "Enter Address: ";
        cin.ignore(); // To clear the newline character from the input buffer
        getline(cin, address);
        cout << "Enter Phone Number: ";
        cin >> phoneNumber;
        cout << "Enter Driving License No.: ";
        cin >> drivingLicense;
    }

    // Friend Class
    friend class Admin;

    // Function to display data in tabular format
    void displayRow() const {
        cout << left << setw(15) << name
             << setw(10) << rollNo
             << setw(10) << studentClass
             << setw(10) << division
             << setw(15) << dob
             << setw(10) << bloodGroup
             << setw(20) << address
             << setw(15) << phoneNumber
             << setw(20) << drivingLicense << endl;
    }
};

// Initialize static member
int Student::studentCount = 0;

int main() {
    Student *students;
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    // Dynamic memory allocation
    students = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        students[i].setDataDynamically();
    }

    // Display student data in tabular format
    cout << "\nStudent Database:\n";
    cout << left << setw(15) << "Name"
         << setw(10) << "Roll No"
         << setw(10) << "Class"
         << setw(10) << "Division"
         << setw(15) << "DOB"
         << setw(10) << "Blood Grp"
         << setw(20) << "Address"
         << setw(15) << "Phone No"
         << setw(20) << "Driving License" << endl;

    cout << string(120, '-') << endl;

    for (int i = 0; i < n; i++) {
        students[i].displayRow();
        cout << string(120, '-') << endl; // Add dashed line after each student's data
    }

    // Free dynamically allocated memory
    delete[] students;

    cout << "\nTotal Students in System after deletion: " << Student::getStudentCount() << endl;

    return 0;
}

