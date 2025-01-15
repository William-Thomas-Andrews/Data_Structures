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





class HashList
{
    private:
        int numElements;
        std::vector<std::list<std::string>*> data;
        void init(int size)
        {
            numElements = 0;
            for (int i = 0; i < size; i++)
            {
                data.push_back(nullptr);
            }
        }
        int hash(const std::vector<std::list<std::string>*>& table, std::string str)
        {
            return (((int) str[0]) % data.size());
        }
        
        std::vector<std::list<std::string>*> rehash()
        {
            std::vector<std::list<std::string>*> newData(data.size()*2, NULL);
            for (int i = 0; i < data.size(); i++)
            {
                if (data[i] != NULL)
                {
                    for (std::string str : *(data[i]))
                    {
                        int index = hash(newData, str);
                        if (newData[index] ==  nullptr)
                        {
                            newData[index] = (new std::list<std::string>({str}));
                        }
                        else
                        {
                            (*(newData[index])).push_back(str);
                        }
                    }
                }
            }
            return newData;
        }

    public:
        HashList(int size)
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
                data[index] = (new std::list<std::string>({str}));
            }
            else if (data[index] != nullptr)
            {                
                (*(data[index])).push_back(str);
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
            for (std::list<std::string>* x : data)
            {
                if (x != nullptr)
                {
                    for (std::string y : *x)
                    {
                        std::cout << y << std::endl;
                    }
                }
            }
        }
};
