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
#include <BadRobots/src/Controllers/InGameController/SceneFactory/BRSceneFactory.h>

#include <FlameSteelEngine/FSEUtils.h>

using namespace std;

BRInGameController::BRInGameController() {
    
    robotsController = shared_ptr<BRSceneRobotsController>(new BRSceneRobotsController());
    
    robotsController->gameplayDifficulty = 10;
    
    crosshairController = shared_ptr<BRCrosshairController>(new BRCrosshairController());
    
    objectsPickerController = shared_ptr<BRObjectsPickerController>(new BRObjectsPickerController());
    
    objectsPickerController->delegate = this;
    
    preRendererObjectsSorter = shared_ptr<BRPreRendererObjectsSorter>();
}

BRInGameController::BRInGameController(const BRInGameController& orig) {    
}

void BRInGameController::beforeStart() {
    
    FSEGTSceneController::beforeStart();
    
    BRSceneFactory::makeScene(gameData);
    
    this->setSceneObjects(gameData->getGameObjects());
    
}

void BRInGameController::step() {
    
    FSEGTSceneController::step();
    
    this->ioSystem->getInputController()->pollKey();
    this->ioSystem->getInputController()->pollPointerPosition();
    
    crosshairController->step(this->ioSystem->getInputController(), gameData);
    
    objectsPickerController->step(this->ioSystem->getInputController(), gameData);
    
    robotsController->step(gameData);
    
    preRendererObjectsSorter->sort(gameData);

    renderer->blankScreen();
    
    renderer->render(gameData);
    
    renderer->updateScreen();
    
}

void BRInGameController::objectsPickerDidPickerObject(BRObjectsPickerController *pickerController, shared_ptr<FSEObject> object) {
    
    cout << "BRInGameController: picked object" << endl;
    
    if (object->getClassIdentifier()->compare(BRObjectClassIdentifierRobot) == 0) {
        
        robotsController->respawnRobot(object);
        
        if (FSEUtils::FSERandomInt(2) == 1) {
        
            robotsController->gameplayDifficulty++;
            
            cout << "BRInGameController difficulty up!" << endl;
        }
    }
}

BRInGameController::~BRInGameController() {
}

