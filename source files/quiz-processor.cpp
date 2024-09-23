//A program that reads a text file (score.txt), and calculate individual and class
//averages, and standard deviation of the class.


#include <iostream>
#include <fstream>
#include <string>


//function prototypes i will use in the main loop
double calulateAverage(int arr[], int size); { //this will take the array and size of the array as arguments to calculate the average
    int sum = 0; //set the sum to 0, this is because we will be adding the elements of the array to this variable
    for (int i = 0; i < size; i++) { //loop from 0 all the way up to the size of the array
        sum += arr[i]; //add the element at index i to the sum
    }
    double average = sum / size; //calculate the average by dividing the sum by the size of the array
    std::cout<< "The average is: " << average << std::endl; //print the average to the console
}

void readTextFile() { //function to read the text file
    std::ifstream file("scores.txt"); //this will open the file of scores

    if (!file.is_open()) { //if the file doesnt open print an error message
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

void sortArray() { // Define an array of integers
    int arr[] = {5, 2, 9, 1, 5, 6}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    
    // Sorting the array in ascending order
    std::sort(arr, arr + n);
     std::cout << "Sorted array in ascending order: "; // Display the sorted array to the console
    for(int i = 0; i < n; i++) { //this loop will iterate through the array and print each element
    std::cout << arr[i] << " "; //print the element found at index i
    }
    std::cout << std::endl; // Print a newline character
    return 0; 
}

int main() {
    readTextFile();
    stringToArray();

// Define a 2D array of integers we will use to calculate the average of each row
    const int rows = 3;
    const int cols = 4;
    int array[rows][cols] = {
    {10, 20, 30, 40},
    {50, 60, 70, 80},
    {90, 100, 110, 120}
    };
    for (int i = 0; i < rows; i++) {
    double avg = calculateAverage(array[i], cols);
    std::cout << "Average of row " << i + 1 << " is: " << avg << std::endl;
    }
    return 0;
}
