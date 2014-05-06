/*
 * ZMQ PUB/SUB plugin to enable publish feature through Edison API
 * Copyright (c) 2014, Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU Lesser General Public License,
 * version 2.1, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 */

/** @file zmqpubsub-service.c

    This class helps in publishing the message to the clients which are connected and subscribed
    on a topic.

*/

#include <stdio.h>
#include <zmq.h>
#include <zmq_utils.h>
#include "zmqpubsub-service.h"
#include "../inc/zhelpers.h"

#ifndef DEBUG
#define DEBUG 0
#endif

/** @defgroup zmqpubsubservice
*   This is ZMQ PUB/SUB Service
*  @{
*/

/** Structure which holds the context and publisher handler
 */
struct ZMQPubSubService {
	void *context; /**< context handler */
	void *publisher; /**< publisher handler */
};

/** An Global ZMQPubSubService Object.
 */
struct ZMQPubSubService zmqContainer;


/**  Creates the context object and publisher socket. With the help of the ServiceDescription parameter the
publisher socket binds to the address and port to initiate communication.

* @param serviceDesc an void pointer
* @return The result code
*/
int init(void *serviceDesc) {
	#if DEBUG
		printf("In createClient\n");
	#endif
	ServiceDescription *serviceDescription = (ServiceDescription *)serviceDesc;
	zmqContainer.context = zmq_ctx_new();
	#if DEBUG
		printf("context initialised\n");
	#endif
    zmqContainer.publisher = zmq_socket(zmqContainer.context,ZMQ_PUB);
    char addr[128];
    sprintf(addr, "tcp://%s:%d\n", serviceDescription->address, serviceDescription->port);
    #if DEBUG
        printf("going to bind %s\n",addr);
    #endif
    int rc = zmq_bind(zmqContainer.publisher,addr);
    #if DEBUG
        printf("bind completed\n");
    #endif
    return rc;
}

/**  Empty function. This function is unimplemented since in ZMQ pub/sub service we use only
publish

* @param client a client object
* @param message a string message
* @param context a context object
* @return The result code

*/
int sendTo(void *client, char *message, Context context) {
	#if DEBUG
		printf("In sendTo\n");
	#endif
}

/**  Publishing a message. The service will be publishing a message to the clients.

* @param message a string message
* @param context a context object
* @return The result code

*/
int publish(char *message,Context context) {
	#if DEBUG
		printf("publish started\n");
	#endif
	#if DEBUG
   		printf("Publishing message %s\n",message);
   	#endif
	int rc = s_send(zmqContainer.publisher, message);
	#if DEBUG
		printf("Publisher Finished\n");
	#endif
	return rc;
}

/** Empty function. This function is unimplemented since in ZMQ pub/sub service we use only
publish
* @param client a client object
* @param context a context object
* @return The result code

*/
int manageClient(void *client,Context context) {
    #if DEBUG
        printf("In manageClient\n");
    #endif
}

/** Empty function. This function is unimplemented since in ZMQ pub/sub service we use only
publish
* @param handler a callback handler which takes multiple params
* @return The result code

*/
int receive(void (*handler)(void *client,char *message,Context)) {
    #if DEBUG
        printf("In receive\n");
    #endif
}

/** Cleanup function. This method helps in closing the publisher socket and destroying the
context object.
* @return The result code

*/
int done() {
	if (zmqContainer.publisher != NULL) {
		zmq_close(zmqContainer.publisher);
		zmqContainer.publisher = NULL;
		#if DEBUG
			printf("publisher freed\n");
		#endif
	}
	if (zmqContainer.context != NULL) {
		zmq_ctx_destroy(zmqContainer.context);
		zmqContainer.context = NULL;
		#if DEBUG
			printf("context freed\n");
		#endif
	}
	#if DEBUG
		printf("\nclosed\n");
	#endif
}

/** @} */ // end of zmqpubsubservice