#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ifstream inputFile("Students.txt");  // Input file for student data
    ofstream outputFile("StudentAverages.txt");  // Output file for averages

    string studentName;
    double scoreMid1, scoreMid2, scoreFinal;

    if (inputFile.is_open())
    {
        if (outputFile.is_open())
        {

            outputFile << "Student\tMid1\tMid2\tFinal\tAverage" << endl;

            while (inputFile >> studentName >> scoreMid1 >> scoreMid2 >> scoreFinal)
            {

                double finalAverage = 0.25 * scoreMid1 + 0.25 * scoreMid2 + 0.5 * scoreFinal;

                outputFile << studentName << "\t"
                    << scoreMid1 << "\t"
                    << scoreMid2 << "\t"
                    << scoreFinal << "\t"
                    << (static_cast<int>(finalAverage * 100 + 0.5) / 100.0) << endl;
            }
        }
        else
        {
            cerr << "Error: Cannot open output file." << endl;
            return 1;
        }
    }
    else
    {
        cerr << "Error: Cannot open input file." << endl;
        return 1;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
