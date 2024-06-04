/**
*
* @Name : simpleCalculator
* @Version : 1.0
* @Date : 2024-05-27
* 
**/

#include <iostream>
#include <cstdlib>

int main() {
    system("clear");
    std::cout << "Simple Calculator" << std::endl;
    int x, y, result;
    char operation = 1;
    
    while (operation != 0) {
        std::cout << "Choose Operation: Addition[+], Subtraction[-], Multiplication[*], Division[/], Quit[q]" << std::endl;
        bool validinput = false;
        while(!validinput){
            std::cout << "Enter Operation: ";
            std::cin >> operation;
            if(operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != 'q' && operation != 'Q' ){
                std::cout << "Invlaid Input!" << std::endl;
            }else{
                validinput = true;
            }
        }
        
        if (operation == 'q' || operation == 'Q'){
            operation = 0;
            std::cout << "GoodBye" << std::endl;
            return 0;
        }

        std::cout << "Enter Number 1: "; 
        std::cin >> x; 
        std::cout << "Enter Number 2: "; 
        std::cin >> y; 
        
        switch (operation) {
            case '+':
                result = x + y;
                break;
            case '-':
                result = x - y;
                break;
            case '*':
                result = x * y;
                break;
            case '/':
                if (y != 0){
                    result = x / y;
                }else{
                    std::cout << "Error: Division by zero!" << std::endl;
                    result = 0;
                }
                break;
            default:
                std::cout << "Invalid operation!" << std::endl;
                continue;
        }
        
        std::cout << "Result: " << result << std::endl;
    }

    return 0;
}
