/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRGameScoreController.cpp
 * Author: demensdeum
 * 
 * Created on March 28, 2017, 11:05 PM
 */

#include "BRGameScoreController.h"

#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>

BRGameScoreController::BRGameScoreController() {
    
    gameScoreObject = shared_ptr<FSEObject>();
    gameScore = shared_ptr<BRGameScore>();
}

BRGameScoreController::BRGameScoreController(const BRGameScoreController& orig) {
}

void BRGameScoreController::step() {
    
    auto score = gameScore->getScore();
    
    auto scoreString = std::to_string(score);
    
    auto text = string("Score: ") + scoreString;
    
    FSEGTUtils::setText(shared_ptr<string>(new string(text)), gameScoreObject);
}

BRGameScoreController::~BRGameScoreController() {
}

