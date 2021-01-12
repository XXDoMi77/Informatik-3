/*
 * SIMPLESOCKET.H
 *
 *  Created on: 10.09.2019
 *      Author: aml
 */

/**
 *
 * \file simplesocket.H
 *
 * \brief Contains the definition of the classes
 * for a TCP/IP client und server.
 *
 */

#ifndef SIMPLESOCKET_H_
#define SIMPLESOCKET_H_

#include <string>
#include <arpa/inet.h> //inet_addr
#include <ctype.h> //to check if character is number, letter or punctuation
#include "battleship.h"


using namespace std;

/**
 *
 *  \class TCPclient
 *  \brief The class defining the  of a TCP/IP client.
 *
 */
class TCPclient{
private:
	int sock;
	string address;
	int port;
	struct sockaddr_in server;

public:
	/**
	 *
	 * \brief constructor
	 *
	 */
	TCPclient();

	/**
	 *
	 * \brief Connects the client to the server.
	 *
	 * \param ipAdr string IP address of the server.
	 *
	 * \param port int number of the server
	 *
	 * \return bool true if connection is successfully established.
	 *
	 */
	bool conn(string ipAdr, int port);

	/**
	 *
	 * \brief Sends data to the server.
	 *
	 * \param data string containing the data send to the server
	 *
	 * \return bool true if the sending is successful.
	 *
	 */
	bool sendData(string data);

	/**
	 *
	 * \brief Waits for the response of the server and returns a string containing the response data.
	 *
	 * \param size int maximal string size of the return string.
	 *
	 * \return string contains the response after sending data.
	 *
	 */
	string receive(int size);
};

/**
 *
 *  \class TCPserver
 *  \brief     The class defining the  of a TCP/IP server.
 *
 */
class TCPserver{
private:
	struct sockaddr_in ipOfServer_;
	int    clintListn_ = 0;
	int    clintConnt_ = 0;
	bool _isRunning = true;
	int _port = 0;
	string _latestMsg = "nothing received yet...";
	World* _world;

public:
	/**
	 *
	 * \brief Destructor
	 *
	 */
	~TCPserver();

	/**
	 *
	 *  \brief constructor
	 *
	 *  \param port int number the server listens.
	 *  \param maxDataSizeRecv int maximal size of the messages the server can receive.
	 *
	 */
	TCPserver(int port, int maxDataSizeRecv);

	/**
	 *
	 * \brief Starts the server.
	 *
	 */
	void run();

	/**
	 * \brief Check if server is running
	 */
	bool is_running();

	/**
	 * \brief Get the port the server is running on
	 */
	int get_port();

	/**
	 * \brief Get the latest incoming message from server
	 */
	string get_latest_inc_msg();

protected:
	const char   *dataSend_;
	char 		 *dataRecv_;
	char   		  maxDataSizeRecv_;

	/**
	 *
	 * \brief Defines the responses to the given received data.
	 *
	 * \param input contains the data the server has received.
	 *
	 * \return string containing the response of the server.
	 *
	 */
	virtual string        myResponse(string input);

private:

	/**
	 *
	 * \brief Wrapping method for method  myResponse.
	 *
	 * \param string incomingMsg contains the data the server has received.
	 *
	 * \return string containing the response of the server.
	 *
	 */
	string response(string incomingMsg);
};




#endif /* SIMPLESOCKET_H_ */
