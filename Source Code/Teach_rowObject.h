//
//  Teach_rowObject.h
//  Row Builder
//
//  Created by Jason Smash on 2015-10-17.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
////  This Class contains the implementation of the TEACHING row object (an easy-acess container structure for holing the data from an individual row on the CSV.
//  This data is held in public member variables for ease of programming (fewer getters/setters required)

#include <stdio.h>
#include <string>

#pragma once

using namespace std;

class Teach_rowObject{
public:

    
    //flag: true = error, false = no error
    bool errorFlag;
    
    //Column Types for Teaching
    
    string name; //Member Name
    string domain; // Primary domain
    string program; //Program
    string courseType; //Course Type
    string geoScope; //geographical scope
    
    int nTeach; // Number of teaching sessions
    int sDate;// Start Date
    int eDate; //End Date
    
    float hpTeach;//hours per teaching session or week
    float tHours;//total hours
    int totalStudents;  //Total number of students

    //constructor - creates a fullly operational rowObject
    Teach_rowObject(bool error, string name, string domain,string program,string courseType,string  geoScope, int nTeach, int sDate, int eDate, float hpTeach, float tHours, int tStudents);

    //default constructor - required by director
    Teach_rowObject();
    
    // this is sort of like a ToString Function - used for dumping errors
    string infoDump();

};

