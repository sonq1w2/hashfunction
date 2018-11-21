#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// These are encoded IDs, different from actual ones
#define NUM_STUDENTS	49
static long long students_id[NUM_STUDENTS] = {
  40116104020, 40116104024, 40116104098, 40116104166, 40116104178, 
  40116104193, 40116104262, 40116104290, 40116104295, 40116104301, 
  40116104321, 40116104336, 40116104372, 40116104382, 
  40117037217, 40117104017, 40117104049, 40117104081, 40117104086, 
  40117104129, 40117104132, 40117104189, 40117104214, 40117104277, 
  40117104307, 40117104313, 40117104449, 40117104463, 40117110170, 
  40117110576, 40117113099, 40117113964, 40117114727, 40117117785, 
  40117118653, 40117114989, 40117115012, 40119104004, 40119104051, 
  40119104090, 40119104117, 40119104176, 40119104184, 40119104293, 
  40119104325, 40119104339, 40119104404, 40119104406, 40119118005, 
};


/////////////////////////////////////////////////////////////////////
typedef struct node{
	long long id;
	struct node* next;
} NODE;
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
int find_index(long long id){
	return id%4611%49;
}
NODE* hashtable[NUM_STUDENTS];
void addhash(long long key,NODE* node){
	int index=find_index(key);
	if (hashtable[index]==NULL) hashtable[index]=node;
	else {
		node->next=hashtable[index];
		hashtable[index]=node;
	}			
	
}
void deletefunc(NODE* array[]){

	for (int i=0;i<49;i++){
		if (array[i]==NULL) ;

		else free(array[i]);
	}
}
int find_key(long long key,NODE* array[]){
	int index;	
	for (int i=0;i<49;i++){
		if (key=array[i]->id) index=i;	
	}
	return index;
}
/////////////////////////////////////////////////////////////////////
int main()
{
int i=0;
int j=0;
int q;
int p=0;
long long id[49];
NODE* hash_table[49];

	for (i=0;i<49;i++){
		NODE* node=(NODE*)malloc(sizeof(NODE));
		node->id=students_id[i];
		node->next=NULL;
		addhash(node->id,node);    	
	}

	for (i=0;i<49;i++){
		if (hashtable[i]!=NULL)	{ 	
			if (hashtable[i]->next!=NULL) 
				printf("id:%lld  index:%d\n",hashtable[i]->next->id,i);			
			printf("id:%lld  index:%d\n",hashtable[i]->id,i);}
	}



}
