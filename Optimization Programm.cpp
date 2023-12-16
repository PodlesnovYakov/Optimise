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
        std::cout << "Select function." << std::endl <<
            "Press 2 - for the 2D function e^(x/2)(x+y^2)." << std::endl <<
            "Press 3 - for the 3D function x^2+y^2+z^2+2x+4y-6z." << std::endl <<
            "Press 4 - for the 4D function sin^2(x) + y^2 + sin(z-1/2)+t^2." << std::endl;
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
        std::cout << "Do you want to enter the coordinates of the parallelepiped (hard) or enter predefined ones (easy)." << std::endl <<
            "Press 1 - to enter coordinates." << std::endl <<
            "Press 2 - for preset coordinates." << std::endl <<
            "For a two-dimensional function, the region suggested is (-3,-3) x (3,3)." << std::endl <<
            "For a 3D function, the region suggested is (-4,-4,-4) x (4,4,4)." << std::endl <<
            "For a four-dimensional function, the region suggested is (-1,-1,-1,-1) x (1,1,1,1)." << std::endl;
        std::cin >> ChoiceArea;
        if (ChoiceArea == 1) {
            std::cout << "Enter the coordinates of the parallelepiped, according to " << ChoiceFun << "things in each line, first the minimum, then the maximum" << std::endl;
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
        std::cout << "Select stopping method" << std::endl <<
            "Press 1 - gradient stop (gradient descent)." << std::endl <<
            "Press 2 - stop at two closest points (gradient descent)." << std::endl <<
            "Press 3 - stop based on the relative error of the two closest function values (gradient descent)." << std::endl <<
            "Press 4 - stop by number of iterations (gradient descent and random search)." << std::endl <<
            "Press 5 - stop at the two closest values of the function (random search)." << std::endl;
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
        std::cout << "Enter the eps at which the stop will be made." << std::endl;
        std::cin >> eps;
        std::cout << "Enter the maximum number of iterations." << std::endl;
        std::cin >> kmax;
        Stop->Setkmax(kmax);
        Stop->Seteps(eps);
        
        std::cout << "Select a minimum search method." << std::endl <<
            "Press 1 - gradient descent (derivatives numerically)." << std::endl <<
            "Press 2 - random search" << std::endl;
        std::cin >> ChoiceMethod;
        std::cout << "Enter starting point." << std::endl;
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
            std::cout << "Enter alpha." << std::endl;
            std::cin >> alpha;
            std::cout << "Enter p" << std::endl;
            std::cin >> p;
            delta.resize(ChoiceFun);
            double Delta;
            std::cout << "Enter delta" << std::endl;
            std::cin >> Delta;
            for (int i = 0; i < delta.size(); ++i) {
                delta[i] = Delta;
            }
            
            opt = new StochOpt(alpha, p ,delta);
        }
        opt->optimise(init_point,fun, Stop, area);
        vec find_point(Stop->GetPoint());
        std::cout << "Minimum point: ";
        for (auto i : find_point) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        std::cout << "Value at minimum: ";
        std::cout << fun->GetValF(find_point);
        std::cout << std::endl;
        std::cout << "Number of iterations: ";
        std::cout << Stop->GetK();
        answer = 0;
        
    }
    delete Stop;
    delete fun;
    delete opt;
    
    
    return 0;
}



