//
//  main.cpp
//  grade_calculator
//
//  Created by Amber Woodrow on 1/5/15.
//  Copyright (c) 2015 Amber Woodrow. All rights reserved.
//

//return value, type, purose whats it used for what does it do.


#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

void init();
void user_inputs();
void grade_calc(vector<int> grades);
string letter_grade(int grade);
bool is_d(char c);
bool is_number(string s);

string e1 = "exit";
string e2 = "EXIT";

int main() {
    init();
}

// Initiates program.
void init(){
    cout << "Get your grade average!\n"
            "Enter as many grades as you'd like and let the calculator give you your grade average.\n"
            "Type start to begin or exit to leave.\n";
    string user_input = "";
    cin >> user_input;
    
    while(user_input != "start" && user_input != "START" && user_input != e1 && user_input != e2){
        cout << "Invalid answer, type start to begin and exit to leave.\n";
        cin >> user_input;
    }
    if(user_input == "start" || user_input == "START"){
        user_inputs();
    }
    else if(user_input == e1 || user_input == e2){
        cout << "Bye-bye!\n";
    }

}

// Handles user input
void user_inputs(){
    string grade_input = "";
    vector<int> grades;
    
    cout << "Type exit at any time to get your average and exit the program.\n";
    do{
        cout << "Please enter a number grade or type exit.\n";
        cin >> grade_input;
        
        if(grade_input == e1 || grade_input == e2){
            break;
        }
    
        if(is_number(grade_input)){
            int grade = atoi(grade_input.c_str());

            cout << "Your grade is: " << letter_grade(grade) << endl;
            if(grade <= 100 && grade >= 0){
                grades.push_back(grade);
            }
        }
        else
            {cout << "Not a valid number answer.\n";}
        
    }while(grade_input != e1 && grade_input != e2);
    grade_calc(grades);
}

// Calculates average grade then exits program
void grade_calc(vector<int> grades){
    int total = 0;
    for(vector<int>::iterator it = grades.begin(); it != grades.end(); ++it){
        total = *it + total;
    }
    
    if(grades.size() != 0){
        int grade_average = 0;
        grade_average = total / grades.size();
        cout << "Your grade is: " << grade_average << " " << letter_grade(grade_average) << endl;
    }
    
    else {
        cout << "Bye-bye\n";
    }
}

// Returns a string from user's input
string letter_grade(int grade){
    
    string letter = "";
    
    if(grade > 100 || grade < 0){
        cout << "not a valid entry.";
    }
    else if(grade == 100){
        letter = "A+ a perfect score!";
    }
    else if(grade >= 90 && grade <= 99){
        letter = "A!";
    }
    else if(grade >= 80){
        letter = "B!";
    }
    else if(grade >= 70){
        letter = "C.";
    }
    else if(grade >= 60){
        letter = "D.";
    }
    else if(grade >= 0){
        letter = "F :(!";
    }
    return letter;
}

// Checks if input is a number
bool is_d(char c){
    return !isdigit(c);
}

// Checks if input is a string
bool is_number(string s){
    return !s.empty() && find_if(s.begin(), s.end(), is_d) == s.end();
}