/*
 * @2017-11-08
 */

//////////////////////////////////////////////////////////////////////////
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>


//////////////////////////////////////////////////////////////////////////
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#ifndef _WIN32
#include <netinet/in.h>
#ifdef _XOPEN_SOURCE_EXTENDED
#include <arpa/inet.h>
#endif
#include <sys/socket.h>
#endif

#define EVENT2_CORE_EXPORT_SYMBOL
#define USE_DEBUG

#include "event2/event-config.h"
#include "util-internal.h"
#include "event2/bufferevent.h"
#include "event2/buffer.h"
#include "event2/listener.h"
#include "event2/util.h"
#include "event2/event.h"
#include "event2/event_compat.h"
#include "event2/event_struct.h"

#include <WinSock2.h>

using namespace std;

int called = 0;

#define NEVENT	20000

struct event *ev[NEVENT];

struct evutil_weakrand_state weakrand_state;

static int
rand_int(int n)
{
	return evutil_weakrand_(&weakrand_state) % n;
}

static void
time_cb(evutil_socket_t fd, short event, void *arg)
{
	struct timeval tv;
	int i, j;

	called++;

	if (called < 10*NEVENT) {
		for (i = 0; i < 10; i++) {
			j = rand_int(NEVENT);
			tv.tv_sec = 0;
			tv.tv_usec = rand_int(50000);
			if (tv.tv_usec % 2 || called < NEVENT)
				evtimer_add(ev[j], &tv);
			else
				evtimer_del(ev[j]);
		}
	}
}

int
main(int argc, char **argv)
{
	struct timeval tv;
	int i;
#ifdef _WIN32
	WORD wVersionRequested;
	WSADATA wsaData;

	wVersionRequested = MAKEWORD(2, 2);

	(void) WSAStartup(wVersionRequested, &wsaData);
#endif

	evutil_weakrand_seed_(&weakrand_state, 0);

	/* Initalize the event library */
	event_init();

	for (i = 0; i < NEVENT; i++) {
		ev[i] = (event *)malloc(sizeof(struct event));

		/* Initalize one event */
		evtimer_set(ev[i], time_cb, ev[i]);
		tv.tv_sec = 0;
		tv.tv_usec = rand_int(50000);
		evtimer_add(ev[i], &tv);
	}

	event_dispatch();


	printf("%d, %d\n", called, NEVENT);
	return (called < NEVENT);
}
