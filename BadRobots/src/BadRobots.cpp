/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BadRobots.cpp
 * Author: demensdeum
 * 
 * Created on March 8, 2017, 8:07 AM
 */

#include <iostream>

#include <BadRobots/src/Const/BRConst.h>
#include <BadRobots/src/Controllers/GameController/BRGameController.h>

using namespace std;

int main() {

	cout << "Bad Robots, bad bad robots, very bad." << endl;

        auto controller = shared_ptr<BRGameController>(new BRGameController());
        controller->startGameFromState(BRStateIngame);
        
	return 0;
}
