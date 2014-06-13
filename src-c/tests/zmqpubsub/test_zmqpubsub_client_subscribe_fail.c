/*
 * ZMQ PUB/SUB plugin through Edison API
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

/** @file test_zmqpubsub_client_subscribe_fail.c

 */

#include <stdio.h>
#include <assert.h>
#include <zmq.h>
#include <zmq_utils.h>
#include "../../edison-lib/libedison/edisonapi.h"

int main (void)
{

    int result = subscribe("service");
    if (result == 0) {
        printf("Subscribed Successfully\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Failed: Subscription\n");
        exit(EXIT_SUCCESS);
    }
}