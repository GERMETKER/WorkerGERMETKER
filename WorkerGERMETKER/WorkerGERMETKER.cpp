#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
class Worker
{
public:
    void Start()
    {
        static int rabochie = 1;
        int answ;
        SetName();
        SetExp();
        SetMonInHour();
        SetKolvOfHour();
        SumOfMoney();
        PremSum();
        SumAllMoney();
        PrintAllCharact();
        std::cout << "Занести информацию о работнике в файл?\n1 - Да\n2 - Нет\n";
        std::cin >> answ;
        int answ2;
        if (answ == 1)
        {
            AddToFile(rabochie);
            std::cout << "Начать заполнять данные о следующем работнике?\n1 - Да\n2 - Нет\n";
            std::cin >> answ2;
            if (answ2 == 1)
            {
                rabochie++;
                Start();
            }
        }
        else
        {
            std::cout << "Начать заполнять данные о следующем работнике?\n1 - Да\n2 - Нет\n";
            std::cin >> answ2;
            if (answ2 == 1)
            {
                rabochie++;
                Start();
            }
        }
    }
    void SetName()
    {
        std::cin.ignore(32000, '\n');
        std::cout << "Введите ФИ работника\n";
        std::getline(std::cin, name, '\n');
    }
    void SetExp()
    {
        std::cout << "Введите стаж работника\n";
        std::cin >> experience;
    }
    void SetMonInHour()
    {
        std::cout << "Введите часовую зарплату работника\n";
        std::cin >> money_in_hour;
    }
    void SetKolvOfHour()
    {
        std::cout << "Введите кол-во отработанных часов работника\n";
        std::cin >> kolv_of_hours;
    }
    void SumOfMoney()
    {
        moneyOfHours = money_in_hour * kolv_of_hours;
    }
    void PremSum()
    {
        double kooficent = 0;
        if (experience < 1)
        {
            kooficent = 0;
        }
        else if (experience < 3 && experience >= 1)
        {
            kooficent = 0.05;
        }
        else if (experience < 5 && experience >= 3)
        {
            kooficent = 0.08;
        }
        else if (experience >= 5)
        {
            kooficent = 0.15;
        }
        premia = moneyOfHours * kooficent;
    }
    void SumAllMoney()
    {
        allMoney = moneyOfHours + premia;
    }
    void PrintAllCharact()
    {
        std::cout << "ФИ: " << name << "\n";
        std::cout << "Стаж: " << experience << " \n";
        std::cout << "Зарплата в час: " << money_in_hour << "\n";
        std::cout << "Кол-во отработанный часов: " << kolv_of_hours << "\n";
        std::cout << "Зарплата за отработанное время (без учёта премии): " << moneyOfHours << "\n";
        std::cout << "Премия: " << premia << "\n";
        std::cout << "Итоговая сумма зарплаты: " << allMoney << "\n";
    }
    void AddToFile(int rabochie)
    {
        static std::string fileName;    
        std::ofstream Workers;
        if (rabochie > 1)
        {
            int answ3;
            std::cout << "Использовать тот же файл или другой?\n1 - Тот же\n2 - Другой\n";
            std::cin >> answ3;
            if (answ3 == 2)
            {
                std::cout << "Введите имя файла\n";
                std::cin >> fileName;
            }
        }
        else
        {
            std::cout << "Введите имя файла\n";
            std::cin >> fileName;
        }
        Workers.open(fileName, std::ofstream::app);
        if(!Workers.is_open())
        {
            std::cerr << "Error!\n";
        }
        else
        {
            Workers << "Работник " << rabochie << "\n";
            Workers << "ФИ: " << name << "\n";
            Workers << "Стаж: " << experience << " \n";
            Workers << "Зарплата в час: " << money_in_hour << "\n";
            Workers << "Кол-во отработанный часов: " << kolv_of_hours << "\n";
            Workers << "Зарплата за отработанное время (без учёта премии): " << moneyOfHours << "\n";
            Workers << "Премия: " << premia << "\n";
            Workers << "Итоговая сумма зарплаты: " << allMoney << "\n";
        }

        
        Workers.close();
    }

private:
    std::string name;
    double experience;
    double money_in_hour;
    double kolv_of_hours;
    double moneyOfHours;
    double premia;
    double allMoney;
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Worker one;
    one.Start();  
}

