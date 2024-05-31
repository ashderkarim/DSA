#include<iostream>
using namespace std;

const int SIZE = 7;

class HashTable {
    private:
        int table[SIZE];

    public:
        HashTable() {
            for (int i = 0; i < SIZE; ++i) {
                table[i] = -1;
            }
        }

        int hashFunction(int key) {
            return key % SIZE;
        }

        void insert(int key) {
            int index = hashFunction(key);

            while (table[index] != -1) {
                index = (index + 1) % SIZE;
            }
            table[index] = key;
        }

        void display() {
            for (int i = 0; i < SIZE; ++i) {
                cout<<"HashKey["<<i<<"] = "<<table[i]<<endl;
            }
        }
};

int main() {
    HashTable hashTable;

    hashTable.insert(50);
    hashTable.insert(700);
    hashTable.insert(76);
    hashTable.insert(85);
    hashTable.insert(92);
    hashTable.insert(73);
    hashTable.insert(101);

    hashTable.display();

    return 0;
}