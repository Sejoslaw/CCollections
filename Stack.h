/**
    Created by: Krzysztof Dobrzynski - k.dobrzynski94@gmail.com
                https://github.com/Sejoslaw


    OS-independent implementation of Stack.
*/

#ifndef KD_CCOLLECTIONS_STACK
#define KD_CCOLLECTIONS_STACK

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

/// Definition of single element on Stack
typedef struct StackElement
{
    void* value;
    struct StackElement* element_under;
} StackElement;

/// Definition of Stack
typedef struct Stack
{
    StackElement* top_element;
} Stack;


/// ============================================ Operations

/**
    @return
        Returns new Stack.
*/
Stack* cc_stack_new()
{
    Stack *new_stack = malloc(sizeof(Stack));
    new_stack->top_element = NULL;

    return new_stack;
}

/**
    Tests if the given Stack is empty.

    @return
        Returns CC_TRUE if the given Stack contains no elements.
*/
CC_BOOL cc_stack_is_empty(Stack* s)
{
    if (!s->top_element) return CC_TRUE;
    return CC_FALSE;
}

/**
    Looks at the element at the top of given Stack without removing it from the Stack.

    @return
        Returns the element at the top of given Stack.
*/
void* cc_stack_peek(Stack* s)
{
    /// Return NULL if given Stack is empty
    if (cc_stack_is_empty(s)) return NULL;

    /// Return value from top element from given Stack
    return s->top_element->value;
}

/**
    Removes the element at the top of given Stack and returns that element as the value of this function.

    @return
        Returns the element at the top of given Stack.
*/
void* cc_stack_pop(Stack* s)
{
    /// Return NULL if given Stack is empty
    if (cc_stack_is_empty(s)) return NULL;

    /// Top element
    StackElement *top = s->top_element;
    /// Top element value
    void *top_value = top->value;
    /// Set new top
    s->top_element = s->top_element->element_under;
    /// Return previous top value;
    return top_value;
}

/**
    Pushes an element onto the top of given Stack.

    @return
        Return the given element.
*/
void* cc_stack_push(Stack* s, void* element)
{
    /// New element which will be placed on top of Stack
    StackElement *new_top = malloc(sizeof(StackElement));
    /// Assign value to new top element
    new_top->value = element;
    /// Set last top as under of new top
    new_top->element_under = s->top_element;
    /// Set new top as top element
    s->top_element = new_top;
    /// Return given element as new top value from the given Stack
    return s->top_element->value;
}

/**
    @return
        Returns the number of elements in given Stack.
*/
int cc_stack_size(Stack* s)
{
    /// Return 0 if Stack is empty
    if (cc_stack_is_empty(s)) return 0;

    /// Take head
    StackElement *current = s->top_element;
    /// Stack size
    int stack_size = 1;
    while (current->element_under)
    {
        current = current->element_under;
        stack_size++;
    }
    /// Return Stack size
    return stack_size;
}

#endif // KD_CCOLLECTIONS_STACK

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
