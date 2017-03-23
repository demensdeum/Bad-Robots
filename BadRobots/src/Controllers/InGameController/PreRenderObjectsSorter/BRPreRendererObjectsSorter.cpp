/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PreRenderObjectsSorter.cpp
 * Author: demensdeum
 * 
 * Created on March 21, 2017, 11:21 PM
 */

#include "BRPreRendererObjectsSorter.h"
#include <BadRobots/src/Const/BRConst.h>
#include "FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h"

#include <algorithm>

BRPreRendererObjectsSorter::BRPreRendererObjectsSorter() {
}

void BRPreRendererObjectsSorter::sort(shared_ptr<FSEGTGameData> gameData) {
    
    struct ySort
{
    inline bool operator() (const shared_ptr<FSEObject> lhs, const shared_ptr<FSEObject> rhs)
    {
        int lhsY = FSEGTUtils::getObjectY(lhs);
        int rhsY = FSEGTUtils::getObjectY(rhs);
        
        return lhsY < rhsY;
    }
};

    auto gameObjectsVector = gameData->getGameObjects()->getObjectsVector();
    
    std::sort(gameObjectsVector->begin(), gameObjectsVector->end(), ySort());
    
    // crosshair on top and scene on bottom
    
    shared_ptr<FSEObject> scene;
    shared_ptr<FSEObject> crosshair;
    
    for (int i = 0; i < gameData->getGameObjects()->size(); i++) {
        
        auto object = gameData->getGameObjects()->objectAtIndex(i);
        
        if (object->getInstanceIdentifier()->compare(BRObjectClassIdentifierScene)==0) {
            
            scene = object;
            
            gameData->getGameObjects()->removeObjectAtIndex(i);
            i--;
        }
        
        else if (object->getInstanceIdentifier()->compare(BRObjectClassIdentifierCrosshair)==0) {
            
            crosshair = object;

            gameData->getGameObjects()->removeObjectAtIndex(i);
            i--;            
        }        
    }
    
    gameObjectsVector->insert(gameObjectsVector->begin(), scene);
    gameObjectsVector->insert(gameObjectsVector->end(), crosshair);
}

BRPreRendererObjectsSorter::BRPreRendererObjectsSorter(const BRPreRendererObjectsSorter& orig) {
}

BRPreRendererObjectsSorter::~BRPreRendererObjectsSorter() {
}

