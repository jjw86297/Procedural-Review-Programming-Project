//This program simulates Rock, Paper, Scissors.
#include <iostream>
#include <random>
using namespace std;

string pick = 0;
int total_score = 0;
int total_cscore = 0;

int main()
{
    int choice();
    int computer();
    int winner();
    int round_winner();
    int tour_winner();

    round_winner();
}

int choice()
{
    int decision = 0;

    cout << "Rock, paper, scissors ..." << endl << "Please make a choice in all lowercase or type quit to end: ";
    cin >> pick;

    while (decision == 0)
    {
        if (pick == "rock")
        {
            decision = 1;
            return decision;
        }
        else if (pick == "paper")
        {
            decision = 2;
            return decision;
        }
        else if (pick == "scissors")
        {
            decision = 3;
            return decision;
        }
        else if (pick == "quit")
            tour_winner();
        else
        {
            cout << "You did not enter a correct option!" << endl;
            cout << "Rock, paper, scissors ..." << endl << "Please make a choice in all lowercase or type quit to end: ";
            cin >> pick;
        }
    }
}

int computer()
{
    random_device myEngine;
    uniform_int_distribution<int> randomInt(1, 3);
    return randomInt(myEngine);
}

int winner()
{
    int count = 0;
    int score = 0;
    int cscore = 0;

    while (count < 3)
    {
        choice();
        int selection = choice();
        computer();
        int random = computer();

        string cpick = 0;
    
        if (random == 1)
            cpick = "rock";
        else if (random == 2)
            cpick = "paper";
        else
            cpick = "scissors";

        if (selection == 1 && random == 3)
        {
            cout << "SHOOT!" << endl << "User chose " << pick << "." << endl << "Computer chose " << cpick << "." << endl << "User wins!" << endl;
            count++;
            score++;
        }
        else if (selection == 3 && random == 1)
        {
            cout << "SHOOT!" << endl << "User chose " << pick << "." << endl << "Computer chose " << cpick << "." << endl << "Computer wins!" << endl;
            count++;
            cscore++;
        }
        else if (selection > random)
        {
            cout << "SHOOT!" << endl << "User chose " << pick << "." << endl << "Computer chose " << cpick << "." << endl << "User wins!" << endl;
            count++;
            score++;
        }
        else if (selection < random)
        {
            cout << "SHOOT!" << endl << "User chose " << pick << "." << endl << "Computer chose " << cpick << "." << endl << "Computer wins!" << endl;
            count++;
            cscore++;
        }
        else
        {
            cout << "SHOOT!" << endl << "User chose " << pick << "." << endl << "Computer chose " << cpick << "." << endl << "It's a draw!" << endl;
            count++;
        }
    }
    if (score > cscore)
        return 1;
    else if (score < cscore)
        return 2;
    else
        return 0;
}

int round_winner()
{
    while (true)
    {
        winner();
        if (winner() == 1)
        {
            cout << "User won the round!" << endl;
            total_score++;
        }
        else if (winner() == 2)
        {
            cout << "Computer won the round!" << endl;
            total_cscore++;
        }
        else
            cout << "The round is a draw!" << endl;
    }
}

int tour_winner()
{
    if (total_score > total_cscore)
        cout << "User is the tournament winner!" << endl;
    else if (total_score < total_cscore)
        cout << "Computer is the tournament winner!" << endl;
    else
        cout << "The tournament has ended in a draw ..." << endl;
    exit(0);
}

