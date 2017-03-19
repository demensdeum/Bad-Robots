/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRCreditsFactory.h
 * Author: demensdeum
 *
 * Created on March 19, 2017, 3:21 PM
 */

#ifndef BRCREDITSFACTORY_H
#define BRCREDITSFACTORY_H

#include <FlameSteelEngine/FSEObject.h>
#include <FlameSteelEngineGameToolkit/Data/FSEGTGameData.h>

class BRCreditsFactory {
public:
    BRCreditsFactory();
    BRCreditsFactory(const BRCreditsFactory& orig);
    virtual ~BRCreditsFactory();
    
    void makeScene(shared_ptr<FSEGTGameData> gameData);
    
private:

};

#endif /* BRCREDITSFACTORY_H */

