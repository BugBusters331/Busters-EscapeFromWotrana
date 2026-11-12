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
    bool falling = false;
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
            first.printSlow("One has a bird resting on it, another has a squirrel, and the last one has nothing on it but the branch itself is really big and even has a cool pattern on it. Will you choose the...", speed);
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
                    first.printSlow("There's nothing you can do with the acorn right now.", speed);
                }
            }
            else if (choice1 == "ROCK") {
                if (!hasRock) {
                    first.printSlow("You pick up the rock. Could be useful?", speed);
                    hasRock = true;
                }
                else {
                    first.printSlow("There's nothing you can do with the rock right now.", speed);
                }
            }
            else if (choice1 == "1") {
                branch = 2;
                first.printSlow("You hop over to the branch with the bird on it.", speed);
                first.printSlow("It flies away upon seeing you.", speed);
                first.dots(3, speed);
                first.printSlow("You are now alone on the branch, with no bird next to you.", speed);
                first.printSlow("Not that it really matters though. The bird doesn't do anything useful for you.", speed);
                if (hasRock) {
                    first.printSlow("You do still have that rock in your pocket, that you could throw at the bird.", speed);
                    first.printSlow("If there were 2 birds you could even kill them with 1 stone...", speed);
                    first.printSlow("But there's only 1 so what's the point?", speed);
                }
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
            else if (choice1 == "ACORN") {
                if (!hasAcorn) {
                    first.printSlow("You do not have an acorn.", speed);
                }
                else {
                    first.printSlow("There's nothing you can do with the acorn right now.", speed);
                }
            }
            else if (choice1 == "ROCK") {
                if (!hasRock) {
                    first.printSlow("You do not have a rock.", speed);
                }
                else {
                    first.printSlow("There's nothing you can do with the rock right now.", speed);
                }
            }
            else {
                cout << "Invalid Input." << endl;
            }
        }
        if (branch == 3) {
            first.printSlow("You are on the branch with the squirrel. It looks like it might be a little bit rabid.", speed);
            if (hasAcorn) {
                first.printSlow("The squirrel takes interest in your acorn.", speed);
                choice1 = first.prompt("Do you give it? (yes/no)");
                if (choice1 == "y") {
                    first.printSlow("You offer the acorn to the squirrel. It mistakes you for a threat and leaps onto your face, scratching and mauling you violently.", speed);
                    first.printSlow("You eventually manage to get the squirrel off of you, but then you slip and fall off the branch.", speed);
                    fails += 2;
                    branch = 5;
                }
                else if (choice1 == "n") {
                    first.printSlow("The squirrel gets mad and decides to take the acorn anyway. It lunges onto your leg, crawls into your pocket, and snatches the acorn.", speed);
                    hasAcorn = false;
                    if (hasRock) {
                        first.pause(500, speed);
                        first.printSlow("And it also takes the rock from your pocket too.", speed);
                        hasRock = false;
                    }
                    first.printSlow("The squirrel lets out a horrific screech at you before running away.", speed);
                    branch = 8;
                }
                else {
                    cout << "Invalid Input." << endl;
                }
            }
            else {
                first.prompt(stdPrompt);
                first.printSlow("Before you even have a chance to think about your next action, the squirrel angrily bites your leg and runs off.", speed);
                fails += 1;
                branch = 8;
            }
        }
        if (branch == 4) {
            first.printSlow("The head of the snake comes down to look at you standing on its body", speed);
            first.printSlow("This snake is absolutely going to attack you if you don't do something quick.", speed);
            choice1 = first.prompt(stdPrompt);
            if (falling) {
                first.printSlow("You're about to do whatever you just typed, but then you realize the snake actually isn't hostile.", speed);
                first.printSlow("It actually feels bad for you since the developers are trying to troll you so badly, so it decides to escort you to the ground peacefully.", speed);
                onTree = false;
            }
            else {
                if (choice1 == "ROCK" && hasRock) {
                    first.printSlow("You grab your rock and throw it at the snake.", speed);
                    first.printSlow("It hits right in the snake's head. The snake starts panicking and slithering its body around to get away, which causes you to fall off.", speed);
                    first.printSlow("But luckily you're able to land on another branch not too far below.", speed);
                }

                else if (choice1 == "ACORN" && hasAcorn) {
                    first.printSlow("You grab your acorn and throw it at the snake.", speed);
                    first.printSlow("The snake opens its mouth and eats the acorn whole. Then it bites into your side which hurts a lot.", speed);
                    first.printSlow("You wince in pain, then the snake pushes you off of its body, and you fall to another branch not too far below.", speed);
                    fails += 3;
                }
                else {
                    first.printSlow("That's not something you can do right now.", speed);
                    first.printSlow("Unfortunately you did not do something quick enough, and the snake bites into your side which hurts a lot.", speed);
                    first.printSlow("You wince in pain, then the snake pushes you off of its body, and you fall to another branch not too far below.", speed);
                    fails += 3;
                }
                branch = 9;
            }
        }
        if (branch == 5) {
            falling = true;
            bool stillFalling = true;
            first.printSlow("You are now in a state of free fall.", speed);
            first.printSlow("There is a branch getting closer as you fall that you could grab on to, but you have no idea how durable this one will be.", speed);
            choice1 = first.prompt("Do you want to try grabbing the branch? (yes/no)");
            if (choice1 == "y") {
                first.printSlow("You grab the branch and it snaps imediately too.", speed);
                first.printSlow("Tough luck, maybe the next one will be better.", speed);
            }
            else if (choice1 == "n") {
                first.printSlow("Yeah, maybe the next branch will be more promising.", speed);
            }
            else {
                first.printSlow("That was an invalid input... but it doesn't matter, the branch was gonna break anyway.", speed);
            }
            first.printSlow("You continue falling. You approach another branch you can grab and this one for sure looks durable enough.", speed);
            first.printSlow("Even with all the wind blowing in your face you can still see how sturdy this tree branch looks.", speed);
            first.printSlow("It's so big and it even has a cool pattern on it.", speed);
            first.printSlow("This shouldn't even be a choice, you should just grab the super cool branch. (yes/yes)", speed);
            choicePicked = false;
            while (!choicePicked) {
                choice1 = first.prompt(" ");
                if (choice1 == "y") {
                    first.printSlow("You grab onto the branch. And it moves a lot more than you think it should.", speed);
                    first.printSlow("You're startled by a sudden and loud hissing sound, realizing that this super cool tree branch you grabbed onto is actually a snake!", speed);
                    stillFalling = false;
                    branch = 4;
                    choicePicked = true;
                }
                else if (choice1 == "n") {
                    first.printSlow("okay. fine. guess you'll just keep falling.", speed);
                    choicePicked = true;
                }
                else {
                    cout << "Invalid Input, try again. (and when you do please choose yes!!!!)" << endl;
                }
            }
            if (stillFalling) {
                first.printSlow("You're about to slam into the ground in a very painful manner.", speed);
                first.printSlow("There's only one more branch you can grab before that happens.", speed);
                first.printSlow("Will you grab it? (yes/no)", speed);
                choicePicked = false;
                while (!choicePicked) {
                    choice1 = first.prompt(" ");
                    if (choice1 == "y") {
                        first.printSlow("You grab onto the branch. And it's good you did because otherwise you would've been very hurt.", speed);
                        choicePicked = true;
                    }
                    else if (choice1 == "n") {
                        first.printSlow("You fall all the way to the ground. The feeling of slamming into the dirt is really rough, but it could've been worse.", speed);
                        fails += 4;
                        onTree = false;
                        choicePicked = true;
                    }
                    else {
                        cout << "Invalid Input, try again." << endl;
                    }
                }
            }
        }
        if (branch == 6) {
            first.printSlow("The boring branches continue for a bit longer, until after a while something interesting finally happens.", speed);
            branch = 9;
        }
        if (branch == 8) {
            first.dots(3, speed);
            first.printSlow("That was strange. Regardless, there's nothing else of interest here, so you continue to the next branch.", speed);
            branch = 9;
        }
        if (branch == 9) {
            first.printSlow("You're almost at the bottom of the tree.", speed);
            first.printSlow("But one final obstacle stands in your way.", speed);
            first.printSlow("Somebody decided to place a large beartrap on the ground right where you would hop down.", speed);
            bool beartrap = true;
            first.printSlow("Perhaps there's something you could use to disarm the trap?", speed);
            choicePicked = false;
            while (!choicePicked) {
                choice1 = first.prompt("Type an item to use it or type GO to go ahead and jump to the ground.");
                if (choice1 == "ACORN") {
                    if (hasAcorn) {
                        first.printSlow("You toss the acorn into the trap, and it activates.", speed);
                        first.printSlow("Now you can jump down to the ground safely.", speed);
                        beartrap = false;
                        choicePicked = true;
                    }
                    else {
                        first.printSlow("You don't have an acorn right now.", speed);
                    }
                }
                else if (choice1 == "ROCK") {
                    if (hasRock) {
                        first.printSlow("You toss the rock into the trap, and it activates.", speed);
                        first.printSlow("Now you can jump down to the ground safely.", speed);
                        beartrap = false;
                        choicePicked = true;
                    }
                    else {
                        first.printSlow("You don't have a rock right now.", speed);
                    }
                }
                else if (choice1 == "GO") {
                    first.printSlow("You brace yourself and jump down to the ground, setting off the beartrap.", speed);
                    first.printSlow("Oddly enough it doesn't hurt as much as you though it would.", speed);
                    first.printSlow("...as in instead of completely tearing you in half it just hurts a lot.", speed);
                    fails += 3;
                    choicePicked = true;
                    if (!hasAcorn && !hasRock) {
                        first.printSlow("Perhaps you should've picked up something along your way down the tree.", speed);
                    }
                }

            }
            onTree = false;
        }
    }
    first.printSlow("At last, you've made it to the ground safely.", speed);
    if (fails > 0) {
        first.printSlow("Well, safely might be a stretch. You did take damage on your way down.", speed);
        if (fails < 2) {
            first.printSlow("Luckily you only made one small slip up, so your HP is at a comfortable 90.", speed);
            player.setPlayerHealth(90);
        }
        else if (fails < 3) {
            first.printSlow("The damage wasn't too bad though, you're left with a solid 75 HP.", speed);
            player.setPlayerHealth(75);
        }
        else if (fails < 5) {
            first.printSlow("You got hurt quite a bit, but your HP is still at a decent 60.", speed);
            player.setPlayerHealth(60);
        }
        else if (fails < 7) {
            first.printSlow("You suffered quite a lot fo hits, bringing your HP down to 45.", speed);
            player.setPlayerHealth(45);
        }
        else {
            first.printSlow("A lot of damage in fact. It was really bad, you only have 30 HP left.", speed);
            player.setPlayerHealth(30);
        }
    }
    first.printSlow("You can now finally traverse Wotrana's surface and get to work on reapiring your ship.", speed);
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
    if (text == "engine" || text == "ENGINE") {
        text = "ENGINE";
    }
    if (text == "screw" || text == "screws" || text == "SCREW" || text == "SCREWS") {
        text = "SCREWS";
    }
    if (text == "strap" || text == "straps" || text == "STRAP" || text == "STRAPS") {
        text = "STRAPS";
    }
    if (text == "branch" || text == "BRANCH") {
        text = "BRANCH";
    }
    if (text == "rock" || text == "ROCK") {
        text = "ROCK";
    }
    if (text == "acorn" || text == "ACORN") {
        text = "ACORN";
    }
    if (text == "drill" || text == "DRILL") {
        text = "DRILL";
    }
    return text;
}