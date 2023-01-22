#include <iostream>
#include <string>
#include <exception>

int function(std::string str, int forbidden_length)
{
    if (str.length() == forbidden_length)
    {
        throw std::exception("Вы ввели слово запретной длины! До свидания");
    }
    std::cout << "Длина слова " << '"' << str << '"' << " равна " << str.length() << std::endl;
    return 0;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    int forbidden_length = 0;
    std::string str;
    try
    {
        std::cout << "Введите запретную длину: ";
        std::cin >> forbidden_length;
        do
        {
            std::cout << "Введите слово: ";
            std::cin >> str;
            function(str, forbidden_length);
        } while (str.length() != forbidden_length);
    }
    catch (const std::exception& bad_length)
    {
        std::cout << bad_length.what() << std::endl;
    }
    return 0;
}

