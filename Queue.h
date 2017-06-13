/**
    Created by: Krzysztof Dobrzynski - k.dobrzynski94@gmail.com
                https://github.com/Sejoslaw


    OS-independent implementation of Queue.
*/

#ifndef KD_CCOLLECTIONS_QUEUE
#define KD_CCOLLECTIONS_QUEUE

/// ============================================ Definitions

/// Windows has NULL declared
#ifndef NULL
    #ifdef __cplusplus
        #define NULL 0
    #else
        #define NULL ((void*)0)
    #endif
#endif // NULL

/// Definition of BOOL values
typedef unsigned char CC_BOOL;
#define CC_TRUE 1
#define CC_FALSE 0

/// Definition of single element in Queue
typedef struct QueueElement
{
    void* value;
    struct QueueElement* next_in_queue;
} QueueElement;

/// Definition of Queue
typedef struct Queue
{
    QueueElement* head;
} Queue;


/// ============================================ Operations

/**
    @return
        Returns new Queue.
*/
Queue* cc_queue_new()
{
    Queue* new_queue = malloc(sizeof(Queue));
    new_queue->head = NULL;

    return new_queue;
}

/**
    @return
        Returns CC_TRUE if the given Queue is empty.
*/
CC_BOOL cc_queue_is_empty(Queue* q)
{
    if (!q->head) return CC_TRUE;
    return CC_FALSE;
}

/**
    Inserts the specified element into given Queue.

    @return
        Returns CC_TRUE if the element was added correctly.
*/
CC_BOOL cc_queue_add(Queue* q, void* element)
{
    if (cc_queue_is_empty(q))
    {
        /// Set new head if Queue is empty
        q->head = malloc(sizeof(QueueElement));
        q->head->value = element;
        q->head->next_in_queue = NULL;

        return CC_TRUE;
    }
    /// If Queue is not empty, add new element after last in Queue
    /// Take current Queue head
    QueueElement* current = q->head;
    while (current->next_in_queue)
        current = current->next_in_queue;
    /// current should now be the last in Queue
    /// Set last element
    current->next_in_queue = malloc(sizeof(QueueElement));
    current->next_in_queue->value = element;
    current->next_in_queue->next_in_queue = NULL;
    /// Return true
    return CC_TRUE;
}

/**
    @return
        Returns, but does NOT remove, the head of given Queue.
*/
void* cc_queue_peek(Queue* q)
{
    /// Return the value of the head
    return q->head->value;
}

/**
    @return
        Returns and removes the head of given Queue.
*/
void* cc_queue_poll(Queue* q)
{
    /// Take head
    QueueElement* current_head = q->head;
    /// Take current head value
    void* current_head_value = q->head->value;
    /// Set next in Queue as new head
    q->head = q->head->next_in_queue;
    /// Return current head value
    return current_head_value;
}

/**
    @return
        Returns the number of elements in given Queue.
*/
int cc_queue_size(Queue* q)
{
    /// Return 0 if Queue is empty
    if (cc_queue_is_empty(q)) return 0;

    /// Take head
    QueueElement *current = q->head;
    /// Queue size
    int queue_size = 1;
    while (current->next_in_queue)
    {
        current = current->next_in_queue;
        queue_size++;
    }
    /// Return Queue size
    return queue_size;
}

#endif // KD_CCOLLECTIONS_QUEUE

/***
	License page: http://www.zlib.net/zlib_license.html

	version 1.2.11, January 15th, 2017

	  Copyright (C) 2010-2017 Krzysztof Dobrzynski

	  This software is provided 'as-is', without any express or implied
	  warranty.  In no event will the authors be held liable for any damages
	  arising from the use of this software.
	  Permission is granted to anyone to use this software for any purpose,
	  including commercial applications, and to alter it and redistribute it
	  freely, subject to the following restrictions:

	  1. The origin of this software must not be misrepresented; you must not
		 claim that you wrote the original software. If you use this software
		 in a product, an acknowledgment in the product documentation would be
		 appreciated but is not required.
	  2. Altered source versions must be plainly marked as such, and must not be
		 misrepresented as being the original software.
	  3. This notice may not be removed or altered from any source distribution.

	  Krzysztof Dobrzynski
	  k.dobrzynski94@gmail.com
*/
