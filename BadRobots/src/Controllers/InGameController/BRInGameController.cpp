/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRInGameController.cpp
 * Author: demensdeum
 * 
 * Created on March 8, 2017, 10:30 AM
 */

#include "BRInGameController.h"

#include <iostream>
#include <BadRobots/src/Data/SceneFactory/BRSceneFactory.h>

using namespace std;

BRInGameController::BRInGameController() {
}

BRInGameController::BRInGameController(const BRInGameController& orig) {    
}

void BRInGameController::beforeStart() {
    
    FSEGTSceneController::beforeStart();
    
    BRSceneFactory::makeScene(gameData);
    
}

void BRInGameController::step() {
    
    FSEGTSceneController::step();
    
    renderer->blankScreen();
    
    renderer->render(gameData);
}

BRInGameController::~BRInGameController() {
}

