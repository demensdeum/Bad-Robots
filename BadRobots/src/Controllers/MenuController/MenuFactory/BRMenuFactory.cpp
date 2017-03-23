/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRMenuFactory.cpp
 * Author: demensdeum
 * 
 * Created on March 23, 2017, 9:10 PM
 */

#include "BRMenuFactory.h"

#include <BadRobots/src/Const/BRConst.h>

#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>

BRMenuFactory::BRMenuFactory() {
}

BRMenuFactory::BRMenuFactory(const BRMenuFactory& orig) {
}
void BRMenuFactory::makeScene(shared_ptr<FSEGTGameData> gameData) {
    
    gameData->getGameObjects()->removeAllObjects();
    
    auto menuImageObject = FSEGTFactory::makeOnSceneObject(
        
            shared_ptr<string>(new string(BRFilePathBadRobotsImage)),
            shared_ptr<string>(new string(BRFilePathBadRobotsImage)),
            shared_ptr<string>(new string(BRFilePathBadRobotsImage)),
            360,
            540,
            0,
            720,
            540,
            0,
            0
    );    
    
    gameData->addGameObject(menuImageObject);
}


BRMenuFactory::~BRMenuFactory() {
}

