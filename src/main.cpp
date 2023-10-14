#include <iostream>
#include <memory>
#include <string>

#include "MyClass.hpp"

//cmake -G "MinGW Makefiles" ../

int main()
{
    std::cout << "Start of the program..." << std::endl<<std::endl;
    
    MyClass<int> value(123);
    std::shared_ptr<MyClass<int>> sharedPtr1 = std::make_shared<MyClass<int>>(value);

    // Создаем еще один shared_ptr, который также управляет объектом
    std::shared_ptr<MyClass<int>> sharedPtr2 = sharedPtr1;

    // Используем shared_ptr для вызова методов объекта
    std::cout << "\nUsing printData() for SharedPtr1... " << std::endl;
    sharedPtr1->printData();
    std::cout << "Using printData() for SharedPtr2... " << std::endl;
    sharedPtr2->printData();
    std::cout << std::endl;

    // Используем rvalue ссылки и std::move для передачи владения объектом
    std::string value2 = "Value 2";
    std::shared_ptr<MyClass<std::string>> sharedPtr3 = std::make_shared<MyClass<std::string>>(std::move(value2));
    std::shared_ptr<MyClass<std::string>> sharedPtr4 = std::move(sharedPtr3);

    // Попытка использования sharedPtr3 приведет к ошибке, так как теперь объектом владеет sharedPtr4
    //sharedPtr3->printData(); // Ошибка: у sharedPtr3 нет владения объектом

    std::cout << "\nUsing printData() for SharedPtr4... " << std::endl;
    sharedPtr4->printData();

    // Используем lvalue ссылки для возврата объекта из shared_ptr
    std::shared_ptr<MyClass<std::string>> sharedPtr5 = sharedPtr4; // Создаем lvalue объект, который получает владение
    std::cout << "\nUsing printData() for SharedPtr5... " << std::endl;
    sharedPtr5->printData();

    // Объект будет удален только после уничтожения последнего shared_ptr, управляющего им
    return 0;
}