#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include "Stack.h"

int main(int argc, char *argv[])
{
#if 0
    /// Sub-List Test
    List* list = cc_list_new();
    for (int i = 0; i < 10; ++i)
        cc_list_add(list, i);

    for (int i = 0; i < cc_list_size(list); ++i)
        printf("list[i] = %i\n", cc_list_get(list, i));

    printf("\n\n\n\n");

    List *sub_list = cc_list_sub_list(list, 2, 6);
    int *sub_val;
    for (int i = 0; i < cc_list_size(sub_list); ++i)
    {
        sub_val = cc_list_get(sub_list, i);
        printf("sub_list[i] = %i\n", *sub_val);
    }
#endif

#if 0
    /// List Test
    List* list = cc_list_new();
    printf("List size = %i\n", cc_list_size(list));
    printf("Is List empty ? => %i\n", cc_list_is_empty(list));
    int x = 27;
    int y = 13;
    int z = 123;
    cc_list_add(list, &x); printf("Added x \n");
    cc_list_add(list, &y); printf("Added y \n");
    cc_list_add(list, &z); printf("Added z \n");
    printf("List size = %i\n", cc_list_size(list));
    printf("Is List empty ? => %i\n", cc_list_is_empty(list));
    int *x1 = cc_list_get(list, 0);
    int *y1 = cc_list_get(list, 1);
    int *z1 = cc_list_get(list, 2);
    printf("X = %i\n", *x1);
    printf("Y = %i\n", *y1);
    printf("Z = %i\n", *z1);
    printf("\n");
    printf("\n");
    int y2 = 31;
    int *y2p = cc_list_set(list, 1, &y2);
    int *y2n = cc_list_get(list, 1);
    printf("New y2 = %i\n", *y2n);
    printf("Previous y2 = %i\n", *y2p);
    printf("\n");
    printf("\n");
    cc_list_remove(list, 1);
    printf("\n");
    x1 = cc_list_get(list, 0);
    y1 = cc_list_get(list, 1);
    printf("X = %i\n", *x1);
    printf("Y = %i\n", *y1);
#endif

#if 0
    /// Stack Test
    Stack *stack = cc_stack_new();
    printf("Is Stack empty ? => %i\n", cc_stack_empty(stack));
    for (int i = 0; i < 10; ++i)
        cc_stack_push(stack, i);
    printf("Is Stack empty ? => %i\n", cc_stack_empty(stack));
    printf("Current top value (peek) = %i\n", cc_stack_peek(stack));
    printf("Current top value (pop) = %i\n", cc_stack_pop(stack));
    printf("Current top value (peek) = %i\n", cc_stack_peek(stack));
#endif

    return 0;
}
