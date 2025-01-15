#include "LinearHashTable.cpp"
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
#include <list>





class NestedHash
{
    private:
        int numElements;
        std::vector<LinearHashTable*> data;
        void init(int size)
        {
            numElements = 0;
            for (int i = 0; i < size; i++)
            {
                data.push_back(nullptr);
            }
        }
        int hash(const std::vector<LinearHashTable*>& table, std::string str)
        {
            return (((int) str[0]) % data.size());
        }
        std::vector<LinearHashTable*> rehash()
        {
            std::vector<LinearHashTable*> newData(data.size()*2, NULL);
            for (int i = 0; i < data.size(); i++)
            {
                if (data[i] != NULL)
                {
                    for (std::string str : data[i]->getData())
                    {
                        int index = hash(newData, str);
                        if (newData[index] ==  nullptr)
                        {
                            newData[index] = (new LinearHashTable(data.size()));
                            newData[index]->insert(str);
                        }
                        else
                        {
                            (newData[index])->insert(str);
                        }
                    }
                }
            }
            return newData;
        }

    public:
        NestedHash(int size)
        {
            init(size);
        }

        void insertH(std::string str)
        {
            if (data.size() / 2 <= numElements)
            {
                data = std::move(rehash());
            }
            int index = hash(data, str);
            if (data[index] == nullptr)
            {
                data[index] = (new LinearHashTable(data.size()));
                data[index]->insert(str);
            }
            else if (data[index] != nullptr)
            {                
                (data[index])->insert(str);
            }
            numElements++;
        }
        void insertH(std::vector<std::string> strs)
        {
            for (std::string str : strs)
            {
                insertH(str);
            }
        }
        void print()
        {
            for (LinearHashTable* x : data)
            {
                if (x != nullptr)
                {
                    x->print();
                }
            }
        }
};
