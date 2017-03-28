/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRGameOverFactory.h
 * Author: demensdeum
 *
 * Created on March 23, 2017, 10:42 PM
 */

#ifndef BRGAMEOVERFACTORY_H
#define BRGAMEOVERFACTORY_H

#include <FlameSteelEngineGameToolkit/Data/FSEGTGameData.h>
#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>

#include <memory>

using namespace std;

class BRGameOverFactory: public FSEGTController {
public:
    BRGameOverFactory();
    BRGameOverFactory(const BRGameOverFactory& orig);
    virtual ~BRGameOverFactory();
    
    void makeScene(shared_ptr<FSEGTGameData> gameData, int score);
    
private:

};

#endif /* BRGAMEOVERFACTORY_H */

