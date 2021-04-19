/***************************
Author: Stephanie Benamati (Catlett)
Date: 11/29/2019
Description:
***************************/
#include "Museum.hpp"
#include "Menu.hpp"
#include "getNum.hpp"
#include "Game.hpp"
#include <iostream>
/************
 * default constructor
 * *********/
Museum::Museum(){}

/*********
 * constructor
 * ******/
Museum::Museum(int num)
{
	gotStatue=false;
	roomNum=num;
}
/*********
 * default destructor
 * ******/
Museum::~Museum(){}

/***********
 *setTop
 *links room to another on top of it
 * *********/
void Museum::setTop(Space* t)
{
	top=t;
}

/***********
 *setBottom
 *links room to another below it
 * *********/
void Museum::setBottom(Space* b)
{
	bottom=b;
}

/***********
 *setLeft
 *links room to another to the left of it
 * *********/
void Museum::setLeft(Space* l)
{
	left=l;
}

/***********
 *setRight
 *links room to another to the right of it
 * *********/
void Museum::setRight(Space* r)
{
	right=r;
}

/***********
 * describe room
 * prints initial description of room
 * *********/
void Museum::describeRoom()
{	
	Menu menu;
	switch(roomNum)
	{
		case 4: //visitors entrance
			break;
		case 5: //security office
			menu.message("The room is dimly lit with the blinking lights of machinery and computer screens.\nYou close the door quietly behind you and pray there isn't a guard on duty at the moment.\nYou take a moment, however, to make sure all of the doors around you are unlocked, in case you need to move more freely later.");
			std::cout << "\nTo the north is a door with a sign above it that says 'Visitor Entrace'.\n"
				<< "To the south is a desk with an old, boxy computer monitor and a clunky computer tower.\n"
				<< "To the west is the door back to the courtyard.\n"	
				<< "To the east is  a door with a sign above it that says 'Exhibit 2-Paintings'\n";
			break;
		case 6: //paintings room
			menu.message("The temperature drops appreciably as you enter the room filled with the scent of old oil paints.\nYou figure it's to preserve the integrity of the painting, or something like that.\nMany of the paintings are displayed behind ropes, though a select few are sealed in glass boxes with security triggers.\nSome parts of the exhibit look like they aren't ready for viewing yet, as they are covered by curtains or tarps.");
			std::cout << "\nTo the north is an open doorway with a banner designating it the 'Historical Artifacts' exhibit.\n"
				<< "To the south are some curtains and tarps, used to hide that section of the room from view.\n"
				<< "To the west is the security office.\n"	
				<< "To the east are some paintings on a wall.\n";

			break;
		case 7: //artifacts room
			menu.message("You enter the room showing 'Pieces of History' and raise your eyebrows at some of the items on display.\nThere are indeed things you would expect to be in a museum, such as native american arrowheads or stone jewelry from Greece... but a Motorola Flip Phone??\n	'A Nintendo64 and a Walkman are NOT historical artifacts!' you hiss angrily.\nYou can practically hear someone from Gen-Z laugh in the distance.");
			std::cout << "\nTo the north is some sort of information kiosk. It looks like it's meant to be manned by an employee.\n"
				<< "To the south is an open passageway with an arrow labeled 'Paintings'.\n"
				<< "To the west is the visitor entrance.\n"	
				<< "To the east is a hallway with posters naming it the 'Sculpture Exhibit'.\n";

			break;
		case 8: //sculpture room + guard
			break;
	}
}

/************
 * explore
 * gives descriptions of when the player explores the room. returns new space when they leave to another room
 * *********/
