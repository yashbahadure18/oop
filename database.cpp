#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;

class Student;

class Display {
public:
    void showDetails(const Student& s);
};

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dob;
    string bloodGroup;
    string contactAddress;
    long long telephoneNumber;
    string drivingLicenseNo;
    static int studentCount;

public:
    // Default constructor
    Student() {
        name = "N/A";
        rollNumber = 0;
        studentClass = "N/A";
        division = 'N';
        dob = "N/A";
        bloodGroup = "N/A";
        contactAddress = "N/A";
        telephoneNumber = 0;
        drivingLicenseNo = "N/A";
        studentCount++;
    }

    // Parameterized constructor
    Student(string name, int rollNumber, string studentClass, char division,
            string dob, string bloodGroup, string contactAddress, long long telephoneNumber,
            string drivingLicenseNo) {
        this->name = name;
        this->rollNumber = rollNumber;
        this->studentClass = studentClass;
        this->division = division;
        this->dob = dob;
        this->bloodGroup = bloodGroup;
        this->contactAddress = contactAddress;
        this->telephoneNumber = telephoneNumber;
        this->drivingLicenseNo = drivingLicenseNo;
        studentCount++;
    }

    // Copy constructor
    Student(const Student& s) {
        name = s.name;
        rollNumber = s.rollNumber;
        studentClass = s.studentClass;
        division = s.division;
        dob = s.dob;
        bloodGroup = s.bloodGroup;
        contactAddress = s.contactAddress;
        telephoneNumber = s.telephoneNumber;
        drivingLicenseNo = s.drivingLicenseNo;
        studentCount++;
    }

    // Destructor
    ~Student() {
        studentCount--;
        cout << "Destructor called for " << name << endl;
    }

    static int getStudentCount() {
        return studentCount;
    }

    inline void setData() {
        try {
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Roll Number: ";
            cin >> rollNumber;
            cout << "Enter Class: ";
            cin >> studentClass;
            cout << "Enter Division (A/B/C): ";
            cin >> division;
            cout << "Enter Date of Birth (DD/MM/YYYY): ";
            cin >> dob;
            cout << "Enter Blood Group: ";
            cin >> bloodGroup;
            cout << "Enter Contact Address: ";
            cin.ignore();
            getline(cin, contactAddress);
            cout << "Enter Telephone Number: ";
            cin >> telephoneNumber;
            if (cin.fail()) {
                throw invalid_argument("Invalid telephone number input!");
            }
            cout << "Enter Driving License No.: ";
            cin >> drivingLicenseNo;
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    friend void Display::showDetails(const Student& s);
};

int Student::studentCount = 0;

void Display::showDetails(const Student& s) {
    cout << "\nStudent Details:\n";
    cout << "Name: " << s.name << endl;
    cout << "Roll Number: " << s.rollNumber << endl;
    cout << "Class: " << s.studentClass << endl;
    cout << "Division: " << s.division << endl;
    cout << "Date of Birth: " << s.dob << endl;
    cout << "Blood Group: " << s.bloodGroup << endl;
    cout << "Contact Address: " << s.contactAddress << endl;
    cout << "Telephone Number: " << s.telephoneNumber << endl;
    cout << "Driving License No.: " << s.drivingLicenseNo << endl;
}

int main() {
    Student* student1 = new Student();
    student1->setData();
    Display display;
    display.showDetails(*student1);
    cout << "\nCurrent number of students: " << Student::getStudentCount() << endl;

    Student* student2 = new Student();
    student2->setData();
    display.showDetails(*student2);
    cout << "\nCurrent number of students: " << Student::getStudentCount() << endl;

    delete student1;
    delete student2;
    cout << "\nFinal number of students: " << Student::getStudentCount() << endl;

    return 0;
}
