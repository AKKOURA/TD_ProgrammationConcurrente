#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <String.h>
int kilometrage_total;
pthread_mutex_t lock_kt;
typedef struct _course {
int cid; // identifiant de la course
int km; // longueur de la course
} course;

void *faire_course(void* arg){
    course *une_course = (course *) arg;
    int km_total;
    pthread_mutex_lock(&lock_kt);
    printf("Acquisition de la course : %d\n", une_course->cid);	
	kilometrage_total += une_course->km;
    km_total = kilometrage_total;
	printf("Kilometrage total mis à jour après course %d : %d\n", une_course->cid, km_total);
    pthread_mutex_unlock(&lock_kt);
    pthread_exit(NULL);
   
}
int main(int argc, char**argv){
    int ptc;
	int nbCourses = atoi(argv[1]);
	printf("Nb de courses : %d\n", nbCourses);
    course tabCourse[nbCourses];
    pthread_t tabThread[nbCourses];
    kilometrage_total = 0;
    pthread_mutex_init(&lock_kt, NULL);
    for(int i=0; i< nbCourses;i++){
        tabCourse[i].cid = i;
		tabCourse[i].km = (i + nbCourses) * nbCourses;//pk * nbCourse
        
        if((pthread_create(&tabThread[i],NULL,faire_course,&tabCourse[i] )) != 0) {
            perror("erreur pthread_create");
            exit(-1);
        }
        

    }
    for (int i = 0; i < nbCourses; ++i) {
		pthread_join(tabThread[i], NULL);
	}

	printf("\nKilometrage total à la fin de toutes les courses : %d\n", kilometrage_total);

	return EXIT_SUCCESS;
}
