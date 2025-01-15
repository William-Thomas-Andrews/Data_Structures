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



class LinearHashTable
{
    private:
        int noiseVariable;
        int numElements;
        std::vector<std::string> data;
        void init(int size)
        {
            numElements = 0;
            data.reserve(size);
            for (int i = 0; i < size; i++)
            {
                data.push_back("");
            }
            
        }
        int hash(const std::vector<std::string>& table, std::string str)
        {
            int index = 0;
            int i = 0;
            noiseVariable = (int) str[0];
            for (unsigned int hash = 0; ; hash%=table.size())
            {
                if (table[hash] != "") // continue
                {
                    index = hash;
                    hash = 31*i + noiseVariable;
                    i++;
                }
                else if (table[hash] == "")
                {
                    index = hash;
                    break;
                }
            }
            
            return index;
        }
        std::vector<std::string> rehash()
        {
            std::vector<std::string> newData(data.size()*2, "");
            for (int i = 0; i < data.size(); i++)
            {
                if (data[i] != "")
                {
                    newData[hash(newData, data[i])] = data[i];
                }
            }
            return newData;
        }

    public:
        LinearHashTable(int size)
        {
            init(size);
        }

        void insert(std::string str)
        {
            if (data.size() / 2 <= numElements) // re-hash
            {
                data = std::move(rehash());
            }
            data[hash(data, str)] = str; 
            numElements++;
        }
        void insert(std::vector<std::string> strs)
        {
            for (std::string str : strs)
            {
                insert(str);
            }
        }
        void print()
        {
            for (std::string x : data)
            {
                    std::cout << x << std::endl;
            }
        }
        const std::vector<std::string>& getData()
        {
            return data;
        }
};

