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
                                first.printSlow("The engine starts to stabilize and cool down. You wipe a bit of sweat off your head, then return to the cockpit.", speed);
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
        first.pause(500, speed)
        first.printSlow("You then receive a call on your comms panel.On the other end is your totally trustworthy and loyal recruit, Lyre, flying near you in his own ship, calling you to ask about the planet Wotrana.", speed);
        first.printSlow("Lyre: Yo Captain! Isn't that the planet with the super valuable crystals over there?", speed);
        first.printSlow("You: Yeah? What about it?", speed);
        first.printSlow("Lyre: I hear those crystals are worth a fortune! Why don’t we ditch this silly mission and go treasure hunting?", speed);
        first.printSlow("How do you respond?", speed);
        first.printSlow("1: Yeah! You and I can be the richest people in the galaxy!", speed);
        first.printSlow("2: No, we need to focus on our job.", speed);
        first.prompt("");
        if (choice == "1") {
            first.printSlow("Lyre: Heheh, right... you... *and* me...", speed);
        }
        else if (choice == "2") {
            first.printSlow("Lyre: Ugh, you’re such a buzzkill! Y’know what screw this! ", speed);
        }
        first.printSlow("Lyre’s ship slows down a little, and positions itself behind yours.", speed);
        first.printSlow("You: Lyre, what are you doing?", speed);
        first.printSlow("Lyre: I’m done following your dumb commands! I’ll just go get those crystals myself, and you can’t stand in my way!", speed);
        first.printSlow("What will you do?", speed);
        first.printSlow("1: Try to stop him", speed);
        first.printSlow("2: Let him go.", speed);
        first.prompt("");
        if (choice == "1") {
            first.printSlow("You turn your ship around to chase after Lyre. Once your ship is turned, you’re met with Lyre’s ship directly facing yours, with the laser guns charging up. ", speed);
            first.printSlow("You are caught off guard but quickly swerve your ship to the side, just narrowly avoiding the laser shots. ", speed);
            first.printSlow("Lyre: Dang it! I almost had ya!", speed);
            int playerHealth = 100;
        }
        else if (choice == "2") {
            first.printSlow("You decide you’ve had enough of Lyre too and let him leave.", speed);
            first.printSlow("But then out of nowhere, the back of your ship is shot repeatedly by laser bullets, heavily damaging your shields.", speed);
            first.printSlow("Lyre: Haha! Take that you pathetic excuse of a captain!", speed);
            int playerHealth = 50;
        }
        first.printSlow("Turns out Lyre’s not just gonna leave you alone, he wants you dead!", speed);
        first.printSlow("You: What the heck! What’s wrong with you?!", speed);
        first.printSlow("Lyre: Can’t let you go back and rat me out to the boss now, can I?", speed);







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