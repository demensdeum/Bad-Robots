/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRCreditsFactory.cpp
 * Author: demensdeum
 * 
 * Created on March 19, 2017, 3:21 PM
 */

#include "BRCreditsFactory.h"

#include <BadRobots/src/Const/BRConst.h>

#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>

BRCreditsFactory::BRCreditsFactory() {
}

void BRCreditsFactory::makeScene(shared_ptr<FSEGTGameData> gameData) {
    
    auto demensdeumLogoObject = FSEGTFactory::makeOnSceneObject(
        
            shared_ptr<string>(new string(BRFilePathDemensdeumLogoImage)),
            shared_ptr<string>(new string(BRFilePathDemensdeumLogoImage)),
            shared_ptr<string>(new string(BRFilePathDemensdeumLogoImage)),
            360,
            540,
            0,
            720,
            540,
            0,
            0
    );
    
    auto flameSteelEngineLogoObject = FSEGTFactory::makeOnSceneObject(
        
            shared_ptr<string>(new string(BRFilePathFlameSteelEngineLogoImage)),
            shared_ptr<string>(new string(BRFilePathFlameSteelEngineLogoImage)),
            shared_ptr<string>(new string(BRFilePathFlameSteelEngineLogoImage)),
            360,
            540,
            0,
            720,
            540,
            0,
            0
    );
    
    gameData->addGameObject(demensdeumLogoObject);
    gameData->addGameObject(flameSteelEngineLogoObject);
}

BRCreditsFactory::BRCreditsFactory(const BRCreditsFactory& orig) {
}

BRCreditsFactory::~BRCreditsFactory() {
}

