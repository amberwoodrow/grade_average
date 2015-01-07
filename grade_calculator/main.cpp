//
//  main.cpp
//  grade_calculator
//
//  Created by Amber Woodrow on 1/5/15.
//  Copyright (c) 2015 Amber Woodrow. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
using namespace std;

int main(int argc, const char * argv[]) {
  
//    Write a program that allows the user to enter the grade scored in a programming class (0-100).
//    If the user scored a 100 then notify the user that they got a perfect score.
//    
//    ★ Modify the program so that if the user scored a 90-100 it informs the user that they scored an A
//        
//    ★★ Modify the program so that it will notify the user of their letter grade
//    0-59 F 60-69 D 70-79 C 80-89 B 90-100 A
//
//    ★★★ Modify to average out a grade
    cout << "Get your grade average!\nEnter as many grades as you'd like and let the calculator give you your grade average.\nType start to begin.\nType exit to get your average.\n";
    string user_input;
    cin >> user_input;
    
    string grade_input = "";
    
    vector<int> grades;
    int total = 0;
    
    string start1 = "start";
    string start2 = "START";
    string exit1 = "exit";
    string exit2 = "EXIT";
    
    //Calculate average
    
    if(user_input == start1 || user_input == start2){
        do{
            
            cout << "Please enter a number grade.\n";
            cin >> grade_input;
            int grade = atoi(grade_input.c_str());
            grades.push_back(grade);
            //keeps code dry
            string yg = "Your letter grade is: ";
    
            //print out message for user's input
            if(grade > 100 || grade < 0){
                cout << "Not a valid score.\n";}
            else if(grade == 100){
                cout << yg << "perfect score!\n";}
            else if(grade >= 90 && grade <= 99){
                cout << yg << "A!\n";}
            else if(grade >= 80){
                cout << yg << "B!\n";}
            else if(grade >= 70){
                cout << yg << "C.\n";}
            else if(grade >= 60){
                cout << yg << "D.\n";}
            else if(grade >= 0){
                cout << yg << "F :(!\n";}
            //else
            
                        }while(grade_input != exit1 && grade_input != exit2);
        
        for(vector<int>::iterator it = grades.begin(); it != grades.end(); ++it){
            total = *it + total;
        }
        
        int grade_average = 0;
        grade_average = total / grades.size(); //divide when done adding
        
        cout << "Your grade is " << grade_average << endl;}  // total can be configured through the if loop to find the letter grade

    else
        {cout << "Invalid answer, type start to begin and exit to leave.\n";}
;}