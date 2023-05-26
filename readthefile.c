#include <stdio.h>
#include <stdlib.h>

typedef struct Skills_t {
    int level;
    char skill_name[20];
} Skills_t;

typedef struct Contributors_t {
    int nbr_skills;
    char name[21];
    Skills_t* skills;
} Contributors_t;

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

int main() {
    FILE* file;
    file = fopen("/path/to/your_file.txt", "r");

    if (file == NULL) {
        printf("There's no file\n");
        return 1;
    }

    int nbrContributors;
    fscanf(file, "%d", &nbrContributors);
    Contributors_t* contributors = (Contributors_t*)malloc(nbrContributors * sizeof(Contributors_t));

    int nbrProjects;
    fscanf(file, "%d", &nbrProjects);
    Projects_t* projects = (Projects_t*)malloc(nbrProjects * sizeof(Projects_t));
    fgetc(file);

    for (int i = 0; i < nbrContributors; i++) {
        Contributors_t* current_ctbr = &contributors[i];
        fscanf(file, "%s", current_ctbr->name);
        fscanf(file, "%d", &current_ctbr->nbr_skills);
        current_ctbr->skills = (Skills_t*)malloc(current_ctbr->nbr_skills * sizeof(Skills_t));

        for (int j = 0; j < current_ctbr->nbr_skills; j++) {
            Skills_t* current_skill = &current_ctbr->skills[j];
            fscanf(file, "%s", current_skill->skill_name);
            fscanf(file, "%d", &current_skill->level);
            fgetc(file);
        }
        fgetc(file);
    }

    for (int i = 0; i < nbrProjects; i++) {
        Projects_t* current_project = &projects[i];
        fscanf(file, "%s", current_project->name);
        fscanf(file, "%d", &current_project->nbr_of_day);
        fscanf(file, "%d", &current_project->score);
        fscanf(file, "%d", &current_project->best_before);
        fscanf(file, "%d", &current_project->nbr_roles);

        current_project->roles = (Roles_t*)malloc(current_project->nbr_roles * sizeof(Roles_t));
        for (int j = 0; j < current_project->nbr_roles; j++) {
            Roles_t* current_role = &current_project->roles[j];
            fscanf(file, "%s", current_role->name);
            fscanf(file, "%d", &current_role->level);
            fgetc(file);
        }
    }

    fclose(file);
    return 0;
}

   
   
   
 
