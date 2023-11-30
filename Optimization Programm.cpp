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
        std::cout << "�������� �������." << std::endl <<
            "������� 2 - ��� ��������� ������� e^(x/2)(x+y^2)." << std::endl <<
            "������� 3 - ��� ��������� ������� x^2+y^2+z^2+2x+4y-6z." << std::endl <<
            "������� 4 - ��� �������������  ������� sin^2(x) + y^2 + sin(z-1/2)+t^2." << std::endl;
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
        std::cout << "������ �� �� ������ ���������� ��������������� (hard) ��� ��������� ������� �������� (easy)." << std::endl <<
            "������� 1 - ��� �������� ���������." << std::endl <<
            "������� 2 - ��� ������� ��������." << std::endl <<
            "��� ��������� ������� ������������ ������� (-3,-3) x (3,3)." << std::endl <<
            "��� ��������� ������� ������������ ������� (-4,-4,-4) x (4,4,4)." << std::endl <<
            "��� ������������ ������� ������������ ������� (-1,-1,-1,-1) x (1,1,1,1)." << std::endl;
        std::cin >> ChoiceArea;
        if (ChoiceArea == 1) {
            std::cout << "������� ���������� ���������������, �� " << ChoiceFun << " ����� � ������ ������, ������� �����������, ����� ������������" << std::endl;
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
        std::cout << "�������� ����� ���������" << std::endl <<
            "������� 1 - ��������� �� ��������� (����������� �����)." << std::endl <<
            "������� 2 - ��������� �� ���� ��������� ������ (����������� �����)." << std::endl <<
            "������� 3 - ��������� �� ������������� ������ ���� ��������� �������� �������(����������� �����)." << std::endl <<
            "������� 4 - ��������� �� ���������� �������� (����������� ����� � ��������� �����)." << std::endl <<
            "������� 5 - ��������� ���� ��������� ��������� ������� (��������� �����)." << std::endl;
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
        std::cout << "������� eps �� �������� ����� ������������ ���������." << std::endl;
        std::cin >> eps;
        std::cout << "������� ������������ ���������� ��������." << std::endl;
        std::cin >> kmax;
        Stop->Setkmax(kmax);
        Stop->Seteps(eps);
        
        std::cout << "�������� ����� ������ ��������." << std::endl <<
            "������� 1 - ����������� ����� (����������� ��������)." << std::endl <<
            "������� 2 - ��������� �����" << std::endl;
        std::cin >> ChoiceMethod;
        std::cout << "������� ��������� �����." << std::endl;
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
            std::cout << "������� alpha." << std::endl;
            std::cin >> alpha;
            std::cout << "������� p" << std::endl;
            std::cin >> p;
            delta.resize(ChoiceFun);
            double Delta;
            std::cout << "������� delta" << std::endl;
            std::cin >> Delta;
            for (int i = 0; i < delta.size(); ++i) {
                delta[i] = Delta;
            }
            
            opt = new StochOpt(alpha, p ,delta);
        }
        opt->optimise(init_point,fun, Stop, area);
        vec find_point(Stop->GetPoint());
        std::cout << "����������� �����: ";
        for (auto i : find_point) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        std::cout << "�������� � ��������: ";
        std::cout << fun->GetValF(find_point);
        std::cout << std::endl;
        std::cout << "���������� ��������: ";
        std::cout << Stop->GetK();
        answer = 0;
        
    }
    delete Stop;
    delete fun;
    delete opt;
    
    
    return 0;
}



