//A program that reads a text file (score.txt), and calculate individual and class
//averages, and standard deviation of the class.


#include <iostream>
#include <fstream>
#include <string>





int main() 
//this will take a string and split it into an array of integers
    std::string input = "10,20,30,40,50"; //example input

    const int maxSize = 100;
    int numbers[maxSize];
    int index = 0;
    
    cout << "Enter a list of numbers separated by commas: ";
    getline(cin, input);

    std::string temp;