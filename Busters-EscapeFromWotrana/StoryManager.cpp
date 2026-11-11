#include "StoryManager.h"
#include <iostream>
using namespace std;

// Add this file to your C++ project.
// Keep your existing StoryManager.cpp for dialogue method definitions.
StoryManager::StoryManager(Player& player)
    : player(player), lyre("Lyre", 100, 12, 15) {}

void StoryManager::startStory() {
    player.setPlayerName("Captain");
    player.setPlayerHealth(100);
    player.setPlayerDamage(12);
    player.setPlayerArmor(15);
    speed = first.speedChoice();
    openingScene();
    firstCrash();
}

void StoryManager::introDialogue() {
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
    choicePicked = false;
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
        engineRepair();
    }
    first.pause(500, speed);
}

void StoryManager::engineRepair() {
    first.printSlow("You take a look at the ENGINE. It appears to be missing a couple of screws.", speed);
    first.printSlow("You then look down and see the SCREWS laying on the floor.", speed);
    bool engineFixed = false;
    string interaction = "none";
    bool hasScrews = false;
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

void StoryManager::lyreIntro() {
    first.printSlow("You then receive a call on your comms panel.On the other end is your totally trustworthy and loyal recruit, Lyre, flying near you in his own ship, calling you to ask about the planet Wotrana.", speed);
    first.printSlow("Lyre: Yo Captain! Isn't that the planet with the super valuable crystals over there?", speed);
    first.printSlow("You: Yeah? What about it?", speed);
    first.printSlow("Lyre: I hear those crystals are worth a fortune! Why don't we ditch this silly mission and go treasure hunting?", speed);
    first.printSlow("How do you respond?", speed);
    first.printSlow("1: Yeah! You and I can be the richest people in the galaxy!", speed);
    first.printSlow("2: No, we need to focus on our job.", speed);
    choicePicked = false;
    while (choicePicked == false) {
        choice1 = first.prompt("");
        if (choice1 == "1") {
            first.printSlow("Lyre: Heheh, right... you... *and* me...", speed);
            choicePicked = true;
        }
        else if (choice1 == "2") {
            first.printSlow("Lyre: Ugh, you're such a buzzkill! Y'know what screw this! ", speed);
            choicePicked = true;
        }
        else
        {
            cout << "Invalid Input, try again" << endl;
        }
    }
    first.printSlow("Lyre's ship slows down a little, and positions itself behind yours.", speed);
    first.printSlow("You: Lyre, what are you doing?", speed);
    first.printSlow("Lyre: I'm done following your dumb commands! I'll just go get those crystals myself, and you can't stand in my way!", speed);
    first.printSlow("What will you do?", speed);
    first.printSlow("1: Try to stop him", speed);
    first.printSlow("2: Let him go.", speed);
    choicePicked = false;
    while (choicePicked == false) {
        choice1 = first.prompt("");
        if (choice1 == "1") {
            first.printSlow("You turn your ship around to chase after Lyre. Once your ship is turned, you're met with Lyre's ship directly facing yours, with the laser guns charging up. ", speed);
            first.printSlow("You are caught off guard but quickly swerve your ship to the side, just narrowly avoiding the laser shots. ", speed);
            first.printSlow("Lyre: Dang it! I almost had ya!", speed);
            player.setPlayerHealth(100);
            choicePicked = true;
        }
        else if (choice1 == "2") {
            first.printSlow("You decide you've had enough of Lyre too and let him leave.", speed);
            first.printSlow("But then out of nowhere, the back of your ship is shot repeatedly by laser bullets, heavily damaging your shields.", speed);
            first.printSlow("Lyre: Haha! Take that you pathetic excuse of a captain!", speed);
            player.setPlayerHealth(50);
            choicePicked = true;
        }
        else
        {
            cout << "Invalid Input, try again" << endl;
        }
    }
    first.printSlow("Turns out Lyre's not just gonna leave you alone, he wants you dead!", speed);
    first.printSlow("You: What the heck! What's wrong with you?!", speed);
    first.printSlow("Lyre: Can't let you go back and rat me out to the boss now, can I?", speed);
    battle.startBattle(player, lyre);
    battle.runBattle();
}


void StoryManager::lyreBattleEnd() {
    first.printSlow("Your shields have suffered too much damage, your ship begins to break apart and fall into Wotrana's atmosphere. ", speed);
    first.printSlow("Lyre: Sorry captain, it's nothing personal. Oh wait, no it totally is, haha!", speed);
    first.printSlow("Lyre's ship flies down to Wotrana's surface. And yours does too, but... well, in a much more intense and violent manner.", speed);
    first.printSlow("You quickly hit buttons on your ship's control panel, desperately trying to regain control of it or at least slow your descent, but it's too late, your control panel is totally busted.", speed);
    first.printSlow("And it gets worse. The ship's wings have snapped off, the battery has fallen out, and fuel is leaking as you descend. So really all you can do is pray.", speed);
    first.printSlow("The last thing you see before everything goes dark is a tree slamming into your ship.", speed);
    player.setPlayerHealth(100);
    first.dots(3, speed);
}

void StoryManager::openingScene() {
    introDialogue();
    lyreIntro();
    lyreBattleEnd();
}

void StoryManager::firstCrash() {

    first.printSlow("A few minutes later, you wake up.", speed);
    first.printSlow("Amazingly, you're not dead!", speed);
    first.printSlow("The shields of your ship took some heavy hits during the battle, but you came out of it mostly unscathed.", speed);
    first.printSlow("You turn your head to the left and see a tree branch has stabbed through your chair, frighteningly close to your neck.", speed);
    first.printSlow("You also feel like you're being pulled upward by gravity. You look up and down and see the ground above you and the sky below you.", speed);
    first.printSlow("It seems you are hanging upside down, suspended only by the straps of your chair.", speed);
    first.pause(500, speed);
    first.printSlow("You can unbuckle the STRAPS of your chair, but unless you grab onto a BRANCH you'd very quickly fall and get injured.", speed);
    choicePicked = false;
    bool holdBranch = false;
    bool onTree = true;
    while (choicePicked == false) {
        choice1 = first.prompt(stdPrompt);
        if (choice1 == "STRAPS") {
            first.printSlow("The strap unbuckles and gravity releases you to your doom...", speed);
            if (!holdBranch) {
                first.printSlow("You smack into numerous tree branches on your way down, each one feels like it hurts more than the last.", speed);
                first.printSlow("It's so bad that when you finally faceplant into the ground you're relieving.", speed);
                first.pause(500, speed);
                first.printSlow("You stumble your way up from the ground, severely injured.", speed);
                first.printSlow("All you had to do was grab onto that branch.", speed);
                first.printSlow("But now you've got bruises and scratches and splinters everywhere.", speed);
                player.setPlayerHealth(1);
                first.printSlow("You absolutely should be dead right now, but you've managed to scrape by with a measly 1 HP.", speed);
                first.pause(500, speed);
                first.printSlow("Just make sure you get a chance to heal ASAP.", speed);
                first.pause(500, speed);
                onTree = false;
            }
            else {
                first.printSlow("But your grip on the branch is tight, and you're safe from falling.", speed);
                first.printSlow("You plant your feet on a branch below you, then begin your descent down to the ground.", speed);
            }
            choicePicked = true;
        }
        else if (choice1 == "BRANCH") {
            if (!holdBranch) {
                first.printSlow("You grab onto the branch, preparing yourself to not fall upon unbuckling the STRAPS.", speed);
                holdBranch = true;
            }
            else {
                first.printSlow("You're already holding onto the branch.", speed);
                first.printSlow("Wouldn't want to let go now would you?", speed);
            }
            
        }
        else
        {
            cout << "That's not something you can interact with" << endl;
        }
    }
    first.printSlow(" ", speed);
    if (onTree) {
        climbMinigame();
    }
}

void StoryManager::climbMinigame() {
    int branch = 0;
    bool onTree = true;
    int fails = 0;
    bool hasRock = false;
    bool hasAcorn = false;
    first.printSlow("Since only your ship was hit by Lyre, your health is still perfectly at 100.", speed);
    first.printSlow("However if you're not careful you may take some damage on your way down the tree.", speed);
    first.pause(500, speed);
    while (onTree) {
        choicePicked = false;
        if (branch == 0) {
            first.printSlow("There are currently 2 branches you can jump to. A strong looking branch and a weak looking branch. Will you choose the...", speed);
            first.printSlow("1: Strong looking branch", speed);
            first.printSlow("2: Weak looking branch", speed);
            choice1 = first.prompt("");
            if (choice1 == "1") {
                branch = 1;
                first.printSlow("The strong looking branch lives up to its description, staying firmly in place not bothered at all by the weight of you standing on it.", speed);
            }
            else if (choice1 == "2") {
                branch = 5;
                first.printSlow("The weak looking branch lives up to its description. It snaps the moment you step onto it, causing you to fall.", speed);
            }
            else {
                cout << "Invalid Input." << endl;
            }
        }
        if (branch == 1) {
            first.printSlow("There are now 3 branches you can jump to. They all look the same in terms of sturdiness.", speed);
            first.printSlow("One has a bird resting on it, another has a squirrel, and the last one has nothing on it but the branch itself has a cool looking pattern. Will you choose the...", speed);
            first.printSlow("1: Branch with bird", speed);
            first.printSlow("2: Branch with squirrel", speed);
            first.printSlow("3: Patterned branch", speed);
            first.printSlow("...oh and also there's an ACORN and a ROCK laying next to your feet on the current branch.", speed);
            choice1 = first.prompt("");
            if (choice1 == "ACORN") {
                if (!hasAcorn) {
                    first.printSlow("You pick up the acorn. Could be useful?", speed);
                    hasAcorn = true;
                }
                else {
                    first.printSlow("There's nothing you can do with the acorn yet.", speed);
                }
            }
            else if (choice1 == "ROCK") {
                if (!hasRock) {
                    first.printSlow("You pick up the rock. Could be useful?", speed);
                    hasRock = true;
                }
                else {
                    first.printSlow("There's nothing you can do with the rock yet.", speed);
                }
            }
            else if (choice1 == "1") {
                branch = 2;
                first.printSlow("You hop over to the branch with the bird on it.", speed);
                first.printSlow("It flies away upon seeing you.", speed);
                first.dots(3, speed);
                first.printSlow("You are now alone on the branch, with no bird next to you.", speed);
                first.printSlow("Not that it really matters though. The bird doesn't do anything useful for you.", speed);
            }
            else if (choice1 == "2") {
                branch = 3;
                first.printSlow("You hop over to the branch with the squirrel on it.", speed);
            }
            else if (choice1 == "3") {
                branch = 4;
                first.printSlow("You hop onto the patterned branch, then hear a loud hiss.", speed);
                first.printSlow("It seems this patterned branch is actually the body of a large snake!", speed);
            }
            else {
                cout << "Invalid Input." << endl;
            }
        }
        if (branch == 2) {
            first.printSlow("There is a very convenient vine next to you that appears to lead all the way to the ground.", speed);
            first.printSlow("Or you can go to the next branch, with nothing particularly remarkable about it. Will you choose the...", speed);
            first.printSlow("1: Shortcut vine", speed);
            first.printSlow("2: Unremarkable branch", speed);
            choice1 = first.prompt("");
            if (choice1 == "1") {
                first.printSlow("You grab onto the vine and start sliding down.", speed);
                first.printSlow("You then start feeling painful pokes in your hands.", speed);
                first.printSlow("Apparently this vine has thorns on it. A lot of them.", speed);
                first.printSlow("You still make it to the ground safely, but your hands are sore.", speed);
                onTree = false;
                fails += 1;
            }
            else if (choice1 == "2") {
                branch = 6;
                first.printSlow("You feel disappointed missing out on the chance to go down the super convenient vine.", speed);
                first.printSlow("But at least this branch seems fine.", speed);
            }
            else {
                cout << "Invalid Input." << endl;
            }
        }
        if (branch == 3) {
            first.printSlow("You are on the branch with the squirrel.", speed);
            if (hasAcorn) {
                first.printSlow("The squirrel seems interested in your acorn.", speed);
                choice1 = first.prompt("Do you give it? (yes/no)", speed);
                if (choice1 == "y") {
                    first.printSlow("You offer the acorn to the squirrel. It mistakes you for a threat and leaps onto your face, scratching and mauling you violently.", speed);
                    
                }
                else if (choice1 == "n") {
                    first.printSlow("The squirrel gets mad and decides to take the acorn anyway. It lunges onto your leg, crawls into your pocket, and snatches the acorn.", speed);
                    hasAcorn = false;
                    if (hasRock) {
                        first.pause(500, speed);
                        first.printSlow("And it also takes the rock from your pocket too for some reason.", speed);
                        hasRock = false;
                    }
                    


                }
                else {
                    cout << "Invalid Input." << endl;
                }
            }
        }





    }
}

// Dialogue class implementation

int dialogue::speedChoice() {
    string sampleLine = "Text can appear slowly (like it's doing now) to add to the experience.";
    printSlow(sampleLine, 1);
    string ask = "Press 1 for normal text, press 2 for fast text, press 3 for instant text";
    bool speedChosen = false;
    while (!speedChosen) {
        string speed = prompt(ask);
        if (speed == "1") {
            return 1;
        }
        else if (speed == "2") {
            return 3;
        }
        else if (speed == "3") {
            return 1000;
        }
        else {
            cout << "Invalid input. ";
        }
    }

}

void dialogue::print(string text) {
    cout << text;
    cout << endl;
}

void dialogue::printSlow(string text, int speed) {
    auto tp = chrono::steady_clock::now();
    for (char letter : text) {
        cout << letter << std::flush;
        tp += std::chrono::milliseconds(50 / speed);
        std::this_thread::sleep_until(tp);
    }
    tp += std::chrono::milliseconds(500 / speed);
    std::this_thread::sleep_until(tp);
    cout << endl;
}

void dialogue::pause(int pauseTime, int speed) {
    auto tp = chrono::steady_clock::now();
    tp += std::chrono::milliseconds(pauseTime / speed);
    std::this_thread::sleep_until(tp);
}

void dialogue::dots(int dots, int speed) {
    auto tp = chrono::steady_clock::now();
    for (int i = 0; i < dots; i++) {
        cout << ". " << std::flush;
        tp += std::chrono::milliseconds(500 / speed);
        std::this_thread::sleep_until(tp);
    }
    tp += std::chrono::milliseconds(500 / speed);
    std::this_thread::sleep_until(tp);
    cout << endl;
}

string dialogue::prompt(string text) {
    cout << text << endl;
    string choice;
    cin >> choice;
    string parsOut = pars(choice);
    return parsOut;
}

string dialogue::pars(string text) {
    if (text == "y" || text == "yes" || text == "Y" || text == "YES") {
        text = "y";
    }
    if (text == "n" || text == "no" || text == "N" || text == "NO") {
        text = "n";
    }
    return text;
}