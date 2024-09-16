//A program that reads a text file (score.txt), and calculate individual and class
//averages, and standard deviation of the class.


#include <iostream>
#include <fstream>
#include <string>





int main() 
//this will take a string and split it into an array of integers
    std::string input = "10,20,30,40,50"; //example input

    const int maxSize = 100; //seting the max size of the array
    int numbers[maxSize];
    int index = 0; //the first index of the array
    
    cout << "Enter a list of numbers separated by commas: ";
    getline(cin, input);

    std::string temp;