Player* Museum::explore(Player* user)
{
	Menu menu;
	int direction=0;
	int leave=0;

	switch(roomNum)
		{
			case 4://visitor center
				if(user->checkBool(4))
				{
					menu.message("You shine your light over the room, taking in the informational displays.\nThere are currently several items in this building that could fetch a good price on the black market,\nbut you've done your reasearch and scoped out one in particular...\nA gem-encrusted statue found in some amazonian ruin (totally, definitely, not cursed or anything).\nYou wonder if this room might have any clues on how to get to it, as they move it frequently to avoid people like you finding it.");
					std::cout << "\nTo the north is a ticket purchasing booth. It looks like they have several informational pamphlets available for guests.\n"
						<< "To the south is the security room.\n"
						<< "To the west is the way back to the courtyard.\n"	
						<< "To the east is an exhibit with a sign that reads 'Pieces of History'\n";

				}
				else
				{
					menu.message("As you walk through the door, you can hardly see anything. You're gonna need to find some way to brighten up the place!\nThe only thing you can clearly make out the backlit outline of a door to the south.");
					std::cout << "\nTo the north is darkness.\n"
						<< "To the south is a door with light filtering through the cracks.\n"
						<< "To the west is the way back to the courtyard.\n"	
						<< "To the east is darkness\n";
				}
				do
				{	
					if(!user->checkBool(4))
					{
						direction = menu.getNum("\nWhat would you like to do?\n   1-Move North (Darkness)\n   2-Move South (Backlit Door)\n   3-Move West (Courtyard)\n   4-Move East (Darkness)\n   5-GIVE UP",1,5);
					}
					else
					{
						direction = menu.getNum("\nWhat would you like to do?\n   1-Move North (Ticket Booth)\n   2-Move South (Security Office)\n   3-Move West (Courtyard)\n   4-Move East ('Pieces of History' Exhibit)\n   5-GIVE UP",1,5);
					}
					switch(direction)
					{
						case 1: //forward
							if(!user->checkBool(4))
							{
								menu.message("...really? You really want to move into the darkness when I told you you can't see anything?");
								int choice=menu.getNum("   1-Yes\n   2-No",1,2);
								if(choice==1)
								{
									menu.message("You walk and slam your knee into the edge of... something?\nYou don't know what it is, because you can't see sh*t.\nHappy now? *** -1 Courage for Bad Decisions ***");
									user->updateCourage(-1);
								}
							}
							else
							{
								menu.message("You walk up to the ticket window and snag an informational pamplet off the counter.\n\nCome see our uniquely jeweled Amazonian Statue!\n(Currently Displayed in the Statue/Sculpture Exhibit)\nFor a limited time only, see the fascinating work of this secretive tribe.\nUntil this upcoming October, this beautifully crafted work of art will\nbe in our possession before being passed on to\na Sister Museum in Europe.\n\n	'Huh... that was way easier than I expected'.\n\n");
							}
							if(top!=NULL && leave==1 && user->checkBool(4))
							{
								user->setCurrentRoom(top);
							}
							break;
						case 2: //backward
							if(!user->checkBool(2))//look to see if they grabbed bag at all
							{
								menu.message("You walk towards the faint outline and feel around for the doorknob.\nYou finally grab ahold of a handle and give it a firm twist, but its locked!\nYou don't have anything to unlock it right now, but you could've sworn you had something like that in your car at some point.");
							}
							else if(user->checkItem(2))//look for lockpick
							{
								int unlock=menu.getNum("You walk towards the faint outline and feel around for the doorknob.\nYou finally grab ahold of a handle and give it a firm twist, but its locked!\nUnlock it with your Lockpick?\n   1-Yes\n   2-No",1,2);
								if(unlock==1)
								{
									user->removeItem(2);
									user->displayItems();
									user->setAction(4);
									leave=menu.getNum("It's open! Unfortunately, trying to pick locks in near total darkness is not an easy task.\nYou've completely bent the poor fella out of shape. It's days of getting you into places that you shouldn't be are over.\nDon't let his sacrifice be in vain! Go inside?\n   1-Yes\n   2-No",1,2);
								
								}
								else
								{
									menu.message("You decide to leave the locked door alone for now.");
								}
								if(unlock==1 && leave==2)
								{
									menu.message("I just... dont understand you.");
								}
								
							}
							else if(user->checkAction(4))
							{
								leave=menu.getNum("You've already opened the doors to the security office.\nGo in?\n   1-Yes\n   2-No",1,2);
							}
							else
							{
								menu.message("You walk towards the faint outline and feel around for the doorknob.\nYou finally grab ahold of a handle and give it a firm twist, but its locked!\nYou've already broken your lockpick, so you have no way to unlock this. Perhaps you can open it if you go around?");
							}
							if(bottom!=NULL && leave==1)
							{
								user->setCurrentRoom(bottom);
							}
							break;
						case 3: //left 
							if(user->checkAction(2)) //if player picked up the rock and broke the door with it
							{
								leave=menu.getNum("You look out across the shards of glass, listening to the wailing sirens, and contemplate just cutting your losses and leaving this heist behind.\nYou close your eyes and take a deep breath, massaging your temples.\nThis is really not what you were planning when you initially came here.\nGo out to the courtyard?\n   1-Yes\n   2-No",1,2);
							}
							else if(user->checkAction(3))
							{
								leave=menu.getNum("You've already unlocked the doors when you left through here once before.\nGo out to the courtyard?\n   1-Yes\n   2-No",1,2);
							}	
							else
							{
							leave=menu.getNum("From the inside, opening up the visitor doors is a simple task. One twist of a deadbolt latch and it is unlocked!\n Go out into the courtyard?\n   1-Yes\n   2-No",1,2);							
								if(leave==1)
								{
									user->setAction(3);//set opend visitor to true
								}
							}
							if(left!=NULL && leave==1)
							{
								user->setCurrentRoom(left);
							}
							break;
						case 4: //right
							if(!user->checkBool(4))
							{
								menu.message("...really? You really want to move into the darkness when I told you you can't see anything?");
								int choice=menu.getNum("   1-Yes\n   2-No",1,2);
								if(choice==1)
								{
									menu.message("You walk and slam your knee into the edge of... something?\nYou don't know what it is, because you can't see sh*t.\nHappy now? *** -1 Courage for Bad Decisions ***");
									user->updateCourage(-1);
								}
							}
							else
							{
								leave=menu.getNum("A tall, graceful archway seems to invite you into the next exhibit space.\nAt a glace, you can see old pottery, baskets, clothing, and other day-to-day items on pedestals throughout the room.\nEnter the exhibit on 'Pieces of History?'\n  1-Yes\n   2-No",1,2);
							}
							if(right!=NULL && leave==1 && user->checkBool(4))
							{
								user->setCurrentRoom(right);
							}
							break;
						case 5://quits
							user->setCourage(0);
							break;
					}
				}while(leave!=1 && direction!=5);
				break;
			case 5: //security office
				user->setAction(4);
				do
				{
					direction = menu.getNum("\nWhat would you like to do?\n   1-Move North (Towards Visitor's Entrance)\n   2-Move South (Check Desk)\n   3-Move West (Towards Courtyard)\n   4-Move East (To 'Paintings' Exhibit)\n   5-GIVE UP",1,5);
					switch(direction)
					{
						case 1: //forward
							leave=menu.getNum("You prepare the leave the comforting glow of the security office for the darkened rooms in the museum.\nGo to visitor entrance?\n   1-Yes\n   2-No",1,2);
							if(top!=NULL && leave==1)
							{
								user->setCurrentRoom(top);
							}
							break;
						case 2: //backward
							menu.message("The desk is a made of a sturdy metal, with some parts of it rusted from age. \nIn addition to the ancient looking computer, it has a drawer on the right side.");
							interact(user);
							if(bottom!=NULL && leave==1)
							{
								user->setCurrentRoom(bottom);
							}
							break;
						case 3: //left 
							if(user->checkAction(1))
							{
								leave=menu.getNum("You wonder if there's something more you could get from exploring outside.\nReturn to Courtyard?\n   1-Yes\n   2-No",1,2);
							}
							if(user->checkAction(4))
							{
								menu.message("That door is locked with a chain... and there's no way to open it now that your lockpick is broken");
							}
							if(left!=NULL && leave==1)
							{
								user->setCurrentRoom(left);
							}
							break;
						case 4: //right
							if(user->checkBool(4))//if player took light
							{	
								leave=menu.getNum("The wall is made of white painted bricks, but is otherwise unadorned.\nUnless you count ingrained dust as adornment?\nYou prepare to leave the comforting glow of the security office for the darkened rooms in the musuem.\nGo to 'Paintings' Exhibit?\n   1-Yes\n   2-No",1,2);
							}
							else
							{
								menu.message("You open the door to the painting exhibit, but can't see anything. It's too dark.\nYou'll never find what you're looking for if you cant...well...see.\nYou decide to come back to it after you find a light source");
							}
							if(right!=NULL && leave==1)
							{
								user->setCurrentRoom(right);
							}
							break;
						case 5://quits
							user->setCourage(0);
							break;
					}
				}while(leave!=1 && direction!=5);
				break;
			case 6: //paintings room
				do
				{
					direction = menu.getNum("\nWhat would you like to do?\n   1-Move North (Toward 'Historical Artifacts' Exhibit)\n   2-Move South (Towards Tarps)\n   3-Move West (To security office)\n   4-Move East (To Hung Paintings)\n   5-GIVE UP",1,5);
					switch(direction)
					{
						case 1: //forward
							leave=menu.getNum("You walk up to the open doorway and peek your head around the frame.\nYou see various pedestals with what would have been everyday items in that time period.\nYou can make out the vague shapes of pottery, silverware, tapestries...\nGo in?\n   1-Yes\n   2-No",1,2);
							if(top!=NULL && leave==1)
							{
								user->setCurrentRoom(top);
							}
							break;
						case 2: //backward
							menu.message("You push aside the curtains and tarps to see frames of varying sizes leaned up against the wall.\nYou walk forward to see things from a different angle and your foot strikes something under a pile of cloth.\nYou quietly curse whoever placed this item here and lift the fabric...it's a safe with a 9 key pin on it!");
							interact(user);
							if(bottom!=NULL && leave==1)
							{
								user->setCurrentRoom(bottom);
							}
							break;
						case 3: //left 
							leave=menu.getNum("The area around the security door is devoid of paintings.\nIn the darkness, the blankness compared to the surrounding walls gives it an eerie feeling.\nGo inside?\n   1-Yes\n   2-No",1,2);
							if(left!=NULL && leave==1)
							{
								user->setCurrentRoom(left);
							}
							break;
						case 4: //right
							menu.message("Colorful abstracts, stunning impressionist work, and photo-realistic brushwork hang side by side.\nYou're not sure what the musuem was going for exactly when they made the plan for this room,\nbut it gives you the feeling of a sort of joyful chaos.\nIf you weren't planning on robbing the place blind, you'd love to come back and see these someday.");
							if(right!=NULL && leave==1)
							{
								user->setCurrentRoom(right);
							}
							break;
						case 5://quits
							user->setCourage(0);
							break;
					}
				}while(leave!=1 && direction!=5);
				break;
			case 7: //pieces of history
				do
				{
					direction = menu.getNum("\nWhat would you like to do?\n   1-Move North (Check the Kiosk)\n   2-Move South (Towards 'Paintings' Exhibit)\n   3-Move West (Towards Visitor's Entrance)\n   4-Move East (To 'Sculptures' Exhibit)\n   5-GIVE UP",1,5);
					switch(direction)
					{
						case 1: //forward
							interact(user);
							if(top!=NULL && leave==1)
							{
								user->setCurrentRoom(top);
							}
							break;
						case 2: //backward
							leave=menu.getNum("You slink over to the door separating the 'Paintings' exhibit from the 'Pieces of History' exhibit, simultaneously incredulous and bewildered.\n	'Anyone who puts a VHS TAPE in a MUSEUM deserves to be robbed' you huff.\nGo see paintings instead of being reminded of how old you are?\n   1-Yes\n   2-No",1,2);
							menu.intResult("Leave is currently: ",leave);
							if(bottom!=NULL && leave==1)
							{
								user->setCurrentRoom(bottom);
							}
							break;
						case 3: //left 
							leave=menu.getNum("You just can't believe they would do your boy StarFox like that!\n   'Classic does not mean ancient!' you grit, shaking your fist into the air.\nGo to the visitor entrance to escape the creeping feeling of aging and mortality?\n   1-Yes\n   2-No",1,2);
							if(left!=NULL && leave==1)
							{
								user->setCurrentRoom(left);
							}
							break;
						case 4: //right
							if(!user->checkItem(7))//if user doesn't have key, can't progress
							{
								menu.message("You can't just go in there without a clear way to access the statue. You need a key, or something!");
							}
							else
							{	
								if(user->checkAction(2)) //if player broke door
								{
									menu.message("You try to approach the threshhold cautiously, and as silently as you can manage.\nSeeing as the alarm is still wailing and you very uncerimoniously smashed the front doors with a rock...\nYeah... try is the optimal word here.");	
									leave=menu.getNum("Traverse the hallway to the Statue Exhibit? \n   1-Yes\n   2-No",1,2);				
								}
								else //if unlocked
								{
									menu.message("You try to approach the threshhold cautiously, and as silently as you can manage.\nYou don't think you've alerted any security to your presence so far...\nLet's see if your luck holds.");	
									leave=menu.getNum("Traverse the hallway to the Statue Exhibit? \n   1-Yes\n   2-No",1,2);	
								}	
							}
							if(right!=NULL && leave==1)
							{
								user->setCurrentRoom(right);
							}
							break;
						case 5://quits
							user->setCourage(0);
							break;
					}
				}while(leave!=1 && direction!=5);
				break;
			case 8: //statues and scupltures
				if(user->checkAction(2)) //if player broke door
				{
					menu.message("As you get closer and your vision adjusts further to the darkness, you notice an agitated guard.\nHe's holding his position by the center of the room, next to a prominent pedestal displaying a small figurine.\nHe is gripping a communication device tightly in his fist, and his other hand hovers over a can of mace.\nYou're not getting in without distracting him, or taking him out...");
				}
				else //if unlocked
				{
					menu.message("As you get closer and your vision adjusts further to the darkness, you notice a sleepy guard.\nHe's holding his position by the center of the room, next to a prominent pedestal displaying a small figurine.\nHowever, he appears unfocused as he lists slowly from side to side.\nIt doesn't seem like you can get closer to the statue without distracting him, or taking him out...");
				}	
				interact(user);
				if(user->checkAction(5))
				{
					direction = menu.getNum("\nWhat would you like to do?\n   1-GRAB STATUE\n   2-YOU GOTTA GRAB IT\n   3-TIMES RUNNING SHORT HERE\n   4-JUST. DOOOO ITTTT!\n   5-GIVE UP",1,5);
					if(direction!=5)
					{
						menu.message("You rush to the backside of the glass case that holds the shining carved sculpture.\nThe gems set into its stone surface gleam bright with the promise of wealth.\nYou stick the key into the lock and turn it, hearing the sweet click of an opening mechanism.\nThe glass panels seem to unfold before you like petals of a blooming flower, and you grab hold of your prize.");
						menu.message("You've done it! You've really managed it...but will it end up being worth the trouble?\nThis thing is...pretty ugly. Hopefully you'll find a buyer that appreciates an 'unconventional beauty'.\nI mean... if people think pugs are cute, there's gotta be someone out there who's into this gaudy statue. \n\n\nGetting out of the museum is a much simpler task than getting in was.\nYou rush directly to the exit, holding the artifact close to your chest under your jacket.\nYou escape into the night, and, with some luck, into a new life.");
						user->setAction(6);
					}
					else
					{
						menu.message("Wow. Quitting at the end here huh?\nLiterally... if you just grabbed it... you would've won.\nWhy are you like this?");
						user->setCourage(0);
					}
				}
				break;
		}
	return user;
}

