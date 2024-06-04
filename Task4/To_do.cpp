/**
*
* @Name : Todo
* @Version : 1.0
* @Date : 2024-05-29
* 
**/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <string>

// // ANSI escape code for green text
// const std::string GREEN_TEXT = "\033[1;32m";
// // ANSI escape code for red text
// const std::string RED_TEXT= "\033[1;31m";
// // ANSI escape code to reset text color to default
// const std::string RESET_COLOR = "\033[0m";

// Macro
// Define color escape codes
#define RED_TEXT "\033[1;31m"
#define GREEN_TEXT "\033[1;32m"
#define RESET_COLOR "\033[0m"

bool checkEmpty(std::vector<std::pair<std::vector<std::string>,int>>& data){
    if(data.empty()){
        std::cout << "Todo List is Empty! Add task" << std::endl;
        return true;
    }
    return false;
}

void addTask(std::vector<std::pair<std::vector<std::string>,int>>& data){
    std::cout << "Enter task: ";
    std::string task;
    std::cin.ignore();
    getline(std::cin,task);
    data.push_back({ {task}, 0  });
    std::cout << "Task added successfully!" << std::endl;
}

void viewTask(std::vector<std::pair<std::vector<std::string>,int>>& data){
    if(checkEmpty(data)) return;
    else{
        std::cout << "Tasks:" << std::endl;
        // for(auto it : data){
        //     std::cout << "{" << std::endl; std::cout << '\t';
        //     std::cout << "Task: ";
        //     for(auto str: it.first){
        //         std::cout << str << "";
        //     }
        //     // output By concatenation of string predefined
        //     // std::cout << " ,Status: "<< ((it.second == 0)? (RED_TEXT+"Pending"+RESET_COLOR):(GREEN_TEXT+"Completed"+RESET_COLOR))  << std::endl;

        //     // when you try to concatenate a string literal with a macro (which is essentially a preprocessor directive),
        //     //it doesn't work as expected because macros are expanded by the preprocessor before the compilation begins.
        //     std::cout <<  ","<< std::endl << '\t' << "Status: "
        //         << ((it.second == 0)? (RED_TEXT "Pending" RESET_COLOR):(GREEN_TEXT "Completed" RESET_COLOR))  << std::endl;
        //     std::cout << "}" << std::endl;
        // }

        for (size_t i = 0; i < data.size(); ++i) {
            std::cout << i+1 << ". ";
            for (const auto& str : data[i].first) {
                std::cout << str << " ";
            }
            std::cout << "   , [Status: "<<  ((data[i].second == 0)? (RED_TEXT "Pending" RESET_COLOR):(GREEN_TEXT "Completed" RESET_COLOR)) << ']';
            std::cout << std::endl;
        }
    }

}

void completeTask(std::vector<std::pair<std::vector<std::string>,int>>& data){
    if(checkEmpty(data)) return;
    std::cout << "Tasks:" << std::endl;
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << i+1 << ". ";
        for (const auto& str : data[i].first) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "Enter the task No to be Marked as Completed: ";
    int taskNo;
    while (!(std::cin >> taskNo) || (typeid(taskNo).name() != typeid(int).name())) {
        std::cin.clear(); // Clear the error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Disca1rd invalid input
        std::cout << "Only Integers Allowed! Try again: ";
    }
    if(taskNo <= 0 || taskNo > static_cast<int>(data.size())){
        std::cout << "Invalid! Task Number." << std::endl;
        return;
    }

    data[taskNo-1].second = 1;
    std::cout << "Task Marked as Completed" << std::endl;
}

void deleteTask(std::vector<std::pair<std::vector<std::string>,int>>& data){
    if(checkEmpty(data)) return;
    std::cout << "Tasks:" << std::endl;
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << i+1 << ". ";
        for (const auto& str : data[i].first) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "Enter the task number to delete: ";
    int taskNo;
    while (!(std::cin >> taskNo) || (typeid(taskNo).name() != typeid(int).name())) {
        std::cin.clear(); // Clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Disca1rd invalid input
        std::cout << "Only Integers Allowed! Try again: ";
    }
    
    if (taskNo <= 0 || taskNo > static_cast<int>(data.size())) {
        std::cout << "Invalid task number!" << std::endl;
        return;
    }
    
    // Remove the task from the data vector
    data.erase(data.begin() + taskNo - 1);
    std::cout << "Task deleted successfully!" << std::endl;
}

int main(){
    system("clear");
    std::cout << "Welcome, TO-DO" << std::endl;
    bool validChoice = false;
    char Choice;
    std::vector<std::pair<std::vector<std::string>,int>> data ;
    while(!validChoice){
        std::cout << "Actions:   Add Task[A],   View Task[V],   Complete Task[C],    Delete Task[D],     Quit[Q]:"<< std::endl;
        std::cout << "Your Choice: ";
        std::cin >> Choice;
        if(Choice != 'A' && Choice != 'V' && Choice != 'C' && Choice != 'D' && Choice != 'Q' &&Choice != 'a' && Choice != 'v' && Choice != 'c' && Choice != 'd' && Choice != 'q' ){
            std::cout << "Invalid! Input. Try Again" << std::endl;
        }
        else if(Choice == 'Q' || Choice == 'q'){
            std::cout << "Thanks! For using To-do" << std::endl;
            break;
        }
        else{
            Choice = toupper(Choice);
            switch (Choice){
                case 'A':
                    addTask(data);
                    break;
                case 'V':
                    viewTask(data);
                    break;
                case 'C':
                    completeTask(data);
                    break;
                case 'D':
                    deleteTask(data);
                    break;
                default:
                    std::cout << "Invalid Operation" << std::endl;
                    break;
            }
        }
    }




    return 0;
}