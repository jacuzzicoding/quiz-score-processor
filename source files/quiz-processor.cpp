#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

const int MAX_STUDENTS = 100;
const int NUM_QUIZZES = 5;

// Function prototypes
void readTextFile(std::string lines[], int& lineCount);
void stringToArray(const std::string& input, int numbers[], int& count);
void sortArray(int arr[], int size);
double calculateAverage(const int arr[], int size);
double calculateClassAverage(const double studentAverages[], int count);
double calculateStandardDeviation(const double studentAverages[], int count, double classAverage);
void calculateScoreDistribution(const double studentAverages[], int count, int distribution[]);
double calculateMedian(double studentAverages[], int count);
double calculateMode(const double studentAverages[], int count);

int main() {
    std::string lines[MAX_STUDENTS];
    int lineCount = 0;
    double studentAverages[MAX_STUDENTS];
    int distribution[5] = {0};

    readTextFile(lines, lineCount);
    //error check to see if file is empty
    if (lineCount == 0) {
        std::cerr << "File is empty." << std::endl;
        return 1;
    }

    for (int i = 0; i < lineCount; i++) {
        int scores[NUM_QUIZZES];
        int scoreCount = 0;
        stringToArray(lines[i], scores, scoreCount);
        sortArray(scores, scoreCount);
        double avg = calculateAverage(scores, 4); // Use top 4 scores
        studentAverages[i] = avg;
        std::cout << "Student " << i + 1 << " average: " << std::fixed << std::setprecision(2) << avg << std::endl;
    }

    double classAvg = calculateClassAverage(studentAverages, lineCount);
    double stdDev = calculateStandardDeviation(studentAverages, lineCount, classAvg);
    calculateScoreDistribution(studentAverages, lineCount, distribution);

    double median = calculateMedian(studentAverages, lineCount);
    double mode = calculateMode(studentAverages, lineCount);

    // Output results
    std::cout << "\nClass average: " << std::fixed << std::setprecision(4) << classAvg << std::endl;
    std::cout << "Standard Deviation: " << std::fixed << std::setprecision(5) << stdDev << std::endl;
    std::cout << "Median: " << std::fixed << std::setprecision(2) << median << std::endl;
    std::cout << "Mode: " << std::fixed << std::setprecision(2) << mode << std::endl;
    std::cout << "\nScore Distribution:" << std::endl;
    std::cout << "0-59: " << distribution[0] << " students" << std::endl;
    std::cout << "60-69: " << distribution[1] << " students" << std::endl;
    std::cout << "70-79: " << distribution[2] << " students" << std::endl;
    std::cout << "80-89: " << distribution[3] << " students" << std::endl;
    std::cout << "90-100: " << distribution[4] << " students" << std::endl;

    return 0;
}

void readTextFile(std::string lines[], int& lineCount) {
    std::ifstream file("scores.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line) && lineCount < MAX_STUDENTS) {
        lines[lineCount++] = line;
    }
    file.close();
}

void stringToArray(const std::string& input, int numbers[], int& count) {
    std::stringstream ss(input);
    std::string temp;
    count = 0;
    while (std::getline(ss, temp, ',') && count < NUM_QUIZZES) {
        numbers[count++] = std::stoi(temp);
    }
}

void sortArray(int arr[], int size) {
    std::sort(arr, arr + size, std::greater<int>());
}

double calculateAverage(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

double calculateClassAverage(const double studentAverages[], int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += studentAverages[i];
    }
    return sum / count;
}

double calculateStandardDeviation(const double studentAverages[], int count, double classAverage) {
    double sumSquaredDiff = 0;
    for (int i = 0; i < count; i++) {
        double diff = studentAverages[i] - classAverage;
        sumSquaredDiff += diff * diff;
    }
    return std::sqrt(sumSquaredDiff / count);
}

void calculateScoreDistribution(const double studentAverages[], int count, int distribution[]) {
    for (int i = 0; i < count; i++) {
        if (studentAverages[i] < 60) distribution[0]++;
        else if (studentAverages[i] < 70) distribution[1]++;
        else if (studentAverages[i] < 80) distribution[2]++;
        else if (studentAverages[i] < 90) distribution[3]++;
        else distribution[4]++;
    }
}

double calculateMedian(double studentAverages[], int count) {
    std::sort(studentAverages, studentAverages + count);
    if (count % 2 == 0) {
        return (studentAverages[count/2 - 1] + studentAverages[count/2]) / 2.0;
    } else {
        return studentAverages[count/2];
    }
}

double calculateMode(const double studentAverages[], int count) {
    double modeValue = studentAverages[0];
    int maxCount = 0;
    
    for (int i = 0; i < count; i++) {
        int currentCount = 0;
        for (int j = 0; j < count; j++) {
            if (std::abs(studentAverages[j] - studentAverages[i]) < 0.01) {
                currentCount++;
            }
        }
        if (currentCount > maxCount || (currentCount == maxCount && studentAverages[i] > modeValue)) {
            maxCount = currentCount;
            modeValue = studentAverages[i];
        }
    }
    
    return modeValue;
}