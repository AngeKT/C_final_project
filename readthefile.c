#include <stdio.h>
#include <stdlib.h>

typedef struct Skills_t {
    int level;
    char skill_name[20];
} Skills_t;

typedef struct Contributors_t {
    int nbr_skills;
    char name[21];
    Skills_t *skills;
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
        fscanf(file, "%s", contributors[i].name); 
        fscanf(file, "%d", &contributors[i].nbr_skills);
        contributors[i].skills = (Skills_t*) malloc(contributors[i].nbr_skills * sizeof(Skills_t));

        for (int j = 0; j < contributors[i].nbr_skills; j++) {
            fscanf(file, "%s", contributors[i].skills[j].skill_name);
            fscanf(file, "%d", &contributors[i].skills[j].level);
            fgetc(file);
        }
        fgetc(file);
    }

    for (int i = 0; i < nbrProjects; i++) {
        fscanf(file, "%s", projects[i].name);
        fscanf(file, "%d", &projects[i].nbr_of_day);
        fscanf(file, "%d", &projects[i].score);
        fscanf(file, "%d", &projects[i].best_before);
        fscanf(file, "%d", &projects[i].nbr_roles);

      	projects[i].roles = (Roles_t*) malloc(projects[i].nbr_roles * sizeof(Roles_t));
        for (int j = 0; j < projects[i].nbr_roles; j++) {
            fscanf(file, "%s", projects[i].roles[j].name);
            fscanf(file, "%d", &projects[i].roles[j].level);
            fgetc(file);
        }
    }

    fclose(file);
    
    return 0;
}

   
   
   
 
