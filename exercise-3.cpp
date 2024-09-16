#include <iostream>
#include <fstream>
using namespace std;

class Student {
private:
    char fullName[30];
    int labScores[10];
    float avgScore;

public:
    void assignName(const char* name) {
        int i = 0;
        while (name[i] != '\0' && i < 29) {
            fullName[i] = name[i];
            i++;
        }
        fullName[i] = '\0';
    }

    void assignLabScores(int* scores, int size) {
        for (int i = 0; i < size; i++) {
            labScores[i] = scores[i];
        }
    }

    void calculateAvg(int size) {
        int total = 0;
        for (int i = 0; i < size; i++) {
            total += labScores[i];
        }
        avgScore = static_cast<float>(total) / size;
    }

    void displayName() const {
        cout << "Student Name: " << fullName << endl;
    }

    void displayLabScores(int size) const {
        cout << "Lab Scores: ";
        for (int i = 0; i < size; i++) {
            cout << labScores[i] << " ";
        }
        cout << endl;
    }

    void displayAverage() const {
        cout << "Average Score: " << avgScore << endl;
    }
};

void mergeNames(const char* firstName, const char* lastName, char* mergedName, size_t maxSize) {
    size_t i = 0, j = 0;

    while (firstName[i] != '\0' && i < maxSize - 1) {
        mergedName[i] = firstName[i];
        i++;
    }

    if (i < maxSize - 1) {
        mergedName[i] = ' ';
        i++;
    }

    while (lastName[j] != '\0' && i < maxSize - 1) {
        mergedName[i] = lastName[j];
        i++;
        j++;
    }

    mergedName[i] = '\0';
}

int main() {
    ifstream inputFile("data.txt");
    int studentCount = 0, numOfLabs = 0, index = 0;

    inputFile >> studentCount >> numOfLabs;

    Student* students = new Student[studentCount];
    int* labResults = new int[numOfLabs];

    char firstName[30], lastName[30], fullName[30];

    if (inputFile.is_open()) {
        while (inputFile >> firstName >> lastName) {
            mergeNames(firstName, lastName, fullName, 30);

            students[index].assignName(fullName);

            for (int i = 0; i < numOfLabs; i++) {
                inputFile >> labResults[i];
            }

            students[index].assignLabScores(labResults, numOfLabs);
            students[index].calculateAvg(numOfLabs);

            students[index].displayName();
            students[index].displayLabScores(numOfLabs);
            students[index].displayAverage();

            index++;
        }
    }
    else {
        cout << "Error opening the file." << endl;
    }

    delete[] students;
    delete[] labResults;

    inputFile.close();
    return 0;
}
