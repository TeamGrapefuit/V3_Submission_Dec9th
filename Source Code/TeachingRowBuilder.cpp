//
//  TeachingRowBuilder.cpp
//  Row Builder
//
//  Created by Jason Smash on 2015-10-17.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//

#include "TeachingRowBuilder.h"

//fetch each attribute, error checking, build rowobject
//input: string of row from csv, colindex for data type
Teach_rowObject TeachingRowBuilder::buildRow(string data, ColIndex index){
   
    //*** instantiate classes that will help out in this function
    AttributeRetriever fetch(data);
    bool hasError = 0; //Set this to 1 if an error is found
    ErrorChecker filter;
    bool enableErrorChecking (1);
    
    //*** retrieve each attribute - temporarily store them
    
    string name = fetch.getAttribute(index.name_loc);
    string domain = fetch.getAttribute(index.domain_loc);
    string program = fetch.getAttribute(index.program_loc);
    string courseType = fetch.getAttribute(index.courseType_loc);
    string geoScope = fetch.getAttribute(index.geoScope_loc);
    string title = fetch.getAttribute(index.title_loc);
    
    int sDate = fetch.getIntAttribute(index.sDate_loc);
    int eDate = fetch.getIntAttribute(index.eDate_loc);
    int nTeach = fetch.getIntAttribute(index.nTeach_loc);
    int tStudents = fetch.getIntAttribute(index.tStudents_loc);
    
    float hpTeach = fetch.getIntAttribute(index.hpTeach_loc);
    float tHours = fetch.getIntAttribute(index.tHours_loc);
    
    //*** check for errors
    if (enableErrorChecking){
    
        //strings - check for blank entries
        name = filter.blankCatch(name, hasError);
        domain = filter.blankCatch(domain, hasError);
        program = filter.blankCatch(program, hasError);
        courseType = filter.blankCatch(courseType, hasError);
        
        //dates, check for zeroes
        sDate = filter.zeroCatch(sDate, hasError);
        eDate = filter.zeroCatch(eDate, hasError);
        hpTeach = filter.zeroCatch(hpTeach, hasError);
        tHours = filter.zeroCatch(tHours, hasError);
        
    }
    
    
    //*** Build Row
    Teach_rowObject currentRow (hasError, name, domain, program, courseType, geoScope, nTeach, sDate, eDate, hpTeach, tHours, tStudents);
    
    return currentRow;
};