#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    void getData(string n, int a) {
        name = n;
        age = a;
    }

    void display() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

// Derived class: Doctor
class Doctor : public Person {
private:
    string specialization;

public:
    void getDoctorData(string n, int a, string s) {
        getData(n, a);
        specialization = s;
    }

    void displayDoctor() {
        cout << "\n--- Doctor Details ---\n";
        display();
        cout << "Specialization: " << specialization << endl;
    }
};

// Derived class: Nurse
class Nurse : public Person {
private:
    string department;

public:
    void getNurseData(string n, int a, string d) {
        getData(n, a);
        department = d;
    }

    void displayNurse() {
        cout << "\n--- Nurse Details ---\n";
        display();
        cout << "Department: " << department << endl;
    }
};

// Derived class: Administrative Staff
class AdminStaff : public Person {
private:
    string position;

public:
    void getAdminData(string n, int a, string p) {
        getData(n, a);
        position = p;
    }

    void displayAdmin() {
        cout << "\n--- Administrative Staff Details ---\n";
        display();
        cout << "Position: " << position << endl;
    }
};

// Main function
int main() {
    Doctor d;
    Nurse n;
    AdminStaff a;

    d.getDoctorData("Dr. Sharma", 45, "Cardiologist");
    n.getNurseData("Neha", 30, "ICU");
    a.getAdminData("Rajesh", 40, "Receptionist");

    d.displayDoctor();
    n.displayNurse();
    a.displayAdmin();

    return 0;
}
