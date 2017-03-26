/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRGameOverController.cpp
 * Author: demensdeum
 * 
 * Created on March 23, 2017, 10:17 PM
 */

#include "BRGameOverController.h"

#include <BadRobots/src/Const/BRConst.h>

#include <FlameSteelEngineGameToolkit/Input/FSEGTInputController.h>
#include <BadRobots/src/Controllers/GameOverController/GameOverFactory/BRGameOverFactory.h>

BRGameOverController::BRGameOverController() {
    
    this->setClassIdentifier(shared_ptr<string>(new string(BRGameOverControllerIdentifier)));
    
}

BRGameOverController::BRGameOverController(const BRGameOverController& orig) {
}

void BRGameOverController::beforeStart() {
    
    auto gameOverFactory = shared_ptr<BRGameOverFactory>(new BRGameOverFactory());
    gameOverFactory->makeScene(gameData);    
    
}

void BRGameOverController::step() {
    
    renderer->blankScreen();
    
    renderer->render(gameData);
    
    renderer->updateScreen();  
    
    auto inputController = ioSystem->inputController;
    inputController->pollKey();
    
    if (inputController->isShootKeyPressed()) {
     
        this->notifyListenerAboutControllerDidFinish(this);
        
    }    
    
}

BRGameOverController::~BRGameOverController() {
}

