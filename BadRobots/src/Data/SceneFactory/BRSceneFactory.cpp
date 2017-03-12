/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRSceneFactory.cpp
 * Author: demensdeum
 * 
 * Created on March 11, 2017, 11:22 AM
 */

#include "BRSceneFactory.h"
#include "FlameSteelEngineGameToolkit/Data/Components/FSEGTComponentsGenerator.h"

#include <BadRobots/src/Const/BRConst.h>

BRSceneFactory::BRSceneFactory() {
}

BRSceneFactory::BRSceneFactory(const BRSceneFactory& orig) {
}

shared_ptr<FSEObject> BRSceneFactory::makeRobot() {
    
    auto robot = shared_ptr<FSEObject>(new FSEObject());
    robot->setClassIdentifier(shared_ptr<string>(new string(BRObjectClassIdentifierRobot)));
    
    return robot;
}

void BRSceneFactory::makeScene(shared_ptr<FSEGTGameData> gameData) {
    
    auto gameObjects = gameData->getGameObjects();
    
    //clear
    
    gameObjects->removeAllObjects();
    
    // background
    
    auto background = shared_ptr<FSEObject>(new FSEObject());
    
    auto spriteComponent = FSEGTComponentsGenerator::generateSpriteComponent(shared_ptr<string>(new string(BRFilePathSceneImage)));
    
    spriteComponent->framesCount = 1;
    spriteComponent->width = 720;
    spriteComponent->height = 405;
    
    auto positionComponent = FSEGTComponentsGenerator::generatePositionComponent();
    
    positionComponent->x = 360;
    positionComponent->y = 405;
    
    background->addComponent(spriteComponent);
    background->addComponent(positionComponent);
    
    gameObjects->addObject(background);
}

BRSceneFactory::~BRSceneFactory() {
}

