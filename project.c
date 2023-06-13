#include <stdio.h>

// Structure to represent a contributor
typedef struct {
    char name[20];
    int level;
} Contributor;

// Structure to represent a project
typedef struct {
    char name[20];
    int requiredLevel;
    int score;
    int bestBeforeDay;
} Project;

int main() {
    // Contributors
    Contributor contributors[] = {
        {"Ahmed", 5},
        {"Fatima", 2},
        {"Anna", 2},
        {"Karim", 3},
        {"Bob", 5}
    };
    int numContributors = sizeof(contributors) / sizeof(contributors[0]);

    // Projects
    Project projects[] = {
        {"Ecommerce", 3, 10, 7},
        {"BlogApp", 4, 10, 5},
        {"MobileApp", 3, 20, 20}
    };
    int numProjects = sizeof(projects) / sizeof(projects[0]);

    // Array to track project completion status
    int completed[numProjects];
    for (int i = 0; i < numProjects; i++) {
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

        // Find contributors available for the project
        for (int j = 0; j < numContributors; j++) {
            if (contributors[j].level >= projects[i].requiredLevel) {
                assignedContributors[numAssignedContributors] = j;
                numAssignedContributors++;
                contributorsAvailable++;
            }
        }

        // Check if all contributors are available
        if (contributorsAvailable == numAssignedContributors) {
            // Assign contributors to the project and calculate completion day
            int completionDay = day + projects[i].bestBeforeDay;
            for (int j = 0; j < numAssignedContributors; j++) {
                printf("Day %d to day %d: %s is working on project %s\n", day, completionDay, contributors[assignedContributors[j]].name, projects[i].name);
            }

            // Update contributors' skill levels
            for (int j = 0; j < numAssignedContributors; j++) {
                contributors[assignedContributors[j]].level++;
            }

            // Check if the project is completed before the best before day
            if (completionDay <= projects[i].bestBeforeDay) {
                completed[i] = 1;
                totalScore += projects[i].score - (projects[i].bestBeforeDay - completionDay);
                projectCompleted = 1;
            }
        }

        // Increment the day counter if a project is completed
        

    

    return 0;
}

