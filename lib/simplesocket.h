/**
 *
 * \file simplesocket.h
 *
 * \brief Contains the override for myResponse method that
 * originates from SIMPLESOCKET.H
 *
 */

#ifndef IMPROVED_SIMPLESOCKET_H_
#define IMPROVED_SIMPLESOCKET_H_

#include <string>
#include <arpa/inet.h> //inet_addr
#include <ctype.h>	   //to check if character is number, letter or punctuation
#include "TASK3.H"
#include "SIMPLESOCKET.H"
#include "settings.h"
using namespace std;

using namespace std;

/**
 *
 * \class ImprovedTCPserver
 * \brief This class overrides the myResponse() method
 * inherited from SIMPLESOCKET.H
 *
 */
class ImprovedTCPserver : public TCPserver
{
	//inherits the constructor
	using TCPserver::TCPserver;

private:
	/** \brief Stores latest incoming message*/
	char _latestMsg[glset::bufferSize];

	/** \brief Pointer to a World object that stores game state */
	TASK3::World *_world = new TASK3::World;

	/** \brief Overrides myResponse() method that is inherited from TCPserver */
	string myResponse(string input);

public:
	/** 
	 * \brief Forwards latest message to Menu
	 * 
	 * \return Returns String that has the latest message that came from client
	 */
	string get_latest_inc_msg();
};

#endif /* IMPROVED_SIMPLESOCKET_H_ */
