#include <string>
using namespace std;

class Entity
{
protected:
	int health;
	double x_pos;
	double y_pos;
};

class Sprite:protected Entity
{
protected:
	int damage;
	double speed;
	string name;
	int attck_range;
	int direction;
	//QtClass graphics;
	//QtClass hitbox;	
};

class Block:protected Entity
{
private:
	int type; //destructible, moveable
	//QtClass graphics;
public:
	void move(int direction, double length);
	void destruct();
}

class Tile
{
private:
	Entity* onTile;
	int type; //normal, ice, hole, exit, laser, etc;
public:
	int get_type();
}

class Player:protected Sprite
{
private:
	int laser_charges;
	int key_count;
public:
	void move(int direction);
	void attack_melee();
	void attack_range();
	int check_tile_on();
	int check_health();
	bool check_hitbox();
	void take_dmg();
	vector<int> check_tile_facing();
	void die();
	bool check_win();
};
