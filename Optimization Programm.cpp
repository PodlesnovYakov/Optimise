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
    AbstrFunc* fun = nullptr;
    AbstrOptimiser* opt = nullptr;
    AbstrStop* Stop = nullptr;
    bool RightChoice = true;
    int answer = 1;
    while (answer) {


        while (RightChoice) {
            std::cout << "Select function." << std::endl <<
                "Press 1 - for the 2D function e^(x/2)(x+y^2)." << std::endl <<
                "Press 2 - for the 3D function x^2+y^2+z^2+2x+4y-6z." << std::endl <<
                "Press 3 - for the 4D function sin^2(x) + y^2 + sin(z-1/2)+t^2." << std::endl;
            std::cin >> ChoiceFun;
            if (ChoiceFun == 1 || ChoiceFun == 2 || ChoiceFun == 3) RightChoice = false;
            else std::cout << "You press the wrong number." << std::endl;
        }
        RightChoice = true;
        if (ChoiceFun == 1) {
            fun = new F2();
        }
        else if (ChoiceFun == 2) {
            fun = new F3();
        }
        else if (ChoiceFun == 3) {
            fun = new F4();

        }


        while (RightChoice) {
            std::cout << "Do you want to enter the coordinates of the parallelepiped (hard) or enter predefined ones (easy)." << std::endl <<
                "Press 1 - to enter coordinates." << std::endl <<
                "Press 2 - for preset coordinates." << std::endl <<
                "For a two-dimensional function, the region suggested is (-3,-3) x (3,3)." << std::endl <<
                "For a 3D function, the region suggested is (-4,-4,-4) x (4,4,4)." << std::endl <<
                "For a four-dimensional function, the region suggested is (-1,-1,-1,-1) x (1,1,1,1)." << std::endl;
            std::cin >> ChoiceArea;
            if (ChoiceArea == 1 || ChoiceArea == 2) RightChoice = false;
            else std::cout << "You have selected a non-existent mode." << std::endl;
        }
        RightChoice = true;
        lower_point.resize(fun->getDimension());
        upper_point.resize(fun->getDimension());
        area.SetSize(fun->getDimension());
        if (ChoiceArea == 1) {
            while (RightChoice) {
                std::cout << "Enter the coordinates of the parallelepiped, according to " << fun->getDimension() << " things in each line, first the minimum, then the maximum." << std::endl;
                for (int i = 0; i < fun->getDimension(); ++i) {
                    std::cin >> lower_point[i];
                }
                for (int i = 0; i < fun->getDimension(); ++i) {
                    std::cin >> upper_point[i];
                }

                area.SetLower(lower_point);
                area.SetUpper(upper_point);

                RightChoice = false;
                for (int i = 0; i < lower_point.size(); ++i) {
                    if (lower_point[i] > upper_point[i]) {
                        std::cout << "You enter wrong data. Lower point greater than upper point." << std::endl;
                        RightChoice = true;
                        break;
                    }
                }
            }
        }
        else {
            switch (fun->getDimension())
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

        RightChoice = true;
        while (RightChoice) {
            std::cout << "Select stopping method" << std::endl <<
                "Press 1 - gradient stop (gradient descent)." << std::endl <<
                "Press 2 - stop at two closest points (gradient descent)." << std::endl <<
                "Press 3 - stop based on the relative error of the two closest function values (gradient descent)." << std::endl <<
                "Press 4 - stop by number of iterations (gradient descent and random search)." << std::endl <<
                "Press 5 - stop at the two closest values of the function (random search)." << std::endl;
            std::cin >> ChoiceStop;
            if (ChoiceStop == 1 || ChoiceStop == 2 || ChoiceStop == 3 || ChoiceStop == 4 || ChoiceStop == 5) RightChoice = false;
            else std::cout << "You press the wrong number." << std::endl;
        }
        switch (ChoiceStop)
        {
        case 1:
        {
            Stop = new GradStop();
            break;
        }
        case 2: {
            Stop = new PointStop();
            break;
        }
        case 3:
        {
            Stop = new RelErStop();
            break;
        }
        case 4:
        {
            Stop = new StopIter();
            break;
        }

        case 5: {
            
            Stop = new ValFstop();
            break;
        }
        }


        RightChoice = true;
        while (RightChoice) {
            std::cout << "Enter the eps at which the stop will be made." << std::endl;
            std::cin >> eps;
            std::cout << "Enter the maximum number of iterations." << std::endl;
            std::cin >> kmax;
            Stop->Setkmax(kmax);
            Stop->Seteps(eps);
            if (kmax > 0 && eps > 0) RightChoice = false;
            if (kmax < 0) std::cout << "kmax must be > 0" << std::endl;
            if (eps < 0) std::cout << "eps must be > 0" << std::endl;
        }
        

        RightChoice = true;
        while (RightChoice) {
            std::cout << "Select a minimum search method." << std::endl <<
                "Press 1 - gradient descent (derivatives numerically)." << std::endl <<
                "Press 2 - random search" << std::endl;
            std::cin >> ChoiceMethod;
            if ((ChoiceMethod == 1 && (ChoiceStop == 1 || ChoiceStop == 2 || ChoiceStop == 3 || ChoiceStop == 4)) || (ChoiceMethod == 2 && (ChoiceStop == 4 || ChoiceStop == 5))) RightChoice = false;
            else std::wcout << "You have chosen a method that is not suitable for the stopping method you chose earlier." << std::endl;
        }

        RightChoice = true;
        while (RightChoice) {
            std::cout << "Enter starting point." << std::endl;
            init_point.resize(fun->getDimension());
            RightChoice = false;
            for (int i = 0; i < init_point.size(); ++i) {
                std::cin >> init_point[i];
                if (init_point[i] > area.GetUpper()[i] || init_point[i] < area.GetLower()[i]) {
                    std::cout << "Initial point must be in parallelepiped" << std::endl;
                    RightChoice = true;
                    break;
                }
            }
            
        }

        if (ChoiceMethod == 1) {
            opt = new DetOpt();
        }
        else {
            RightChoice = true;
            while (RightChoice) {
                std::cout << "Enter alpha." << std::endl;
                std::cin >> alpha;
                std::cout << "Enter p" << std::endl;
                std::cin >> p;
                delta.resize(fun->getDimension());
                double Delta;
                std::cout << "Enter delta" << std::endl;
                std::cin >> Delta;
                for (int i = 0; i < delta.size(); ++i) {
                    delta[i] = Delta;
                }
                if ((Delta > 0) && (p >  0 && p < 1) && (alpha > 0 && alpha < 1)) RightChoice = false;
                if (Delta < 0) std::cout << "Delta must be > 0" << std::endl;
                if (p < 0 || p > 1) std::cout <<"p must be 0 < p < 1" << std::endl;
                if (alpha < 0 || alpha > 1) std::cout << "alpha must be 0 < alpha < 1" << std::endl;
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