/************
 * interact
 * when player finds space with object, lets them interact with the space
 * *********/
void Museum::interact(Player* p)
{
	Menu menu;
	int choice=0;
	int code=0;
	int fight=0;
	int lure=0;
	int hit=0;
	int kill=0;

	switch(roomNum)
	{
		case 4: //visitors entrance
			break;
		case 5: //security office
			do{
				choice=menu.getNum("   1-Leave the desk alone\n   2-Log into the Computer\n   3-Check Drawer",1,3);
				if(choice==1)
				{
					menu.message("You decide to leave it alone for now");
				}
				else if(choice==2)
				{
					menu.message("You sit down at the desk, and find a yellow sticky note attached to the side of the computer tower.\nIt has the login information for the computer! Classic rookie mistake.\nYou boot up the computer and log in... and wait... and wait...\nDang! How old is this thing!?\n...and wait... ...FINALLY!\nA security camera feed pops up on the screen and a pit forms in your stomach.\nThere is a guard stationed in a room nearby. It's hard to make out exactly where he is due to the darkness\n but it seems like he's surrounded by statues of some sort.\nHopefully you can lure him to another room if/when the time comes to go there.");
				}
				else if (choice==3 && !p->checkBool(4))
				{
					int item=menu.getNum("You open the drawer and shuffle through crumpled papers and candy wrappers.\nDid the guards use this thing as a garbage can?\nOop. Yeah. There's something wet and cold in here.\nGrab it?\n   1-Yes\n   2-No Way",1,2);
					if(item==1)
					{
						p->addItem(5);
						p->displayItems();
						p->setBool(4);	
						menu.message("You found a flashlight! It's dripping with some unknown substance... but useful is useful.\nYou flick the switch and it turns on, though the light is a bit dim.\nMaybe that will work in your favor, in this case though?");
					}
				}
				else
				{
					menu.message("You're not sticking your hand in there again.");
				}
			}while(choice!=1);
			break;
		case 6: //paintings
			if(p->checkItem(7))
			{
				menu.message("You return to the mess of cloths and painting frames, but you've already got the item in this area.");
			}
			else
			{
				do
				{
					choice=menu.getNum("   1-Leave the Safe Alone\n   2-Enter a Passcode",1,2);
					if(choice==2)
					{
						menu.message("ENTER YOUR 3 DIGIT PASSCODE _ _ _");
						code=getInt();
						if(code==721)
						{
							if(!p->checkBool(6))//if user didn't get code
							{
								menu.message("What are you... some kind of psychic?\nI know you don't have the password to this safe, CHEATER");
							}
							int key=menu.getNum("You enter the passcode and hear an audible click as the locking mechanism opens in the safe.\nInside, you find a small metal key...weird that's all they'd put in here, right?.\nTake the key?\n   1-Yes\n   2-No(But why would you choose no?)",1,2);
							if(key==1)
							{
								p->addItem(7);
								p->displayItems();
							}
							else
							{
								menu.message("*Sigh*. Fine. You leave it for some reason for later, I guess?\nYou re-lock the safe for...safe keeping? (Ba-dum tss)");
							}
						}
						else
						{
							menu.message("Nothing happens.");
						}
					}
				}while(choice!=1 && code!=721);
			}
			break;
		case 7: //historical items
			do
			{
				if(p->checkBool(6)) //if you got the code already
				{
					choice=menu.getNum("You've gotten everything you needed from the laptop, but maybe there was something else hidden here.\n   1-Nah, I'll take my chances\n   2-Investigate Further",1,2);
					if(choice==1)
					{
						menu.message("You decide to leave well enough alone.");
					}
					else
					{
						int folder=menu.getNum("After some more searching, you find a hidden folder titled \n'Dave's Secret Folder - DONT LOOK LISA ITS NOT YOUR BUSINESS'\nOpen it?\n   1-Yes\n   2-No",1,2);
						if (folder==1)
						{
							menu.message("Against your better judgement, you click twice on the icon and your eyes widen in shock.\nYou shut the laptop and shake your head, looking up towards the heavens.\n	'Why?' you whisper.\n");
						}
					}
				}
				else
				{
					choice=menu.getNum("You go to the backside of the kiosk and find an employee laptop connected to a shelf with a cut-proof cable.\nYou shrug and open it up, but it requires several modes of authentication before allowing you access.\n   1-Leave the computer alone\n   2-Use Hacking Module",1,2);
					if(choice==1)
					{
						menu.message("You decide to leave it alone for now.");
					}
					else
					{
						menu.message("You plug in your hacking module and it starts to spark and overheat immediately.\nMaybe you shouldn't have left this sensitive piece of hardware taped under your car for so long?\nYou worry it won't get the job done, but before your eyes a desktop appears!\nOh, and your module bursts into flames.");
						menu.message("You find an employee log listing the talking points for various items in the museum.\nIt also has extensive notes about the statue that you're looking for, as there are special security measures related to it.\nThe log mentions a lock box in the 'Paintings' Exhibit that holds the key for the statue display, in case it needs to be cleaned or moved.\n\n\nReading a bit further, you find the code! ***CODE - 721***\n\n");
						p->removeItem(3);//remove hacking module
						p->setBool(6);//add got code info
						p->addItem(6); //add combo code
						p->displayItems(); //display inventory
					}
				}
			}while(choice!=1);
			break;
		case 8: //statues
			do
			{
				fight=menu.getNum("Should you lure him away, or fight him? **NOTE: Once you choose to fight or lure the guard, you must finish the game**\n   1-Lure Options\n   2-Fight Options\n   3-Come back later",1,3);
				if(fight==1) //lure darts or rock
				{
					//1 = darts, 4=rock
					if(p->checkItem(1) && p->checkItem(4)) //if player has darts and rock
					{
						lure=menu.getNum("Lure Options:\n   1-Throw darts into other rooms\n   2-Throw rock into another room\n   3-See other options",1,3);
						switch(lure)
						{
							case 1: choice=menu.getNum("You strategically throw the darts in your posession in different areas of the museum, drawing the guard back towards the visitors entrance.\nYou manage to stay hidden behind a pedestal as he passes by you, but you're not going to have much time until he returns.\nGo for the statue?\n   1-Yes\n   2-Yes (C'mon. It's too late to turn back now.)",1,2);
								p->removeItem(1);//remove dart
								p->displayItems();
								p->setAction(5);//moved guard
								break;
							case 2:	choice=menu.getNum("You hurl the rock with suprising accuracy at one of the glass covered paintings in the paintings exhibit.\nThe glass shatters and the guard starts running.\nYou manage to stay hidden behind a pedestal as he passes by you, but you're not going to have much time until he returns.\nGo for the statue?\n   1-Yes\n   2-Yes(C'mon. It's too late to turn back now.)",1,2);
								p->removeItem(4);//remove rock
								p->displayItems();
								p->setAction(5);
								break;
							case 3: menu.message("You decide to consider other options first.");
								break;
						}
					}
					else if(p->checkItem(4) && !p->checkItem(1)) //player just has rock
					{
						lure=menu.getNum("Lure Option:\n   1-Throw rock into another room\n   2-See other options",1,2);
						if(lure==1)
						{
							choice=menu.getNum("You hurl the rock with suprising accuracy at one of the glass covered paintings in the paintings exhibit.\nThe glass shatters and the guard starts running.\nYou manage to stay hidden behind a pedestal as he passes by you, but you're not going to have much time until he returns.\nGo for the statue?\n   1-Yes\n   2-Yes(C'mon. It's too late to turn back now.)",1,2);
							p->removeItem(4);//remove rock
							p->displayItems();
							p->setAction(5);
						}
						else
						{
							menu.message("You decide to see other options first.");
						}
						}
					else if(p->checkItem(1) && !p->checkItem(4)) //player just has darts
					{
						lure=menu.getNum("Lure Option:\n   1-Throw darts into other rooms\n   2-See other options",1,2);
						if(lure==1)
						{
							choice=menu.getNum("You strategically throw the darts in your posession in different areas of the museum, drawing the guard back towards the visitors entrance.\nYou manage to stay hidden behind a pedestal as he passes by you, but you're not going to have much time until he returns.\nGo for the statue?\n   1-Yes\n   2-Yes (C'mon. It's too late to turn back now.)",1,2);
							p->removeItem(1);//remove dart
							p->displayItems();
							p->setAction(5);//moved guard
						}
						else
						{
							menu.message("You decide to consider some other choices first.");
						}	
					}
					else //doesn't have items for luring
					{
						menu.message("You have not picked up, or have already used, the items that could help you lure the guard away.");
					}		
				}
				else if(fight==2) //fight rock or flashlight
				{
					if(p->checkItem(4)) //has rock
					{
						hit=menu.getNum("Fight Options:\n   1-Throw rock at guard\n   2-Whack guard with flashlight\n   3-See other options",1,3);
						switch(hit)
						{
							case 1: choice=menu.getNum("You decide the only way to definitively get the statue without being seen or captured is to knock out the guard.\nYou grip your trusty rock, mouth going suddenly very dry...you have to make the shot count.\nYou cock your arm back, tighten your core, and throw.\nYou hit him square in the temple!\nHis eyes roll back and he crumples to the ground. He's still breathing, so you think that--hope that--eventually he'll just wake up with a nasty headache.\nGo for the statue?\n   1-Yes\n   2-Yes (C'mon. It's too late to turn back now.)",1,2);
								p->removeItem(4);//remove rock
								p->displayItems();
								p->setAction(5);//moved guard
								break;
							case 2:	kill=menu.getNum("Your stomach ties yourself in knots over what you're about to attempt...\nYou take a few deep breaths and steel yourself.\nAs soon as he turns away and looks in another direction, you spring forward and club him over the head with the flashlight.\n\n\nHe's getting up... HE'S GETTING UP WHAT DO YOU DO?\n   1-Hit him until he stops moving\n   2-Give up",1,2);
								if(kill==1)
								{
									choice=menu.getNum("You hit him. Again, and again... and again...\n\nUntil he stops moving.\n\nYou can't bear to check if he's still alive or not.\nThe slick feeling of his blood on your flashlight makes you want to vomit too badly already to risk taking a closer look.\nGo for the statue?\n   1-Yes\n   2-Yes",1,2);
									p->setAction(5);
								}
								else
								{
									menu.message("This isn't what you signed up for at all... not at all.");
									menu.message("You drop your weapon and surrender to whatever fate awaits you. At least they can't collect your debt in jail.");
									p->setCourage(0);
								}
								break;
							case 3: menu.message("You decide to consider your other options first");
								break;
						}
					}
					else
					{
						hit=menu.getNum("Fight Option:\n   1-Whack guard with flashlight\n   2-See other options",1,2);
						if(hit==1)
						{
							kill=menu.getNum("Your stomach ties yourself in knots over what you're about to attempt...\nYou take a few deep breaths and steel yourself.\nAs soon as he turns away and looks in another direction, you spring forward and club him over the head with the flashlight.\n\n\nHe's getting up... HE'S GETTING UP WHAT DO YOU DO?\n   1-Hit him until he stops moving\n   2-Give up",1,2);
								if(kill==1)
								{
									int trash=menu.getNum("You hit him. Again, and again... and again...\n\nUntil he stops moving.\n\nYou can't bear to check if he's still alive or not.\nThe slick feeling of his blood on your flashlight makes you want to vomit too badly already to risk taking a closer look.\nGo for the statue?\n   1-Yes\n   2-Yes",1,2);
									p->setAction(5);
								}
								else
								{
									menu.message("This isn't what you signed up for at all... not at all.");
									menu.message("You drop your weapon and surrender to whatever fate awaits you. At least they can't collect your debt in jail.");
									p->setCourage(0);
								}
						}
						else
						{
							menu.message("You contemplate if there are other solutions.");
						}
					}
				}
				else
				{
					menu.message("You break out into a cold sweat. You need to think about what to do here...");
					p->setCurrentRoom(left);//move player back to previous room

				}				
			}while(!p->checkAction(5) && fight!=3 && p->getCourage()!=0);
			break;
	}
	
}
/************
 * getCurrentroom
 * returns the room number of the current room
 * **********/
int Museum::getCurrentRoom()
{
	return roomNum;
}
