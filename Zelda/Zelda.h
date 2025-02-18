#pragma once
#include<vector>
//---------------------Classes------------------------
class HelperFunctions;
class Item;
class Treasure;
class Weapon;
class Monster;
class Princess;
class Player;
class Room;
class Castle;
class Game;




//---------------------Definitions------------------------





//---------------------Helper Functions------------------------
class HelperFunctions
{
private:

public:

	//Converts all the characters of Input to UpperCase
	static void	charactersCase(char*);
	static void color(int);
};





//------------------------Item----------------------------------
class Item
{
protected:

	char* name;

public:

	Item();
	~Item();

	inline char* getItemName();
	inline virtual int getWorth() = 0;


};





//------------------------Treasure--------------------------------
class Treasure : public Item
{
private:
	int worth;

public:

	Treasure();
	~Treasure();
	Treasure(char const*, int);

	inline int	getWorth();

};





//----------------------Weapon---------------------------------------
class Weapon : public Item
{
private:

public:

	Weapon();
	~Weapon();
	Weapon(char const*);

	inline int getWorth();

};





//-----------------------Monster---------------------------------------
class Monster
{
private:
	char* name;
	bool  is_Alive;
	Item* killing_weapon;


public:

	Monster();
	~Monster();
	Monster(char const*, Item*);

	inline Item* 	getKillingWeapon();
	inline void		setKillingWeapon(Item*);
	inline bool		getLivingState();
	inline void		setLivingState(bool);
	inline char*	getMonsterName();

};





//---------------------Princess-------------------------------------
class Princess
{
private:
	bool is_Alive;

public:
	Princess();
	~Princess();

	inline bool	 getLivingState();
	inline void	 setLivingState(bool);
};





//-----------------------Room------------------------------------------
class Room
{
private:
	std::vector<Room*> 		paths;
	std::vector<Item*> 		items_Present;
	Monster*    monster_Present;
	Princess*   princess_Present;


	char*		description;
	int 		roomNumber;


public:
	Room();
	~Room();

	inline std::vector<Room*>& 		getPaths();
	inline std::vector<Item*>&		getItemsPresent();
	inline Monster*		getMonsterPresent();
	inline Princess*	getPrincessPresent();
	inline char*		getDescription();
	inline int 			getRoomNumber();

	bool				isRoomFull();


	int					directionIndex(char const*);
	char* 				directionName(int);
	/*
	inline void			setEast(Room*);
	inline void			setWest(Room*);
	inline void			setSouth(Room*);
	inline void			setNorth(Room*);
	*/
	inline void			setMonsterPresent(Monster*);
	inline void			setItemsPresent(int, Item*);
	inline void			setPrincessPresent(Princess*);
	inline void			setDesription(char const*);
	inline void			setRoomNumber(int);

	//North
	void operator+(Room* roomNo) {
		paths[0] = roomNo;
	}

	//South
	void operator-(Room* roomNo) {
		paths[1] = roomNo;
	}

	//East
	void operator*(Room* roomNo) {
		paths[2] = roomNo;
	}

	//West
	void operator/(Room* roomNo) {
		paths[3] = roomNo;
	}
};





//----------------Castle--------------------------------------
class Castle
{
private:
	std::vector<Room> rooms;

public:
	Castle();
	~Castle();

	inline Room* getRoom(int);
	void LinkRoomsWithOtherThings(std::vector<Item*>&, std::vector<Monster*>&, Princess*);
	void HiddenRoomsUnlocker(char const*, std::vector<Monster*>&);
	void LinkRoom5and8();
	void LinkRoom6and9();

	inline void setDescriptionOfRooms();
	inline void setNumbersofRooms();


};





//----------------------------Player------------------------------
class Player
{

private:
	char* name;
	Princess* princess_Pointer;
	std::vector<Item*> 		bag;
	Room* current_Room;

	bool is_Alive;
	int  cash;

	//Utility Functions

	bool isBagEmpty();
	bool isBagFull();

public:

	Player();
	~Player();
	Player(char const*, Room*);

	inline bool 	getCurrentState();
	inline void 	setCurrentState(bool);

	inline Princess* getPrincess_Pointer();

	void 			CashUpdater();
	inline int  	getCash();
	inline char* getPlayerName();

	bool			Move(char const*, bool&);
	void			Pick(char const*);
	void			Drop(char const*);
	void			Look();
	bool			Attack(char const*);
	void			Exit();


};




//--------------------------Game-------------------------------
class Game
{
private:
	Castle* castlePtr;
	std::vector<Item*>	itemsPtr;
	Princess* princessPtr;
	std::vector<Monster*>	monstersPtr;
	Player* playerPtr;


public:

	Game();
	~Game();

	void	 Play();
	void	 displayStory();
	void	 PlayerDead();
	void	 gameCheck();
};