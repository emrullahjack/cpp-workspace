#include <iostream>
using namespace std;

class Hash {
  int bucket; // number of buckets
  list<int> *table; // pointer to an array containing buckets

public:
  int hashFucntion(int key) { // maps hash function values to keys
    return key % bucket;
  }

  Hash(int v);
  void insertItem(int key); // inserts a key into hash table
  void deleteItem(int key); // deletes a key from hash table
  void displayHash();
};

Hash::Hash(int v) {
  this->bucket = v;
  table = new list<int>[bucket];
}

Hash::insertItem(int key) {
  int index = hashFucntion(key);
  table[index].push_back(key);
}

void Hash::deleteItem(int key) {
  int index = hashFucntion(key);
  list <int> :: iterator i;
  for (i = table[index].begin(); i != table[index].end(); i++) {
    if (*i == key)
      break;
  }

  if (i != table[index].end())
    table[index].erase(i);
}

void Hash::displayHash() {
  for (int i = 0; i < bucket; i++) {
    cout << i;
    for (auto x : table[i]) {
      cout << " --> " x;
    }
    cout << endl;
  }
}

// Driver Program
int main(int argc, char const *argv[]) {
  int a[] = {15, 11, 27, 8, 12};
  int n = sizeof(a)/sizeof(a[0]);

  Hash h7;

  return 0;
}
