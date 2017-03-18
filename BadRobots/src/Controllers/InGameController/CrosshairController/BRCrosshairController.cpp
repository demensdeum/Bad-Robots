/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRCrosshairController.cpp
 * Author: demensdeum
 * 
 * Created on March 18, 2017, 6:29 PM
 */

#include <BadRobots/src/Const/BRConst.h>

#include "BRCrosshairController.h"
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>

BRCrosshairController::BRCrosshairController() {
}

BRCrosshairController::BRCrosshairController(const BRCrosshairController& orig) {
}

void BRCrosshairController::step(shared_ptr<FSEGTInputController> inputController, shared_ptr<FSEGTGameData> gameData) {
    
    auto gameObjects = gameData->getGameObjects();
    
    for (int i = 0; i < gameObjects->size(); i++) {
     
        auto object = gameObjects->objectAtIndex(i);
        
        if (object->getClassIdentifier()->compare(BRObjectClassIdentifierCrosshair) == 0) {
         
            int cursorX = inputController->getPointerX();
            int cursorY = inputController->getPointerY();
            
            FSEGTUtils::setObjectX(object, cursorX);
            FSEGTUtils::setObjectY(object, cursorY + BRCrosshairHeight / 2);
        }
    }
}

BRCrosshairController::~BRCrosshairController() {
}

