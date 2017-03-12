/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRSceneFactory.h
 * Author: demensdeum
 *
 * Created on March 11, 2017, 11:22 AM
 */

#ifndef BRSCENEFACTORY_H
#define BRSCENEFACTORY_H

#include <memory>

#include <FlameSteelEngine/FSEObject.h>
#include <FlameSteelEngineGameToolkit/Data/FSEGTGameData.h>

using namespace std;

class BRSceneFactory: public FSEObject {
public:
    BRSceneFactory();
    BRSceneFactory(const BRSceneFactory& orig);
    virtual ~BRSceneFactory();
    
    static shared_ptr<FSEObject> makeRobot();
    
    static void makeScene(shared_ptr<FSEGTGameData> gameData);
    
private:

};

#endif /* BRSCENEFACTORY_H */

