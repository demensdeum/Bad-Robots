/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTGameOverRuleController.cpp
 * Author: demensdeum
 * 
 * Created on March 23, 2017, 11:45 PM
 */

#include "BRGameOverRuleController.h"

#include <BadRobots/src/Const/BRConst.h>

#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>

BRGameOverRuleController::BRGameOverRuleController() {
    
    delegate = NULL;
    
}

BRGameOverRuleController::BRGameOverRuleController(const BRGameOverRuleController& orig) {
}

bool BRGameOverRuleController::step(shared_ptr<FSEGTGameData> gameData) {
    
    for (int i = 0; i < gameData->getGameObjects()->size(); i++) {
        
        auto object = gameData->getGameObjects()->objectAtIndex(i);
        
        if (object->getClassIdentifier()->compare(BRObjectClassIdentifierRobot) != 0) {
            
            continue;
        }
        
        int x = FSEGTUtils::getObjectX(object);
        
        if (x > BRGameControllerScreenWidth) {
            
            if (delegate != NULL) {
                
                delegate->gameOverRuleControllerDidGameOverCase(this);
                
            }
            
            return true;
            
        }
    }
    
    return false;
}

BRGameOverRuleController::~BRGameOverRuleController() {
}

