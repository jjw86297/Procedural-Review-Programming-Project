#include <iostream>
#include <fstream>
using namespace std;

int read();
int averages();
int letter();
void report();

string names[50];
int scores[50][35];
double averages_array[50];

int count1 = 0;
int count2 = 0;
int new_count1 = 0;
int average = 0;
int the_final_count = 0;

const int num_scores = read();

int main()
{
    int average_count = 0;

    while (average_count < count1)
    {
        averages_array[average_count] = averages();
        average_count++;
    }

    report();
    return 0;
}

int read()
{
    ifstream inputFile("C:\\Users\\jacob\\Downloads\\StudentGrade.txt");

    while (count1 < 50 && inputFile >> names[count1])
    {
        int count2 = 0;

        while (count2 < 35 && inputFile >> scores[count1][count2])
        {
            count2++;
        }
        count1++;
    }

    inputFile.close();

    return count1 * count2;
}

int averages()
{
    int new_count2 = 0;
    int holder = 0;
    int average = 0;

    while (new_count1 < count1)
    {
        while (new_count2 < count2)
        {
            holder = scores[new_count1][new_count2];
            average += holder;
            new_count2++;
        }
        average /= count2;
        new_count1++;
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

    while (the_final_count < count1)
    {
        letter_grade = letter();
        cout << "     " << names[the_final_count] << "     " << averages_array[the_final_count] << "     " << letter_grade << endl;
        the_final_count++;
    }

    exit(0);
}

