/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PreRenderObjectsSorter.h
 * Author: demensdeum
 *
 * Created on March 21, 2017, 11:21 PM
 */

#ifndef PRERENDEROBJECTSSORTER_H
#define PRERENDEROBJECTSSORTER_H

#include <memory>

#include <FlameSteelEngineGameToolkit/Data/FSEGTGameData.h>

using namespace std;

class BRPreRendererObjectsSorter {
public:
    BRPreRendererObjectsSorter();
    BRPreRendererObjectsSorter(const BRPreRendererObjectsSorter& orig);
    virtual ~BRPreRendererObjectsSorter();
    
    void sort(shared_ptr<FSEGTGameData> gameData);
    
private:

};

#endif /* PRERENDEROBJECTSSORTER_H */

