/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRExitController.cpp
 * Author: demensdeum
 * 
 * Created on March 26, 2017, 3:53 PM
 */

#include "BRExitController.h"
#include <iostream>
#include "FlameSteelEngineGameToolkit/Input/FSEGTInputController.h"

BRExitController::BRExitController() {
}

BRExitController::BRExitController(const BRExitController& orig) {
}

void BRExitController::step() {
    
#ifndef __EMSCRIPTEN__
    
    ioSystem->inputController->pollKey();
    
    if (ioSystem->inputController->isExitKeyPressed()) {
        
        cout << "Bye-Bye!" << endl;
        
        exit(0);
        
    }
#endif
    
}

BRExitController::~BRExitController() {
}

