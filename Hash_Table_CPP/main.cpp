// #include "HashLin.cpp"
#include "HashList.cpp"
#include "NestedHash.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <string>
#include <utility>
#include <type_traits>
#include <ranges>
#include <concepts>
#include <utility>
#include <random>
#include <set>
#include <unordered_set>
#include <chrono>
#include <map>
#include <unordered_map>
#include <mutex>
#include <thread>
#include <fstream>
#include <array>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <ranges>
#include <cmath>
#include <memory>




int main()
{
    LinearHashTable hashTable(10);

    // Insert and print basic entries
    hashTable.insert("apple");
    hashTable.insert("banana");
    hashTable.insert("cherry");
    std::cout << "Linear Hash Table after basic insertions:" << std::endl;
    hashTable.print();

    // Insert duplicates
    hashTable.insert("banana");
    std::cout << "After inserting a duplicate ('banana'):" << std::endl;
    hashTable.print();

    // Insert elements causing collision
    hashTable.insert("grape");
    std::cout << "After inserting 'grape' (may cause collision):" << std::endl;
    hashTable.print();

    // Insert into a full table
    hashTable.insert("orange");
    std::cout << "After inserting 'orange' into full table:" << std::endl;
    hashTable.print();

    // Inserting an empty key (optional behavior)
    hashTable.insert("");  // Assuming we allow empty strings
    std::cout << "After inserting empty string:" << std::endl;
    hashTable.print();






    std::cout << std::endl;
    std::cout << "_______________________________________" << std::endl;
    std::cout << std::endl;





    /// List Hash Table Implementation
    HashList listhashTable(10);

    // Insert basic entries
    listhashTable.insertH("apple");
    listhashTable.insertH("banana");
    listhashTable.insertH("cherry");
    std::cout << "List Hash Table after basic insertions:" << std::endl;
    listhashTable.print();

    // Insert multiple elements with hash collisions
    listhashTable.insertH("grape");
    listhashTable.insertH("melon");
    std::cout << "After inserting more entries (some may collide):" << std::endl;
    listhashTable.print();

    // Insert duplicates
    listhashTable.insertH("apple");
    std::cout << "After inserting a duplicate ('apple'):" << std::endl;
    listhashTable.print();

    // Insert an empty string
    listhashTable.insertH("");  // Assuming we allow empty strings
    std::cout << "After inserting an empty string:" << std::endl;
    listhashTable.print();




    std::cout << std::endl;
    std::cout << "_______________________________________" << std::endl;
    std::cout << std::endl;




    /// Nested Hash Implementation

    NestedHash nestedhashTable(7);

    // Insert and print basic nested data
    nestedhashTable.insertH(std::vector<std::string>({"Fruits", "apple"}));
    nestedhashTable.insertH(std::vector<std::string>({"Fruits", "banana"}));
    nestedhashTable.insertH(std::vector<std::string>({"Vegetables", "carrot"}));
    std::cout << "Nested Hash Table after basic insertions:" << std::endl;
    nestedhashTable.print();

   // Insert into a new outer key
    nestedhashTable.insertH(std::vector<std::string>({"Dairy", "milk"}));
    nestedhashTable.insertH(std::vector<std::string>({"Dairy", "cheese"}));
    std::cout << "After adding new outer key ('Dairy'):" << std::endl;
    nestedhashTable.print();

    // Insert into existing outer key (duplicate inner keys)
    nestedhashTable.insertH(std::vector<std::string>({"Fruits", "apple"}));  // Update value of 'apple'
    std::cout << "After inserting into an existing outer key ('Fruits'):" << std::endl;
    nestedhashTable.print();

    // Edge case - empty outer and inner keys
    nestedhashTable.insertH(std::vector<std::string>({"", ""}));
    std::cout << "After inserting empty string as key:" << std::endl;
    nestedhashTable.print();


    /// these are not pairs!!! I did not build it to be pairs
}