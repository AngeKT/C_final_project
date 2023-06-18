#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[21];
    	int level;
	struct Contributor* next;
} Contributor;

typedef struct{
	char skill_name[21];
    	Contributor* ctbrNames;
    	struct Skills* next;
} Skills;

typedef struct{
	int level;
	char name[21];
} Roles;

typedef struct{
    int nbr_of_day;
    int score;
    int best_before;
    int nbr_roles;
    Roles_t* roles;
    char name[21];
} Projects;


//This function will help us each time we find a new skill to add to the linked list. 
void add_skills(Skills** head_add, char* skillName){
	Skills* head = *head_add;
    	Skills* newNode = malloc(sizeof(Skills));
	newNode->skill_name = skillName;
	newNode->ctbrNames = NULL;
	newNode->next = NULL;
	
	if (head == NULL){
		*head = newNode;
		return;
	}
	
	else{	//We will loop till we find the last element of the list
		Skills parcours = **head_add;
		while (parcours.next != NULL)
			parcours = *(parcours.next);
		parcours = newNode;
	}
}

//This function will help us each time we find a new contributor for a skill to add it to the linked list for this skill.
void add_contributors(Contributor** head_add, char* name, int niveau){
	Contributor* head = *head_add;
    	Contributor* newNode = malloc(sizeof(Contributor));
	newNode->name =	name;
	newNode->level = niveau;
	newNode->next = NULL;
	
	if (head == NULL){
		*head = newNode;
		return;
	}
	
	else{
		Contributor parcours = **head_add;
		while (parcours.next != NULL)
			parcours = *(parcours.next);
		parcours = newNode;
	}
}



int searchSkill(Skills* head, char* skillName){
	Skills* parcours = head;
	int count = -1;//This variable is for knowing the position of the skill if we happen to find it
	do{
		if (strcmp(parcours->skill_name, skillName) == 0){
			count++;
			free(ptr);
    			ptr = NULL;
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



int main(int argc, char *argv[]){
    FILE* file;
    file = fopen(argv[1], "r");

    if (file == NULL){
        printf("There's no file\n");
        return 1;
    }//This is to handle a potential error when our programme was given no or empty file.

    int nbrContributors, int nbrProjects;
    fscanf(file, "%d %d", &nbrContributors, &nbrProjects);

    Skills* ptr_skills = NULL; //Here we define a pointer of the structure Skills initialized at NULL to use it after each reading.
    
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
   			int position = searchSkill(ptr_skills, skillName) 
   			Skills* parcours = ptr_skills;
   			for (int loop = 0; loop < position; loop++){
   				parcours = parcours->next;
   			add_contributors(&(parcours->ctbrNames), currentContributor, niveau);
   			}
   		}
   	}
   }

//Once we've finished with each contributor and its skills, let's take care of the project now.  
    
    
    
    for (int i = 0; i < nbrProjects; i++){
        fscanf(file, "%s", &projects[i].name);
        fscanf(file, "%d", &projects[i].nbr_of_day);
        fscanf(file, "%d", &projects[i].score);
        fscanf(file, "%d", &projects[i].best_before);
        fscanf(file, "%d", &projects[i].nbr_roles);

      	projects[i].roles = (Roles_t*) malloc(current_project->nbr_roles * sizeof(Roles_t));
        for (int j = 0; j < projects[i].nbr_roles; j++) {
            fscanf(file, "%s", &roles[i].name);
            fscanf(file, "%d", &roles[i].level);
            fgetc(file);
        }
    }

    fclose(file);
    return 0;
}
