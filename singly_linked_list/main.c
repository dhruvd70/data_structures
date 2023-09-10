#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_node_t
{
    void* data;
    struct list_node_t* pNext;
}list_node_t;

typedef struct linked_list_t
{
    list_node_t* head;
    size_t data_size;
}linked_list_t;

linked_list_t* init_linked_list(size_t data_size)
{
    linked_list_t *list = (linked_list_t *)malloc(sizeof(linked_list_t));
    list->head = NULL;

    list->data_size = data_size;

    return list;
}

list_node_t* get_node(linked_list_t*list, void* data)
{
    list_node_t* node = (list_node_t*)malloc(sizeof(list_node_t));
    node->data = malloc(list->data_size);
    memcpy(node->data, data, list->data_size);
    node->pNext = NULL;

    return node;
}

void insert_node(linked_list_t* list, void* data)
{
    list_node_t**temp = &list->head;
    
    while (*temp) {
        temp = &(*temp)->pNext;
    }
    (*temp) = get_node(list, data);
}

void print_int(void*val)
{
    printf("%d -> ",*(int*)val);
}

void print_char(void*val)
{
    printf("%c -> ",*(char*)val);
}

void print_list(linked_list_t *list, void(*print)(void*))
{
    list_node_t* head = list->head;
    if(!list->head) {
        printf("Empty List\n");
    }
    while(list->head) {
        print(list->head->data);
        list->head = list->head->pNext;
    } 
    printf("\n");
}

int main()
{
    linked_list_t *integers = init_linked_list(sizeof(int));
    linked_list_t *alphs = init_linked_list(sizeof(char));

    int nums[] = {1,2,3,4,5,6,7,8,9,0};
    char alph[] = "qwertyuiop";

    for(int i=0;i<sizeof(nums)/sizeof(int);i++) {
        insert_node(integers, &nums[i]);
    }
    for(int j=0;j<sizeof(alph)/sizeof(char);j++) {
        insert_node(alphs, &alph[j]);
    }
    
    print_list(alphs, print_char);
    printf("\n");
    print_list(integers, print_int);
    return 0;
}