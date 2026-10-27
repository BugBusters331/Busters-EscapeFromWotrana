#include "GameManager.h"
#include "StoryManager.h"
#include "MainMenu.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

int main(){

    mainMenu menu;
    int choice;

    menu.displayMenu();
    choice = menu.getuserChoice();

    if (choice == 1) {


        cout << "Game In Progress" << endl;
        dialogue first;
        float speed = first.speedChoice();
        string stdPrompt = "What will you do?";

        first.printSlow("It's been a long day of traveling through space, hasn't it?", speed);
        first.printSlow("Your ship's practically out of fuel, gonna have to take care of that soon.", speed);
        first.printSlow("And these missions aren't getting any easier either.", speed);
        first.printSlow("Being the reasonably tired space captain you are, you sit back in your cockpit chair and gaze outside the ship.", speed);
        first.pause(1000, speed);
        first.printSlow("The endless expanse of outer space is truly a sight to behold.", speed);
        first.printSlow("A few planets are visible, like Wotrana--the crystal planet--to your left,", speed);
        first.printSlow("but for the most part, the empty black void is decorated with stars.", speed);
        first.printSlow("You've always loved the way the stars shimmer in the distance, so far away yet their warmth feels so close.", speed);
        first.dots(3, speed);
        first.printSlow("Oh wait, that's not the stars. That's just the engine overheating again.", speed);
        first.pause(1000, speed);
        first.printSlow("Well, common sense says you should go handle that, but this is the third time this week that the engine's been acting up.", speed);
        string choice1;
        bool choicePicked = false;
        while (choicePicked == false) {
            choice1 = first.prompt("Do you feel like fixing the engine? (yes/no)");
            if (choice1 == "y") {
                first.printSlow("Good choice, you make your way to the Engine Room to take a look.", speed);
                choicePicked = true;
            }
            else if (choice1 == "n") {
                first.printSlow("Yeah, you've got better things to do. Surely this won't blow up in your face later.", speed);
                choicePicked = true;
            }
            else
            {
                cout << "Invalid Input, try again" << endl;
            }
        }
        if (choice1 == "y") {
            first.printSlow("You take a look at the ENGINE. It appears to be missing a couple of screws.", speed);
            first.printSlow("You then look down and see the SCREWS laying on the floor.", speed);
            bool engineFixed = false;
            string interaction = "none";
            bool hasScrews = false;
            bool hasDrill = false;
            first.printSlow("(Items labeled in ALL CAPS can be interacted with. Try interacting with the screws by typing SCREWS.)", speed);
            while (engineFixed == false) {
                interaction = first.prompt(stdPrompt);
                if (interaction == "SCREWS") {
                    if (!hasScrews) {
                        first.printSlow("You pick up the screws. Now you can place them in the ENGINE by interacting with it.", speed);
                        hasScrews = true;
                    }
                    else {
                        first.printSlow("You have the screws in your hand. You can place them in the ENGINE by interacting with it.", speed);
                    }
                }
                else if (interaction == "ENGINE") {
                    if (!hasScrews) {
                        first.printSlow("Yup. That's the engine. But you don't have the screws to put in yet, they're on the floor.", speed);
                    }
                    else {
                        first.printSlow("The engine is missing some screws, which you're holding in your hand.", speed);
                        choicePicked = false;
                        while (choicePicked == false) {
                            string choice2 = first.prompt("Do you wish to put the screws back in their spots? (yes/no)");
                            if (choice2 == "y") {
                                first.printSlow("You place a screw into an opening, and attempt to spin it with your hand, which isn't working very well.", speed);
                                first.printSlow("It's at this moment you remember you had a DRILL on hand this whole time.", speed);
                                hasDrill = true;
                                choicePicked = true;
                                bool choseDrill = false;
                                while (choseDrill == false) {
                                    string choice3 = first.prompt(stdPrompt);
                                    if (choice3 == "DRILL") {
                                        choseDrill = true;
                                    }
                                    else {
                                        first.printSlow("Just type DRILL it's not that hard", speed);
                                    }
                                }
                                first.printSlow("You smack your head with your hand, wondering why you didn't just use the drill to begin with, then drill the screws into place.", speed);
                                engineFixed = true;
                            }
                            else if (choice2 == "n") {
                                first.printSlow("Odd choice but okay.", speed);
                                choicePicked = true;
                            }
                            else
                            {
                                cout << "Invalid Input, try again" << endl;
                            }
                        }

                    }
                }
                else {
                    cout << "That's not something you can interact with. Try Again" << endl;
                }
            }
        }

        cout << "Wow you made it!";



        GameManager game;

        game.startGame();
    }

    else if (choice == 2)
    {
        menu.displayUserManual();
    }
    else if (choice == 3)
    {
        cout << "Goodbye!" << endl;
        return 0;
    }

	return 0;
}