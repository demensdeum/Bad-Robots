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

#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTComponentsGenerator.h>

BRCreditsFactory::BRCreditsFactory() {
}

void BRCreditsFactory::makeScene(shared_ptr<FSEGTGameData> gameData) {
    
    auto demensdeumLogoObject = shared_ptr<FSEObject>(new FSEObject());
    auto demensdeumLogoPositionComponent = FSEGTComponentsGenerator::generatePositionComponent(360, 405);
    auto demensdeumLogoSpriteComponent = FSEGTComponentsGenerator::generateSpriteComponent(shared_ptr<string>(new string(BRFilePathDemensdeumLogoImage)));
    demensdeumLogoSpriteComponent->width = 720;
    demensdeumLogoSpriteComponent->height = 405;
    demensdeumLogoObject->addComponent(demensdeumLogoSpriteComponent);
    demensdeumLogoObject->addComponent(demensdeumLogoPositionComponent);
    
    auto flameSteelEngineLogoObject = shared_ptr<FSEObject>(new FSEObject());
    auto flameSteelEnginePositionComponent = FSEGTComponentsGenerator::generatePositionComponent(360, 540);
    auto flameSteelEngineSpriteComponent = FSEGTComponentsGenerator::generateSpriteComponent(shared_ptr<string>(new string(BRFilePathFlameSteelEngineLogoImage)));
    flameSteelEngineSpriteComponent->width = 720;
    flameSteelEngineSpriteComponent->height = 540;
    flameSteelEngineLogoObject->addComponent(flameSteelEngineSpriteComponent);
    flameSteelEngineLogoObject->addComponent(flameSteelEnginePositionComponent);
    
    gameData->addGameObject(demensdeumLogoObject);
    gameData->addGameObject(flameSteelEngineLogoObject);
}

BRCreditsFactory::BRCreditsFactory(const BRCreditsFactory& orig) {
}

BRCreditsFactory::~BRCreditsFactory() {
}

