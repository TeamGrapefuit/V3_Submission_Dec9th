//
//  GrantRowBuilder.h
//  Row Builder
//
//  Created by Jason Smash on 2015-10-17.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//
//  This class creates a grants row object
//  error checking is also included here


#include <stdio.h>
#include "Grant_rowObject.h"
#include <string>
#include "attributeretriever.h"
#include "ColIndex.h"
#include "ErrorChecker.h"

class GrantRowBuilder{
public:
    //default constructor - does nothing
    GrantRowBuilder(){};
    
    //fetch each attribute, error checking, build row
    Grant_rowObject buildRow(string data, ColIndex index);
    
};
