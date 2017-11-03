/*
 * @2017-10-23
 *  ��1������VS2005/VS2008�������Դ����ڴ��⹤��/������
 *         #include <crtdbg.h>
 *  ��2�� Memory Leak Check 
 *
 * @2017-11-01
 *   (1) �¼�Դ: Linux �����ļ�������; windows ���� Socket ���� Handle; 
 *       �¼�Դ ͳ��Ϊ �����.
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

#ifndef WIN32
#include <netinet/in.h>
#ifdef _XOPEN_SOURCE_EXTENDED
#include <arpa/inet.h>
#endif
#include <sys/socket.h>
#endif

#include "event2/event-config.h"
#include "event2/bufferevent.h"
#include "event2/buffer.h"
#include "event2/listener.h"
#include "event2/util.h"
#include "event2/event.h"
#include "event2/event_compat.h"
#include "event2/event_struct.h"

#include <WinSock2.h>

using namespace std;

/* �� */
#define PRINTF_BUFFER_COUNT 512
static const int PORT = 9995;

struct event *ev;
struct timeval tv;
static int called = 0;

/* �������� */
char * isprintf(const char * format, ...);
char * ivsprintf(const char * format, va_list args);
void print(vector<int> v);
static void listener_cb(struct evconnlistener *, evutil_socket_t, struct sockaddr *, int socklen, void *);

void time_cb(int fd, short event, void *agrc);

/* �� - ���� new ������ */
#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)	

int main()
{
#if 0
	struct event_base *base;
	struct evconnlistener *listener;
	struct event *signal_event;

	struct sockaddr_in sin;
#ifdef _WIN32
	WSADATA wsa_data;
	WSAStartup(MAKEWORD(2, 2), &wsa_data);	/* Open WinSocket DLL */
#endif

	/* Init libevent, == Reactor == After this step, then Register events */
	base = event_base_new();
	if (!base) {
		fprintf(stderr, "Could not initialize libevent!\n");
		return 1;
	}

	memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
	sin.sin_port = htons(PORT);

	listener = evconnlistener_new_bind(base, listener_cb, (void *)base, 
		LEV_OPT_REUSEABLE|LEV_OPT_CLOSE_ON_FREE, -1,
		(struct sockaddr*)&sin, sizeof(sin));
	if (!listener) {
		fprintf(stderr, "Could not create a listener!\n");
		return 1;
	}

	/* End of Memory Leak Check */
	_CrtDumpMemoryLeaks();

	/* pause */
	system("pause");
	return 0;
#endif

#ifdef _WIN32
	WSADATA wsa_data;
	WSAStartup(MAKEWORD(2, 2), &wsa_data);	/* Open WinSocket DLL */
#endif

	/* Initalize the event library */
	event_init();

    //struct event_base *base = event_base_new();
	ev = (struct event*)malloc(sizeof(struct event));

	/* Initalize one event */
	evtimer_set(ev, time_cb, NULL);
	tv.tv_sec = 1;
	tv.tv_usec = 123;
	evtimer_add(ev, &tv);

	event_dispatch();

	printf("End Line : %d\n", called);
}                  

// 
char * ivsprintf(const char * format, va_list args)
{
	static char szBuffer[PRINTF_BUFFER_COUNT];
	vsprintf_s(szBuffer, format, args);
	return szBuffer;
}
//
char * isprintf(const char * format, ...)
{
	char * p;
	va_list args;
	va_start(args, format);
    p=ivsprintf(format, args);
	va_end(args);
	return p;
}

//
void print(vector<int> v)
{
     //cout << "\n vector size is: " << v.size() << endl;
     vector<int>::iterator p = v.begin();
}

/*
 *	
 */
static void listener_cb(struct evconnlistener *listener, evutil_socket_t fd,
                        struct sockaddr *sa, int socklen, void *user_data)
{
}

/*
 *	
 */
void time_cb(int fd, short event, void *agrc)
{
	printf("timer wakeup. %d.\r\n", ev->ev_res);
	evtimer_add(ev, &tv);	/* if no this line, then it only run once - printf("timer wakeup.\r\n");  */
}
