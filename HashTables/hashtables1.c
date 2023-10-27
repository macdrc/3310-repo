#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

typedef struct node_ {
    char name;
    unsigned long long phone;
    struct node_ *next;
} node;

typedef struct list_ {
    node *head;
    node *tail;
    int count;
} list;

node* create_node (char new_name, unsigned long long new_phone){
    node* new_node = (node*) malloc(sizeof(node*));
    new_node->next = NULL;
    new_node->name = new_name;
    new_node->phone = new_phone;
    return new_node;
}

list* create_list (){
    list* new_list = (list*) malloc(sizeof(list*));
    if (new_list == NULL)
        return NULL;
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->count = 0;
    return new_list;
}

list* add_node_tail (list* my_list, node* new_tail){
    if (my_list == NULL || new_tail == NULL)
        return NULL;
    if (my_list->head == NULL){
        my_list->head = new_tail;
        my_list->tail = new_tail;
        my_list->count = 1;
    }
    else{
    my_list->tail->next = new_tail;
    my_list->tail = new_tail;
    ++my_list->count;
    }
    return my_list;
}

// returns an index number from a node using the phone
int hash_function (unsigned long long phone){
    int ix = phone % SIZE;
    return ix;
}

void add_to_hastable (list* hashtable [], node* my_node){
    int ix = hash_function(my_node->phone);
    hashtable [ix] = add_node_tail (hashtable [ix], my_node);
}

unsigned long long numbers_list[] = {
    5048451427,
    8103749840,
    8562644130,
    9079212010,
    5135494561,
    4198006759,
    7739248565,
    4088131105,
    6057944895
};

node* search (list* hashtable [], unsigned long long phone){
    int ix = hash_function(phone);
    node* current_node = hashtable[ix]->head;

    while(current_node->phone != phone){
        current_node = current_node->next;
    }
    return current_node;
}

void print_hashtable (list* hashtable []){
    for (int i = 0; i < SIZE; i++){
        printf("\nindex %d: ", i);
        
        node* current_node = hashtable[i]->head;

        while (current_node != NULL){
            printf("%llu ", current_node->phone);
            current_node = current_node->next;
        }
    }
}

void free_list(node* head){
            if (head == NULL)
                return;
            free_list(head->next);
            free(head);
        }
        
void free_hashtable (list* hashtable []){
    
    for (int i = 0; i < SIZE; i++){
        
        printf("\nfreeing memory");

        node* head1 = hashtable[i]->head;
        
        free_list(head1);
    }
}

int main(int argc, char **argv){

    printf("main has run\n");
    list* hashtable_1 [SIZE];

    for (int i = 0; i < SIZE; i++){
        hashtable_1[i] = create_list();
    }

    

    for (int i = 0; i < 9; i++){
        add_to_hastable (hashtable_1, create_node('A'+i, numbers_list[i]));
    }

    char found = (search (hashtable_1, 4088131105))->name;
    printf("Found: %c\n", found);

    print_hashtable(hashtable_1);
    
    free_hashtable(hashtable_1);

    print_hashtable(hashtable_1);
    
    return 0;
}