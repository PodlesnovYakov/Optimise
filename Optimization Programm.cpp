#include <iostream>
#include <cmath>
#include <locale.h>
#include <crtdbg.h>
#include "RectArea.h"
#include "F2.h"
#include "F3.h"
#include "F4.h"
#include "AbstrOptimiser.h"
#include "VectorOper.h"
#include "DetOpt.h"
#include "GradStop.h"
#include "StopIter.h"
#include "PointStop.h"
#include "StochOpt.h"
#include "RelErStop.h"
#include "ValFstop.h"

int main(){
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    setlocale(LC_ALL, "rus");

    int ChoiceFun;
    int ChoiceArea;
    int ChoiceStop;
    int ChoiceMethod;
    double eps;
    int kmax;
    double p;
    double alpha;
    vec delta({ -1,-1 });
    vec lower_point{ -1,-1};
    vec upper_point{ 1,1 };
    vec init_point{ 0.5,0.5 };
    RectArea area(2, lower_point, upper_point);
    AbstrFunc* fun = new F2();
    AbstrOptimiser* opt = new DetOpt();
    AbstrStop* Stop = new GradStop();
    int answer = 1;
    while (answer) {
        std::cout << "Выберите функцию." << std::endl <<
            "Нажмите 2 - для двумерной функции e^(x/2)(x+y^2)." << std::endl <<
            "Нажмите 3 - для трёхмерной функции x^2+y^2+z^2+2x+4y-6z." << std::endl <<
            "Нажмите 4 - для четырехмерной  функции sin^2(x) + y^2 + sin(z-1/2)+t^2." << std::endl;
        std::cin >> ChoiceFun;
        lower_point.resize(ChoiceFun);
        upper_point.resize(ChoiceFun);
        area.SetSize(ChoiceFun);
        if (ChoiceFun == 2) {
            delete fun;
            fun = new F2();
        }
        else if (ChoiceFun == 3) {
            delete fun;
            fun = new F3();
        }
        else if (ChoiceFun == 4) {
            delete fun;
            fun = new F4();
        }
        std::cout << "Хотите ли вы ввести координаты параллелипипеда (hard) или поставить заранее заданные (easy)." << std::endl <<
            "Нажмите 1 - для введения координат." << std::endl <<
            "Нажмите 2 - для заранее заданных." << std::endl <<
            "Для двумерной функции предлагается область (-3,-3) x (3,3)." << std::endl <<
            "Для трёхмерной функции предлагается область (-4,-4,-4) x (4,4,4)." << std::endl <<
            "Для четырёхмерной функции предлагается область (-1,-1,-1,-1) x (1,1,1,1)." << std::endl;
        std::cin >> ChoiceArea;
        if (ChoiceArea == 1) {
            std::cout << "Введите координаты параллелипипеда, по " << ChoiceFun << " штуки в каждой строке, сначала минимальные, потом максимальные" << std::endl;
            for (int i = 0; i < ChoiceFun; ++i) {
                std::cin >> lower_point[i];
            }
            for (int i = 0; i < ChoiceFun; ++i) {
                std::cin >> upper_point[i];
            }
            area.SetLower(lower_point);
            area.SetUpper(upper_point);
        }
        else {
            switch (ChoiceFun)
            {
            case 2:
            {
                vec lower({ -3,-3 });
                vec upper({ 3,3 });
                area.SetLower(lower);
                area.SetUpper(upper);
                break;
            }
            case 3:
            {
                vec lower({ -4,-4,-4 });
                vec upper({ 4,4,4 });
                area.SetLower(lower);
                area.SetUpper(upper);
                break;

            }
            case 4: 
            {
                vec lower({ -1,-1,-1,-1 });
                vec upper({ 1,1,1,1 });
                area.SetLower(lower);
                area.SetUpper(upper);
                break;
            }
            }
            
        }
        std::cout << "Выберите метод остановки" << std::endl <<
            "Нажмите 1 - остановка по градиенту (градиентный спуск)." << std::endl <<
            "Нажмите 2 - остановка по двум ближайшим точкам (градиентный спуск)." << std::endl <<
            "Нажмите 3 - остановка по относительной ошибке двух ближайших значений функции(градиентный спуск)." << std::endl <<
            "Нажмите 4 - остановка по количеству итераций (градиентный спуск и случайный поиск)." << std::endl <<
            "Нажмите 5 - остановка двум ближайшим значениям функции (случайный поиск)." << std::endl;
        std::cin >> ChoiceStop;
        switch (ChoiceStop)
        {
        case 1:
        {
            delete Stop;
            Stop = new GradStop();
            break;
        }
        case 2: {
            delete Stop;
            Stop = new PointStop();
            break;
        }
        case 3:
        {
            delete Stop;
            Stop = new RelErStop();
            break;
        }
        case 4:
        {
            delete Stop;
            Stop = new StopIter();
            break;
        }

        case 5: {
            delete Stop;
            Stop = new ValFstop();
            break;
        }
        }
        std::cout << "Введите eps по которому будет производится остановка." << std::endl;
        std::cin >> eps;
        std::cout << "Введите максимальное количество итераций." << std::endl;
        std::cin >> kmax;
        Stop->Setkmax(kmax);
        Stop->Seteps(eps);
        
        std::cout << "Выберите метод поиска минимума." << std::endl <<
            "Нажмите 1 - градиентный спуск (производные численно)." << std::endl <<
            "Нажмите 2 - случайный поиск" << std::endl;
        std::cin >> ChoiceMethod;
        std::cout << "Введите начальную точку." << std::endl;
        init_point.resize(ChoiceFun);
        for (int i = 0; i < init_point.size(); ++i) {
            std::cin >> init_point[i];
        }
        if (ChoiceMethod == 1) {
            delete opt;
            opt = new DetOpt();
            
        }
        else {
            delete opt;
            std::cout << "Введите alpha." << std::endl;
            std::cin >> alpha;
            std::cout << "Введите p" << std::endl;
            std::cin >> p;
            delta.resize(ChoiceFun);
            double Delta;
            std::cout << "Введите delta" << std::endl;
            std::cin >> Delta;
            for (int i = 0; i < delta.size(); ++i) {
                delta[i] = Delta;
            }
            
            opt = new StochOpt(alpha, p ,delta);
        }
        opt->optimise(init_point,fun, Stop, area);
        vec find_point(Stop->GetPoint());
        std::cout << "Минимальная точка: ";
        for (auto i : find_point) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        std::cout << "Значение в минимуме: ";
        std::cout << fun->GetValF(find_point);
        std::cout << std::endl;
        std::cout << "Количество итераций: ";
        std::cout << Stop->GetK();
        answer = 0;
        
    }
    delete Stop;
    delete fun;
    delete opt;
    
    
    return 0;
}



