// This #include statement was automatically added by the Particle IDE.
#include <InternetButton.h>





#include "InternetButton.h"
#include "math.h"
InternetButton b = InternetButton();


// Global variables to store how many lights should be turned on
int option = 1;
bool lights= false;

void setup() {

    // 1. Setup the Internet Button
    b.begin();


    Particle.function("animalsVsFruits", Button);



}

void loop(){

    // This loop just sits here and waits for the numLightsChanged variable to change to true
    // Once it changes to true, run the activateLEDS() function.
    if(lights == true){

        activateLEDS();

        lights = false;
    }
}

 void activateLEDS(){



   if(option== 0){

        b.allLedsOn(0,255, 0);
    }

   if(option == 1){

         b.allLedsOn(255, 0, 0);
    }
 }

 int Button(String command){
    //parse the string into an integer
    int Correct = atoi(command.c_str());


    // If no errors, then set the global variable to numLights
    option = Correct;

    lights = true;

    // In embedded programming, "return 1" means that
    // the function finished successfully
    return 1;
}
