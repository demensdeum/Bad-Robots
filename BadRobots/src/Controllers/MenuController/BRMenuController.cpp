/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRMenuController.cpp
 * Author: demensdeum
 * 
 * Created on March 23, 2017, 9:05 PM
 */

#include "BRMenuController.h"
#include <BadRobots/src/Const/BRConst.h>
#include <FlameSteelEngineGameToolkit/Input/FSEGTInputController.h>
#include <BadRobots/src/Controllers/MenuController/MenuFactory/BRMenuFactory.h>

BRMenuController::BRMenuController() {
    
    this->setClassIdentifier(shared_ptr<string>(new string(BRMenuControllerIdentifier)));
    
}

void BRMenuController::beforeStart() {
    
    auto menuFactory = shared_ptr<BRMenuFactory>(new BRMenuFactory());
    menuFactory->makeScene(gameData);       
}

void BRMenuController::step() {
        
    renderer->blankScreen();
    
    renderer->render(gameData);
    
    renderer->updateScreen();   
    
    auto inputController = ioSystem->getInputController();
    inputController->pollKey();
    
    if (inputController->isShootKeyPressed()) {
     
        this->notifyListenerAboutControllerDidFinish(this);
        
    }
}

BRMenuController::BRMenuController(const BRMenuController& orig) {
}

BRMenuController::~BRMenuController() {
}

