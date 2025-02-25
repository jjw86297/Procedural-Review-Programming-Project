//This program simulates Rock, Paper, Scissors.

//The program will take a user's input of "rock," "paper," or "scissors" and put them against a computer's randomly generated inputs.
//Entering "quit" shall stop the program early and display the latest total score within the whole tournament.
//Entering any other option shall cause an error, and another input will need to be entered.
//Entering any other option three times in a row will stop the program early and display the total score within the whole tournament.

//Rounds occur in groups of three "sub-rounds" or matches, and the winner of the round is given one point in the tournament score, which is the score that matters for the win.

#include <iostream>
#include <random>
#include <cstdlib>
using namespace std;

int choice(string &, int &, int &);
int computer();
int winner(int &, int &);
void round_winner();
void tour_winner(int &, int &);

int main()
{
    round_winner();
    return 0;
}

//This function will not be called before the winner function is called.
//This function takes in the total score variables in order to pass them to the tour_winner function.
//This function takes the user's input of "rock," "paper," or "scissors" converts it into a numerical form, and returns it for comparison with the computer's value in the winner function.
//Typing "quit" shall call upon the tour_winner function to terminate the program.
//Entering an incorrect option will restart the loop, and entering one three times will call upon the tour_winner function to terminate the program.
int choice(string &pick1, int &total_score2, int &total_cscore2)
{
    int decision = 0;
    int incorrect = 0;

    while (decision == 0 && incorrect != 3)
    {
        cout << "Rock, paper, scissors ..." << endl << "Please make a choice in all lowercase or type quit to end: ";
        cin >> pick1;

        if (pick1 == "rock")
        {
            decision = 1;
            return decision;
        }
        else if (pick1 == "paper")
        {
            decision = 2;
            return decision;
        }
        else if (pick1 == "scissors")
        {
            decision = 3;
            return decision;
        }
        else if (pick1 == "quit")
        {
            tour_winner(total_score2, total_cscore2);
            return 0;
        }
        else
        {
            cout << "You did not enter a correct option!" << endl << endl;
            incorrect++;
        }
    }

    cout << "You did not enter a correct option 3 times!" << endl;
    tour_winner(total_score2, total_cscore2);
    return 0;
}

//A number from one to three is generated and returned to the winner function.
//The number represents one of the three choices in the game.
//This function will not be called before the winner function is called.
int computer()
{
    random_device myEngine;
    uniform_int_distribution<int> randomInt(1, 3);
    return randomInt(myEngine);
}

//This function calls upon the choice function and computer function and then compares the user's choice in number form to the computer's to determine who won the match or "sub-round."
//This function takes in the total score variables simply so they can be passed to the choice function.
//This function shall not be called before the round winner function is called and the total score variables are defined.
//This function ends by returning a int value to the round winner function to determine the winner of the round.
int winner(int &total_score1, int &total_cscore1)
{
    int count = 0;
    int score = 0;
    int cscore = 0;

    string pick = "";

    while (count < 3)
    {
        int selection = choice(pick, total_score1, total_cscore1);
        int random = computer();

        string cpick = "";
    
        if (random == 1)
            cpick = "rock";
        else if (random == 2)
            cpick = "paper";
        else
            cpick = "scissors";

        if ((selection == 1 && random == 3) || (selection > random && !(selection == 3 && random == 1)))
        {
            cout << "SHOOT!" << endl << endl << "User chose " << pick << "." << endl << "Computer chose " << cpick << "." << endl << "User wins!" << endl << endl;
            count++;
            score++;
            cout << "Round Score: " << score << "-" << cscore << endl << endl;
        }
        else if ((selection == 3 && random == 1) || (selection < random && !(selection == 1 && random == 3)))
        {
            cout << "SHOOT!" << endl << endl << "User chose " << pick << "." << endl << "Computer chose " << cpick << "." << endl << "Computer wins!" << endl << endl;
            count++;
            cscore++;
            cout << "Round Score: " << score << "-" << cscore << endl << endl;
        }
        else
        {
            cout << "SHOOT!" << endl << endl << "User chose " << pick << "." << endl << "Computer chose " << cpick << "." << endl << "It's a draw!" << endl << endl;
            count++;
            cout << "Round Score: " << score << "-" << cscore << endl << endl;
        }
    }
    if (score > cscore)
        return 1;
    else if (score < cscore)
        return 2;
    else
        return 0;
}

//This function is the first one called by main.
//It allows for the game to go on until one of the players reaches a score of 5, in which the program then ends and the tournament winner is decided.
//This function calls on the winner function to determine the victor of the round.
void round_winner()
{
    int victor;

    int total_score = 0;
    int total_cscore = 0;

    while (total_score < 5 && total_cscore < 5)
    {
        victor = winner(total_score, total_cscore);
        if (victor == 1)
        {
            cout << "User won the round!" << endl << endl;
            total_score++;
            cout << "Tournament Score: " << total_score << "-" << total_cscore << endl << endl;
        }
        else if (victor == 2)
        {
            cout << "Computer won the round!" << endl << endl;
            total_cscore++;
            cout << "Tournament Score: " << total_score << "-" << total_cscore << endl << endl;
        }
        else
        {
            cout << "The round is a draw!" << endl << endl;
            cout << "Tournament Score: " << total_score << "-" << total_cscore << endl << endl;
        }
    }

    tour_winner(total_score, total_cscore);
}

//This function is only called if the user decides to quit, a player reaches five points, or the user enters too many incorrect options.
//This function cannot be called before the choice function.
//It takes in the total round scores to compare them and determine the tournmanent winner.
//The function ends by terminating the program.
void tour_winner(int &total_score3, int &total_cscore3)
{
    if (total_score3 > total_cscore3)
    {
        cout << "User is the tournament winner!" << endl << endl;
        cout << "Tournament Score: " << total_score3 << "-" << total_cscore3 << endl;
    }
    else if (total_score3 < total_cscore3)
    {
        cout << "Computer is the tournament winner!" << endl << endl;
        cout << "Tournament Score: " << total_score3 << "-" << total_cscore3 << endl;
    }
    else
    {
        cout << "The tournament has ended in a draw ..." << endl << endl;
        cout << "Tournament Score: " << total_score3 << "-" << total_cscore3 << endl;
    }
    exit(0);
}

