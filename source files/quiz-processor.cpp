//A program that reads a text file (score.txt), and calculate individual and class
//averages, and standard deviation of the class.


#include <iostream>
#include <fstream>
#include <string>


//function prototypes
double calulateAverage(int arr[], int size); {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return static double (sum) / size;
}

void readTextFile() { //function to read the text file
    std::ifstream file("example.txt");

    if (!file.is_open()) {
    std::cerr << "Failed to open the file." << std::endl;
    return 1;
    }
    std::string line;
    while (std::getline(file, line)) {
    std::cout << line << std::endl;
    }
    file.close();
    return 0;
 }

void stringToArray() { //function to convert a string to an array of integers
    std::string input = "10,20,30,40,50"; //example input
    const int maxSize = 100;
    int numbers[maxSize];
    int index = 0;
    std::stringstream ss(input);
    std::string temp;
    while (std::getline(ss, temp, ',')) {
    if (index < maxSize) {
    numbers[index] = std::stoi(temp);
    index++;
    } else {
    std::cerr << "Array size exceeded." << std::endl;
    break;
    }
    }
    std::cout << "Stored integers:" << std::endl;
    for (int i = 0; i < index; i++) {
    std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

int main() {
    readTextFile();
    stringToArray();
    return 0;
}