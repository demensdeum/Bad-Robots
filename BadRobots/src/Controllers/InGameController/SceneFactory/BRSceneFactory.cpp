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
#include "FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h"

#include <iostream>
#include <BadRobots/src/Const/BRConst.h>

BRSceneFactory::BRSceneFactory() {
}

BRSceneFactory::BRSceneFactory(const BRSceneFactory& orig) {
}

shared_ptr<FSEObject> BRSceneFactory::makeRobot() {
    
    auto robot = shared_ptr<FSEObject>(new FSEObject());
    robot->setInstanceIdentifier(shared_ptr<string>(new string(BRObjectClassIdentifierRobot)));
    robot->setClassIdentifier(shared_ptr<string>(new string(BRObjectClassIdentifierRobot)));
    
    auto spriteComponent = FSEGTFactory::makeSpriteComponent(shared_ptr<string>(new string(BRFilePathRobotImage)));
    
    spriteComponent->framesCount = 4;
    spriteComponent->width = 68;
    spriteComponent->height = 68;    
    
    spriteComponent->animationTickMax = 20;
    
    robot->addComponent(spriteComponent);
    
    auto positionComponent = FSEGTFactory::makePositionComponent(360, 405);
        
    robot->addComponent(positionComponent);
    
    auto speedComponent = FSEGTFactory::makeSpeedComponent(2);
    auto rotationComponent = FSEGTFactory::makeRotationComponent(0);
    
    robot->addComponent(speedComponent);
    robot->addComponent(rotationComponent);
    
    return robot;
}

shared_ptr<FSEObject> BRSceneFactory::makeCrosshair() {
    
    auto crosshair = shared_ptr<FSEObject>(new FSEObject());
    crosshair->setInstanceIdentifier(shared_ptr<string>(new string(BRObjectClassIdentifierCrosshair)));
    crosshair->setClassIdentifier(shared_ptr<string>(new string(BRObjectClassIdentifierCrosshair)));    
    
    auto spriteComponent = FSEGTFactory::makeSpriteComponent(shared_ptr<string>(new string(BRFilePathCrosshairImage)));
    
    spriteComponent->width = 64;
    spriteComponent->height = 64;    
    
    crosshair->addComponent(spriteComponent);
    
    auto positionComponent = FSEGTFactory::makePositionComponent();
    
    positionComponent->x = 64;
    positionComponent->y = 64;
    
    crosshair->addComponent(positionComponent);
    
    return crosshair;
}
shared_ptr<FSEObject> BRSceneFactory::makeGameScoreObject(int score) {
    
    auto gameScoreObject = shared_ptr<FSEObject>(new FSEObject());
    
    gameScoreObject->setClassIdentifier(shared_ptr<string>(new string(BRObjectClassIdentifierGameScore)));
    gameScoreObject->setInstanceIdentifier(shared_ptr<string>(new string(BRObjectClassIdentifierGameScore)));
    
    auto scoreString = string("Score: ") + std::to_string(score);
    
    auto textComponent = FSEGTFactory::makeTextComponent(shared_ptr<string>(new string(BRFont)), shared_ptr<string>(new string(scoreString)));
    gameScoreObject->addComponent(textComponent);
    
    auto positionComponent = FSEGTFactory::makePositionComponent(10, 10, 0);
    gameScoreObject->addComponent(positionComponent);
    
    return gameScoreObject;
}

void BRSceneFactory::makeScene(shared_ptr<FSEGTGameData> gameData) {
    
    if (gameData.get() == NULL) {
        
        cout << "BRSceneFactory: cannot makeScene - gameData is NULL" << endl;
        exit(1);
    }
    
    auto gameObjects = gameData->getGameObjects();
    
    //clear
    
    gameObjects->removeAllObjects();
    
    // background
    
    auto background = shared_ptr<FSEObject>(new FSEObject());
    background->setInstanceIdentifier(shared_ptr<string>(new string(BRObjectClassIdentifierScene)));
    background->setClassIdentifier(shared_ptr<string>(new string(BRObjectClassIdentifierScene)));
    
    auto spriteComponent = FSEGTFactory::makeSpriteComponent(shared_ptr<string>(new string(BRFilePathSceneImage)));
    
    spriteComponent->framesCount = 1;
    spriteComponent->width = 720;
    spriteComponent->height = 405;
    
    auto positionComponent = FSEGTFactory::makePositionComponent(360, 405);
    
    background->addComponent(positionComponent);
    background->addComponent(spriteComponent);
    
    gameObjects->addObject(background);
    
    // crosshair
    
    gameObjects->addObject(BRSceneFactory::makeCrosshair());
    
    gameObjects->addObject(BRSceneFactory::makeGameScoreObject(0));
}

BRSceneFactory::~BRSceneFactory() {
}

