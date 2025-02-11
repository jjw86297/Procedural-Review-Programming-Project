//This program simulates Rock, Paper, Scissors.

#include <iostream>
#include <random>
#include <cstdlib>
using namespace std;

string pick = "";
int total_score = 0;
int total_cscore = 0;

int choice();
int computer();
int winner();
void round_winner();
void tour_winner();

int main()
{
    round_winner();
    return 0;
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
        {
            tour_winner();
            return 0;
        }
        else
        {
            cout << "You did not enter a correct option!" << endl << endl;
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
        int selection = choice();
        int random = computer();

        string cpick = "";
    
        if (random == 1)
            cpick = "rock";
        else if (random == 2)
            cpick = "paper";
        else
            cpick = "scissors";

        if (selection == 1 && random == 3)
        {
            cout << "SHOOT!" << endl << endl << "User chose " << pick << "." << endl << "Computer chose " << cpick << "." << endl << "User wins!" << endl << endl;
            count++;
            score++;
            cout << score << "-" << cscore << endl << endl;
        }
        else if (selection == 3 && random == 1)
        {
            cout << "SHOOT!" << endl << endl << "User chose " << pick << "." << endl << "Computer chose " << cpick << "." << endl << "Computer wins!" << endl << endl;
            count++;
            cscore++;
            cout << score << "-" << cscore << endl << endl;
        }
        else if (selection > random)
        {
            cout << "SHOOT!" << endl << endl << "User chose " << pick << "." << endl << "Computer chose " << cpick << "." << endl << "User wins!" << endl << endl;
            count++;
            score++;
            cout << score << "-" << cscore << endl << endl;
        }
        else if (selection < random)
        {
            cout << "SHOOT!" << endl << endl << "User chose " << pick << "." << endl << "Computer chose " << cpick << "." << endl << "Computer wins!" << endl << endl;
            count++;
            cscore++;
            cout << score << "-" << cscore << endl << endl;
        }
        else
        {
            cout << "SHOOT!" << endl << endl << "User chose " << pick << "." << endl << "Computer chose " << cpick << "." << endl << "It's a draw!" << endl << endl;
            count++;
            cout << score << "-" << cscore << endl << endl;
        }
    }
    if (score > cscore)
        return 1;
    else if (score < cscore)
        return 2;
    else
        return 0;
}

void round_winner()
{
    int victor;

    while (true)
    {
        victor = winner();
        if (victor == 1)
        {
            cout << "User won the round!" << endl << endl;
            total_score++;
            cout << total_score << "-" << total_cscore << endl << endl;
        }
        else if (victor == 2)
        {
            cout << "Computer won the round!" << endl << endl;
            total_cscore++;
            cout << total_score << "-" << total_cscore << endl << endl;
        }
        else
        {
            cout << "The round is a draw!" << endl << endl;
            cout << total_score << "-" << total_cscore << endl << endl;
        }
    }
}

void tour_winner()
{
    if (total_score > total_cscore)
    {
        cout << "User is the tournament winner!" << endl << endl;
        cout << total_score << "-" << total_cscore << endl;
    }
    else if (total_score < total_cscore)
    {
        cout << "Computer is the tournament winner!" << endl << endl;
        cout << total_score << "-" << total_cscore << endl;
    }
    else
    {
        cout << "The tournament has ended in a draw ..." << endl << endl;
        cout << total_score << "-" << total_cscore << endl;
    }
    exit(0);
}

