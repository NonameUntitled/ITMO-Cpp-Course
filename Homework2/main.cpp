//
// Created by Noname Untitled on 10.09.18.
//

#include <iostream>
#include <string>
#include <vector>

#include "Person.h"

using namespace std;

void printSomeText(const string& message) {
    cout << message << endl;
}

double meanFunction(const vector<int>& values) {
    cout << "This is function for integers" << endl;

    double mean = 0.0;

    for (int value : values) {
        mean += value;
    }
    mean /= values.size();

    return mean;
}

double meanFunction(const vector<double>& values) {
    cout << "This is function for doubles" << endl;

    double mean = 0.0;

    for (double value : values) {
        mean += value;
    }
    mean /= values.size();

    return mean;
}

void simpleGreetings(const string& firstName = "Noname",
        const string& lastName = "Untitled",
        const string& question = "How are you?") {
    cout << "Hi, " << firstName << " " << lastName << "! " << question << endl;
}

void multiplication(int& value, int otherValue) {
    value *= otherValue;
}

void subtraction(int value, int otherValue) {
    value -= otherValue;
}

int main() {
    cout << "1. Write a Program to demonstrate functions." << endl;
    string textExample = "Message";

    for (int i = 0; i < 5; ++i) {
        printSomeText(textExample);
    }
    cout << endl;

    cout << "2. Write  a Program to demonstrate function overloading." << endl;
    vector<int> someIntValues = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<double> someDoubleValues = {0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5};

    cout << meanFunction(someIntValues) << endl;
    cout << meanFunction(someDoubleValues) << endl;
    cout << endl;

    cout << "3. Write a Program to demonstrate default arguments." << endl;
    simpleGreetings();
    simpleGreetings("Yan");
    simpleGreetings("Yan", "Sychev");
    simpleGreetings("Yan", "Sychev", "How old are you?");
    cout << endl;

    cout << "4. Write a Program to demonstrate pass by value, pass by reference and return by reference." << endl;
    int passByRef = 10, passByVal = 10, otherValue = 2;
    cout << "Before function: " << passByRef << endl;
    multiplication(passByRef, otherValue);
    cout << "After function: " << passByRef << endl << endl;

    cout << "Before function: " << passByVal << endl;
    subtraction(passByVal, otherValue);
    cout << "After function: " << passByVal << endl << endl;

    cout << "5. Write a Program to demonstrate classes and objects.\n"
            "6. Write a Program to demonstrate  constructors." << endl;

    Person strangePerson = Person();
    cout << strangePerson.getName() << " " << strangePerson.getSurName() << endl;

    Person author = Person("Vladimir", "Baykalov");
    cout << author.getName() << " " << author.getSurName() << endl;

    return 0;
}
