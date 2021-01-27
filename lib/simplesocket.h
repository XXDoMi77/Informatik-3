/*
 * SIMPLESOCKET.H
 *
 *  Created on: 10.09.2019
 *      Author: aml
 */

/**
 *
 * \file simplesocket.h
 *
 * \brief Contains the definition of the classes
 * for a TCP/IP client und server.
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
 *  \class TCPserver
 *  \brief     The class defining the  of a TCP/IP server.
 *
 */
class ImprovedTCPserver : public TCPserver
{
	using TCPserver::TCPserver;

private:
	/** \brief Stores latest incoming message*/
	char _latestMsg[glset::bufferSize];

	/** \brief Pointer to a World object that stores game state */
	TASK3::World *_world = new TASK3::World;;

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
