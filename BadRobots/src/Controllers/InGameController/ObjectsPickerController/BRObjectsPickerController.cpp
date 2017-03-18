/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRObjectsPickerController.cpp
 * Author: demensdeum
 * 
 * Created on March 18, 2017, 7:37 PM
 */

#include "BRObjectsPickerController.h"
#include <BadRobots/src/Const/BRConst.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>

#include <iostream>

BRObjectsPickerController::BRObjectsPickerController() {
    
    delegate = NULL;
    
}

BRObjectsPickerController::BRObjectsPickerController(const BRObjectsPickerController& orig) {
}

void BRObjectsPickerController::step(shared_ptr<FSEGTInputController> inputController, shared_ptr<FSEGTGameData> gameData) {
    
    if (inputController->isShootKeyPressed()) {
        
        inputController->clearKeys();
        
        int pointerX = inputController->getPointerX();
        int pointerY = inputController->getPointerY();
        
        for (int i = 0; i < gameData->getGameObjects()->size(); i ++) {
            
            auto object = gameData->getGameObjects()->objectAtIndex(i);
            
            if (FSEGTUtils::objectIsPickable(object)) {

                int objectWidth = BRCrosshairWidth;
                int objectHeight = BRCrosshairHeight;
                
                int pickerZoneX = FSEGTUtils::getObjectX(object) - objectWidth / 2;
                int pickerZoneY = FSEGTUtils::getObjectY(object) - objectHeight;
                
                if (pointerX > pickerZoneX &&
                    pointerX < pickerZoneX + objectWidth &&
                    pointerY > pickerZoneY &&
                    pointerY < pickerZoneY + objectHeight) {
                    
                    cout << "clicked on some object: " << object->getClassIdentifier()->c_str() << endl;
                    
                    if (delegate != NULL) {
                        
                        delegate->objectsPickerDidPickerObject(this, object);
                        
                    }
                }
            }
        }
    }
}

BRObjectsPickerController::~BRObjectsPickerController() {
}

