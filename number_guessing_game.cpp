/**
*
* @Name : nuber_guessing_game
* @Version : 1.0
* @Date : 2024-05-26
* 
**/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

void play(){
	std::srand(std::time(nullptr));
	int secret = std::rand() % 100 + 1 ;
	int Guess = 0;
	do{
		std::cout << "Guess Number b/w (1,100) : ";
		bool validGuess = false;
		while(!validGuess){
			std::cin >> Guess;
			if(std::cin.fail()){
				std::cout << "Invalid input Expected an integer! " << "Re-Enter:  ";
            	std::cin.clear();
            	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			} else {
            	validGuess = true;
			}
		}
		if(secret < Guess) std:: cout << "Secret Number is lower" << std::endl;
		else if(secret > Guess) std:: cout << "Secret Number is higer"<< std::endl;
	}while(secret != Guess);

	std::system("clear");
	std::cout << "Congratulations! You guessed it Right"  << std::endl;
}

void handleChoice(int choice){
	switch (choice){
		case 0:
			std::cout << "GoodBye!" << std::endl;
			return;
			break;
		
		case 1:
			play();
			break;
		
		default:
			std::cout << "Invaild Choice! Try Again" << std::endl;
	}
}

int main(){
	std::system("clear");
	int choice = 1; bool validInput = false;
	while(choice != 0) {
		std:: cout << "Play [1]:		Quit[0]:" << std::endl;
		while(!validInput){
			std::cout << "Enter Choice: ";	std::cin >> choice;
			if(std::cin.fail()){
				std::cout << "Invalid input Expected an integer." << std::endl;
            	std::cin.clear();
            	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			} else {
            	validInput = true;
			}
		}
		handleChoice(choice); validInput = false;
	}
	return 0;
}
