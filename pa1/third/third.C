#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int info;
	struct node *next;
} node;

node *head;

#define size 10000
node* free_Nodes[size + 1];
int count = 0;
int find = 0;
int count_I = 0;
void fixList(int key, node** buckets);
void search(int key, node* buckets[]) {
int hash = key % size;
if (hash < 0) {
hash += 10000;
}
if (hash > size) {
return;
}
if (buckets[hash]) {
node* head = buckets[hash];
while (head != NULL) {
if (head->info == key) {
++find;
}
head = head->next;
}
}
}
void insertToTable(int key, node* buckets[]);
void clearHash(int count_I, node * free_Nodes[]) {
int i;
for (i = 0; i < count_I; i++) {
if (free_Nodes[i] != NULL) {
free(free_Nodes[i]);
}
}
}
void fixList(int key, node** buckets){
int hash = key % size;
if (hash < 0) {
hash += 10000;
}
if (hash > size) {
return;
}
if (buckets[hash]) {
node* head = buckets[hash];
}
}
int main(int argc, char** argv) {
FILE *file;
file = fopen(argv[1], "r");
if (file == NULL) {
printf("error");
return 0;
}
char tempHolder;
int key;
node* buckets[size + 1];
for (int i = 0; i < size; i++) {
buckets[i] = NULL;
}
while (!feof(file)) {
fscanf(file, "%c\t%d\n", &tempHolder, &key);
if (tempHolder == 'i') {
insertToTable(key, buckets);
++count_I;
}
else if (tempHolder == 's') {
search(key, buckets);
}
}
fclose(file);
printf("%d\n", count);
printf("%d", find);
clearHash(count_I, free_Nodes);
return 0;
}
void insertToTable(int key, node* buckets[]) {
int hash = key % size;
if (hash < 0) {
hash += 10000;
}
if (hash > size) {
return;
}
node* hashedNode = (node *)malloc(sizeof(node));
hashedNode->info = key;
if (buckets[hash] != NULL) {
++count;
node* head = buckets[hash];
while (head) {
if (head->info == key) {
free(hashedNode);
return;
}
if (!(head->next)) {
head->next = hashedNode;
free_Nodes[count_I] = hashedNode;
return;
}
head = head->next;
}
}
else {
hashedNode->next = NULL;
buckets[hash] = hashedNode;
free_Nodes[count_I] = hashedNode;
}
}

