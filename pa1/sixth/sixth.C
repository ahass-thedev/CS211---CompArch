#include <stdio.h>
#include <stdlib.h>

typedef struct node {
int info;
int tree_height;
struct node *left;
struct node *right;
} node;

int insertion(node *head_insert, int info);
void update(node *head);
void sort(node *head);

int main(int argc, char **argv) {
struct node *head = (node*)malloc(sizeof(node));
char tracker;
int info;
FILE *file;
file = fopen(argv[1], "r");
if (file == NULL) {
printf("error\n");
return 0;}
int length = 0;
while (fscanf(file, "%c\t%d\n", &tracker, &info) != EOF) {
if (tracker == 'i') {
length = insertion(head, info);
if (length == 0) {
continue;}
}
}
sort(head);
free(head);
fclose(file);
return 0;
}
int insertion(node *head_insert, int info) {
struct node *ptr = head_insert;
struct node *prev = NULL;
struct node *switch_node = (node*)malloc(sizeof(node));
int tree_height = 1;
if (head_insert->tree_height == 0) {
head_insert->left = NULL;
head_insert->right = NULL;
head_insert->tree_height = 1;
head_insert->info = info;
return 1;
}
switch_node->left = NULL;
switch_node->right = NULL;
switch_node->tree_height = 0;
switch_node->info = info;
while (ptr != NULL) {
if (ptr->info == switch_node->info) 
return 0;
if (ptr->info > switch_node->info) {
prev = ptr;
ptr = ptr->left;
tree_height++;
}
else {
prev = ptr;
ptr = ptr->right;
tree_height++;
}
}
switch_node->tree_height = tree_height;
if (prev->info > switch_node->info) {
prev->left = switch_node;
return switch_node->tree_height;
}
else {
prev->right = switch_node;
return switch_node->tree_height;
}
free(switch_node);
}
void update(node *head){
struct node *ptr = head;
struct node *prev = NULL;
struct node *switch_node = (node*)malloc(sizeof(node));
int tree_height = 1;
}
int treeheight(node *head) {
struct node *ptr = head;
int counter;
if (head == NULL) 
return 0;

while(ptr!= NULL){
counter++;
}	
return counter;	}
void sort(node *head) {
if (head == NULL)
return;
sort(head->left);
printf("%d\t", head->info);
sort(head->right);
}


