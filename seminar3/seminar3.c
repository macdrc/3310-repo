#include <stdlib.h>
#include <stdio.h>

typedef struct node_ {
    int pid;
    char name;
    struct node_ *left;
    struct node_ *right;
} node;

typedef struct tree_ {
    node *root;
    int count;
} tree;

node* create_node_4 (int pid, char my_name);                // 4
tree* create_tree_5 ();                                     // 5
int add_to_tree_pid_6 (tree* my_tree, node* my_node);       // 6


int print_ascending_7 (node *root);                             // 7
int print_decending_8 (node *root);                             // 8

int remove_node_with_pid (node *root, int my_pid);              // 9
node* remove_node_and_return_it (node *root, node *my_node);    // 10

int check_pid_in_tree_11 (node *root, int my_pid);              // 11

int add_to_tree_alphabetical_12(tree* my_tree, node* my_node);  // 12

int find_size_of_tree_13 (node *root);                          // 13
node* make_copy_of_tree_14 (node *root);                        // 14

int count_nodes_with_char_15 (node *root, char my_name);        // 15

int sum_of_all_pid_16 (node *root);                             // 16

int print_all_even_details_17 (node *root);                     // 17

int get_max_total_branch_value_18 (node *root);                 // 18
int get_longest_branch_size_19 (node *root);                    // 19




