/**
    Created by: Krzysztof Dobrzynski - k.dobrzynski94@gmail.com
                https://github.com/Sejoslaw


    OS-independent implementation of List.
*/

#ifndef KD_CCOLLECTIONS_LIST
#define KD_CCOLLECTIONS_LIST

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

/// Definition of single node in List
typedef struct ListNode
{
    void* value;
    struct ListNode* next;
} ListNode;

/// Definition of List
typedef struct List
{
    ListNode* head;
} List;


/// ============================================ Operations

/**
    @return
        Returns new List.
*/
List* cc_list_new()
{
    List *new_list = malloc(sizeof(List));
    new_list->head = 0;

    return new_list;
}

/**
    @return
        Returns CC_TRUE if given List contains no elements.
*/
CC_BOOL cc_list_is_empty(List* l)
{
    /// If List does not have Head, return TRUE
    if (!l->head) return CC_TRUE;
    return CC_FALSE;
}

/**
    Appends the specified element to the end of specified List.

    @return
        Returns CC_TRUE if the element was added to List.
*/
CC_BOOL cc_list_add(List* l, void* element)
{
    /// Check if the list contains at least head element
    if (cc_list_is_empty(l))
    {
        l->head = malloc(sizeof(ListNode));
        l->head->value = element;
        l->head->next = NULL;

        return CC_TRUE;
    }

    /// If the head is set, set another element
    ListNode *current = l->head;
    ListNode *next = current->next;
    while (current->next)
        current = current->next;

    /// current->next is now an empty pointer
    current->next = malloc(sizeof(ListNode));
    current->next->value = element;
    current->next->next = NULL;

    return CC_TRUE;
}

/**
    Appends all of the elements in the specified List_2 (collection) to the end of List_1 (l).

    @return
        Returns CC_TRUE if the collection was added to List.
*/
CC_BOOL cc_list_add_list(List* l, List* collection)
{
    /// If collection has at least head, we can try and add head
    /// Next elements must be checked
    if (collection->head) /// Optionally it could be -> !cc_list_is_empty(collection)
    {
        ListNode *current = collection->head;
        cc_list_add(l, current->value); /// Add current head value

        /// Loop through elements and add value from each
        while (current->next)
        {
            cc_list_add(l, current->next->value);
            current = current->next;
        }
        return CC_TRUE;
    }
    return CC_FALSE;
}

/**
    Removes all of the elements from given List.
*/
void cc_list_clear(List* l)
{
    /// Remove the head pointer (set it to 0)
    l->head = 0;
}

/**
    @return
        Returns the element at the specified position in the specified List.
*/
void* cc_list_get(List* l, int index)
{
    /// Return NULL if wrong index
    if (index < 0) return NULL;

    /// Return NULL if this List contains no elements.
    if (cc_list_is_empty(l)) return NULL;

    /// Return value from head if index is 1
    if (index == 0) return l->head->value;

    /// Take List head
    ListNode *current = l->head;
    /// Search through List
    for (int i = 0; i < index; ++i)
    {
        /// If the index is incorrect return NULL
        if (!current->next) return NULL;
        current = current->next;
    }
    return current->value;
}

/**
    Removes the element at the specified position from specified List.

    @return
        Returns the element previously at the specified position.
*/
void* cc_list_remove(List* l, int index)
{
    /// Return NULL if wrong index
    if (index < 0) return NULL;

    /// Return NULL if List is empty
    if (cc_list_is_empty(l)) return NULL;

    /// Take head
    ListNode *current = l->head;
    /// Find value one before right index
    for (int i = 0; i < index - 1; ++i)
    {
        if (!current->next) return NULL;
        current = current->next;
    }

    /// Create temporary node
    ListNode *tmp_node = current->next;
    /// Get return value from node
    void *return_value = tmp_node->value;
    /// Remove node - remove reference to it
    current->next = tmp_node->next;
    /// Free memory from temporary node
    free(tmp_node);
    /// Return value from removed node
    return return_value;
}

/**
    Replaces the element at the specified position in specified List with the specified element.

    @return
        Returns the element previously at the specified position.
*/
void* cc_list_set(List* l, int index, void* element)
{
    /// Return NULL if wrong index
    if (index < 0) return NULL;

    /// Return NULL if List is empty
    if (cc_list_is_empty(l)) return NULL;

    /// Take head
    ListNode *current = l->head;
    /// Find node on right index
    for (int i = 0; i < index; ++i)
    {
        if (!current->next) return NULL;
        current = current->next;
    }

    /// Save previous value
    void *return_value = current->value;
    /// Set value
    current->value = element;
    /// Return saved previous value
    return return_value;
}

/**
    @return
        Returns the number of elements in specified List.
*/
int cc_list_size(List* l)
{
    /// Return 0 if List is empty
    if (cc_list_is_empty(l)) return 0;

    /// Take head
    ListNode *current = l->head;
    /// List size
    int list_size = 1;
    while (current->next)
    {
        current = current->next;
        list_size++;
    }
    /// Remove List size
    return list_size;
}

/**
    @return
        Returns List between the specified fromIndex, inclusive, and toIndex, exclusive.
*/
List* cc_list_sub_list(List* l, int fromIndex, int toIndex)
{
    /// If given List is empty we can't create sub-list
    if (cc_list_is_empty(l)) return NULL;

    /// We can't create List if end index is less than start index
    if (toIndex < fromIndex) return NULL;

    /// Check if sub-list can be created
    if (cc_list_size(l) < toIndex) return NULL;

    /// Do not use pre-made methods because they have few checks each and will start from begging
    /// It may be inefficient
    /// New List
    List *new_list = cc_list_new();

    /// Write elements to new List
    ListNode *current = l->head;
    for (int i = 0; i < fromIndex; ++i)
        current = current->next;

    /// current_index should be = with fromIndex
    /// Count how many elements should be written to new List
    for (int i = fromIndex; i < toIndex; ++i)
    {
        cc_list_add(new_list, current);
        current = current->next;
    }
    /// Return new List
    return new_list;
}

#endif // KD_CCOLLECTIONS_LIST

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
