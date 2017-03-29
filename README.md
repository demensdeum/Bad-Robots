# badrobots
Bad Robots - arcade game for desktop and web

In action:
http://demensdeum.com/games/BadRobots/BadRobots.html

Build for Desktop:
1. Create FlameSteelProjects directory
2. Create FlameSteelFramework directory inside
3. Checkout BadRobots into FlameSteelProjects
4. Checkout FlameSteelEngine and FlameSteelGameToolkit into FlameSteelProjects directory
5. Inside BadRobots directory:

cmake .<br>
make

Build for Web:
1. First compile for Desktop
2. Install emsdk into ~/emsdk directory
3. Run ./2web.sh from BadRobots directory
