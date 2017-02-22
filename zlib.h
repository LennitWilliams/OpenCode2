
/*
Zlib - Norman Advanced Robotics Movement Funtions
Version: 0.1
By:Zachary Sasser


Stuff to know:
-Declare variables before using the library.
-I use millimeters for everything.
-I use seconds as my unit of time.
-Don't touch things you don't know what they do.

Developers Notes:
-I don't make mistakes therefore there are no bugs YOU FOOL
-Make sure that the movement functions can handle themselves with floats, round them if we have to(test on a robot).
*/

//IMPORTS (smuggling them illegals, don't tell trump...)
import <stdio.h>
import <math.h>
import <thread.h>

Making my threads, DONT TOUCH EM'
thread one;
thread two;


//VARIABLES:

//YOU MUST CALL THESE VARIABLES IN YOUR PROGRAM IF YOU DON'T WANT THE DEFAULT
//Just call the variable like normal like:
//position = {1,2}

//Motor 1 {port #, Ticks per rotation}
int leftMotor[2] = {0,1800};

//Motor 2 {port #, Ticks per rotation}
int rightMotor[2] = {0,1800};

//Current Position of the Bot
float position[2] = {0,0};

//The diameter of the wheels
float wheelDiameter = 20; 

//The distance between the two wheels ( Should work even if the wheels aren't parralel ) 
float wheelSeperation = 50;

//Circumference of Wheel (automatically decided based on radius of wheel)
float circumference = (wheelDiameter/2)*3.14159*2;

//Whether to print debug messages
int debugger = 1;

//FUNCTIONS:

//Moves forward a distance in millimeters
int forward(float distance,float time){
	one.join(mrp, leftMotor[0], ((distance/time)/circumference)*leftMotor[1], (distance/circumference)*leftMotor[1]);
	two.join(mrp, rightMotor[0], ((distance/time)/circumference)*rightMotor[1], (distance/circumference)*rightMotor[1]);
	msleep(time*1000);
	if(debugger==1){
		printf("Moved forward %d millimeters MASTER!!!", distance);
	}
}

//Rotates the wheels a specified angle
int rotateWheel(int angle,float time){
	one.join(mrp, leftMotor[0], angle*leftMotor[1]/360, angle*leftMotor[1]/(time*360));
	two.join(mrp, rightMotor[0], angle*rightMotor[1]/360, angle*leftMotor[1]/(time*360));
	msleep(time*1000)
	if(debugger==1){
		printf("Rotated wheels %d degrees. Have I paid my debt to you yet master?", angle);
	}
}

//Rotates the bot a certain amount.
int rotate(int angle, float time){
	one.join(rotateWheel, 3.14159*angle*wheelSeperation*leftMotor[1]/(360*circumference), time);
	two.join(rotateWheel, 3.14159*angle*wheelSeperation*rightMotor[1]/(360*circumference), time);
	if(debugger==1){
		printf("Rotated the bot %d degrees int %f", angle, time);
	}
}

//Moves to a specific coordinate.
//The default starting coordinate is (0,0) when you start the program.
int move(int x, int y, float time){
	rotate(arctan(y/x), arctan(y/x));
	forward(pow(pow(x,2)+pow(y,2),0.5), pow(pow(x,2)+pow(y,2),0.5)/time);
	if(debugger==1){
		printf("We moved to a X of %d and a Y of %d . Can I come out of my cage now?", x, y);
	}
}

//Converts Ticks to millimeters
//Please note: this uses your declared variables for calculation
//Make sure motor is a string
int convertToMillimeter(int ticks, char motor){
	if(motor == "left" || motor == "l" || motor == "L" || motor == "antiradial"){
	 	return (ticks/leftMotor[1])*circumference;
	}
	else if(motor == "right" || motor == "r" || motor == "R" || motor == "radial"){
		return (ticks/rightMotor[1])*circumference;
	}
	else{
		printf("input a real motor silly master!");
	}
}

//Converts Millimeters to Ticks
//Please note: this uses your declared variables for calculation
//Make sure motor is a string
int convertToTicks(int millimeters, char motor){
	if(motor == "left" || motor == "l" || motor == "L" || motor == "antiradial"){
	 	return (millimeters/circumference)*leftMotor[1];
	}
	else if(motor == "right" || motor == "r" || motor == "R" || motor == "radial"){
		return (millimeters/circumference)*rightMotor[1];
	}
	else{
		printf("input a real motor silly master!");
	}
}

//Welcome Message Creator



