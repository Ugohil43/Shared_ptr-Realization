#include <iostream>
#include <memory>
#include <string>

#include "My_shared_ptr.hpp"

//cmake -G "MinGW Makefiles" ../

void check_ptr()
{
    My_shared_ptr<int> p1(new int(100));
    My_shared_ptr<int> p2;
    My_shared_ptr<int> p3(std::move(p1));
    My_shared_ptr<int> p4(new int(200));

    std::cout << "Use_count p1: " << p1.use_count() << std::endl;
    std::cout << "p2 is " << p2.operator bool() << std::endl;
    std::cout << "Use_count p3: " << p3.use_count() << std::endl;
    std::cout << "Use_count p4: " << p4.use_count() << std::endl << std::endl;
    
    std::cout << "Data p1: " << *p1 << std::endl;    
    std::cout << "Data p3: " << *p3 << std::endl;    
    std::cout << "Data p4: " << *p4 << std::endl << std::endl << std::endl;    
    
    std::cout << "test_1 p2 = p1" << std::endl;
    p2 = p1;
    std::cout << "Use_count p2: " << p2.use_count() << std::endl;
    std::cout << "Data p2: " << *p2 << std::endl;
    std::cout << "Use_count p1: " << p1.use_count() << std::endl;
    std::cout << "Data p1: " << *p1 << std::endl << std::endl << std::endl;


    std::cout << "test_2 p2 = p3" << std::endl;
    p2 = p3;
    std::cout << "Use_count p2: " << p2.use_count() << std::endl;
    std::cout << "Data p2: " << *p2 << std::endl;
    std::cout << "Use_count p3: " << p3.use_count() << std::endl;
    std::cout << "Data p3: " << *p3 << std::endl << std::endl << std::endl;

    std::cout << "test_3 p1.swap(p4)" << std::endl;
    p1.swap(p4);
    std::cout << "Use_count p1: " << p1.use_count() << std::endl;
    std::cout << "Data p1: " << *p1 << std::endl;
    std::cout << "Use_count p4: " << p4.use_count() << std::endl;
    std::cout << "Data p4: " << *p4 << std::endl << std::endl << std::endl;

    std::cout << "test_4 p1 = move(p4)" << std::endl;
    p1 = std::move(p4);
    std::cout << "Use_count p1: " << p1.use_count() << std::endl;
    std::cout << "Data p1: " << *p1 << std::endl;
    std::cout << "p4 is " << p4.operator bool() << std::endl << std::endl;
    //std::cout << "Use_count p4: " << p4.use_count() << std::endl;
    //std::cout << "Data p4: " << *p4 << std::endl << std::endl;
    //My_shared_ptr<int> p3(p4);
    //std::cout << "Use_count p3: " << p3.use_count() << std::endl;
    //std::cout << "Data p3: " << *p3 << std::endl << std::endl;
    std::shared_ptr<int> sharedPtr1(new int(100));
    std::shared_ptr<int> sharedPtr2(new int(200));
    std::cout << "Data sharedPtr1: " << *sharedPtr1 << std::endl;
    std::cout << "Data sharedPtr2: " << *sharedPtr2 << std::endl;
    std::cout << "Use_count sharedPtr1: " << sharedPtr1.use_count() << std::endl;
    std::cout << "Use_count sharedPtr2: " << sharedPtr2.use_count() << std::endl << std::endl;

    std::cout << "test sharedPtr1 = std::move(sharedPtr2)" << std::endl;
    sharedPtr1 = std::move(sharedPtr2);
    std::cout << "Data sharedPtr1: " << *sharedPtr1 << std::endl;
    std::cout << "Use_count sharedPtr1: " << sharedPtr1.use_count() << std::endl;
    std::cout << "sharedPtr2.bool() " << sharedPtr2.operator bool() << std::endl << std::endl;
    //std::cout << "Data sharedPtr2: " << *sharedPtr2 << std::endl; 
    //std::cout << "Use_count sharedPtr2: " << sharedPtr2.use_count() << std::endl << std::endl;

    std::cout << "test operator[](std::size_t index)" << std::endl;
    My_shared_ptr<int> p5(new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    for (std::size_t i = 0; i < 10; ++i)
        std::cout << p5[i] << ' ';
    std::cout << std::endl << std::endl;

    std::cout << "test make_shared()" << std::endl;
    auto p6 = My_shared_ptr<int>::make_shared(42);
    std::cout << "Use_count p6: " << p6.use_count() << std::endl;
    std::cout << "Data p6: " << *p6 << std::endl;
}

int main()
{
    std::cout << "Start program..." << std::endl << std::endl;
    check_ptr();
    return 0;
}