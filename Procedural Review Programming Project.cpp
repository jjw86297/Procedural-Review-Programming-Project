//This program simulates a grade book.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int num_tests = 5;

int read(string [], int [][num_tests], ifstream &);
void averages(int [][num_tests], double [], int);
char letter(double);
void report(string [], double [], int);

int main()
{
    string names[50];
    int scores[50][num_tests];
    double averages_array[50];

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

    int students = 0;
    students = read(names, scores, inputFile);

    inputFile.close();

    averages(scores, averages_array, students);
    report(names, averages_array, students);

    return 0;
}

int read(string names[], int scores[][num_tests], ifstream &file)
{
    string name = " ";
    int count = 0;

    while (getline(file, name) && count < 50)
    {
        names[count] = name;

        for (int count2 = 0; count2 < num_tests; count2++)
        {
            file >> scores[count][count2];
        }

        file.ignore();
        count++;
    }

    return count;
}

void averages(int scores[][num_tests], double averages_array[], int students)
{
    for (int count = 0; count < students; count++)
    {
        double total = 0;
        
        for (int count2 = 0; count2 < num_tests; count2++)
        {
            total += scores[count][count2];
        }

        averages_array[count] = total / num_tests;
    }
}

char letter(double average)
{
    char grade = 0;

    if (average < 60)
        grade = 'F';
    else if (average < 70)
        grade = 'D';
    else if (average < 80)
        grade = 'C';
    else if (average < 90)
        grade = 'B';
    else
        grade = 'A';

    return grade;
}

void report(string names[], double averages_array[], int students)
{
    cout << endl << "     " << "Name" << "     " << "Average Test Score" << "     " << "Letter Grade" << endl;

    char letter_grade = 0;

    for (int count = 0; count < students; count++)
    {
        letter_grade = letter(averages_array[count]);
        cout << setw(10) << names[count] << setw(15) << averages_array[count] << setw(19) << letter_grade << endl;
    }
}

