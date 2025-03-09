//This program simulates a grade book.

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int read(int &, int &);
double averages(int &, int &, int &);
int letter(int &);
void report(int &, int &);

string names[6];
int scores[6][5];
double averages_array[6];

int main()
{
    int count1 = 0;
    int count2 = 0;
    int new_count1 = 0;
    int the_final_count = 0;
    int average_count = 0;
    
    const int num_scores = read(count1, count2);

    while (average_count < count1)
    {
        averages_array[average_count] = averages(count1, count2, new_count1);
        average_count++;
    }

    report(the_final_count, count1);
    return 0;
}

int read(int &firstcount1, int &firstcount2)
{
    ifstream inputFile("StudentGrades.txt");

    if (inputFile)
    {
        cout << "Opening file..." << endl;
    }
    else
    {
        cout << "Error opening the file." << endl;

        exit(0);
    }

    while (inputFile >> names[firstcount1] && firstcount1 < 6)
    {
        firstcount2 = 0;

        while (inputFile >> scores[firstcount1][firstcount2] && firstcount2 < 5)
        {
            firstcount2++;
        }

        firstcount1++;
    }

    inputFile.close();

    return firstcount1 * firstcount2;
}

double averages(int &secondcount1, int &secondcount2, int &firstnew_count1)
{
    int new_count2 = 0;
    int holder = 0;
    double average = 0;

    while (firstnew_count1 < secondcount1)
    {
        while (new_count2 < secondcount2)
        {
            holder = scores[firstnew_count1][new_count2];
            average += holder;
            new_count2++;
        }

        average /= secondcount2;
        firstnew_count1++;
        return average;
    }
}

int letter(int &firstthe_final_count)
{
    char grade = 0;

    if (averages_array[firstthe_final_count] < 60)
        grade = 'F';
    else if (averages_array[firstthe_final_count] < 70)
        grade = 'D';
    else if (averages_array[firstthe_final_count] < 80)
        grade = 'C';
    else if (averages_array[firstthe_final_count] < 90)
        grade = 'B';
    else
        grade = 'A';

    return grade;
}

void report(int &secondthe_final_count, int &thirdcount1)
{
    cout << endl << "     " << "Name" << "     " << "Average Test Score" << "     " << "Letter Grade" << endl;

    char letter_grade = 0;

    while (secondthe_final_count < thirdcount1)
    {
        letter_grade = letter(secondthe_final_count);
        cout << setw(10) << names[secondthe_final_count] << setw(15) << averages_array[secondthe_final_count] << setw(19) << letter_grade << endl;
        secondthe_final_count++;
    }

    exit(0);
}