node* create_node_4 (int pid, char my_name){                    // 4
    node* new_node = malloc(sizeof(node));
    new_node->pid = pid;
    new_node->name = my_name;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

tree* create_tree_5 (){                                         // 5
    tree* new_tree = malloc(sizeof(tree));
    new_tree->root = NULL;
    new_tree->count = 0;
    return new_tree;
}

int add_to_tree_pid_6 (tree* my_tree, node* my_node){           // 6
    if (my_tree == NULL || my_node == NULL)
        return -1;
    if (my_tree->root == NULL){
        my_tree->root = my_node;
        my_tree->count = 1;
        return 0;
    }
    ++(my_tree->count);
    node* current_node = my_tree->root;

    while (1){
        if (my_node->pid < current_node->pid){
            if (current_node->left == NULL){
                current_node->left = my_node;
                return 0;
            }
            current_node = current_node->left;
        }
        else {
            if (my_node->pid > current_node->pid){
                if (current_node->right == NULL){
                    current_node->right = my_node;
                    return 0;
                }
            }
            current_node = current_node->right;
        }
    }  
}

int print_ascending_7 (node *root){                             // 7
    if (root == NULL)
        return -1;
    print_ascending_7 (root->left);
    printf ("%d%c ", root->pid, root->name);
    print_ascending_7 (root->right);
    return 0;
}

int print_decending_8 (node *root){                             // 8
    if (root == NULL)
        return -1;
    print_decending_8 (root->right);
    printf ("%d%c ", root->pid, root->name);
    print_decending_8 (root->left);
    return 0;
}

int remove_node_with_pid (node* root, int my_pid){              // 9
    if (root == NULL)
        return -1;
    if (root->pid == my_pid){

    }
    
}

node* remove_node_and_return_it (node *root, node *my_node){    // 10

}

int check_pid_in_tree_11 (node *root, int my_pid){              // 11
    if (root == NULL)
        printf("pid %d NOT IN THE TREE!!!\n", my_pid);
    if (root->pid == my_pid){
        printf("%d found in node %c\n", my_pid, root->name);
    }
    if (my_pid < root->pid)
        return check_pid_in_tree_11(root->left, my_pid);
    if (my_pid > root->pid)
        return check_pid_in_tree_11(root->right, my_pid);
}

int add_to_tree_alphabetical_12(tree* my_tree, node* my_node){  // 12
    if (my_tree == NULL || my_node == NULL)
        return -1;
    if (my_tree->root == NULL){
        my_tree->root = my_node;
        my_tree->count = 1;
        return 0;
    }
    ++(my_tree->count);
    node* current_node = my_tree->root;

    while (1){
        if (my_node->name < current_node->name){
            if (current_node->left == NULL){
                current_node->left = my_node;
                return 0;
            }
            current_node = current_node->left;
        }
        else {
            if (my_node->name > current_node->name){
                if (current_node->right == NULL){
                    current_node->right = my_node;
                    return 0;
                }
            }
            current_node = current_node->right;
        }
    } 
}

int find_size_of_tree_13 (node *root){                          // 13
    if (root == NULL)
        return 0;
    else {
    return 1
    + find_size_of_tree_13(root->left)
    + find_size_of_tree_13 (root->right);
    }
}

node* make_copy_of_tree_14 (node *root){                        // 14
    if (root == NULL)
        return NULL;
    
    node* new_node = create_node_4(root->pid, root->name);
    new_node->left = make_copy_of_tree_14(root->left);
    new_node->right = make_copy_of_tree_14(root->right);
    return new_node;
}

int count_nodes_with_char_15 (node *root, char my_name){        // 15
    if (root == NULL)
        return 0;

    int count = 0;
    
    if (root->name == my_name) {
        count++;
    }
    return count 
    + count_nodes_with_char_15 (root->left, my_name)
    + count_nodes_with_char_15 (root->right, my_name);
}

int sum_of_all_pid_16 (node *root){                             // 16
    if (root == NULL)
        return 0;
    
    else {
        return root->pid
        + sum_of_all_pid_16 (root->left)
        + sum_of_all_pid_16 (root->right);
    }
}

int print_all_even_details_17 (node *root){                     // 17
    if (root == NULL)
        return 0;

    // same as print_ascending, but checking if even
    if (root->pid % 2 == 0){
        print_all_even_details_17 (root->left);
        printf ("%d%c ", root->pid, root->name);
        print_all_even_details_17 (root->right);
        return 0;
    }
}

int get_max_total_branch_value_18 (node *root){                 // 18
    if (root == NULL)
        return 0;
    int max_left = get_max_total_branch_value_18 (root->left);
    int max_right = get_max_total_branch_value_18 (root->right);

    int largest;

    if (max_left > max_right)
        largest = max_left;
    else
        largest = max_right;

    int final_sum = largest + root->pid; // where the actual summing is happening

    return final_sum;
}

int get_longest_branch_size_19 (node *root){                 // 19
    
    // same as branch size, except adding up depths
    if (root == NULL)
        return 0;
    int longest_left = get_longest_branch_size_19 (root->left);
    int longest_right = get_longest_branch_size_19 (root->right);

    int longest;

    if (longest_left > longest_right)
        longest = longest_left;
    else
        longest = longest_right;

    int final_sum = 1 + longest; // where the actual summing is happening

    return final_sum;
}

int main (int argc, char** argv){

    tree* my_tree = create_tree_5();

    add_to_tree_pid_6 (my_tree, create_node_4(20, 'A'));
    add_to_tree_pid_6 (my_tree, create_node_4(16, 'B'));
    add_to_tree_pid_6 (my_tree, create_node_4(30, 'A'));
    add_to_tree_pid_6 (my_tree, create_node_4(12, 'D'));
    add_to_tree_pid_6 (my_tree, create_node_4(18, 'E'));
    add_to_tree_pid_6 (my_tree, create_node_4(26, 'F'));
    add_to_tree_pid_6 (my_tree, create_node_4(40, 'G'));
    add_to_tree_pid_6 (my_tree, create_node_4(10, 'H'));
    add_to_tree_pid_6 (my_tree, create_node_4(14, 'I'));
    add_to_tree_pid_6 (my_tree, create_node_4(17, 'J'));
    add_to_tree_pid_6 (my_tree, create_node_4(19, 'K'));
    add_to_tree_pid_6 (my_tree, create_node_4(21, 'L'));
    add_to_tree_pid_6 (my_tree, create_node_4(35, 'M'));
    add_to_tree_pid_6 (my_tree, create_node_4(45, 'N'));
    add_to_tree_pid_6 (my_tree, create_node_4(65, 'O'));

    // add_to_tree_alphabetical_12 (my_tree, create_node_4(20, 'A'));
    // add_to_tree_alphabetical_12 (my_tree, create_node_4(16, 'B'));
    // add_to_tree_alphabetical_12 (my_tree, create_node_4(30, 'C'));
    // add_to_tree_alphabetical_12 (my_tree, create_node_4(12, 'D'));
    // add_to_tree_alphabetical_12 (my_tree, create_node_4(18, 'E'));
    // add_to_tree_alphabetical_12 (my_tree, create_node_4(26, 'F'));
    // add_to_tree_alphabetical_12 (my_tree, create_node_4(40, 'G'));
    // add_to_tree_alphabetical_12 (my_tree, create_node_4(10, 'H'));
    // add_to_tree_alphabetical_12 (my_tree, create_node_4(14, 'I'));
    // add_to_tree_alphabetical_12 (my_tree, create_node_4(17, 'J'));
    // add_to_tree_alphabetical_12 (my_tree, create_node_4(19, 'K'));
    // add_to_tree_alphabetical_12 (my_tree, create_node_4(21, 'L'));
    // add_to_tree_alphabetical_12 (my_tree, create_node_4(35, 'M'));
    // add_to_tree_alphabetical_12 (my_tree, create_node_4(45, 'N'));
    // add_to_tree_alphabetical_12 (my_tree, create_node_4(65, 'O'));

    // check_pid_in_tree_11 (my_tree->root, 30);
    // print_ascending_7 (my_tree->root);
    // print_decending_8 (my_tree->root);

    // printf("Count is %d\nManual count is %d", my_tree->count, find_size_of_tree_13 (my_tree->root));

    tree *tree2 = create_tree_5();
    tree2->root = make_copy_of_tree_14 (my_tree->root);
    print_ascending_7 (my_tree->root);
    printf("\n");

    print_ascending_7 (tree2->root);
    printf("\n");

    printf ("nodes with A in my_tree: %d\n", count_nodes_with_char_15 (my_tree->root, 'A'));

    printf ("Sum of all pid in my_tree: %d\n", sum_of_all_pid_16 (my_tree->root));
    
    print_all_even_details_17 (tree2->root);
    printf("\n");
    
    printf ("Max total branch value of my_tree is: %d\n", get_max_total_branch_value_18 (my_tree->root));
    printf ("Longest branch size of my_tree is: %d\n", get_longest_branch_size_19 (my_tree->root));
    return 0;
}