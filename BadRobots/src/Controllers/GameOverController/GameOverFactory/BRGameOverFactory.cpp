/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRGameOverFactory.cpp
 * Author: demensdeum
 * 
 * Created on March 23, 2017, 10:42 PM
 */

#include "BRGameOverFactory.h"
#include "BadRobots/src/Controllers/InGameController/SceneFactory/BRSceneFactory.h"

#include <BadRobots/src/Const/BRConst.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>

#include <memory>

BRGameOverFactory::BRGameOverFactory() {
}

BRGameOverFactory::BRGameOverFactory(const BRGameOverFactory& orig) {
}

void BRGameOverFactory::makeScene(shared_ptr<FSEGTGameData> gameData, int score) {
    
    gameData->getGameObjects()->removeAllObjects();
    
    auto gameOverLogoObject = FSEGTFactory::makeOnSceneObject(
        
            shared_ptr<string>(new string(BRFilePathGameOverImage)),
            shared_ptr<string>(new string(BRFilePathGameOverImage)),
            shared_ptr<string>(new string(BRFilePathGameOverImage)),
            360,
            405,
            0,
            720,
            405,
            0,
            0
    );    

    gameData->addGameObject(gameOverLogoObject);
    gameData->addGameObject(BRSceneFactory::makeGameScoreObject(score));
}

BRGameOverFactory::~BRGameOverFactory() {
}

