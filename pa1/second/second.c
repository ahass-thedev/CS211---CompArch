#include <stdio.h>
#include <stdlib.h>

typedef struct node {
int info;
struct node* next;
} node;

node *newNode(int info, node *head);
int location(int info, node *head);
//void testNode(node *head);
node *removeNode(int info, node *head);
int itemCount(node *head);
node *sortList(node *head);
int main(int argc, char** argv) {
struct node *head = NULL;
struct node *ptr = NULL;
int y, counter, state, var = 0;
char tracker;
FILE *file;
file = fopen(argv[1], "r");
if (file == NULL) {
printf("error\n");
return 0;
}
while (fscanf(file, "%c\t%d\n", &tracker, &y) != EOF) {
state = location(y, head);
if (tracker == 'i') {
if (state == 1) {
var++;
continue;
}
head = newNode(y, head);}
else if (tracker == 'd') {
head = removeNode(y, head);
}
}
ptr = head;
counter = itemCount(ptr) + var;
if (counter == 0) {
printf("%d\n", counter);
return (0);
}
printf("%d\n", counter);
head = sortList(head);
while (ptr != NULL) {
printf("%d\t", ptr->info);
ptr = ptr->next;
}
fclose(file);
return 0;
}
node *newNode(int info, node *head) {
struct node *newNode = malloc(sizeof(node));
newNode->info = info;
newNode->next = head;
return newNode;
free(newNode);
}
int location(int info, node *head) {
struct node *ptr = head;
while (ptr != NULL) {
if (ptr->info == info)
return 1;
ptr = ptr->next;
}
return 0;
}
node *removeNode(int info, node *head) {
if (head == NULL)
return head;
if (head->info == info) {
if (head->next == NULL) {
head = head->next;
return head;
}
head = head->next;
}
struct node *ptr = head->next;
struct node *prev = head;
while (ptr != NULL) {
if (ptr->info == info) {
prev->next = ptr->next;
}
prev = ptr;
ptr = ptr->next;
}
return head;
}
/*void testNode(node *head){

struct node *ptr = head;
struct node *prev = NULL;
//fix
int tree_height = 1;
}
*/
int itemCount(node *head) {
if (head == NULL)
return 0;
struct node *ptr = head;
int counter = 0;
while (ptr != NULL) {
ptr = ptr->next;
counter++;
}
//testNode(head);
return counter;
}
node *sortList(node *head) {
int temp;
struct node *ptr;
struct node *bot;
struct node *prev = head;
while (prev != NULL) {
ptr = prev->next;
bot = prev;
while (ptr != NULL) {
if (ptr->info < bot->info) {
bot = ptr;
}
ptr = ptr->next;
}
temp = prev->info;
prev->info = bot->info;
bot->info = temp;
prev = prev->next;
}
return head;
}


