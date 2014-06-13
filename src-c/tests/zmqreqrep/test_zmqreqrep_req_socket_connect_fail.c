/*
 * ZMQ REQ/REP plugin through Edison API
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

/** @file test_zmqreqrep_req_socket_connect_fail.c

This file tests whether ZMQ Requester socket fails when we pass the Invalid IP Address.
*/

#include <stdio.h>
#include <assert.h>
#include <zmq.h>
#include <zmq_utils.h>
#include "../../edison-lib/libedison/edisonapi.h"

int main (void)
{

    ServiceQuery *serviceQuery = (ServiceQuery *)malloc(sizeof(ServiceQuery));
    serviceQuery->address = "127.0.0.123232132321323123232233";
    serviceQuery->port = 100;
    int result = init(serviceQuery);
    done();
    free(serviceQuery);
    if (result == 0) {
        printf("Requester Socket Successfully Connected\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Failed: Requester Socket Binding\n");
        exit(EXIT_SUCCESS);
    }
}