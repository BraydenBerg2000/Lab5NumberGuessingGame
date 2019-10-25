/*
Brayden Berg and Mason Henry and Lane
C++ Fall 2019
Number Guessing Game 2.0
Write a number-guessing game in which the computer selects a random
number in the range of 0 to 100, and users get a maximum of 20 attempts to guess it. At
the end of each game, users should be told whether they won or lost, and then be asked
whether they want to play again. When the user quits, the program should output the
total number of wins and losses. To make the game more interesting, the program
should vary the wording of the messages that it outputs for winning, for losing, and for
asking for another game. Create 10 different messages for each of these cases, and use
random numbers to choose among them. This application should use at least one Do-
While loop and at least one Switch statement. Write your C++ code using good style and
documenting comments. You should use functions in your code as well. Your source
code file should be called Lab5.cpp.
*/

//these are the libraries used throughout the program
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<cassert>

using namespace std;

//these are the function prototypes 
void randWin();
void randLose();
void randAgain();
void subfunc(bool& correct, int&w, int&l,int&userInput,int&j, bool&playAgainInput);

//this is the main function
int main()
{
	//this bool statement sets correct as false
	bool correct = false;
	//this bool statement sets playAgainInput as true
	bool playAgainInput = true;
	//this sets the identifier againchar as a character value
	char againchar;
		
		//sets the identifier userInput as an integer value
		int userInput;
		//sets the identifier j as an integer that starts off equal to zero, representing the total number of games played
		int j = 0;
		//sets the identifier w as an integer that starts off equal to zero, representing the total wins
		int w = 0;
		//sets the identifier l as an integer that starts off equal to zero, representing the total loses
		int l = 0;
		//precondition: correct must equal fale; playAgainInput must equal true; j,w, and l must all equal zero
		//postcondition: correctly executes all lines of code how they are ment to be exicuted for an outcome that follows the directions
		do
		{
			//the function call for the for loop
			subfunc(correct, w, l, userInput, j, playAgainInput);
			//the function call for the play again switch statement with a random number generator
			randAgain();
			//prompt for the user to continue or exit game
			cout << "Click 'y' to play again or 'n' to exit the program.\n" << endl;
			//user inputted response to the prompt
			cin >> againchar;
			//if statement that limits answer choices for prompt
			if (againchar == 'y' || againchar == 'Y' || againchar == 'n' || againchar == 'N')
			{
				//if statement that exits the program if 'n'or'N'is entered by the user, also outputs total number of wins and loses
				if (againchar == 'n' || againchar == 'N')
				{
					cout << "Total Wins: " << w << endl;
					cout << "Total Loses: " << l << endl;
					return 0;
				}
				//else if statement that allows the do while loop to execute another iteration if the user inputs a 'y'or'Y'.
				else if (againchar == 'y' || againchar == 'Y')
				{
					playAgainInput = true;
				}
			}
			//else statement that exicutes if the user inputs an invalid response then outputs that it was invalid and exits the game
			else
			{
				cout << "Not a valid input letter, exiting program." << endl;
				return 1;
			}	
			//end of do while loop
		} while (playAgainInput == true);
		return 0;
}

//function defonition that generates a random number then picks out of the ten win statements
void randWin()
{
	int randNum = rand() % 10 + 1;
	switch (randNum)
	{
	case 1: cout << "Yer a winner!" << endl;
		break;
	case 2: cout << "Congrats! You won!" << endl;
		break;
	case 3: cout << "You won!" << endl;
		break;
	case 4: cout << "Great job on winning." << endl;
		break;
	case 5: cout << "You now get braging rights for winning this game." << endl;
		break;
	case 6: cout << "You won something for once in your life." << endl;
		break;
	case 7: cout << "Congradulations on winning, but honestly what did you gain from this?" << endl;
		break;
	case 8: cout << "Way to win!" << endl;
		break;
	case 9: cout << "You done won!" << endl;
		break;
	case 10: cout << "Neeto Burrito you won!" << endl;
		break;
	default: cout << "Error!" << endl;
	}
}

