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
    
    this->setClassIdentifier(shared_ptr<string>(new string(BRIngameControllerIdentifier)));
    
    robotsController = shared_ptr<BRSceneRobotsController>(new BRSceneRobotsController());
    
    crosshairController = shared_ptr<BRCrosshairController>(new BRCrosshairController());
    
    objectsPickerController = shared_ptr<BRObjectsPickerController>(new BRObjectsPickerController());
    
    objectsPickerController->delegate = this;
    
    preRendererObjectsSorter = shared_ptr<BRPreRendererObjectsSorter>(new BRPreRendererObjectsSorter());
    
    gameOverRuleController = shared_ptr<BRGameOverRuleController>(new BRGameOverRuleController());
    
    gameOverRuleController->delegate = this;
    
    gameScore = shared_ptr<BRGameScore>(); // empty game score
    
    gameScoreController = shared_ptr<BRGameScoreController>(new BRGameScoreController());
}

BRInGameController::BRInGameController(const BRInGameController& orig) {    
}

void BRInGameController::beforeStart() {

    robotsController->gameplayDifficulty = 10;
    
    gameScoreController->gameScore = gameScore;
    
    gameScore->reset();
    
    FSEGTSceneController::beforeStart();
    
    BRSceneFactory::makeScene(gameData);
    
    gameScoreController->gameScoreObject = gameData->getGameObjects()->getObjectWithIdentifier(shared_ptr<string>(new string(BRObjectClassIdentifierGameScore)));
    
    this->setSceneObjects(gameData->getGameObjects());
}

void BRInGameController::gameOverRuleControllerDidGameOverCase(BRGameOverRuleController* controller) {
    
    this->notifyListenerAboutControllerDidFinish(this);
    
}

void BRInGameController::step() {
    
    FSEGTSceneController::step();
    
    
    if (gameOverRuleController->step(gameData) == true) {
        
        return;
        
    }
    
    auto inputController = this->ioSystem->inputController;
    
    inputController->pollKey();
    inputController->pollPointerPosition();
    
    crosshairController->step(inputController, gameData);
    
    objectsPickerController->step(inputController, gameData);
    
    robotsController->step(gameData);
    
    gameScoreController->step();
    
    preRendererObjectsSorter->sort(gameData);

    renderer->blankScreen();
    
    renderer->render(gameData);
    
    renderer->updateScreen();
}

void BRInGameController::objectsPickerDidPickerObject(BRObjectsPickerController *pickerController, shared_ptr<FSEObject> object) {
    
    cout << "BRInGameController: picked object" << endl;
    
    if (object->getClassIdentifier()->compare(BRObjectClassIdentifierRobot) == 0) {
        
        robotsController->respawnRobot(object);
        
        gameScore->addScore(1);
        
        if (FSEUtils::FSERandomInt(2) == 1) {
        
            robotsController->gameplayDifficulty++;
            
            cout << "BRInGameController difficulty up!" << endl;
        }
    }
}

BRInGameController::~BRInGameController() {
}

