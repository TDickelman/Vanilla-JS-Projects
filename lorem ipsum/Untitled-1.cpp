// Header files section
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


// function prototype
int getWinnderIndex(int votes[], int size);

// start main function
int main()
{
// constant declaration
// maximum size of the array
const int MAX = 5;

// parallel arrays for names of candidates,
// number of votes received, and percentage of votes
string names[MAX];
int votes[MAX];
double percentages[MAX];

// other variables
double total = 0;
int winnerIndex;
string str;

/* allow the user to enter the last names of five candidates in a local election and the number of votes received by each candidate */
for (int i = 0; i < MAX; i++)
{
cout << "\nEnter the name of the candidate " << (i + 1) << ": ";
getline(cin, names[i]);

cout << "Enter the number of votes received by " << names[i] << ": ";
getline(cin, str);
votes[i] = stoi(str);
}

// compute the total number of votes
for (int i = 0; i < MAX; i++)
{
total = total + votes[i];
}

// compute the percentage of votes for each condidate
for (int i = 0; i < MAX; i++)
{
percentages[i] = votes[i] / total * 100.0;
}

// get the winner index in the array by calling the getWinnderIndex function
winnerIndex = getWinnderIndex(votes, MAX);

/* display each candidate's name, the number of votes received, and the percentage of the total votes received by the candidate */
cout << endl << left << setw(25) << "NAME_OF_CANDIDATE" << right << setw(15) << "VOTES_COUNT" << setw(15) << "PERCENTAGE" << endl;
for (int i = 0; i < MAX; i++)
{
cout << left << setw(25) << names[i] << right << setw(15) << votes[i] << setw(14) << setprecision(2) << fixed << percentages[i] << "%" << endl;
}

// display the winner of the election
cout << "The Winner of the Election is " << names[winnerIndex] << " (" << votes[winnerIndex] << ")" << endl << endl;

system("pause");
} // end of main function

// getWinnderIndex function implementation
int getWinnderIndex(int votes[], int size)
{
int i, max, loc = 0;
max = votes[0];

for (i = 1; i < size; i++)
{
if (votes[i] >max)
{
max = votes[i];
loc = i;
}
}

return loc;
}