//function defonition that generates a random number then picks out of the ten lose statements
void randLose()
{
	int randNum2 = rand() % 10 + 1;
	switch (randNum2)
	{
	case 1: cout << "You lose!" << endl;;
		break;
	case 2: cout << "Losing was inevitable." << endl;
		break;
	case 3: cout << "Really, you couldn't guess a single number." << endl;
		break;
	case 4:cout << "You were so close to winning! But you didn't." << endl;
		break;
	case 5: cout << "You get nothing! You lose! Good day sir!" << endl;
		break;
	case 6: cout << "Good guesses, but not the right ones." << endl;
		break;
	case 7: cout << "You had 20 tries but couldn't guess the right number." << endl;
		break;
	case 8: cout << "You didn't quite win. In fact it is quite the opposite." << endl;
		break;
	case 9: cout << "None of the numbers you inputted matched the random number." << endl;
		break;
	case 10: cout << "You done goofed up and lost!" << endl;
		break;
	default: cout << "Error!" << endl;
	}
}

//function defonition that generates a random number then picks out of the ten play again statements
void randAgain()
{
	int randNum3 = rand() % 10 + 1;
	switch (randNum3)
	{
	case 1: cout << "Would you like another go?" << endl;
		break;
	case 2: cout << "Wanna go again?" << endl;
		break;
	case 3: cout << "Why don't you click 'y' so that you can play again." << endl;
		break;
	case 4: cout << "Want to play again?" << endl;
		break;
	case 5: cout << "How about another game?" << endl;
		break;
	case 6: cout << "Would you like to partake in another game of number guessing?" << endl;
		break;
	case 7: cout << "Möchten Sie noch einmal spielen?(Would you like to play again?*German*)" << endl;
		break;
	case 8: cout << "Why waste your time grading papers when you can play again." << endl;
		break;
	case 9: cout << "Why not take another shot?" << endl;
		break;
	case 10: cout << "You've got nothing better to do, play another round." << endl;
		break;
	default: cout << "Error!" << endl;
	}
}

//function definition that executes the for loop where the respective function call is located
void subfunc(bool & correct, int&w, int&l, int&userInput, int&j, bool & playAgainInput)
{
		//this generates a random number between 0 and 100 for the program to use as the answer to the user's guesses
		int ranNum = rand() % 100 + 0;
		//this is the introduction statement
		cout << "Please enjoy the Number Guessing Game, you have 20 guesses to guess a number between 0 and 100.\n" << "Please input a number between 0 and 100. " << endl;
		//this resets correct to be equal to false if it was changed to true last game
		correct = false;
		//this establishes the identifier k as an integer that starts off equal to 20, representing the number of guesses the user has left
		int k = 20;
		//adds one to the value of j each time an iteration of the do loop is initiated, to signify that one game is played
		j++;
		//this for loop makes it so that the user has 20 chances to guess the random number
		for (int i = 1; i <= 20 && correct == false; i++)
		{
			//this is where the user inputs their guess
			cin >> userInput;
			//if the guess is not an integer this statement initiates and tells them that their input is invalid
			if (!cin)
			{
				cout << "Not a valid input, exiting the program." << endl;
			}
			//this assertion statement exits the game if the input is a character
			assert(cin);
			//outputs the user's number that they guessed
			cout << "Your Number: " << userInput << endl;
			//takes one value off of the k integer signifying that a guess has been made
			k--;
			//this if statement initiates if the guess inputted by the user is between 0 and 100(including 0 and 100)
			if (userInput >= 0 && userInput <= 100)
			{
				//if statement that initiates if the user's guess equals the random answer generated, it then outputs the win protocal
				if (ranNum == userInput)
				{
					//adds one to the integer w signifing one win
					w++;
					//function call for the function that randomly picks a win statement
					randWin();
					//ends the for loop function by setting correct to true
					correct = true;
				}
				//else statement that initiates if the user inputs the incorrect answer, tells user that they were wrong and displays number of guesses remaining
				else
				{
					cout << "That answer is wrong!" << endl;
					cout << "You have " << k << " guesses remaining." << endl;
				}
			}
			//else statement that initiates if the user inputs a number that is outside the parameters for the random number, takes a guess away as a penalty
			else
			{
				cout << "That is not a valid input number! That's gonna count against you!" << "Only " << k << " guesses left." << endl;
			}
		}
		//if statement that initiates if all of the user's guesses were incorrect, it then outputs the lose protocal
		if (ranNum != userInput)
		{
			//adds one to the integer l signifying one lose
			l++;
			//outputs a line space
			cout << "\n";
			//function call for the function that randomly picks a lose statement
			randLose();
		}
		//displays random number and then outputs a line space
		cout << "Random Number: " << ranNum << "\n" << endl;
		//displays number of games the user has played so far and then outputs a line space
		cout << "You have played " << j << " games.\n" << endl;
}
