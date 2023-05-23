#include <stdio.h>
#include <stdlib.h>

typedef struct Contributors_t{
	int nbr_skills;
	char name[21];
	Skills* skills;
} ctbr; 

typedef struct Skills_t{
	int level;
	char skill_name[20];
} Skills; 

typedef struct Projects_t{
	int nbr_of_day;
	int score;
	int best_before;
	int nbr_roles;
	Roles* roles;.
	char name[21];
} Projects;

typedef struct Roles_t{
	int level;
	char name[21];
} Roles;


int main(){
 FILE* file;
 file = fopen("/path/to/your_file.txt", "r");
 
 if (file == NULL){
    	printf("There's no file\n");
    	return 1;
 }
    
 int nbrContributors;
 fscanf(file, "%d", &nbrContributors);
 ctbr* contributors = (ctbr*) malloc(nbrContributors * sizeof(ctbr));  
 
 int nbrProjects;
 fscanf(file, "%d", &nbrProjects);
 Projects* projects;
 fgetc(file);
 
 for (int i= 0; i < nbrContributors; i++){
 	ctbr* current_ctbr = &contributors[i];
 	scanf("%s", currentCtbr->name);
 	scanf("%d", &currentCtbr->nbr_skills);
 	currentCtbr->skills = (Skills*) malloc(nbr_skills * sizeof(Skills));
 	
 	for (int j = 0; j < nbr_skills; j++){
	 	Skills current_skills = &skills[j];
	 	scanf("%s", current_skills->skill_name);
	 	scanf("%d", &skill->level);
	 	fgets(file);
 	}
 	fgets(line);
 	
 projects = (Projects*) malloc(nbrProjects * sizeof(Projects));
 for (int i= 0, i < nbrProjects, i++){
 	Projects* current_project = projects + i;
 	scanf("%s", current_project->name);
 	scanf("%d", &current_project->nbr_of_day);
 	scanf("%d", &current_project->score);
 	scanf("%d", &current_project->best_before);
 	scanf("%d", &current_project->nbr_roles);
 	
 	Roles roles = (Roles*) malloc(nbr_roles * sizeof(Roles));
 	for (int j = 0; j < nbr_skills; j++){ple:
 		Roles* current_role = roles + j;
 		scanf("%s", current_role->name);
 		scanf("%d", &current_role->level);
 		fgets(file);
 	}
    
    
   
   
   
   
   
   
 fclose(file);
 return 0;
}

