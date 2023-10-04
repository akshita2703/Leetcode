
//https://leetcode.com/problems/design-hashmap/?envType=daily-question&envId=2023-10-04
#include <iostream>
using namespace std; 

class MyHashMap {
public:
    int data[1000001];
    MyHashMap() {
        fill(data, data + 1000000, -1);
    }
    void put(int key, int val) {
        data[key] = val;
    }
    int get(int key) {
        return data[key];
    }
    void remove(int key) {
        data[key] = -1;
    }
};



int main() {
    // Create an instance of MyHashMap
    MyHashMap myMap;

    // Add some key-value pairs
    myMap.put(1, 42);
    myMap.put(2, 99);
    myMap.put(5, 17);

    // Retrieve and print values
    cout << "Value at key 1: " << myMap.get(1) << endl;
    cout << "Value at key 2: " << myMap.get(2) << endl;
    cout << "Value at key 5: " << myMap.get(5) << endl;

    // Remove a key-value pair
    myMap.remove(2);

    // Attempt to retrieve the removed key
    cout << "Value at key 2 after removal: " << myMap.get(2) << endl;

    return 0;
}


// /**
//  * Your MyHashMap object will be instantiated and called as such:
//  * MyHashMap* obj = new MyHashMap();
//  * obj->put(key,value);
//  * int param_2 = obj->get(key);
//  * obj->remove(key);
//  */