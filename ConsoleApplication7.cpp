#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;
//const variables to use in arrays 
const int row = 10;
const int column = 5;
//declaring arrays
int scores[row][column];
string names[row];
double averageScore[row];
//filename for reading file
string inFileName = "BowlingScores.txt";
//counter variables for the loops
int i = 0;
int x = 0;
//variable to calculate average score
int total = 0;


//Function called GetBowlingData reading and storing array names, and scores from file "BowlingScores.txt"
bool GetBowlingData(string inFileName, string names[row], int scores[row][column]) {
    //opening stream to read data
    ifstream fInStream;
    fInStream.open(inFileName);
    //Error message incase file can't be opened that returns false
    if (!fInStream) {
        cout << "Error in opening the file: " << endl;
        return false;
    }

    //one dimensional array that stores bowlers names
    while (fInStream.good()) {
        fInStream >> names[i];
        //two dimensional array that stores the bowling scores
        for (x = 0; x < column; x++)
        {
            fInStream >> scores[i][x];
        }
        i++;
    }
    //returning true if file reading success
    return true;

}

//Function called PrettyPrintResults that outputs the results
void PrettyPrintResults(string names[row], int scores[row][column], double averageScore[row])
{
    //outputting title with iomanipulation

    cout << setw(63) << setfill('*') << "*" << endl;
    cout << setw(14) << "*" << "Welcome to my Bowling Score Program" << setw(14)  << "*"  << endl;
    cout << setw(63)  << "*" << endl;
    cout << endl;
    
    //for loop to output names
    for (i = 0; i < row; i++)
    {
        cout << names[i] << " scores in 5 games were: ";
        //two dimensional loop to output scores after names
        for (x = 0; x < column; x++)
        {
            cout << scores[i][x] << " ";
        }
        //outputting average score after second for loop
        cout << endl << "And their average was: " << averageScore[i] << endl << endl;



    }
}

//Function GetAverageScore that calculates the average score and takes in the populated array scores
void GetAverageScore(int scores[row][column], double averageScore[row])
{


    //for loop to calculate average score
    for (i = 0; i < row; i++)
    {
        //setting total to 0 again so that new row gets calculated correct
        total = 0;
        //for loop to calculate total scores by row
        for (x = 0; x < column; x++)
        {
            //adding scores to total to get all scores combined for each row
            total = total + scores[i][x];
        }
        //dividing total scores to get averageSCore
        averageScore[i] = (total / 5.0);
    }

}
int main()
{



    // Getting Bowling Data by calling function GetBowlingData
    GetBowlingData("BowlingScores.txt", names, scores);

    //calculating average score by calling function GetAverageScore
    GetAverageScore(scores, averageScore);

    //Printing name,scores and average score by calling function PrettyPrintResults
    PrettyPrintResults(names, scores, averageScore);

    cout << endl;
    system("Pause");
    return 0;
}