#pragma once
#include <iostream>
#include <math.h>
using namespace std;

const int rows = 3;
const int cols = 4;

void print_binary(int num) {  // Takes a Decimal number and prints the Binary equivalent
    const int bit = 5000;
    double x = 1;
    int  firstOnePos = 1;
    bool firstOneFound = false, isNegative = false, binaryNumber[bit];
    if (num < 0) {
        isNegative = true;
        num = abs(num); // Turning the number into a postive number so we can work on it
    }
    if (num == 0)
        cout << "binary : 0000";
    else {
        for (int i = 0; !firstOneFound; i++) {
            if (num < x) {
                firstOnePos = i;
                firstOneFound = true;
                x = x / 2;
            }
            else
                x *= 2;
        }
        cout << "Binary : ";
        if (isNegative)
            cout << "-";
        for (int i = firstOnePos - 1; i >= 0; i--)
        {
            if (num >= x) {
                binaryNumber[i] = 1;
                num = num - x;
            }
            else {
                binaryNumber[i] = 0;
            }
            x = x / 2;
            cout << binaryNumber[i];
        }
    }
    cout << endl;
}

void sort2d(int arr2d[][cols]) { // Sort 2d Array in Ascending Order
    int k = 0, temp;
    int arr1d[rows * cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr1d[k] = arr2d[i][j];
            k++;
        }
    }
    // Insertion Sort
    for (int i = 1; i < rows * cols; i++) {
        if (arr1d[i] < arr1d[i - 1]) {
            temp = arr1d[i];
            arr1d[i] = arr1d[i - 1];
            arr1d[i - 1] = temp;
            for (int j = i - 1; j > 0; j--) {
                if (arr1d[j] < arr1d[j - 1]) {
                    temp = arr1d[j];
                    arr1d[j] = arr1d[j - 1];
                    arr1d[j - 1] = temp;
                }
            }
        }
    }
    k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr2d[i][j] = arr1d[k];
            k++;
        }
    }
}

int* convert2d(int arr2d[][cols]) { // Convert 2d Aarray to 1d Array and returns the value of the 1d Array
    int* arr1d = new int[rows * cols];
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr1d[k] = arr2d[i][j];
            k++;
        }
    }
    return arr1d;
}

void printArray(int array[], int size) { // Print 1d Array  
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
}

void printArray(int** array, int r, int c) { // Print 2d Array  
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << array[i][j] << " ";
        cout << endl;
    }
}

int* createArray(const int size) { // Create 1d Array and fill it
    int* array = new int[size];
    for (int i = 0; i < size; i++)
        array[i] = i + 1;
    return array;
}

int** createArray(const int r, const int c) { // Create 2d Array and fill it
    int** array = new int* [r];
    for (int i = 0; i < r; i++)
    {
        array[i] = new int[c];
        for (int j = 0; j < c; j++)
        {
            array[i][j] = i + j;
        }
    }
    return array;
}

void readable(string text) { // Takes inreadable text and outputs readable text
    bool found_end = false;
    int length = text.length();
    for (int i = 0; i < length; i++)
    {
        if (i == 0 && text[i] != 34) {
            if (text[i] >= 'a' && text[i] <= 'z') 
                text[i] -= 32;
            if (text[i + 1] >= 'A' && text[i + 1] <= 'Z') {
                    text[i + 1] += 32;
                    for (int j = i + 2; text[j] >= 'A' && text[j] <= 'Z'; j++)
                        text[j] += 32;
            }
        }
        if (text[i] == 32) {
            if (text[i + 1] >= 'a' && text[i + 1] <= 'z')
                text[i + 1] -= 32;
            else if (text[i + 1] >= 'A' && text[i + 1] <= 'Z'){
                for (int j = i + 2; text[j] >= 'A' && text[j] <= 'Z'; j++)
                    text[j] += 32;
            }
        }
        else if (text[i] == 45) {
            if (text[i + 1] >= 'a' && text[i + 1] <= 'z')
                text[i + 1] -= 32;
            else if (text[i + 1] >= 'A' && text[i + 1] <= 'Z') {
                for (int j = i + 2; text[j] >= 'A' && text[j] <= 'Z'; j++)
                    text[j] += 32;
            }
        }
        else if (text[i] == 34 && i+1 < length) {
            for (int j = i+1; text[j] != 34 && j+1 < length; j++)
            {
                if (text[j + 1] == 34) {
                    i = j + 1;
                    
                    if (text[i + 1] >= 'a' && text[i + 1] <= 'z' && i+1 < length)
                        text[i + 1] -= 32;
                    if (text[i + 2] >= 'A' && text[i + 2] <= 'Z' && text[i + 1] >= 'A' && text[i + 1] <= 'Z'&& i + 2 < length) {
                        for (int k = i + 2; text[k] >= 'A' && text[k] <= 'Z'; k++)
                            text[k] += 32;
                    }
                    
                    found_end = true;
                    break;
                }   
            } 
            if (!found_end)
            {
                if (text[i + 1] >= 'a' && text[i + 1] <= 'z')
                    text[i + 1] -= 32;
                else if (text[i + 2] >= 'A' && text[i + 2] <= 'Z' && text[i + 1] >= 'A' && text[i + 1] <= 'Z' && i+2 < length) {
                    for (int j = i + 2; text[j] >= 'A' && text[j] <= 'Z' && j < length; j++)
                        text[j] += 32;
                }
            }
        }
        found_end = false;
    }
    system("cls");
    cout << "Readable Text : \n"<<text;
}

int check_ones(int num) { // Check the number of ones in a binary number
    int ones;
    for (ones = 0; num > 0; num = num >> 1) 
        ones += num % 2;
    return ones;
}

int check_zeros(int num) { // Check the number of zeros in a binary number
    int zero;
    for (zero = 0; num > 0; num = num >> 1)
        if (!(num % 2)) zero++;
    return zero;
}

string to_binary(unsigned long long int n, bool flag = false) { // Convert Decimal To Binary and Returns a String
    static const string digits[2] = {"0", "1"};
    if (n != 0)
        return to_binary(n / 2, true) + digits[n & 1];
    return (flag) ? "" : "0"; // if number is zero
}