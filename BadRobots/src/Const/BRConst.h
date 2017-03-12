/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRConst.h
 * Author: demensdeum
 *
 * Created on March 8, 2017, 8:55 AM
 */

#ifndef BRCONST_H
#define BRCONST_H

#include <string>

using namespace std;

// states

enum BRState {
    
    BRStateIngame
    
};

// object identifiers

const string BRObjectClassIdentifierRobot = "Bad Robots Object";
const string BRObjectClassIdentifierScene = "Bad Robots Scene Background";

// file paths

const string BRFilePathSceneImage = "data/graphics/scene.png";

#endif /* BRCONST_H */

