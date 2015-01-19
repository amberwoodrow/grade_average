//
//  main.cpp
//  grade_calculator
//
//  Created by Amber Woodrow on 1/5/15.
//  Copyright (c) 2015 Amber Woodrow. All rights reserved.
//

//    Write a program that allows the user to enter the grade scored in a programming class (0-100).
//    If the user scored a 100 then notify the user that they got a perfect score.
//
//    ★ Modify the program so that if the user scored a 90-100 it informs the user that they scored an A
//
//    ★★ Modify the program so that it will notify the user of their letter grade
//    0-59 F 60-69 D 70-79 C 80-89 B 90-100 A
//
//    ★★★ Modify to average out a grade

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>

#include <stdio.h>
#include <string.h>
using namespace std;


void do_grade();
string letter_grade(int grade);
bool is_number(string s);
void init();



int main() {
    init();
    //do_grade();
}



void init(){
    cout << "Get your grade average!\n"
            "Enter as many grades as you'd like and let the calculator give you your grade average.\n"
            "Type start to begin or exit to leave.\n";
    do_grade();
       //return j;
}



void do_grade(){
    // 11111111 array has elements pushed on to it so it starts with and un-needed 0
    string grade_input = "";
    vector<int> grades;
    int total = 0;
    
    string user_input;
    cin >> user_input;
    //bool j = memcmp(&user_input, "start", user_input.size());
    string e1 = "exit";
    string e2 = "EXIT";
    
    if(user_input == "start" || user_input == "START"){ // start is true
        cout << "Type exit at any time to get your average.\n";
        do{
            
            cout << "Please enter a number grade.\n";
            cin >> grade_input;
            
            if(grade_input == "exit" || grade_input == "EXIT"){
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
            
        }while(grade_input != "exit" && grade_input != "EXIT");
        
        //Calculates average
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
    else if(user_input == "exit" || user_input == "EXIT"){
        cout << "Bye-bye!\n";
    }
    else{
        cout << "Invalid answer, type start to begin and exit to leave.\n";
        do_grade();
        }
    
}


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

bool is_number(string s){
    return !s.empty() && find_if(s.begin(), s.end(), [](char c){return !isdigit(c);}) == s.end();
}










