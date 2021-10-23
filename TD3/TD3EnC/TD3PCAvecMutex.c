#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <String.h>
int val;
pthread_mutex_t monMutex = PTHREAD_MUTEX_INITIALIZER;
int Inc(){
    val++;
    printf("Inc %d\n " ,val);

    return val;

}

int Dec(){
    
    val--;
    printf("Dec %d \n" ,val);
    return val;
 
}

void *IncTache (void *arg){
 for(int i=0;i<=20 ; i++){
     pthread_mutex_lock( &monMutex ); //verrouiller le mutex
     Inc();
     pthread_mutex_unlock( &monMutex ); //deverouille le mutex
 }
 return 0;
 
}
void *DecTache (void *arg){
    
   for(int i=0;i<=20; i++){
     pthread_mutex_lock( &monMutex ); //verrouiller le mutex
     Dec();
     pthread_mutex_unlock( &monMutex ); //deverouille le mutex
    }
    return 0;
   

}

pthread_t cree_tache(void * (*start_routine)(void *), void * arg){
    pthread_t id;
    int erreur;
    erreur = pthread_create( &id, NULL, start_routine, arg);
    if (erreur != 0){
        perror( "Echec creation de tâche Posix" );
        exit(-1);
    } 
 return id;
}

int main(){
  
    pthread_t id;
    pthread_t tacheDec;
    pthread_t tacheInc;

     val = 0;
    tacheInc= cree_tache( IncTache, (void*)  val);
    //  pthread_join(tacheInc, NULL); 
    tacheDec= cree_tache( DecTache, (void*)  val);
      pthread_join(tacheDec, NULL); 

    printf( "valeur final %d ",val);
    return 0;
    
    
  

}
