#include<iostream>
using namespace std;

const int SIZE = 10;

class Employee {
    public:
        int employeeID;
        string name;

        Employee(int id, const string& empName) {
            employeeID = id;
            name = empName;
        }
};

class HashTable {
    private:
        Employee* table[SIZE];

    public:
        HashTable() {
            for (int i = 0; i < SIZE; ++i) {
                table[i] = NULL;
            }
        }

        int hashFunction(int key) {
            int square = key * key;
            int digitCount = 0;
            int temp = square;

            while (temp != 0) {
                temp = temp / 10;
                digitCount++;
            }

            int middleDigits = (digitCount % 2 == 0) ? square / 100 % 100 : square / 10 % 100;
            return middleDigits % SIZE;
        }

        void insert(int key, const string& empName) {
            int index = hashFunction(key);

            while (table[index] != NULL) {
                index = (index + 1) % SIZE;
            }
            table[index] = new Employee(key, empName);
        }

        void display() {
            for (int i = 0; i < SIZE; ++i) {
                if (table[i] != NULL) {
                    cout<<"HashKey["<<i<<"] = Employee Name: "<<table[i]->name<<" :: Employee ID: "<<table[i]->employeeID<<endl;
                }
            }
        }
};

int main() {
    HashTable employeeTable;

    employeeTable.insert(4176, "Zain Ul Abideen Malik");
    employeeTable.insert(5678, "Azhar Ali Khan Toori");
    employeeTable.insert(5469, "Muhammad Mubashir");
    employeeTable.insert(1245, "Gulzaar Abbas");
    employeeTable.insert(8907, "Zain Ali Mehmood");

    employeeTable.display();

    return 0;
}