#include <iostream>
#include <fstream>
using namespace std;

int read();
double averages();
int letter();
void report();

string names[50];
int scores[50][35];
double averages_array[50];

int count = 0;
int count2 = 0;
int new_count = 0;
double average = 0;
int the_final_count = 0;

const int num_scores = read();

int main()
{
    int average_count = 0;

    while (average_count < count)
    {
        averages_array[average_count] = averages();
        average_count++;
    }

    report();
    return 0;
}

int read()
{
    ifstream inputFile("C:\\Users\\jacob\\Downloads\\StudentGrades.txt");

    while (count < 50 && inputFile >> names[count])
    {
        count2 = 0;

        while (count2 < 35 && inputFile >> scores[count][count2])
        {
            count2++;
        }

        count++;
    }

    inputFile.close();

    return count * count2;
}

double averages()
{
    int new_count2 = 0;
    int holder = 0;
    double average = 0;

    while (new_count < count)
    {
        while (new_count2 < count2)
        {
            holder = scores[new_count][new_count2];
            average += holder;
            new_count2++;
        }

        average /= count2;
        new_count++;
        return average;
    }
}

int letter()
{
    char grade = 0;

    if (averages_array[the_final_count] < 60)
        grade = 'F';
    else if (averages_array[the_final_count] < 70)
        grade = 'D';
    else if (averages_array[the_final_count] < 80)
        grade = 'C';
    else if (averages_array[the_final_count] < 90)
        grade = 'B';
    else
        grade = 'A';

    return grade;
}

void report()
{
    cout << "     " << "Name" << "     " << "Average Test Score" << "     " << "Letter Grade" << endl;

    char letter_grade = 0;

    while (the_final_count < count)
    {
        letter_grade = letter();
        cout << "    " << names[the_final_count] << "          " << averages_array[the_final_count] << "                 " << letter_grade << endl;
        the_final_count++;
    }

    exit(0);
}

