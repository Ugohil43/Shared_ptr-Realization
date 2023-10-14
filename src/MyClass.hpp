#ifndef MYCLASS_HPP
#define MYCLASS_HPP
#include <iostream>

template <typename T>
class MyClass 
{
public:
    MyClass(T value) : data(value) 
    {
        std::cout << "Creating MyClass with data = " << data << std::endl;
    }

    void printData() 
    {
        std::cout << "The value of data: " << data << std::endl;
    }

private:
    T data;
};

#endif // MYCLASS_HPP