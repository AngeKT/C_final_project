#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contributor{
	char name[21];
    	int level;
	struct Contributor* next;
};

struct Skills{
	char skill_name[21];
    	struct Contributor* ctbrNames;
    	struct Skills* next;
};

struct Roles{
	int level;
	char name[21];
};

struct Projects{
    int nbr_of_day;
    int score;
    int best_before;
    int nbr_roles;
    struct Roles* roles;
    char name[21];
};

typedef struct Output_t{
	int* roleHashtag;
	int* ctbrHashtag;
} output;


//This function will help us each time we find a new skill to add to the linked list. 
void add_skills(struct Skills** head_add, char* skillName) {
    struct Skills* head = *head_add;
    struct Skills* newNode = malloc(sizeof(struct Skills));
    strncpy(newNode->skill_name, skillName, sizeof(newNode->skill_name) - 1); 
    newNode->ctbrNames = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        *head_add = newNode;  
        return;
    } else {
        // Find the last element of the list
        struct Skills* parcours = head;
        while (parcours->next != NULL) {
            parcours = parcours->next;
        }
        parcours->next = newNode;  
    }
}


//This function will help us each time we find a new contributor for a skill to add it to the linked list for this skill.
void add_contributors(struct Contributor** head_add, char* name, int niveau) {
    struct Contributor* head = *head_add;
    struct Contributor* newNode = malloc(sizeof(struct Contributor));
    strncpy(newNode->name, name, sizeof(newNode->name) - 1);
    newNode->level = niveau;
    newNode->next = NULL;

    if (head == NULL){
        *head_add = newNode;
        return;
    } 
    else{
        struct Contributor* parcours = *head_add;
        while (parcours->next != NULL) {
            parcours = parcours->next;
    	}
        parcours->next = newNode;
    }
}


int searchSkill(struct Skills* head, char* skillName){
	struct Skills* parcours = head;
	int count = -1;//This variable is for knowing the position of the skill if we happen to find it
	do{
		if (strcmp(parcours->skill_name, skillName) == 0){
			count++;
			free(parcours);
    			parcours = NULL;
    			return count;
    		}
		else{
			parcours = parcours->next;
			count++;
		}
	} while (parcours->next != NULL);
	
	if (strcmp(parcours->skill_name, skillName) == 0)
			return count;
	
	return -1;
//If the function returns -1, it means the skill has not be founded. Otherwise, it's at the position returned.
}

//By here, we start implementing the function for the merge sort algorithm so that we sort the contributor based on their skill level
struct Contributor* merge(struct Contributor* left, struct Contributor* right){
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    struct Contributor* result = NULL;
    if (left->level <= right->level) {
        result = left;
        result->next = merge(left->next, right);
    } 
    else{
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
 }
 
 void split(struct Contributor* head, struct Contributor** left, struct Contributor** right) {
    struct Contributor* slow = head;
    struct Contributor* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = head;
    *right = slow->next;
    slow->next = NULL;
}


void mergeSort(struct Contributor** head) {
    struct Contributor* current = *head;
    struct Contributor* left;
    struct Contributor* right;

    if (current == NULL || current->next == NULL)
        return;

    split(current, &left, &right);

    mergeSort(&left);
    mergeSort(&right);

    *head = merge(left, right);
}


//We will do the same things for the skills
struct Skills* merge1(struct Skills* left, struct Skills* right){
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    struct Skills* result = NULL;
    if (left->skill_name[0] <= right->skill_name[0]){
        result = left;
        result->next = merge1(left->next, right);
    } 
    else{
        result = right;
        result->next = merge1(left, right->next);
    }
    return result;
}
 

void split1(struct Skills* head, struct Skills** left, struct Skills** right){
    struct Skills* slow = head;
    struct Skills* fast = head->next;

    while (fast != NULL){
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = head;
    *right = slow->next;
    slow->next = NULL;
}


void mergeSort1(struct Skills** head) {
    struct Skills* current = *head;
    struct Skills* left;
    struct Skills* right;

    if (current == NULL || current->next == NULL)
        return;

    split1(current, &left, &right);

    mergeSort1(&left);
    mergeSort1(&right);

    *head = merge1(left, right);
}



int main(int argc, char *argv[]){
    FILE* file;
    file = fopen(argv[1], "r");

    if (file == NULL){
        printf("There's no file\n");
        return 1;
    }//This is to handle a potential error when our programme was given no or empty file.

    int nbrContributors;
    int nbrProjects;
    fscanf(file, "%d %d", &nbrContributors, &nbrProjects);

    struct Skills* ptr_skills = NULL; //Here we define a pointer of the structure Skills initialized at NULL to use it after each reading.
    
    for (int i = 0; i < nbrContributors; i++){
    	char currentContributor[21]; 
    	int nbrSkills;
    	fscanf(file, "%s %d", currentContributor, &nbrSkills);
   	for (int j = 0; j < nbrSkills; j++){//Now we will loop to read each skill and level for this contributor.
   		char skillName[21];
   		int niveau;
   		fscanf(file, "%s %d", skillName, &niveau);
   		if (ptr_skills == NULL){//This is for the first input.
			add_skills(&ptr_skills, skillName);
			add_contributors(&(ptr_skills->ctbrNames), currentContributor, niveau);
   		}
   		
   		else if (searchSkill(ptr_skills, skillName) == -1){//This means this skill hasn't be previously taken into account. So we have to create a new linked list for it.
   			add_skills(&ptr_skills, skillName);
   			add_contributors(&(ptr_skills->ctbrNames), currentContributor, niveau);
   		}
   		
   		else{//Here the skill has already be created. So, we will just have to add the contributor.
   			int position = searchSkill(ptr_skills, skillName); 
   			struct Skills* parcours = ptr_skills;
   			for (int loop = 0; loop < position; loop++){
   				parcours = parcours->next;
   			add_contributors(&(parcours->ctbrNames), currentContributor, niveau);
   			}
   		}
   	}
   }

//Once we've finished with each contributor and its skills, let's take care of the project now.  
	struct Projects* projects = (struct Projects*) malloc(nbrProjects * sizeof(struct Projects));
	for (int i = 0; i < nbrProjects; i++){
		fscanf(file, "%s", projects[i].name);
		fscanf(file, "%d", &projects[i].nbr_of_day);
		fscanf(file, "%d", &projects[i].score);
		fscanf(file, "%d", &projects[i].best_before);
		fscanf(file, "%d", &projects[i].nbr_roles);

	      	projects[i].roles = (struct Roles*) malloc(projects[i].nbr_roles * sizeof(struct Roles));
		for (int j = 0; j < projects[i].nbr_roles; j++) {
		    fscanf(file, "%s", projects[i].roles[i].name);
		    fscanf(file, "%d", &projects[i].roles[i].level);
		    fgetc(file);
		}
	    }

    fclose(file);
    
    
//Now we're done with reading the input. Let's work on the data to solve the problem then!  
   
  mergeSort1(&ptr_skills);
  mergeSort(&(ptr_skills->ctbrNames));
 
//Now that we've sorted our linked lists, let's assign now the roles to the contributors

// Array to track project completion status
    int completed[numProjects];
    for (int i = 0; i < numProjects; i++)
        completed[i] = 0;
    

 
 


 return 0;
}

