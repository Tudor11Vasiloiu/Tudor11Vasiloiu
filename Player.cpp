#include "Player.hpp"

Player::~Player()
{

}

Player::Player()
{
    this->FirstName = "";
    this->LastName = "";
    this->points = 0;
}

Player::Player(string f,string l,float p)
{
    this->FirstName = f;
    this->LastName = l;
    this->points = p;
}

void Player::set_FirstName(string f)
{
    this->FirstName = f;
}

void Player::set_LastName(string l)
{
    this->LastName = l;
}

void Player::add_XP()
{
    this->points = this->points + 1;
}

void Player::set_points(float a)
{
    this->points = a;
}

string Player::get_FirstName()
{
    return this->FirstName;
}

string Player::get_LastName()
{
    return this->LastName;
}

float Player::get_points()
{
    return this->points;
}
