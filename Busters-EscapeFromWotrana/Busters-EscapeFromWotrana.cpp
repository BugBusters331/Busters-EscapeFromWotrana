#include "GameManager.h"
#include "StoryManager.h"
#include "BattleManager.h"
#include "MainMenu.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;


int main() {

    // TEMPORARY BATTLE TEST
    Player player;
    player.setPlayerName("Captain");
    player.setPlayerHealth(100);

    Enemy lyre("Lyre", 100, 12);

    BattleManager battle;
    battle.startBattle(player, lyre);

    while (battle.isBattleActive()) {
        cout << "\nPress Enter to attack...";
        cin.get();

        int damage = battle.playerAttack();

        cout << "Damage dealt: " << damage << endl;
    }

    cout << "\nBattle test complete!" << endl;

    return 0;

    // Existing main menu code below
}


/*int main(){

    mainMenu menu;
    int choice;

    menu.displayMenu();
    choice = menu.getuserChoice();

    if (choice == 1) {


        cout << "Game In Progress" << endl;
        dialogue first;
        string line1 = "It's been a long day of traveling through space, hasn't it?";
        string line2 = "Your ship's practically out of fuel, gonna have to take care of that soon.";
        string line3 = "And these missions aren't getting any easier either.";
        string line4 = "Being the reasonably tired space captain you are, you sit back in your cockpit chair and gaze outside the ship.";
        string line5 = "The endless expanse of outer space is truly a sight to behold.";
        string line6 = "A few planets are visible, like Wotrana--the crystal planet--to your left,";
        string line7 = "but for the most part, the empty black void is decorated with stars.";
        string line8 = "You've always loved the way the stars shimmer in the distance, so far away yet their warmth feels so close.";
        string line9 = "Oh wait, that's not the stars. That's just the engine overheating again.";
        string line10 = "Well, common sense says you should go handle that, but this is the third time this week that the engine's been acting up.";
        string prompt1 = "Do you feel like fixing the engine? (yes/no)";
        string line11 = "Good choice, you make your way to the Engine Room to take a look.";
        string line11A = "Yeah, you've got better things to do. Surely this won't blow up in your face later.";
        string engineLine1 = "You take a look at the ENGINE. It appears to be missing a couple of screws.";
        string engineLine2 = "You then look down and see the SCREWS laying on the floor.";
        string engineLine3 = "(Items labeled in ALL CAPS can be interacted with. Try interacting with the screws by typing SCREWS.)";
        string standardPrompt = "What will you do?";

        first.printSlow(line1);
        first.printSlow(line2);
        first.printSlow(line3);
        first.printSlow(line4);
        first.pause(1000);
        first.printSlow(line5);
        first.printSlow(line6);
        first.printSlow(line7);
        first.printSlow(line8);
        first.dots(3);
        first.printSlow(line9);
        first.pause(1000);
        first.printSlow(line10);
        string choice1;
        bool choicePicked = false;
        while (choicePicked == false) {
            choice1 = first.prompt(prompt1);
            if (choice1 == "yes" || choice1 == "y") {
                first.printSlow(line11);
                choicePicked = true;
            }
            else if (choice1 == "no" || choice1 == "n") {
                first.printSlow(line11A);
                choicePicked = true;
            }
            else
            {
                cout << "Invalid Input, try again" << endl;
            }
        }
        if (choice1 == "yes" || choice1 == "y") {
            first.printSlow(engineLine1);
            first.printSlow(engineLine2);
            bool engineFixed = false;
            string interaction = "none";
            bool hasScrews = false;
            bool hasDrill = false;
            first.printSlow(engineLine3);
            while (engineFixed == false) {
                interaction = first.prompt(standardPrompt);
                if (interaction == "SCREWS") {
                    if (!hasScrews) {
                        string screwLine = "You pick up the screws. Now you can place them in the ENGINE by interacting with it.";
                        first.printSlow(screwLine);
                        hasScrews = true;
                    }
                    else {
                        string screwLine = "You have the screws in your hand. You can place them in the ENGINE by interacting with it.";
                        first.printSlow(screwLine);
                    }
                }
                else if (interaction == "ENGINE") {
                    if (!hasScrews) {
                        string engineFail = "Yup. That's the engine. But you don't have the screws to put in yet, they're on the floor.";
                        first.printSlow(engineFail);
                    }
                    else {
                        string engineFix = "The engine is missing some screws, which you're holding in your hand.";
                        string fixChoice = "Do you wish to put the screws back in their spots? (yes/no)";
                        first.printSlow(engineFix);
                        choicePicked = false;
                        while (choicePicked == false) {
                            string choice2 = first.prompt(fixChoice);
                            if (choice2 == "yes" || choice2 == "y") {
                                string fixLine1 = "You place a screw into an opening, and attempt to spin it with your hand, which isn't working very well.";
                                string fixLine2 = "It's at this moment you remember you had a DRILL on hand this whole time.";
                                first.printSlow(fixLine1);
                                first.printSlow(fixLine2);
                                hasDrill = true;
                                choicePicked = true;
                                bool choseDrill = false;
                                while (choseDrill == false) {
                                    string choice3 = first.prompt(standardPrompt);
                                    if (choice3 == "DRILL") {
                                        choseDrill = true;
                                    }
                                    else {
                                        string dumb = "Just type DRILL it's not that hard";
                                        first.printSlow(dumb);
                                    }
                                }
                                string finaly = "You smack your head with your hand, wondering why you didn't just use the drill to begin with, then drill the screws into place.";
                                first.printSlow(finaly);
                                engineFixed = true;
                            }
                            else if (choice2 == "no" || choice2 == "n") {
                                string why = "Odd choice but okay.";
                                first.printSlow(why);
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
    */