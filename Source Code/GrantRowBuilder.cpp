//
//  GrantRowBuilder.cpp
//  Row Builder
//
//  Created by Jason Smash on 2015-10-17.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//

#include "GrantRowBuilder.h"

//fetch each object, error checking, build row
//input: raw string of row from CSV, column index for data type
//output: complete row object
Grant_rowObject GrantRowBuilder::buildRow(string data, ColIndex index){
    
    //*** instantiate classes that will help out in this function
    AttributeRetriever fetch(data);
    bool hasError = 0;//IF this row has an error in it, this flag should be set to true
    ErrorChecker filter;
    bool enableErrorChecking (1);
    
    //*** retrieve each attribute - temporarily store them
    
    string name = fetch.getAttribute(index.name_loc);
    string domain = fetch.getAttribute(index.domain_loc);
    string fundType = fetch.getAttribute(index.fundType_loc);
    string stat = fetch.getAttribute(index.stat_loc);
    string role = fetch.getAttribute(index.role_loc);
    string title = fetch.getAttribute(index.title_loc);
    string pInvestigator = fetch.getAttribute(index.pInvestigator_loc);
    
    // Deal with multiple co-investigators in a cell
    string cpInvestigator = fetch.getAttribute(index.cpInvestigator_loc);
    fetch.grabFirstString(cpInvestigator);//TEMPORARY -returns first co-investigator
    
    bool peerReviewed = fetch.getBoolAttribute(index.peerReviewed_loc);
    bool indGrant = fetch.getBoolAttribute(index.indGrant_loc);
    
    int sDate = fetch.getIntAttribute(index.sDate_loc);
    int eDate = fetch.getIntAttribute(index.eDate_loc);
    
    long long totalAmount = fetch.getLongAttribute(index.totalAmount_loc);
    
    
    //*** Error Checking
    if (enableErrorChecking){
    
        //strings - chack for blank fields
        name = filter.blankCatch(name, hasError);
        domain = filter.blankCatch(domain, hasError);
        fundType = filter.blankCatch(fundType, hasError);
        stat = filter.blankCatch(stat, hasError);
        role = filter.blankCatch(role, hasError);
        title = filter.blankCatch(title, hasError);
        pInvestigator = filter.blankCatch(pInvestigator, hasError);
        
        //PEER REVIEWED - if feild is left blank, we assume it has not been peer reviewed
        //INDUSTRY GRANT - if feild is left blank, we assume it was not an industry grant
        
        //dates - check for zeroes
        sDate = filter.zeroCatch(sDate, hasError);
        eDate = filter.zeroCatch(eDate, hasError);
        
        //Assert FundType
        string acceptable_fundTypes [2] = {"Grants","Clinical Trials"};
        fundType = filter.stringAssert(fundType, hasError, 2, acceptable_fundTypes);
        
        //Assert status
        string acceptable_statuses [5] = {"Applied","Funded","Declined","Rejected","Not Funded"};
        stat = filter.stringAssert(stat, hasError, 5, acceptable_statuses);
        
        //Assert Role
        string acceptable_Roles [8] = {"Co-Applicant","Co-Investigator","Collaborator","Co-Principal Investigator","Principal Applicant","Principal Investigator","Principal Site Investigator","Site Investigator"};
        role = filter.stringAssert(role,hasError, 8, acceptable_Roles);
        
    }
    
    //*** Build Row
    Grant_rowObject currentRow (hasError, name, domain, sDate, eDate, fundType, stat, peerReviewed,indGrant, role, title, pInvestigator, cpInvestigator, totalAmount);
    
    return currentRow;
};