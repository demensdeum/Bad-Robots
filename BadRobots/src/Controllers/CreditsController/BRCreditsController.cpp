/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRCreditsController.cpp
 * Author: demensdeum
 * 
 * Created on March 19, 2017, 11:31 AM
 */

#include "BRCreditsController.h"

#include <BadRobots/src/Controllers/CreditsController/CreditsFactory/BRCreditsFactory.h>

BRCreditsController::BRCreditsController() {
        
}

BRCreditsController::BRCreditsController(const BRCreditsController& orig) {
}

void BRCreditsController::beforeStart() {
    
    auto creditsFactory = shared_ptr<BRCreditsFactory>(new BRCreditsFactory());
    creditsFactory->makeScene(gameData);    
    
}

void BRCreditsController::step() {
    
    renderer->blankScreen();
    
    renderer->render(gameData);
    
    renderer->updateScreen();
    
}

BRCreditsController::~BRCreditsController() {
}

