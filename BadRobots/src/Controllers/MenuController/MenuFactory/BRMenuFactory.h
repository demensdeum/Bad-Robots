/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRMenuFactory.h
 * Author: demensdeum
 *
 * Created on March 23, 2017, 9:10 PM
 */

#ifndef BRMENUFACTORY_H
#define BRMENUFACTORY_H

#include <FlameSteelEngineGameToolkit/Data/FSEGTGameData.h>

#include <memory>

using namespace std;

class BRMenuFactory {
public:
    BRMenuFactory();
    BRMenuFactory(const BRMenuFactory& orig);
    virtual ~BRMenuFactory();
    
    void makeScene(shared_ptr<FSEGTGameData> gameData);
    
private:

};

#endif /* BRMENUFACTORY_H */

