#include <stdio.h>
#include <stdlib.h>

typedef struct contributor
{
    char name[21];
    int level;
    int isassigned = 0;
    struct contributor* next;
}   t_contributor;

typedef struct skill_s
{
    char skill_name[21];
    t_contributor* c_names;
    struct skill_s* next;
}   t_skills;

typedef struct Roles_t {
    int level;
    char name[21];
} Roles_t;

typedef struct Projects_t {
    int nbr_of_day;
    int score;
    int best_before;
    int nbr_roles;
    Roles_t* roles;
    char name[21];
} Projects_t;


void add_skills(t_skills** head_add, char* skill_name){
	t_skills* head = *head_add;
    	t_skills* newNode = malloc(sizeof(t_skills));
	newNode->skill_name = skill_name;
	newNode->next = NULL;
	
	if (head == NULL){
		*head = newNode;
		return;
	}
	
	else{	//We will loop till we find the last element of the list
		t_skills parcours = **head_add;
		while (parcours.next != NULL)
			parcours = *(parcours.next);
		parcours = newNode;
	}
}

void add_contributors(t_contributor** head_add, char* name, int num){
	t_contributor* head = *head_add;
    	t_contributor* newNode = malloc(sizeof(t_contributor));
	newNode->name =	name;
	newNode->level = num;
	newNode->next = NULL;
	
	if (head == NULL){
		*head = newNode;
		return;
	}
	
	else{
		t_skills parcours = **head_add;
		while (parcours.next != NULL)
			parcours = *(parcours.next);
		parcours = newNode;
	}
}

int main(int argc, char *argv[]) {
    FILE* file;
    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("There's no file\n");
        return 1;
    }

    int nbrContributors;
    fscanf(file, "%d", &nbrContributors);
    Contributors_t* contributors = (Contributors_t*) malloc(nbrContributors * sizeof(Contributors_t));

    int nbrProjects;
    fscanf(file, "%d", &nbrProjects);
    Projects_t* projects = (Projects_t*) malloc(nbrProjects * sizeof(Projects_t));
    fgetc(file);

    for (int i = 0; i < nbrContributors; i++) {
        fscanf(file, "%s", &contributors[i].name); 
        fscanf(file, "%d", &contributors[i].nbr_skills);
        contributors[i].isassigned = 0;
        contributors[i].skills = (Skills_t*) malloc(current_ctbr->nbr_skills * sizeof(Skills_t));

        for (int j = 0; j < contributors[i].nbr_skills; j++) {
            fscanf(file, "%s", &skills[j].skill_name);
            fscanf(file, "%d", &skills[j].level);
            fgetc(file);
        }
        fgetc(file);
    }

    for (int i = 0; i < nbrProjects; i++) {
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
    
    
    // Array to track project completion status
    int completed[nbrProjects];
    for (int i = 0; i < nbrProjects; i++) {
        completed[i] = 0;
    }

    // Assign contributors to projects and calculate scores
    int totalScore = 0;
    int day = 0;
    for (int i = 0; i < numProjects; i++) {
        int projectCompleted = 0;
        int contributorsAvailable = 0;
        int assignedContributors[numContributors];
        int numAssignedContributors = 0;



 return 0;
}

