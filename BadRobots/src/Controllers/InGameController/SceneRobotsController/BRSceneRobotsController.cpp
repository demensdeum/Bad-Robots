/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRSceneRobotsController.cpp
 * Author: demensdeum
 * 
 * Created on March 18, 2017, 10:20 AM
 */

#include "BRSceneRobotsController.h"
#include "FlameSteelEngine/FSEUtils.h"

#include <BadRobots/src/Const/BRConst.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <BadRobots/src/Controllers/InGameController/SceneFactory/BRSceneFactory.h>

BRSceneRobotsController::BRSceneRobotsController() {
    
    gameplayDifficulty = 0;
}

BRSceneRobotsController::BRSceneRobotsController(const BRSceneRobotsController& orig) {
}

void BRSceneRobotsController::step(shared_ptr<FSEGTGameData> gameData) {
    
    this->respawnRobotsIfNeeded(gameData->getGameObjects());
}

void BRSceneRobotsController::respawnRobot(shared_ptr<FSEObject> robot) {
    
    FSEGTUtils::setObjectX(robot, randomRobotRespawnX());

}

void BRSceneRobotsController::respawnRobotsIfNeeded(shared_ptr<FSEObjects> sceneObjects) {
    
    int robotsCount = 0;
    
    for (int i = 0; i < sceneObjects->size(); i++) {
        
        auto object = sceneObjects->objectAtIndex(i);
        
        if (object->getClassIdentifier()->compare(BRObjectClassIdentifierRobot) == 0) {
            
            int x = FSEGTUtils::getObjectX(object);
            
            if (x > BRGameControllerScreenWidth + BRRobotWidth) {
                
                respawnRobot(object);
            }
            
            robotsCount++;
        }
    }
    
    for (int i = robotsCount; i < gameplayDifficulty; i++) {
        
        // spawn robot
        
        auto robot = BRSceneFactory::makeRobot();
        
        FSEGTUtils::setObjectX(robot, randomRobotRespawnX());
        FSEGTUtils::setObjectY(robot, BRGameSceneTop + FSEUtils::FSERandomInt(130));
        
        sceneObjects->addObject(robot);
    }
}

int BRSceneRobotsController::randomRobotRespawnX() {
    
    return -BRRobotWidth - FSEUtils::FSERandomInt(BRGameControllerScreenWidth) * 4;
}

BRSceneRobotsController::~BRSceneRobotsController() {
}

